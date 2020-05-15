#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gtirb_layout" for configuration "RelWithDebInfo"
set_property(TARGET gtirb_layout APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(gtirb_layout PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/gtirb_layout.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/gtirb_layout.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS gtirb_layout )
list(APPEND _IMPORT_CHECK_FILES_FOR_gtirb_layout "${_IMPORT_PREFIX}/lib/gtirb_layout.lib" "${_IMPORT_PREFIX}/bin/gtirb_layout.dll" )

# Import target "gtirb_pprinter" for configuration "RelWithDebInfo"
set_property(TARGET gtirb_pprinter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(gtirb_pprinter PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/gtirb_pprinter.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/gtirb_pprinter.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS gtirb_pprinter )
list(APPEND _IMPORT_CHECK_FILES_FOR_gtirb_pprinter "${_IMPORT_PREFIX}/lib/gtirb_pprinter.lib" "${_IMPORT_PREFIX}/bin/gtirb_pprinter.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
