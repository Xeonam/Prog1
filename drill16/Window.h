#ifndef WINDOW_GUARD
#define WINDOW_GUARD 1

#include "fltk.h"

#include "std_lib_facilities.h"

#include "Point.h"

namespace Graph_lib {

class Shape; //forward deklaráció
class Widget;

class Window : public Fl_Window { 
public: 
	Window(int w, int h, const string& title ); //konstruktor 1.: rendszer határozza meg hova kerüljön az ablak.
	Window(Point xy, int w, int h, const string& title ); //konstruktor 2.
	virtual ~Window() { } //viruális destruktor

	int x_max() const { return w; } //elkérjük ezekkel az ablak méretét
	int y_max() const { return h; }

	void resize(int ww, int hh) { w=ww, h=hh; size(ww,hh); } //ablak átméretezése.

	void set_label(const string& s) { label(s.c_str()); } //ablak átnevezése

	void attach(Shape& s); //Shape felrakása
	void attach(Widget& w);//widget felrakása

	void detach(Shape& s);//hogy letudjuk venni
	void detach(Widget& w);

	void put_on_top(Shape& p); //A shapet a tetejére teszi.

protected:
	void draw();	//rajzolni fog.
     
private:
	  vector<Shape*> shapes; //Ablakbe egy Shape vector. Ebbe fogjuk tárolni, hogy milyen shapeket akarunk kirajzolni.
	  int w,h;	//méret

	  void init(); //Inicializáló fgv, amivel inicializáljuk az ablakot
}; 

int gui_main();

inline int x_max() { return Fl::w(); } //Lekérjük a screen méretét, az inline miatt nem az
inline int y_max() { return Fl::h(); } //xmax()-hoz fog ugrani, hanem egyőbl a fl::w()-hez

}
#endif
