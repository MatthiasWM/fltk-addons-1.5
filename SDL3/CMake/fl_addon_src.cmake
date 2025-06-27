#
# This is called by the core add-on feature from the FLTK core library.
#
# FL_ADDON_BASE is the absolute path to this add-on
# FL_ADDON_INCLUDE is the absolute file name of this script
#

message("Das ist ein test ----")


list(REMOVE_ITEM DRIVER_FILES
  drivers/Darwin/fl_macOS_platform_init.cxx
)

list(APPEND DRIVER_FILES
  ${FL_ADDON_BASE}/src/drivers/SDL3/SDL_platform_init.cxx
)

list(APPEND DRIVER_HEADER_FILES
#  ${FL_ADDON_BASE}/FL/FL_Range_Slider.H
)

include_directories(${FL_ADDON_BASE})

