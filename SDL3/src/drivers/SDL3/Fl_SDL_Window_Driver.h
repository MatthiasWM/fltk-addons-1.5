


#ifndef FL_SDL_WINDOW_DRIVER_H
#define FL_SDL_WINDOW_DRIVER_H

#include "src/Fl_Window_Driver.H"

// In this version of the SDL driver, we assume one fu

class Fl_SDL_Window_Driver : public Fl_Window_Driver {
public:
public:
  Fl_SDL_Window_Driver(Fl_Window *win);
  void show() override;
  void makeWindow() override;
};


#endif // FL_SDL_WINDOW_DRIVER_H
