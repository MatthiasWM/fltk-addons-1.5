

#include "Fl_SDL_Screen_Driver.h"

#include <SDL3/SDL.h>
//?? #define SDL_MAIN_HANDLED
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

Fl_SDL_Screen_Driver::Fl_SDL_Screen_Driver()
: Fl_Screen_Driver()
{
}

void Fl_SDL_Screen_Driver::open_display_platform()
{
  //?? SDL_RunApp(/*argc*/0, /*argv*/nullptr, SDL_main, nullptr);
  SDL_Init(SDL_INIT_EVENTS|SDL_INIT_VIDEO);
  SDL_SetMainReady();
  the_window_ = SDL_CreateWindow("FLTK with SDL3", w(), h(), SDL_WINDOW_HIGH_PIXEL_DENSITY);
  the_renderer_ = SDL_CreateRenderer(the_window_, nullptr);
  SDL_SetRenderDrawColor(the_renderer_, 20, 20, 200, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(the_renderer_);

  // https://wiki.libsdl.org/SDL3/SDL_CreateTexture
  //?? SDL_Texture * SDL_CreateTexture(SDL_Renderer *renderer, SDL_PixelFormat format, SDL_TextureAccess access, int w, int h);
  //?? SDL_PIXELFORMAT_RGBA8888
  //?? SDL_TEXTUREACCESS_STREAMING SDL_TEXTUREACCESS_TARGET // https://wiki.libsdl.org/SDL3/SDL_TextureAccess
  //?? bool SDL_LockTexture(SDL_Texture *texture,const SDL_Rect *rect,void **pixels, int *pitch);
  //?? SDL_Surface * SDL_CreateSurface(int width, int height, SDL_PixelFormat format);

  //?? bool SDL_CreateWindowAndRenderer(const char *title, int width, int height, SDL_WindowFlags window_flags, SDL_Window **window, SDL_Renderer **renderer);

  SDL_Texture *texture = SDL_CreateTexture(the_renderer_,
                                           SDL_PIXELFORMAT_RGBA8888,
//                                           SDL_TEXTUREACCESS_TARGET, // low res
                                           SDL_TEXTUREACCESS_STREAMING, // high res
                                           w(), h());
//
  SDL_FRect r { 10, 10, 150, 100 };
//
  SDL_SetRenderTarget(the_renderer_, texture);
  SDL_SetRenderDrawColor(the_renderer_, 0x00, 0xff, 0x00, 0xFF);
  SDL_RenderClear(the_renderer_);
  SDL_RenderRect(the_renderer_,&r);
  SDL_SetRenderDrawColor(the_renderer_, 0xFF, 0x00, 0x00, 0xFF);
  SDL_RenderFillRect(the_renderer_, &r);

  void *bitmap = nullptr;
  int pitch = 0;
  SDL_LockTexture(texture, nullptr, &bitmap, &pitch);
  for (int y=0; y<100; y++) {
    uint32_t *d = ((uint32_t*)bitmap) + 200 + y*pitch/4;
    for (int x=0; x<100; x++) {
      *d++ = 0x0000FFFF;
    }
  }
  SDL_UnlockTexture(texture);

  SDL_SetRenderTarget(the_renderer_, NULL);
  SDL_RenderTexture(the_renderer_, texture, NULL, NULL);

  SDL_RenderPresent(the_renderer_);


  Fl_Screen_Driver::open_display_platform();
  // TODO: create the graphics bitmaps and context for the entire screen
  // TODO: load all the resources that we need, fonts, etc.
  // TODO: open the SDL screen
}


void Fl_SDL_Screen_Driver::get_system_colors() {
  open_display();
  Fl_Screen_Driver::get_system_colors();
}
