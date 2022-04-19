#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "Window.h"

using namespace Graph_lib;

/*g++ drill5.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill5 `fltk-config --ldflags --use-images`
*/

using namespace Graph_lib;

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);
private:
	Open_polyline lines;
	bool wait_for_button();

	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Button menu_button;
	Menu lines_menu;
	Button lines_button;
	
	void change(Color c) { lines.set_color(c); }
	void hide_menu() { color_menu.hide(); menu_button.show(); }

	void changelns(Line_style ls) { lines.set_style(ls); }
	void hide_lines() {lines_menu.hide(); lines_button.show();}

	void red_pressed() { change(Color::red); hide_menu(); }
	void blue_pressed() { change(Color::blue); hide_menu(); }
	void black_pressed() { change(Color::black); hide_menu(); }
	void menu_pressed() { menu_button.hide(); color_menu.show(); }

	void solid_pressed() { changelns(Line_style::solid); hide_lines(); }
	void dash_pressed() { changelns(Line_style::dash); hide_lines(); }
	void dot_pressed() { changelns(Line_style::dot); hide_lines(); }
	void lines_menu_pressed() { lines_button.hide(); lines_menu.show(); }

	void next();
	void quit();

	static void cb_red(Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();}
	static void cb_blue(Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();}
	static void cb_black(Address, Address pw) {reference_to<Lines_window>(pw).black_pressed();}
	static void cb_menu(Address, Address pw) {reference_to<Lines_window>(pw).menu_pressed();}

	static void cb_solid(Address, Address pw){reference_to<Lines_window>(pw).solid_pressed();}
	static void cb_dash(Address, Address pw){reference_to<Lines_window>(pw).dash_pressed();}
	static void cb_dot(Address, Address pw){reference_to<Lines_window>(pw).dot_pressed();}
	static void cb_lines_menu(Address, Address pw){reference_to<Lines_window>(pw).lines_menu_pressed();}

	static void cb_next(Address, Address pw) {reference_to<Lines_window>(pw).next();}
	static void cb_quit(Address, Address pw) {reference_to<Lines_window>(pw).quit();}
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title},
	next_button{Point{x_max()-150,0}, 70, 20, "Next point", cb_next},
	quit_button{Point{x_max()-70,0}, 70, 20, "Quit", cb_quit},
	next_x{Point{x_max()-310,0}, 50, 20, "next x:"},
	next_y{Point{x_max()-210,0}, 50, 20, "next y:"},
	xy_out{Point{100,0}, 100, 20, "current (x,y):"},
	color_menu{Point{x_max()-70,30},70,20,Menu::vertical,"color"},
	menu_button{Point{x_max()-80,30}, 80, 20, "color menu", cb_menu},
	lines_menu{Point{x_max()-70,100},70,20,Menu::vertical,"lines"},
	lines_button{Point{x_max()-80,100}, 80, 20, "lines menu", cb_lines_menu}
	{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no point");
	color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
	color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
	color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
	
	lines_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
	lines_menu.attach(new Button{Point{0,0},0,0,"dash",cb_dash});
	lines_menu.attach(new Button{Point{0,0},0,0,"dot",cb_dot});
	attach(color_menu);
	attach(lines_menu);
	color_menu.hide();
	lines_menu.hide();
	attach(menu_button);
	attach(lines_button);
	attach(lines);
}

void Lines_window::quit()
{
	hide();
}

void Lines_window::next()
{
int x = next_x.get_int();
int y = next_y.get_int();

lines.add(Point{x,y});

ostringstream ss;
ss << '(' << x << ',' << y << ')';
xy_out.put(ss.str());
redraw();
}
int main(){
try{
	Lines_window win {Point{100,100},1920,1080,"lines"};
	return gui_main();  //gui_main(), ami maga csak az FLTK run() hívása 
}
catch(exception& e){
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...){
	cerr << "Some exception\n";
	return 2;
}	

}
