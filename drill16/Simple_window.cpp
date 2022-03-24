#include "Simple_window.h"

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
    button_pushed(false)
{
    attach(next_button);
}

bool Simple_window::wait_for_button()
{
    show();
    button_pushed = false;
#if 1
    while (!button_pushed) Fl::wait(); //megállítja a futást vár a gombnyomásra
    Fl::redraw();	//ha megnyomjuk a gombot, redrawol
#else
    Fl::run();	//közvetlenül hívjuk a FL runját
#endif
    return button_pushed; //visszaadjuk a button_pushed értékét
}

//egy memóriacímet adunk át
void Simple_window::cb_next(Address, Address pw)
{
    reference_to<Simple_window>(pw).next();
    //ezt a memóriacímet castoljuk át egy simple_window
    //referencia típussá, és erre tudjuk hívni a next()-et
}

void Simple_window::next()
{
    button_pushed = true;
    hide(); //ha már nincs mit redrawolni, akkor elrejtük.
}
