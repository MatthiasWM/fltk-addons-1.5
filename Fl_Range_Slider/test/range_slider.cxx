//
// Hello, World! program for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-2021 by Bill Spitzak and others.
//
// This library is free software. Distribution and use rights are outlined in
// the file "COPYING" which should have been included with this file.  If this
// file is missing or damaged, see the license at:
//
//     https://www.fltk.org/COPYING.php
//
// Please see the following page on how to report bugs and issues:
//
//     https://www.fltk.org/bugs.php
//

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Range_Slider.H>

int main(int argc, char **argv) {
  Fl_Window *window = new Fl_Window(340, 205);
  Fl_Box *box = new Fl_Box(20, 40, 300, 100, "Hello, Add-On!");
  box->box(FL_UP_BOX);
  box->labelfont(FL_BOLD + FL_ITALIC);
  box->labelsize(36);
  box->labeltype(FL_SHADOW_LABEL);
  Fl_Range_Slider *slider = new Fl_Range_Slider(20, 145, 300, 25);
  slider->type(FL_HORIZONTAL);
  slider->scrollvalue(10, 50, 0, 100);
  window->end();
  window->show(argc, argv);
  return Fl::run();
}
