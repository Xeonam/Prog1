#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main(){
try{

    //1.
    cout << "sizeof: \n";
    cout << "chat\t" << sizeof(char) << "\n";
    cout << "short\t" << sizeof(short) << "\n";
    cout << "int\t" << sizeof(int) << "\n";
    cout << "long\t" << sizeof(long) << "\n";
    cout << "float\t" << sizeof(float) << "\n";
    cout << "double\t" << sizeof(double) << "\n";
    cout << "int*\t" << sizeof(int*) << "\n"; //Pointerek 8 bitosak lesznek 
    cout << "double*\t" << sizeof(double*) << "\n";
    cout << "long*\t" << sizeof(long*) << "\n";
    cout << "float*\t" << sizeof(float*) << "\n";

    //2.
    cout << "Matrix sizes:\n";
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int, 2> d(10,10);
    Matrix<int, 3> e(10,10,10);

    cout << "1D int, 10 elem\t\t" << sizeof(a) << '\n';
    cout << "1D int, 100 elem\t\t" << sizeof(b) << '\n';
    cout << "1D double, 10 elem\t\t" << sizeof(c) << '\n';
    cout << "2D int, 10x10 elem\t\t" << sizeof(d) << '\n';
    cout << "3D int, 10x10x10 elem\t\t" << sizeof(e) << '\n';

    //3.
    cout << "Number of elements:\n";
    cout << "a:\t" << a.size() << '\n';
    cout << "b:\t" << b.size() << '\n';
    cout << "c:\t" << c.size() << '\n';
    cout << "e:\t" << d.size() << '\n';
    cout << "e:\t" << e.size() << '\n';

    //4. 

    int i{};
    while (cin >> i){
        if( i < 0){
            cout << "Number cannot be negative! \n";
        }
        else{
            cout << "Square root of " << i << " is " << sqrt(i) << endl;
        }
    }

    //5.

    cin.clear(); //Hibatárolót fogja törölni
    cin.ignore();//beütött, felkérés után fent maradt karaktereket hagyja figyelmen kívül
    cout << "\nEnter 10 floats: ";
    Matrix<double> m(10);
    double d2;
    for (int i=0; i<m.size(); i++){
        cin >> d2;
        if(!cin) throw runtime_error("Error while reading from cin!");
        m[i] = d2;
    }
    cout << "Matrix:\n" << m << '\n';


    //6.
    cout << "Mátrix szorzótábla: ";
    int num1 = 0;
    int num2 = 0;
    cin >> num1 >> num2;

    Matrix<int, 2> m1(num1, num2);
    //cout << m1;

    for (int i = 0; i < num1; ++i){
        for(int j = 0; j < num2; ++j){
            m1(i, j) = (i+1)*(j+1);
            cout << setw(4) <<  m1(i,j);
        }
        cout << '\n';
    }

    //7.

    Matrix<complex<double>> m4(10);
    cout << "\nEnter 10 complex numbers (Re, Im): ";
    complex<double> comp;
    for (int i = 0; i < 10; ++i){
        cin >> comp;
        if(!cin) throw runtime_error("Problem reading complex numbers!");
        m4[i] = comp;
    };
    
    complex<double> sum;
    for(int i = 0; i< m4.size(); ++i){
        sum += m4[i];
    }

    cout << "Sum: " << sum << '\n';


    //8.
    cout << "\nMatrix(2,3)\n";

    Matrix<int, 2> mi(2,3);
    int n {};
    for (int i = 0; i < mi.dim1(); ++i){
        for(int j = 0; j < mi.dim2(); ++j){
            cout << "Enter an integer: ";
            cin >> n;
            mi[i][j] = n;
        }
    }

    cout << "Mátrix: \n";
    for (int i = 0; i < mi.dim1(); ++i){
        for(int j = 0; j < mi.dim2(); ++j){
            cout << mi(i,j) << " ";
        }
        cout << "\n";
    }

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
