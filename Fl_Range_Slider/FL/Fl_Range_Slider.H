
#ifndef Fl_Range_Slider_H
#define Fl_Range_Slider_H

#include <FL/Fl_Scrollbar.H>

class Fl_Range_Slider:public Fl_Scrollbar
{
  short pushed_;
  short slider_size_i_;
  short min_sash_size_;

private:
  void drawSlider(int x, int y, int w, int h);
  void drawSliderBg(int x, int y, int w, int h);

protected:
  FL_EXPORT void draw() override;
  FL_EXPORT int handle(int) override;

public:
  FL_EXPORT Fl_Range_Slider(int x, int y, int w, int h, const char *l = 0);
  FL_EXPORT int value() { return int(Fl_Slider::value()); }
  FL_EXPORT int value(int position, int size, int top, int total)
    { return scrollvalue(position, size, top, total); }
  FL_EXPORT int scrollvalue(int position, int size, int top, int total);
  FL_EXPORT void slider_size_i(int v);
  FL_EXPORT int slider_size_i() { return slider_size_i_; }
};

#endif
