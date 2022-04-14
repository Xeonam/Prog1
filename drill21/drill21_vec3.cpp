#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>

template<typename C>
void print(const C& c, char sep = '\n'){
    std:: cout << "Container elements:\n";
    
    for(const auto elem : c){
        std::cout << elem << sep;
    }
    std::cout << std::endl;
}   

int main()
try{
    const std::string iname {"input_float.txt"};
    std::ifstream ifs {iname};
    if(!ifs) throw std::runtime_error("Could not read file: " + iname);

    std::vector<double> vd;
    for(double d; ifs >> d;){
        vd.push_back(d);
    }

    print(vd);

    //3.
    std::vector<int> vi(vd.size()); //Meg kell adni, hogy cd.size(), mert másképp nem foglalna elég helyet a copyhoz.
    //std::copy -> reference oldal
    
    std::copy(vd.begin(), vd.end(), vi.begin());
    print(vi);

    for(int i=0; i<vd.size(); i++){
        std::cout << vd[i] << '\t' << vi[i] << std::endl;

    }

    std::cout.precision(10); //Pontosság beállítása formázáshoz.
    
    //5.
    std::cout << std::endl;
    double sum = 0;
    sum = std::accumulate(vd.begin(), vd.end(), sum);
    std::cout << "Sum of vd: " << sum << std::endl;

    //6.
    int sum2 = 0;
    sum2 = std::accumulate(vi.begin(), vi.end(), sum2);
    std::cout << "Difference between the sum of the elements: "<<
            sum - sum2 << std::endl;

    //7.
    std::reverse(vd.begin(), vd.end());
    print(vd);

    //8.
    double vd_mean = sum /vd.size();
    std::cout << "Mean value of vd: "<< vd_mean << std::endl;

    //9.
    std::vector<double> vd2;
    for (double& d: vd){
        if (d < vd_mean){
            vd2.push_back(d);
        }
    }

    print(vd2);

    //10.
    std::sort(vd.begin(), vd.end());
    print(vd);

} catch(std::exception& e){
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;

} catch(...){
    std::cerr << "Unknown Exception: " << '\n';
    return 2;
}
