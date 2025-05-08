#
# This is called by the core add-on feature from the FLTK core library.
#
# FL_ADDON_BASE is the absolute path to this add-on
# FL_ADDON_INCLUDE is the absolute file name of this script
#

fl_create_example(native_input ${FL_ADDON_BASE}/test/native_input.cxx fltk::images)
target_include_directories(native_input PRIVATE ${FL_ADDON_BASE} )

