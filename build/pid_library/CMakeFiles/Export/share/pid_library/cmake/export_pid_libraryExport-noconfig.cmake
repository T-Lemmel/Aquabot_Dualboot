#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "pid_library::pid_library" for configuration ""
set_property(TARGET pid_library::pid_library APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(pid_library::pid_library PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libpid_library.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS pid_library::pid_library )
list(APPEND _IMPORT_CHECK_FILES_FOR_pid_library::pid_library "${_IMPORT_PREFIX}/lib/libpid_library.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
