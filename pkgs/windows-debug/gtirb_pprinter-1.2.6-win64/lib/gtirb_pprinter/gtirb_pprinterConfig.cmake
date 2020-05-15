function(check_gtirb_pprinter_branch GTIRB_PPRINTER_BRANCH_NAME)
  if(NOT "${GTIRB_PPRINTER_BRANCH_NAME}" STREQUAL "master")
    message(
      SEND_ERROR
        "The requested gtirb-pprinter branch ${GTIRB_PPRINTER_BRANCH_NAME} is not the branch which was used in the gtirb-pprinter build.  gtirb-pprinter's package branch was: master."
    )
  endif()
endfunction()
include("${CMAKE_CURRENT_LIST_DIR}/gtirb_pprinterTargets.cmake")
