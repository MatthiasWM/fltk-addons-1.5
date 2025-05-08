#
# This is called by the core add-on feature from the FLTK core library.
#
# FL_ADDON_BASE is the absolute path to this add-on
# FL_ADDON_INCLUDE is the absolute file name of this script
#

list(APPEND HEADER_FILES
  ${FL_ADDON_BASE}/FL/Fl_Native_Input.H
)

include_directories(${FL_ADDON_BASE})
include_directories(${FLTK_SOURCE_DIR})



#######################################################################
# optional inclusion of class Fl_Native_Input
#######################################################################
#if(FLTK_OPTION_NATIVE_INPUT)
  list(APPEND CPPFILES ${FL_ADDON_BASE}/src/Fl_Native_Input.cxx)
  if(FLTK_USE_CAIRO)
    if(NOT PKG_CONFIG_FOUND)
      message(FATAL_ERROR "Option FLTK_OPTION_NATIVE_INPUT requires availability of pkg-config on the build machine.")
    endif(NOT PKG_CONFIG_FOUND)
    pkg_check_modules(GTK3 IMPORTED_TARGET gtk+-3.0)
    if(NOT(GTK3_FOUND))
      message(FATAL_ERROR "Module 'gtk+-3.0' required for FLTK_OPTION_NATIVE_INPUT is absent")
    endif(NOT(GTK3_FOUND))
    list(APPEND CPPFILES ${FL_ADDON_BASE}/src/drivers/Cairo/Fl_Cairo_Native_Input_Driver.cxx)
    list(APPEND FLTK_BUILD_INCLUDE_DIRECTORIES ${GTK3_INCLUDE_DIRS})
  elseif(WIN32)
    list(APPEND CPPFILES ${FL_ADDON_BASE}/src/drivers/WinAPI/Fl_WinAPI_Native_Input_Driver.cxx)
  elseif(APPLE)
    list(APPEND MMFILES ${FL_ADDON_BASE}/src/drivers/Cocoa/Fl_Cocoa_Native_Input_Driver.mm)
  else()
    list(APPEND CPPFILES ${FL_ADDON_BASE}/src/Fl_Backup_Native_Input.cxx)
  endif()
#endif(FLTK_OPTION_NATIVE_INPUT)
