#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "proto" for configuration "Debug"
set_property(TARGET proto APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(proto PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/protod.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS proto )
list(APPEND _IMPORT_CHECK_FILES_FOR_proto "${_IMPORT_PREFIX}/lib/protod.lib" )

# Import target "gtirb" for configuration "Debug"
set_property(TARGET gtirb APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(gtirb PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/gtirbd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/gtirbd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS gtirb )
list(APPEND _IMPORT_CHECK_FILES_FOR_gtirb "${_IMPORT_PREFIX}/lib/gtirbd.lib" "${_IMPORT_PREFIX}/bin/gtirbd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
