#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "VLCQt::Widgets" for configuration "Debug"
set_property(TARGET VLCQt::Widgets APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(VLCQt::Widgets PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/libVLCQtWidgetsd.dll.a"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/libVLCQtWidgetsd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VLCQt::Widgets )
list(APPEND _IMPORT_CHECK_FILES_FOR_VLCQt::Widgets "${_IMPORT_PREFIX}/lib/libVLCQtWidgetsd.dll.a" "${_IMPORT_PREFIX}/bin/libVLCQtWidgetsd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
