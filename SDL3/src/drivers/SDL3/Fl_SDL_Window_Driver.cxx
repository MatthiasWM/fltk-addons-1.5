
#include "Fl_SDL_Window_Driver.h"
#include "Fl_SDL_Screen_Driver.h"

#include <FL/x.H>
#include <FL/Fl_Window.H>


// Really old school leftover from FLTK 0.6, also see Fl_X
class FLWindow {
  Fl_Window *window_;
public:
  FLWindow(Fl_Window *w): window_(w) { }
};


Fl_SDL_Window_Driver::Fl_SDL_Window_Driver(Fl_Window *win)
: Fl_Window_Driver(win)
{
}


void Fl_SDL_Window_Driver::show() {
  Fl_X *top = NULL;
  if (parent()) top = Fl_X::flx(pWindow->top_window());
  if (!shown() && !parent()) {
//  if (!shown() && (!parent() || (top && ![(FLWindow*)top->xid isMiniaturized]))) {
    makeWindow();
  } else {
//    if ( !parent() ) {
//      Fl_X *i = Fl_X::flx(pWindow);
//      if ([(FLWindow*)i->xid isMiniaturized]) {
//        i->w->redraw();
//        [(FLWindow*)i->xid deminiaturize:nil];
//      }
//      if (!fl_capture) {
//        [(FLWindow*)i->xid makeKeyAndOrderFront:nil];
//      }
//    }
//    else pWindow->set_visible();
  }
}

