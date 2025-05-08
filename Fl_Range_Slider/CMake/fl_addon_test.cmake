#
# This is called by the core add-on feature from the FLTK core library.
#
# FL_ADDON_BASE is the absolute path to this add-on
# FL_ADDON_INCLUDE is the absolute file name of this script
#

fl_create_example(range_slider ${FL_ADDON_BASE}/test/range_slider.cxx fltk::fltk)
target_include_directories(range_slider PRIVATE ${FL_ADDON_BASE} )

