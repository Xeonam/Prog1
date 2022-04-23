#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

// 1. feladat 
struct Item{
    string name;
    int iid;
    double val;

    Item(): name(), iid(0), val(0){}
    Item(string n, int i, double v): name(n), iid(i), val(v) {}
};

ifstream& operator>>(ifstream& in, Item& m){
    in >> m.name >> m.iid >> m.val;
    return in;
}

ostream& operator<<(ostream& os, const Item& m){
    os << m.name << ' ' << m.iid << ' ' << m.val;
    return os;
}

void print(vector<Item> v){
    for(const auto& i: v){
        cout << i << endl;
    }
    cout << endl;
}

struct item_comp_by_name{
    bool operator()(const Item& a, const Item& b){
        return a.name < b.name;
    }
};

struct item_comp_by_iid{
    bool operator()(const Item& a, const Item& b){
        return a.iid < b.iid;
    }

};

struct item_comp_by_value{
    bool operator()(const Item& a, const Item& b){
        return a.val > b.val;
    }

};

//erase by name
std::vector<Item>  string_erase(std::vector<Item> &v, std::string s){
    for(std::vector<Item>::iterator it = v.begin(); it != v.end(); it++){
        if ( (*it).name == s){
            v.erase(it);
            return v; //Ide kell a return, mert ha az utolsó elemet törölnénk, akkor segmentation errort dobna ki.
        }
        
    }

    return v;

}

//erase by iid
std::vector<Item> iid_erase(std::vector<Item> &v, int i){
    for(std::vector<Item>::iterator it = v.begin(); it != v.end(); it++){
        if ( (*it).iid == i){
            v.erase(it);
            return v;
        }
        
    }

    return v;

}

//Functor erase:
class Find_by_name{
    string name;
public:
    Find_by_name(const string& s) :name(s) { }
    bool operator()(const Item& it) const
    {
        return it.name == name;
    }
};

//Listához kapcsolódó..
void print_list(list<Item> l){
    for(const auto& i: l){
        cout << i << endl;
    }
    cout << endl;
}

//erase by name
std::list<Item>  list_string_erase(std::list<Item>  &v, std::string s){
    for(std::list<Item>::iterator it = v.begin(); it != v.end(); it++){
        if ( (*it).name == s){
            v.erase(it);
            return v;
        }
        
    }

    return v;

}

//erase by iid
std::list<Item> list_iid_erase(std::list<Item>  &v, int i){
    for(std::list<Item>::iterator it = v.begin(); it != v.end(); it++){
        if ( (*it).iid == i){
            v.erase(it);
            return v;
        }
        
    }

    return v;

}



int main(){
try{

    //VECTOR
    const string iname {"input.txt"};
	ifstream ifs {iname};
	if(!ifs) throw runtime_error("Could not read file: " + iname);
	
    //1.
    std::vector<Item> vi;
    Item m;
    while(ifs >> m){
        vi.push_back(m);
    }
    ifs.close();

    print(vi);

    //2. Sort vi by name
    cout << "Sort by name: " << endl;
    sort(vi.begin(), vi.end(), item_comp_by_name());
    print(vi);

    //3. Sort vi by iid
    cout << "Sort by iid: " << endl;
    sort(vi.begin(), vi.end(), item_comp_by_iid());
    print(vi);

    //4. Sort vi by value
    cout << "Sort by iid: " << endl;
    sort(vi.begin(), vi.end(), item_comp_by_value());
    print(vi);

    //5. Insert items
    vi.push_back({"horse shoe", 99, 12.34});
	vi.push_back({"Canon S400", 9988, 499.95});
	
	print(vi);

    //6.erase by name
    cout << "2 elem törlése után: "<< endl;
    string_erase(vi, "horse shoe");
    string_erase(vi, "Canon S400");
    print(vi);

    //7. erase by iid

    cout << "2 elem törlése után: "<< endl;
    iid_erase(vi, 10);
    iid_erase(vi, 100);
    print(vi);

    //LISTA
    cout << "Feladatok listával:" << endl;
    ifs.open(iname);
	if(!ifs) throw runtime_error("Could not read file: " + iname);
	
    //1.
    std::list<Item> li;
    while(ifs >> m){
        li.push_back(m);
    }
    ifs.close();

    print_list(li);

    
    //2. Sort vi by name
    cout << "Sort by name: " << endl;
    li.sort(item_comp_by_name());
    print_list(li);

    
    //3. Sort vi by iid
    cout << "Sort by iid: " << endl;
    li.sort(item_comp_by_iid());
    print_list(li);

    //4. Sort vi by value
    cout << "Sort by iid: " << endl;
    li.sort(item_comp_by_value());
    print_list(li);

    //5. Insert items
    li.insert(li.end(), Item("horse shoe", 99, 12.34));
    li.insert(li.end(), Item("Cannon S400", 9988, 499.95));
    print_list(li);

    //6.erase by name
    cout << "2 elem törlése után: "<< endl;
    list_string_erase(li, "horse shoe");
    list_string_erase(li, "Cannon S400");
    print_list(li);

    //7. erase by iid

    cout << "2 elem törlése után: "<< endl;
    list_iid_erase(li, 44);
    list_iid_erase(li, 101);
    print_list(li);

    return 0;
}
catch(exception& e){
	cerr << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "Unknown exception!" << '\n';
	return 2;
}
}
