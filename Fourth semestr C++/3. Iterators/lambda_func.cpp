#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool foo (int element){
    return (element > 5);
}

int main(){
    vector<string> v = {"Ksu", "Ksusha", "David", "Ivan"};

    int thr = 7;

    auto result = find_if(v.begin(), v.end(), [thr] (string element){
        return (element[0] == 'K');
        });

    cout << *result << endl;
    return 0;
}