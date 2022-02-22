/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill12.cpp `fltk-config --ldflags --use-images` -o a2.out
*/

#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){


//Kontrolláljuk a hibakezelést: a legalapabb a hiba -> e kivétel képződik -> elkapjuk
//Kiírjuk milyen exception történik és kiíratjuk majd leállítjuk.
try{

    //1. feladat
    Point t1 {100, 100}; //Az ablak bal felső sarka
    Simple_window win {t1, 600, 400, "My window"}; //Ez definiálja, hogyan néz ki egy ablak
    win.wait_for_button();

    //.2 feladat
    //Axis a graph headerből jön. Egy alakzat.
    Axis xa {Axis::x, Point(20, 300), 280, 10, "x_axis"};
    //x tengely, 20-300ig, 280pixel hosszú, 10 "notch", felirat.
    win.attach(xa); //ha nem váratnánk meg lerajzolná a tengelyt és bezárná
    win.set_label("x axis");
    win.wait_for_button();

    //axis::y -> y oreintációs
    Axis ya {Axis::y, Point(20, 300), 280, 10, "y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);

    win.set_label("y axis");
    win.wait_for_button();

    //sinus függvény    0tól 100ig rajzoljuk ki 
    Function sine {sin, 0, 100, Point{20, 150}, 1000, 50 ,50};
    win.attach(sine);
    win.set_label("sine");
    win.wait_for_button();

    //háromszög
    Polygon poly;
    poly.add(Point{300, 200});
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});
    
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);

    win.set_label("triangle");
    win.wait_for_button();


    Rectangle r {Point{200, 200}, 100, 50};
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 100});
    poly_rect.add(Point{100, 100});
    poly_rect.add(Point{50, 75});
    win.attach(poly_rect);

    win.set_label("Rectangle");
    win.wait_for_button();

    r.set_fill_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("colors");
    win.wait_for_button();

    //szöveg
    Text t {Point{150, 150}, "Hello, graphical world!"};
    win.attach(t);
    win.set_label("Text");
    win.wait_for_button();
    
    t.set_font(Font::times_bold); //graph_lib::font::..
    t.set_font_size(20);
    win.set_label("Text_font");
    win.wait_for_button();


    
    //Image
    Image ii {Point{100, 50}, "badge.jpg"};
    win.attach(ii);
    win.set_label("Image");
    win.wait_for_button();
    
    //Image move
    ii.move(100,200);
    win.set_label("Image_move");
    win.wait_for_button();
    
    //Much more
    Circle c {Point{100, 200}, 50}; //Kör
    Ellipse e {Point{100, 200}, 75,25}; //Ellipszis
    e.set_color(Color::dark_red);
    Mark m {Point{100, 200}, 'x'}; //Marker
    
    win.attach(c);
    win.attach(e);
    win.attach(m);
    win.set_label("Much more");
    win.wait_for_button();
    

    } catch(exception& e){
    cerr << "Exception " << e.what() << '\n';
    return 1;
} catch(...){ //Bármilyen más típusú hiba történik, akkor "error"
    cerr << "Error\n";
    return 2;
}

}
