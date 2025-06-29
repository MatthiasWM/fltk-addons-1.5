#
# This is called by the core add-on feature from the FLTK core library.
#
# FL_ADDON_BASE is the absolute path to this add-on
# FL_ADDON_INCLUDE is the absolute file name of this script
#

message("---- Using SDL3 as driver backend ----")
# Install and link SDL3 statically. No dynamic linking yet.

include(FetchContent)

FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL
  # This will be a tag once SDL3 is released
  GIT_TAG origin/main
  OVERRIDE_FIND_PACKAGE
)

set(SDL_SHARED OFF)
set(SDL_STATIC ON)
set(SKIP_INSTALL_EXPORT TRUE)
FetchContent_MakeAvailable(SDL3)

list(REMOVE_ITEM DRIVER_FILES
  drivers/Darwin/fl_macOS_platform_init.cxx
)

list(APPEND DRIVER_FILES
  ${FL_ADDON_BASE}/src/drivers/SDL3/SDL_platform_init.cxx
  ${FL_ADDON_BASE}/src/drivers/SDL3/Fl_SDL_Screen_Driver.cxx
  ${FL_ADDON_BASE}/src/drivers/SDL3/Fl_SDL_System_Driver.cxx
  ${FL_ADDON_BASE}/src/drivers/SDL3/Fl_SDL_Window_Driver.cxx
)

list(APPEND DRIVER_HEADER_FILES
  ${FL_ADDON_BASE}/src/drivers/SDL3/Fl_SDL_Screen_Driver.h
  ${FL_ADDON_BASE}/src/drivers/SDL3/Fl_SDL_System_Driver.h
  ${FL_ADDON_BASE}/src/drivers/SDL3/Fl_SDL_Window_Driver.h
)

include_directories(${FL_ADDON_BASE})

