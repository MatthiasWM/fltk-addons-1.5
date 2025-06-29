

#include "Fl_SDL_System_Driver.h"

#include "src/Fl_Timeout.h"
#include <SDL3/SDL_events.h>

// these pointers are set by the Fl::lock() function:
//static void nothing() {}
extern void (*fl_lock_function)();
extern void (*fl_unlock_function)();


Fl_SDL_System_Driver::Fl_SDL_System_Driver()
: Fl_System_Driver()
{
}


double Fl_SDL_System_Driver::wait(double wait_time)
{
  wait_time = Fl_System_Driver::wait(wait_time);

  Fl::flush();

  if (Fl::idle) // 'idle' may have been set within flush()
    wait_time = 0.0;

  // Elapse timeouts and calculate waiting time
  Fl_Timeout::elapse_timeouts();
  wait_time = Fl_Timeout::time_to_wait(wait_time);

  fl_unlock_function();
  for (;;) {
    SDL_Event event;
    bool timed_out = SDL_WaitEventTimeout(&event, (Sint32)(wait_time*1000.0));
    if (timed_out) break;
    if (event.type == SDL_EVENT_QUIT) {
      //?? Close all windows?
      Fl::e_keysym = FL_Escape;
      Fl::handle(FL_KEYBOARD, Fl::first_window());
      Fl::handle(FL_KEYUP, Fl::first_window());
    }
    wait_time = 0.0;
  }
  fl_lock_function();

  return 0.0; //?? wait_time
}
