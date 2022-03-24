#include "Window.h"
#include "Graph.h"
#include "GUI.h"

namespace Graph_lib {

Window::Window(int ww, int hh, const string& title)
:Fl_Window(ww,hh,title.c_str()),w(ww),h(hh) //sorba átadjuk a paramétereket
{
	init(); //inicializálja az ablakot
}

Window::Window(Point xy, int ww, int hh, const string& title)
:Fl_Window(xy.x,xy.y,ww,hh,title.c_str()),w(ww),h(hh)
{ 
	init();
}

void Window::init()
{
   resizable(this); //self-pointert adjuk át. Módosítható ablakot hoz létre
   show(); //Megjleníti
} 

void Window::draw()
{
	Fl_Window::draw();//ősosztyál drawja fogja kirajzolni az ablakot, widgeteket, gombokat
	
	for (unsigned int i=0; i<shapes.size(); ++i) shapes[i]->draw();
	//unsigned  == (előjel nélküli)
	//Minden egyes shapenek meghívjuk a draw tagját.
	//és mindig a megfelelő draw() fog meghívódni.
}

void Window::attach(Widget& w)
{
	begin(); //kell egy FT-ks widget hívás
		w.attach(*this); //van a Widgetnek saját függvénye, saját magát csatolja fel
	end(); //jelezzük, hogy többet már nem akarunk feltenni
}

void Window::detach(Widget& b)
{
	  b.hide(); //Itt csak a hide() tagot kell hívni
}

void Window::attach(Shape& s)
{
		shapes.push_back(&s);
		//hozzáadjuk a shapes vectorhoz.
}
void Window::detach(Shape& s)
{		//feltételezzük, hogy olyan shapet akarunk levenni, amit utoljára adtunk hozzá
		for (unsigned int i = shapes.size(); 0<i; --i)
			if (shapes[i-1]==&s)
				shapes.erase(shapes.begin()+(i-1));
				//&shapes[i-1] ez is működne
}

void Window::put_on_top(Shape& p) {
	for (int i=0; i<shapes.size(); ++i) {
		if (&p==shapes[i]) {
			for (++i; i<shapes.size(); ++i)
				shapes[i-1] = shapes[i];
			shapes[shapes.size()-1] = &p;
			return;
		}
	}
}

int gui_main() { return Fl::run(); } //hívni kell a FL run függvényét

} 
