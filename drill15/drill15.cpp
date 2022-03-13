// g++ drill15.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15 `fltk-config --ldflags --use-images`

/*
Each Function specifies how its first argument (a function of one double argument returning a double) is to be drawn in a
window. The second and third arguments give the range of x (the argument to the function to be graphed). The fourth argument
(here, orig) tells the Function where the origin (0,0) is to be located within the window.
*/

#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

double one(double x) { return 1;}
double slope(double x) { return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) { return cos(x) + slope(x);}

int main(){
    try{
    // 1. Make an empty 600-by-600 Window labeled “Function graphs.”

    Point tl{100, 100};
    Simple_window win{tl, 600, 600, "Function graphs"};

    // 3. Add an x axis and a y axis each of length 400, labeled “1 = = 20 pixels”
    // and with a notch every 20 pixels. The axes should cross at (300,300).

    Axis x {Axis::x, Point{100, 300}, 400, 20, "x axis"};
    Axis y {Axis::y, Point{300, 500}, 400, 20, "y axis"};

    // 5. Make both axes red.

    x.set_color(Color::red);
    y.set_color(Color::red);

    // In the following, use a separate Shape for each function to be graphed:

    // 1. Graph the function double one(double x) { return 1; } in the range [–10,11]
    // with (0,0) at (300,300) using 400 points and no scaling (in the window)

    double range_min = -10, range_max = 11;
    Point origo{300, 300};
    int points = 400;

    // Function s {one, range_min, range_max, origo, points};

    // 2. Change it to use x scale 20 and y scale 20.
    double x_scale = 20, y_scale = 20;
    // 3. From now on use that range, scale, etc. for all graphs.

    Function f {one, range_min, range_max, origo, points, x_scale, y_scale};

    // 4. Add double slope(double x) { return x/2; } to the window
    // 5. Label the slope with a Text "x/2" at a point just above its bottom left end point.
    
    Function f2 {slope, range_min, range_max, origo, points, x_scale, y_scale};
    Text t {Point{100, 400}, "x/2"};

    // 6. Add double square(double x) { return x*x; } to the window.

    Function f3 {square, range_min, range_max, origo, points, x_scale, y_scale};
    
    // 7. Add a cosine to the window (don’t write a new function).

    Function f4 {cos, range_min, range_max, origo, points, x_scale, y_scale};
    
    // 8. Make the cosine blue.
    f4.set_color(Color::blue);

    // 9. Write a function sloping_cos() that adds a cosine
    // to slope() (as defined above) and add it to the window

    Function f5 {sloping_cos, range_min, range_max, origo, points, x_scale, y_scale};

    // Display

    win.attach(x);
    win.attach(y);
    win.attach(f);
    win.attach(f2);
    win.attach(t);
    win.attach(f3);
    win.attach(f4);
    win.attach(f5);

    win.wait_for_button();
 
    }catch(exception& e){
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }catch(...){
        cerr << "Dont know what...";
        return 2;
    }
}