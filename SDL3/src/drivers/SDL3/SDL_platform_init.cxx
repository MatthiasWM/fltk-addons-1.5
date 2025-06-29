//
// macOS-specific code to initialize macOS support.
//
// Copyright 2022 by Bill Spitzak and others.
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

#include <FL/Fl_Copy_Surface.H>
#include <FL/Fl_Graphics_Driver.H>
#include "Fl_SDL_Screen_Driver.h"
#include "Fl_SDL_System_Driver.h"
#include "Fl_SDL_Window_Driver.h"
#include <FL/Fl_Image_Surface.H>
#include <FL/platform.H>


class Fl_SDL_Copy_Surface_Driver : public Fl_Copy_Surface_Driver {
  friend class Fl_Copy_Surface_Driver;
protected:
  Fl_SDL_Copy_Surface_Driver(int w, int h) : Fl_Copy_Surface_Driver(w, h) { }
  void set_current() override { }
  void translate(int x, int y) override { }
  void untranslate() override { }
};

Fl_Copy_Surface_Driver *Fl_Copy_Surface_Driver::newCopySurfaceDriver(int w, int h)
{
  return new Fl_SDL_Copy_Surface_Driver(w, h);
}


class Fl_SDL_Graphics_Driver : public Fl_Graphics_Driver {
public:
  Fl_SDL_Graphics_Driver() : Fl_Graphics_Driver() { }
};

Fl_Graphics_Driver *Fl_Graphics_Driver::newMainGraphicsDriver()
{
  return new Fl_SDL_Graphics_Driver();
}


Fl_Screen_Driver *Fl_Screen_Driver::newScreenDriver()
{
  return new Fl_SDL_Screen_Driver();
}


Fl_System_Driver *Fl_System_Driver::newSystemDriver()
{
  return new Fl_SDL_System_Driver();
}


Fl_Window_Driver *Fl_Window_Driver::newWindowDriver(Fl_Window *w)
{
  return new Fl_SDL_Window_Driver(w);
}


class Fl_SDL_Image_Surface_Driver : public Fl_Image_Surface_Driver {
public:
  Fl_SDL_Image_Surface_Driver(int w, int h, int high_res, Fl_Offscreen off) :
  Fl_Image_Surface_Driver(w, h, high_res, off) { }
  void set_current() override { }
  void translate(int x, int y) override { }
  void untranslate() override { }
  Fl_RGB_Image *image() override { return nullptr; }
};

Fl_Image_Surface_Driver *Fl_Image_Surface_Driver::newImageSurfaceDriver(int w, int h, int high_res, Fl_Offscreen off)
{
  return new Fl_SDL_Image_Surface_Driver(w, h, high_res, off);
}