void Fl_SDL_Window_Driver::makeWindow() {
//  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  Fl_Group::current(0);
  fl_open_display();
//  NSInteger winlevel = NSNormalWindowLevel;
//  NSUInteger winstyle;
//  Fl_Sys_Menu_Bar::create_window_menu(); // effective once at most
  Fl_Window* w = pWindow;
  if (w->parent()) {
    w->border(0);
    show_iconic(0);
  }
  if (w->border()) {
//    winstyle = (NSWindowStyleMaskTitled | NSWindowStyleMaskClosable |
//                NSWindowStyleMaskMiniaturizable);
//    if (is_resizable())
//      winstyle |= NSWindowStyleMaskResizable;
  } else {
//    winstyle = NSWindowStyleMaskBorderless;
  }
//  if (show_iconic() && !w->parent()) { // prevent window from being out of work area when created iconized
//    int sx, sy, sw, sh;
//    Fl::screen_work_area (sx, sy, sw, sh, w->x(), w->y());
//    if (w->x() < sx) x(sx);
//    if (w->y() < sy) y(sy);
//  }
//  int xp = w->x();
//  int yp = w->y();
//
//  int xwm = xp, ywm = yp, bt, bx, by;
//
//  if (!fake_X_wm(w, xwm, ywm, bt, bx, by)) {
//    // menu windows and tooltips
//    if (w->modal()||w->tooltip_window()) {
//      winlevel = modal_window_level();
//    }
//  }
//  if (w->modal()) {
//    winstyle &= ~NSWindowStyleMaskMiniaturizable;
//    winlevel = modal_window_level();
//  }
//  else if (w->non_modal()) {
//    winlevel = non_modal_window_level();
//  }
//
//  if (force_position()) {
//    if (!Fl::grab()) {
//      xp = xwm; yp = ywm;
//      x(xp);y(yp);
//    }
//    xp -= bx;
//    yp -= by+bt;
//  }
//
  Fl_X *x = new Fl_X;
  other_xid = 0; // room for doublebuffering image map. On OS X this is only used by overlay windows
  x->region = 0;
//  subRect(0);
//  gc = 0;
//  mapped_to_retina(false);
//  changed_resolution(false);
//
//  NSRect crect;
//  if (w->fullscreen_active() && fl_mac_os_version < 100700) {
//    int top, bottom, left, right;
//    int sx, sy, sw, sh, X, Y, W, H;
//
//    top = fullscreen_screen_top();
//    bottom = fullscreen_screen_bottom();
//    left = fullscreen_screen_left();
//    right = fullscreen_screen_right();
//
//    if ((top < 0) || (bottom < 0) || (left < 0) || (right < 0)) {
//      top = Fl::screen_num(w->x(), w->y(), w->w(), w->h());
//      bottom = top;
//      left = top;
//      right = top;
//    }
//
//    Fl::screen_xywh(sx, sy, sw, sh, top);
//    Y = sy;
//    Fl::screen_xywh(sx, sy, sw, sh, bottom);
//    H = sy + sh - Y;
//    Fl::screen_xywh(sx, sy, sw, sh, left);
//    X = sx;
//    Fl::screen_xywh(sx, sy, sw, sh, right);
//    W = sx + sw - X;
//
//    w->resize(X, Y, W, H);
//
//    winstyle = NSWindowStyleMaskBorderless;
//    winlevel = NSStatusWindowLevel;
//  }
//  float s = Fl::screen_driver()->scale(0);
//  crect.origin.x = round(s * w->x()); // correct origin set later for subwindows
//  crect.origin.y = main_screen_height - round(s * (w->y() + w->h()));
//  crect.size.width = int(s * w->w());
//  crect.size.height = int(s * w->h());
  FLWindow *cw = new FLWindow(w);
//  FLWindow *cw = [[FLWindow alloc] initWithFl_W:w
//                                    contentRect:crect
//                                      styleMask:winstyle];
//  [cw setFrameOrigin:crect.origin];
//#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_12
//  if (fl_mac_os_version >= 101200) {
//    if (!w->parent() && (winstyle & NSWindowStyleMaskTitled) &&
//        (winstyle & NSWindowStyleMaskResizable) && !w->modal() && !w->non_modal() &&
//        (Fl_MacOS_Sys_Menu_Bar_Driver::window_menu_style() > Fl_Sys_Menu_Bar::tabbing_mode_none)) {
//      if (Fl_MacOS_Sys_Menu_Bar_Driver::window_menu_style() == Fl_Sys_Menu_Bar::tabbing_mode_preferred)
//        [cw setTabbingMode:NSWindowTabbingModePreferred];
//      else [cw setTabbingMode:NSWindowTabbingModeAutomatic];
//    } else {
//      [cw setTabbingMode:NSWindowTabbingModeDisallowed];
//    }
//  }
//#endif
//  if (!w->parent()) {
//    [cw setHasShadow:YES];
//    [cw setAcceptsMouseMovedEvents:YES];
//  }
//  if (w->shape()) {
//    [cw setOpaque:NO]; // shaped windows must be non opaque
//    [cw setBackgroundColor:[NSColor clearColor]]; // and with transparent background color
//  }
  x->xid = (fl_uintptr_t)cw;
  x->w = w;
  flx(x);
//  wait_for_expose_value = 1;
  if (!w->parent()) {
    x->next = Fl_X::first;
    Fl_X::first = x;
  } else if (Fl_X::first) {
    x->next = Fl_X::first->next;
    Fl_X::first->next = x;
  }
  else {
    x->next = NULL;
    Fl_X::first = x;
  }
//  FLView *myview = [[FLView alloc] initWithFrame:crect];
//  [cw setContentView:myview];
//  [myview release];
//  [cw setLevel:winlevel];
//
//  q_set_window_title(cw, w->label(), w->iconlabel());
//  NSImage *icon = icon_image; // is a window or default icon present?
//  if (!icon) icon = ((Fl_Cocoa_Screen_Driver*)Fl::screen_driver())->default_icon;
//  if (icon && (winstyle & NSWindowStyleMaskTitled) && w->label() && strlen(w->label()) > 0) {
//    [cw setRepresentedFilename:[NSString stringWithFormat:@"/%@", [cw title]]];
//    NSButton *icon_button = [cw standardWindowButton:NSWindowDocumentIconButton];
//    if (icon_button) {
//      [icon setSize:[icon_button frame].size];
//      [icon_button setImage:icon];
//    }
//  }
//  if (!force_position()) {
//    if (w->modal()) {
//      [cw center];
//    } else if (w->non_modal()) {
//      [cw center];
//    } else if (!w->fullscreen_active()) {
//      static NSPoint delta = NSZeroPoint;
//      delta = [cw cascadeTopLeftFromPoint:delta];
//    }
//    crect = [cw frame]; // synchronize FLTK's and the system's window coordinates
//    this->x(round(crect.origin.x/s));
//    this->y( round((main_screen_height - crect.origin.y)/s) - w->h() );
//  }
//  if(w->menu_window()) { // make menu windows slightly transparent
//    [cw setAlphaValue:0.97];
//  }
//  // Install DnD handlers
//  [myview registerForDraggedTypes:[NSArray arrayWithObjects:UTF8_pasteboard_type,
//                                   fl_filenames_pboard_type, nil]];
//
//  if (pWindow->get_size_range(NULL, NULL, NULL, NULL, NULL, NULL, NULL)) size_range();
//
//  if ( w->border() || (!w->modal() && !w->tooltip_window()) ) {
//    Fl_Tooltip::enter(0);
//  }
//
//  if (w->modal()) Fl::modal_ = w;
//
  w->set_visible();
  if ( w->border() || (!w->modal() && !w->tooltip_window() &&
                       w->user_data() != (void*)&Fl_Screen_Driver::transient_scale_display) ) Fl::handle(FL_FOCUS, w);
//  [cw setDelegate:[FLWindowDelegate singleInstance]];
//  if (show_iconic()) {
//    show_iconic(0);
//    w->handle(FL_SHOW); // create subwindows if any
//    if (fl_mac_os_version < 101300) { // TODO: threshold may be smaller
//      // draw the window and its subwindows before its icon is computed
//      [cw recursivelySendToSubwindows:@selector(display) applyToSelf:YES];
//    }
//    [cw miniaturize:nil];
//  } else if (w->parent()) { // a subwindow
//    [cw setIgnoresMouseEvents:YES]; // needs OS X 10.2
//    // next 2 statements so a subwindow doesn't leak out of its parent window
//    [cw setOpaque:NO];
//    [cw setBackgroundColor:[NSColor clearColor]]; // transparent background color
//    starting_moved_window = w;
//    [cw setSubwindowFrame];
//    starting_moved_window = NULL;
//    // needed if top window was first displayed miniaturized
//    FLWindow *pxid = fl_xid(w->top_window());
//    [pxid makeFirstResponder:[pxid contentView]];
//  } else { // a top-level window
//    if ([cw canBecomeKeyWindow]) [cw makeKeyAndOrderFront:nil];
//    else [cw orderFront:nil];
//    if (w->fullscreen_active() && fl_mac_os_version >= 100700) {
//      if (fullscreen_screen_top() >= 0)  {
//#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_12
//        if (fl_mac_os_version >= 101200)
//          cw.collectionBehavior |= NSWindowCollectionBehaviorFullScreenNone;
//#endif
//        *no_fullscreen_x() = pWindow->x();
//        *no_fullscreen_y() = pWindow->y();
//      }
//      fullscreen_on();
//    }
//  }
//  if (fl_sys_menu_bar && Fl_MacOS_Sys_Menu_Bar_Driver::window_menu_style() && !w->parent() && w->border() &&
//      !w->modal() && !w->non_modal()) {
//    Fl_MacOS_Sys_Menu_Bar_Driver::driver()->new_window(w);
//  }
  int old_event = Fl::e_number;
  w->handle(Fl::e_number = FL_SHOW);
  Fl::e_number = old_event;
//
  // if (w->modal()) { Fl::modal_ = w; fl_fix_focus(); }
//  if (!w->parent()) [myview did_view_resolution_change]; // to set mapped_to_retina to its current state
//  [pool release];
//
}

