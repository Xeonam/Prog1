#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
//olyan mint egy sima osztály amibe van egy val tag, generikus osztály.
struct S{
    S (T vv = 0) : val{vv}{} //konstruktor 
    T& get(); //Így a struktúra tudja, hogy lesz egy get függvénye
    const T& get() const; //Ha kell konstans get, akkor ez fut le, "constanssal" hívom meg

    //Setter
    void set(T new_t) { val = new_t;}

    void operator=(const T& s); //A "fejet" létre kell hozni, amit később kifejtünk
    //7. feladat
    private:
        T val;
};

//5-6. feladat

template<typename T> //S osztály T típusú paraméter gettere
T& S<T>::get(){
	return val;
}

template<typename T>
const T& S<T>::get() const{ //get()... //simán ebben a kontextusban a val még nem létezik ezért kell a S<T>
    return val; 
}

//12. feladat
template<typename T>
void S<T>::operator=(const T& s){
    val = s;
}

//input beolvasás feladat
template<typename T>
void read_val(T& v) {
	cin >> v; //Fordítási időben derül ki a típus
}

//Utolsó feladat
template<typename T>
std::ostream& operator<<(ostream& os, vector<T>& v) {
	os << "{ "; //könyv kérése
	for (int i = 0; i < v.size(); ++i) {
		os << v[i] << (i < v.size()-1 ? ", ": " ");
        //kiírom a vector aktuális elemét, attól függően, hogy hanyadik elem.
	}
	os << "}\n";
	return os; //könyv kérése
} // cout << vec1 << vec2 << vec3 formátumban

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
	// {1, 1, 2, 3}
    //Beolvasunk egy karaktert, nyitó zárójellel kell kezdeni
    //For ciklussal megy a beolvasás
    //T típussal változót is hozhatok létre, mondjuk ciklusváltozóként
    //input streamről mindig bekérek egy ilyen típusú elemet
    //berakom őket egy vectorba, amíg vesszővel olvasom be tudom, hogy addig tart a vector
	//cout << "meghívjuk" << endl; //<- Segítségnek, hogy hol hívódik meg
	char ch = 0; //
	is >> ch;
	if (ch != '{') {
		is.unget(); //visszaadjuk az unget()-tel
		return is; // visszaadjuk az input streamet (Ennek az értelme, hogy egymás után lehessen overloadolni a dolgokat.
	}
	//Ha kapcsos zárójel jön. Csinálunk egy T típusú változót. (T val).
	//Input paraméternek ott van a vector<T> típusú vector.
	//(Ha vectorba intek vannak akkor int lesz...
	for (T val; is >> val;) {
		v.push_back(val);
		is >> ch; //megnézzük mi a következő karakter
		if (ch != ',') break; //Ha a következő karakter nem ',' akkor kilépünk
	}

	return is;
}
int main(){
    
    //3-4. feladat
    S<int> s;
    S<int> si {37};
    S<char> sc {'c'};
    S<double> sd{3.2};
    S<std::string> ss {"Hello"};
    S<std::vector<int>> svi {std::vector<int>{1,2,3,4,5,8}}; //MI A TÍPUSA? Az "SVI" olyan S objektum, ami vectort tartalmaz, ami inteket tartalmaz

    //7. feladat miatt ki kell javítani a gettert.
    cout << "S<int> : " << s.get() << endl;
    cout << "S<int> : " << si.get() << endl;
    cout << "S<char> : " << sc.get() << endl;
    cout << "S<double> : " << sd.get() << endl;
    cout << "S<string> : " << ss.get() << endl;
    //cout << "S<vector<int>>" << svi.val << endl; -> nincs rá opertarounk ezért komment
    cout << "S<vector<int>> : ";
    for(auto& a: svi.get()){
        cout << a << ' ';
    }
    cout << endl;
    sc.set('s');
    cout << "S<char> : " << sc.get() <<  endl;

    sd = 42.1;
    cout << "S<double> : " << sd.get() << endl;

    //12. feladat
    int ii;
    read_val(ii);
    S<int> si2 {ii};


    double dd;
    read_val(dd);
    S<double> sd2 {dd};

    string str;
    read_val(str);
    S<string> ss2 {str};

    cout << "S<int> : " << si2.get() << endl;
    cout << "S<double> : " << sd2.get() << endl;
    cout << "S<string> : " << ss2.get() << endl;


   cout << "S<vector<int>>: (format: {val1, val2, val3})" << endl;
   vector<int> vec;
   read_val(vec);
   S<vector<int>> svi2 {vec};
   cout << "S<vector<int>> : " << svi2.get();

   return 0;
}
//kérdés: hol futnak a input output operatotok.
