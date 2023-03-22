#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

bool foo (int element){
    return (element > 5);
}

int main(){
    // vector<string> v = {"Ksu", "Ksusha", "David", "Ivan"};

    // vector<string>::iterator result = find_if(v.begin(), v.end(), [] (string element){
    //     return (element[0] == 'K');
    //     });

    // result += 2;

    // cout << *result << endl;

    set<int> s = {1, 2, 3};
    auto it = s.begin();
    it++;

    cout << *it << endl;

    return 0;
}