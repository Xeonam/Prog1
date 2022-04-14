#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <numeric>

using namespace std;

template<typename K, typename V>
void print(const std::map<K, V>& m){
    //for(auto& i :m){
    for(std::pair<K,V> i:m){
        //adattag elérése lesz a first,second
        std::cout << i.first << '\t' << i.second << endl; 
    }
}

//6. feladat
void read_map(std::map<string, int>& m){
    string s;
    int i = 0;
    while (m.size() < 10){
        cin >> s >> i,
        m[s] = i; //S kulcs helyén legyen i (Ha van ilyen akkor felül írja)
        //m.insert(std::make_pair(s, i)); //Itt nem írja felül, az elsőt fogja beszúrni
    }
}

// 8. feladat
int sum(const std::map<string, int>& map){
    int osszeg = 0;
    for (pair<string, int> i : map){
        osszeg += i.second;
    }
    return osszeg;
}

int main()
try{
    //1. feladat
    map<string, int > msi;
    //2. feladat
    msi["a"] = 1;
    msi["b"] = 3;
    msi["ab"] = 7;
    msi["efgh"] = 98;
    msi["xy"] = 76;
    msi["qw"] = 61;
    msi["efh"] = 60;
    msi["xc"] = 23;
    msi["qwertz"] = 11;
    msi["ax"] = 1;

    cout << "Összeg " << sum(msi) << endl;
    //3. feladat
    //"auto": milyen típus lesz az auto (Minden esetben típus lesz)
    //(Dokumentáció olvasás)
    //for(std::pair<k,v)-re alakul át. (K ==string, v == int)
    
    std::cout << "MSI map : " << endl;
    print(msi);

    //4. feladat
    msi.erase("a");
    std::cout << endl << "Egyy elem törlése után: " << endl;
    print(msi);

    msi.erase(msi.begin(), msi.end());
    std::cout << endl << "Teljes törlés után: " << endl;
    print(msi);

    //6.
    std::cout << "Adjon meg 10 kulcs-érték párt: " << std::endl;
    read_map(msi);
    std::cout << endl << "msi beolvasás után: " << endl;
    //7.
    print(msi);

    //8.
    cout << "Map értékeinek összege: " << sum(msi) << endl;

    //9. feladat
    std::map<int, string> mis;
    //10. feladat
    for (std::pair<string, int> i : msi){
		mis[i.second] = i.first;
	}
    //11. feladat
    cout << endl << "mis map" << endl;
    print(mis);


} catch(std::exception& e){
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;

} catch(...){
    std::cerr << "Unknown Exception: " << '\n';
    return 2;
}