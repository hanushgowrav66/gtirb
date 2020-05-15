#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gtirb_layout" for configuration "Debug"
set_property(TARGET gtirb_layout APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(gtirb_layout PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/gtirb_layoutd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/gtirb_layoutd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS gtirb_layout )
list(APPEND _IMPORT_CHECK_FILES_FOR_gtirb_layout "${_IMPORT_PREFIX}/lib/gtirb_layoutd.lib" "${_IMPORT_PREFIX}/bin/gtirb_layoutd.dll" )

# Import target "gtirb_pprinter" for configuration "Debug"
set_property(TARGET gtirb_pprinter APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(gtirb_pprinter PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/gtirb_pprinterd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/gtirb_pprinterd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS gtirb_pprinter )
list(APPEND _IMPORT_CHECK_FILES_FOR_gtirb_pprinter "${_IMPORT_PREFIX}/lib/gtirb_pprinterd.lib" "${_IMPORT_PREFIX}/bin/gtirb_pprinterd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
