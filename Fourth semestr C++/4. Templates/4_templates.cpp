#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
string to_string(T data, string sep){
    stringstream ss;
    for(auto it = data.begin(); it != data.end(); it++){
        if(it != data.begin()){
            ss << sep;
        }
        ss << *it;
    }
    return ss.str();
    
}

//vector overloading
template <typename T>
ostream& operator<< (ostream& os, vector <T> v) {
    return os << "{" << to_string(v, "; ") << "}" << endl;
}

//pair overloading
template <typename T1, typename T2>
ostream& operator<< (ostream& os, pair<T1, T2> p) {
    return os << p.first << "; " << p.second << " " << endl;
}

// map overloading
template <typename T1, typename T2>
ostream& operator<< (ostream& os, map<T1, T2> const & m) {
    for(const auto & [key, value]: m){
        cout << "[" << key << " - " << value << "]; " << endl;
    }
    return os;
}

int main () {
    //vectors
    vector<int> v1 = {1, 2, 3, 4, 8124, 3, 45};
    vector<string> v2 = {"map", "lol", "vec", "kit", "pes"};
    vector<float> v3 = {1.4, 2.003, 3.55, 4, 8124.1, 3.1, 45};

    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;

    //pairs
    pair p1(1, 4);
    pair p2("lol", 4);
    pair p3(5.34, true);

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;

    //maps
    map<int, int> m1 {{1, 10}, 
                        {2, 20}, 
                        {3, 30}, 
                        {4, 40}, };

    map<string, int> m2 {{"mother", 49},
                        {"father", 48}, 
                        {"bro", 21}, 
                        {"sis", 10}, 
                        {"me", 20}};

    map<float, bool> m3 {{1.00, true},
                        {10.53, false},
                        {4.60, true},};

    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;


    return 0;
}