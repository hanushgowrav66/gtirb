function(check_gtirb_branch GTIRB_BRANCH_NAME)
  if(NOT "${GTIRB_BRANCH_NAME}" STREQUAL "master")
    message(
      SEND_ERROR
        "The requested gtirb branch ${GTIRB_BRANCH_NAME} is not the branch which was used in the gtirb build.  Gtirb's package branch was: master."
    )
  endif()
endfunction()
include("${CMAKE_CURRENT_LIST_DIR}/gtirbTargets.cmake")
