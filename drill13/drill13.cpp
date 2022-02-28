#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
    try{
    // 1. Make an 800-by-1000 Simple_window

    Point tl{300, 50};
    Simple_window win{tl, 1000, 800, "My window"};
    win.wait_for_button();

    /* 2. Put an 8-by-8 grid on the leftmost 800-by-800 
    part of that window (so that each square is 100 by 100)*/

    int x_size = 800;
    int y_size = 800;
    Lines grid;

    for (int i=100; i<=x_size; i+=100){
        grid.add(Point(i,0), Point(i, x_size)); //Vertical line
        grid.add(Point(0,i), Point(y_size, i)); //Horizontal line
    }
    win.attach(grid);
    win.label("Grid");
    win.wait_for_button();

    /* 3. Make the eight squares on the diagonal starting
    from the top left corner red (use Rectangle). */

    Vector_ref<Rectangle> rect;
    for (int i = 0; i<x_size; i+=100){
        rect.push_back(new Rectangle{Point{i, i}, 100, 100});
        rect[rect.size()-1].set_fill_color(Color::red);
        //rect[rect.size()-1].set_color(Color::invisible); // Removes the outlines.
        win.attach(rect[rect.size()-1]);

    }
    win.set_label("Red rectangles");
    win.wait_for_button();
    
    /* 4. Find a 200-by-200-pixel image (JPEG or GIF) and place three
    copies of it on the grid (each image covering four squares). If you
    can’t find an image that is exactly 200 by 200, use set_mask() to pick
    a 200-by-200 section of a larger image. Don’t obscure the red squares. */

    Image i1 {Point{0,200},"badge200.jpg"};
    Image i2 {Point{100,500}, "badge200.jpg"};
    Image i3 {Point{300,0}, "badge200.jpg"};

    win.attach(i1);
    win.attach(i2);
    win.attach(i3);
    win.label("Images");
    win.wait_for_button();

    /* 5. Add a 100-by-100 image. Have it move around from square to square
    when you click the “Next” button. Just put wait_for_button() in a loop
    with some code that picks a new square for your image. */

    while(true){
		for(int i = 0; i < 701; i += 100){
			for(int j = 0; j < 701; j += 100){
				Image i100{Point{j, i}, "badge100.jpg"};
				win.attach(i100);
				win.set_label("Moving image");
				win.wait_for_button();
			}
		}
	}
 
    }catch(exception& e){
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }catch(...){
        cerr << "Dont know what...";
        return 2;
    }
}