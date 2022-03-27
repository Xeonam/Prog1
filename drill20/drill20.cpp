#include <array>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <algorithm>

template<typename C>
void print(const C& c){ //Nagy C paraméter, kis c változónév

    for(auto const& x : c) {
      std::cout << x << " ";
   }
   std::cout << '\n';


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

    std::array<int, size> ai; //Egy objektum lesz, aminek az osztálya std::array. std::array rengeteg plusz művelettel és funkcióval van kiegészítve
    std::copy(arr, arr+size, ai.begin());

    std::vector<int> vi(size);
    std::copy(arr, arr+size, vi.begin());

    std::list<int> li(size); //
    std::copy(arr, arr+size, li.begin()); 

    //4. feladat

    std::array<int, size> ai2 =  ai;
    std::vector<int> vi2 = vi;
    std::list<int> li2 =li;

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

    std::vector<int>::iterator vit;
    vit = std::find(vi2.begin(), vi2.end(), 3);
    if( vit!= vi2.end()){
        std::cout << "Found at: " << std::distance(vi2.begin(), vit) << std::endl;
        //distance: első és második paraméter közötti elemek számát adja meg
    } else{
        std::cout << "Not found 3" << std::endl;
    }

    //27 keresése listben
    auto res_l = find(li2.begin(), li2.end(), 27);
    if (res_l != li2.end())
        std::cout << "Found at: " << std::distance(li2.begin(), res_l) << std::endl;
    else
       std::cout << "Not found 27"<< std::endl;
        

    return 0;
}
