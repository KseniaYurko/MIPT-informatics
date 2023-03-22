#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>
#include <stdexcept>
#include <map>

using namespace std;

int main(){
    ifstream input("kaban.txt");
    string s;
    while (getline (input, s)){
        cout << s << endl;
    }
    getline (input, s);
    return 0;
}