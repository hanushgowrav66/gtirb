(defpackage :gtirb/ranged
  (:use :common-lisp)
  (:import-from :uiop :nest)
  (:import-from :alexandria
                :when-let
                :mappend)
  (:import-from :cl-containers
                :binary-search-tree
                :insert-item
                :delete-item
                :size
                :element
                :find-successor-node
                :predecessor
                :successor)
  (:export :ranged
           :ranged-insert
           :ranged-delete
           :ranged-find))
;;; TODO: Check for equivalent blocks before and after modified ranges
;;; in `ranged-insert' and `ranged-delete' and collapse them into the
;;; existing range (maybe with the moral equivalent of an :after
;;; method).  This will avoid the monotonic increase in the number of
;;; ranges in the tree over time.
(in-package :gtirb/ranged)
(declaim (optimize (speed 3) (safety 0) (debug 0)))

(defclass ranged ()
  ((tree :initform (make-instance 'binary-search-tree :key #'car :test #'=)
         :type binary-search-tree
         :documentation "Internal store.")
   (min :initform 0 :initarg :min :type (integer * #.(expt 2 64))
        :reader ranged-min :documentation "Minimum possible range value.")
   (max :initform (expt 2 64) :initarg :max :type (integer * #.(expt 2 64))
        :reader ranged-max :documentation "Maximum possible range value."))
  (:documentation
   "A collection supporting retrieval of objects by 64-bit ranges."))

(defmethod initialize-instance :after ((ranged ranged) &key)
  (with-slots (tree) ranged
    (insert-item tree (list (ranged-min ranged)))
    (insert-item tree (list (ranged-max ranged))))
  ranged)

(defmethod print-object ((obj ranged) (stream stream))
  (print-unreadable-object (obj stream :type t :identity t)
    (with-slots (tree) obj (format stream "~a" (size tree)))))

(declaim (inline key))
(declaim (ftype (function (cl-containers::bst-node) (integer * #.(expt 2 64)))
                key))
(defun key (node) (car (element node)))

(defun in-range (ranged &optional
                          (start (ranged-min ranged))
                          (end (1- (the (integer * #.(expt 2 64))
                                        (ranged-max ranged)))))
  "Return nodes of RANGED between START and END.
Additionally, return the successor following END as a secondary value."
  (declare (type ranged ranged)
           (type (integer * #.(expt 2 64)) start)
           (type (integer * #.(expt 2 64)) end))
  (with-slots (tree) ranged
    (let ((start-item (find-successor-node tree (list start))))
      (unless (= (key start-item) start)
        (setf start-item (predecessor tree start-item)))
      (let ((last (successor tree start-item))
            (ranges (list start-item)))
        (loop
           :while (< (key last) end)
           :do (progn (push last ranges) (setf last (successor tree last)))
           :finally (return (values ranges last)))))))

(defun ranged-insert (ranged item start &optional end &aux last)
  "Insert ITEM into ranged collection RANGED between START and END.
Return the RANGED collection after inserting ITEM."
  (check-type ranged ranged "A ranged collection")
  (check-type start (integer * #.(expt 2 64)) "A 64-bit ranged index")
  (unless end (setf end (1+ start)))
  (check-type end (integer * #.(expt 2 64)) "A 64-bit ranged index")
  (nest
   (with-slots (tree) ranged)
   (flet ((replace-node (node &aux (element (element node)))
            (delete-item tree node)
            (insert-item tree (cons (car element) (cons item (cdr element)))))))
   (multiple-value-bind (ranges successor) (in-range ranged start end)
     ;; Possibly split the first range.
     (let ((first (pop ranges)))
       (setf last first)
       (if (= start (key first))
           ;; No need to split, simply replace.
           (replace-node first)
           ;; Add a new node (without deleting the original) which has
           ;; the effect of splitting the range of the original.
           (insert-item tree (cons start (cons item (cdr (element first)))))))
     ;; Handle the remaining ranges.
     (loop :until (null ranges) :do (replace-node (setf last (pop ranges))))
     ;; Possibly split the last range.
     (unless (= end (key successor))
       (insert-item tree (cons end (cdr (element last)))))))
  ranged)

(defun ranged-delete (ranged item start &optional end &aux last)
  "Delete ITEM from ranged collection RANGED between START and END.
Return the RANGED collection after deleting ITEM."
  (check-type ranged ranged "A ranged collection")
  (check-type start (integer * #.(expt 2 64)) "A 64-bit ranged index")
  (unless end (setf end (1+ start)))
  (check-type end (integer * #.(expt 2 64)) "A 64-bit ranged index")
  (nest
   (with-slots (tree) ranged)
   (flet ((replace-node (node &aux (element (element node)))
            (delete-item tree node)
            (insert-item tree (cons (car element)
                                    (remove item (cdr element)))))))
   (multiple-value-bind (ranges successor) (in-range ranged start end)
     ;; Possibly split the first range.
     (let ((first (pop ranges)))
       (setf last first)
       (if (= start (key first))
           ;; No need to split, simply replace.
           (replace-node first)
           ;; Add a new node (without deleting the original) which has
           ;; the effect of splitting the range of the original.
           (insert-item tree (cons start (remove item (cdr (element first)))))))
     ;; Handle the remaining ranges.
     (loop :until (null ranges) :do (replace-node (setf last (pop ranges))))
     ;; Possibly split the last range.
     (unless (= end (key successor))
       (insert-item tree (cons end (remove item (cdr (element last))))))))
  ranged)

(defun ranged-find (ranged start &optional end)
  "Find all items in RANGED between START and END."
  (check-type ranged ranged "A ranged collection")
  (check-type start (integer * #.(expt 2 64)) "A 64-bit ranged index")
  (unless end (setf end (1+ start)))
  (check-type end (integer * #.(expt 2 64)) "A 64-bit ranged index")
  (mappend (lambda (node) (cdr (element node))) (in-range ranged start end)))