
#ifndef FL_SDL_SYSTEM_DRIVER_H
#define FL_SDL_SYSTEM_DRIVER_H

#include "src/Fl_System_Driver.H"


class Fl_SDL_System_Driver : public Fl_System_Driver {
public:
  Fl_SDL_System_Driver();
  double wait(double time_to_wait) override;
};


#endif // FL_SDL_SYSTEM_DRIVER_H
