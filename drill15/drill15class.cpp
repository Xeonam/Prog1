#include "std_lib_facilities.h"

void checkName(string name){
    string wrongs = ";:\"'[]*&^%$#@!";

    for(int i=0; i<name.size(); i++){
        for (int j = 0; j < wrongs.size(); j++){
            if (name[i] == wrongs[j]){
                error("Not allowed character in name");
            }
        } 
    }


}
void checkAge(int age){
    if (age < 0 && age >=150)
        error("Age is not in range [0,150]");
}

class Person{
    private:
        string first_name;
        string last_name;
        int age;
    public:
        Person() {};
        Person(string fn, string ln, int a){
            setFirstName(fn);
            setLastName(ln);
            setAge(a);
        };
        
        //Setter
        void setFirstName(string fn){
            checkName(fn);
            first_name = fn;
        }

        void setLastName(string ln){
            checkName(ln);
            last_name = ln;
        }

        void setAge(int a){
            if (a > 0 && a <=150)
                age = a;
            else error("Age is not in range [0,150]");
        }

        //Getter
        string getFirstName() const{
            return first_name;
        }

        string getLastName() const{
            return last_name;
        }

        int getAge() const{
            return age;
        }

};

istream& operator>>(istream& input, Person& p){
    string first_name;
    string last_name;
    int age;

    input >> first_name >> last_name >> age;
    p.setFirstName(first_name);
    p.setLastName(last_name);
    p.setAge(age);
    return input; 
}

ostream &operator<<(ostream  &output, Person& p) { 
    output << p.getFirstName() << " " << p.getLastName() << " " << p.getAge() << endl;         
    return output;            
}

int main(){
    try{
        Person p{"Goofy","Goof", 63};

        cout << p << endl;

        vector<Person> persons;
    
        string first_name;
        string last_name;
        int age;

        while(cin >> first_name){
            if (first_name == "exit")
                break;
            else
                cin >> last_name >> age;
                Person np {first_name, last_name, age};
                persons.push_back(np);
        }

        for (int i = 0; i < persons.size(); i++){
            cout << persons[i];
        }

    } catch(exception& e){
        cerr << e.what() << endl;
        return 1;
    } catch(...){
        cerr << "Dont know what..." << endl;
        return 2;
    }
}