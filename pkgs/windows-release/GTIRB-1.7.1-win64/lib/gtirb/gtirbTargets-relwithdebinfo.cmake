#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "proto" for configuration "RelWithDebInfo"
set_property(TARGET proto APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(proto PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/proto.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS proto )
list(APPEND _IMPORT_CHECK_FILES_FOR_proto "${_IMPORT_PREFIX}/lib/proto.lib" )

# Import target "gtirb" for configuration "RelWithDebInfo"
set_property(TARGET gtirb APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(gtirb PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/gtirb.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/gtirb.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS gtirb )
list(APPEND _IMPORT_CHECK_FILES_FOR_gtirb "${_IMPORT_PREFIX}/lib/gtirb.lib" "${_IMPORT_PREFIX}/bin/gtirb.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
