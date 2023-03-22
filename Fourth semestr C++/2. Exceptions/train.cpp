#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <stdexcept>
#include <map>

using namespace std;

int main(){
    map<string, int> m;

    try{
        if (m.at("vitec") == 47){
            cout << "vibtek is here" << endl;
        }
    }
    catch(exception& ex){
        cout << "vitek plohoi" << ex.what() << endl;
    }
    throw exception();
    cout << "dasfgedw" << endl;
    return 0;

}