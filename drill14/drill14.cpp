//Ha egy class-ban szerepel teljesen virtuális függvény, az osztály absztakttá válik. Ezáltal az absztakt osztály nem példányosítható.

#include <string>
#include <iostream>

using namespace std;

class B1{
    public:
        virtual void vf() { cout << "B1::vf()" << endl;}
        //a virtual kulcsó azt mondja meg, hogy futási időben felülíródhat a fgv, és később
        //más értkéket kaphat. Számít rá, hogy felül lehet írva és azt veszi majd alapul.
        
        
        void f() {cout << "B1::f()" << endl; }

        // 4. feladat 100% hogy lesz védésben.
        // Mivel a visszatérési értéke 0 nem fog visszaadni semmit.
        // A 0 azt jelenti, hogy majd később felül fogja definiálni.
        // Nincsen implementáció, ezáltal nem értelmezhető fgv jelenleg
        // Absztakt függvény -> az osztályunk is absztrakt lesz.
        // Mivel van nem értelmezhető fgv-je nem példányosítható!!!!!!
        //virtual void pvf() = 0;
};

//a publikus mód azt mondja mi a legmagasabb láthatósági szint
//a public azt jelenti ami a B1-ben public D1ben public
//                              protected volt protected marad
//                              private volt private marad

//Öröklődés, de vf() újra lesz definiálva
class D1 : public B1{
    public:
        void vf() {cout << "D1::vf()" << endl;}

         // 4. Now define a function called f() for D1 and repeat 1–3. Explain the results.
        void f() {cout << "D1::f()" << endl;}
};

class D2 : public D1{
    public:
        void pvf(){cout << "D2::pvf()" << endl;}
};


// 7. Define a class B2 with a pure virtual function pvf() . Define a class D21
// with a string data member and a member function that overrides pvf() ;
// D21::pvf() should output the value of the string . Define a class D22 that
// is just like D21 except that its data member is an int . Define a function f()
// that takes a B2& argument and calls pvf() for its argument. Call f() with a
// D21 and a D22 .
class B2 {
    public:
        virtual void pvf() = 0;	// Absztakt
};

class D21 : public B2{
    public:
        string s;
        void pvf() {cout << s << endl;} // Itt már nem absztakt
};

class D22 : public B2{
    public:
        int n;
        void pvf() {cout << n << endl;} // Itt sem
};

//Függvény, amelynek argumentuma egy B2 referencia és erre meghívja a pvf()-et
void f(B2& b2){
    b2.pvf();
}

int main(){
    //1. osztály - 1. feladat
    /*  Kikommenteljuk a 4. feladat miatt.
    B1 b1;
    b1.vf();
    b1.f();

    */

    //2. osztály

    /*
    D1 d1;
    d1.vf(); //sajátját használta
    d1.f(); //örökölte ezt a fgv-t


    //3. feladat
    B1& bref = d1; //D tipusú objektumot kap
    bref.vf();
    bref.f();
    */
    
    // // 4. Now define a function called f() for D1 and repeat 1–3. Explain the results.
    /* A kódrészlet, amire az outputok jönnek:
    B1 b1;
	b1.vf();
	b1.f();
	
	D1 d1;
	d1.vf();
	d1.f();
	
	B1& b1r = d1;
	b1r.vf();
	b1r.f();
    */
    /* Outputok a az f() definiálása előtt:
    B1::vf()
	B1::f()
	D1::vf()
	B1::f()
	D1::vf()
	B1::f()
	//Outputok az f() definiálása után
    /*
	B1::vf()
	B1::f()
	D1::vf()
	D1::f()    //-> ez a sor változott, mert f() újból lett definiálva D1-ben
	D1::vf()
	B1::f()
    */

   //6. feladat
   
   D2 d2;
   d2.f();
   d2.vf();
   d2.pvf();

   D21 d21;
   d21.s = "d21.s";
   d21.pvf();

   D22 d22;
   d22.n = 22;
   d22.pvf();

   f(d21);
   f(d22);

}
