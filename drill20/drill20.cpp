#include <array>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <algorithm>


using namespace std;

template<typename C>
void print(const C& c){ //Nagy C paraméter, kis c változónév

    for(auto const& x : c) {
      cout << x << " ";
   }
   cout << '\n';


}

//increment function. Adott számokat megnöveli n értékével.
template<typename C>
void inc(C& c, int n){
    for(auto& i : c){
        i += n;
    }
}

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){

    for(Iter1 p = f1; p != e1; p++){
        *f2++ = *p; //Először a *f2 érték egyenlő lesz a *p értékével, majd növel
        //f2++;

    }
    return f2;
}
int main(){

    constexpr int size = 10;
    int arr[size];
    for (int i = 0; i < size; ++i) arr[i] = i;

    array<int, size> ai; //Egy objektum lesz, aminek az osztálya std::array. std::array rengeteg plusz művelettel és funkcióval van kiegészítve
    copy(arr, arr+size, ai.begin());

    vector<int> vi(size);
    copy(arr, arr+size, vi.begin());

    list<int> li(size); 
    copy(arr, arr+size, li.begin()); 

    //4. feladat

    array<int, size> ai2 =  ai;
    vector<int> vi2 = vi;
    list<int> li2 =li;

    //print feladat
    print(arr);
    print(ai2);
    print(vi2);
    print(li2);

    //5. feladat
    inc(ai2, 2);
    inc(vi2, 3);
    inc(li2, 19);

    print(ai2);
    print(vi2);
    print(li2);

    // 7. feladat
    orai_copy(ai2.begin(), ai2.end(), vi2.begin());
    orai_copy(li2.begin(), li2.end(), ai2.begin());

    print(ai2);
    print(vi2);
    print(li2);

    // 3 keresése vectorban
    //find: Egy iterátort ad vissza a [first,last) tartomány legelső elemére,
    //amely egyenlő a val (3. paraméter) értékkel. Ha nem található ilyen elem,
    //a függvény last-tal (2. paraméter) tér vissza.

    auto res_v = find(vi2.begin(), vi2.end(), 3);
    if(res_v != vi2.end()){
        cout << "Found at: " << distance(vi2.begin(), res_v) << endl;
        //distance: első és második paraméter közötti elemek számát adja meg
    } else{
        cout << "Not found 3" << endl;
    }

    //27 keresése listben
    auto res_l = find(li2.begin(), li2.end(), 27);
    if (res_l != li2.end())
        cout << "Found at: " << distance(li2.begin(), res_l) << endl;
    else
       cout << "Not found 27"<< endl;
        

    return 0;
}
