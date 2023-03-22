#include <iostream>
#include <vector>
#include <map>

using namespace std;



template<typename T>
T pow(T x) {
    return x * x;
}

string to_string()

template <typename T1, typename T2>
ostream& operator<< (ostream& os, pair<T1, T2> p) {
    cout << p.first <<" ; "<< p.second << " ";
    cout << endl;
}

template <typename T1, typename T2>
ostream& operator<< (ostream& os, map<T1, T2> m) {
    
    cout << to_string(m) << endl;//...
}

template <typename T>
ostream& operator<< (ostream& os, vector<T> v) {
    
    cout << "{"<< to_string(v) << "}" << endl;
}

int main () {
    vector<int> v;
    int t = 2;
    cout << pow(t) << endl;
    return 0;
}