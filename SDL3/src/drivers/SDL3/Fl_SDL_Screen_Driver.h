

#ifndef FL_SDL_SCREEN_DRIVER_H
#define FL_SDL_SCREEN_DRIVER_H

#include "src/Fl_Screen_Driver.H"

class SDL_Window;
class SDL_Renderer;


class Fl_SDL_Screen_Driver : public Fl_Screen_Driver {
public:
  SDL_Window *the_window_ { nullptr };
  SDL_Renderer *the_renderer_ { nullptr };
public:
  Fl_SDL_Screen_Driver();
  void open_display_platform() override;
  void get_system_colors() override;
};


#endif // FL_SDL_SCREEN_DRIVER_H
