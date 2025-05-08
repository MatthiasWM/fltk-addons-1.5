#
# This is called by the core add-on feature from the FLTK core library.
#
# FL_ADDON_BASE is the absolute path to this add-on
# FL_ADDON_INCLUDE is the absolute file name of this script
#

message("Das ist ein test ----")

list(APPEND CPPFILES
  ${FL_ADDON_BASE}/src/FL_Range_Slider.cxx
)

list(APPEND HEADER_FILES
  ${FL_ADDON_BASE}/FL/FL_Range_Slider.H
)

include_directories(${FL_ADDON_BASE})
