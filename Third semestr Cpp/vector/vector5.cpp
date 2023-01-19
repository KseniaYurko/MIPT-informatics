#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>

using namespace std;

int print_vector(vector <string> &vec){
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << " ";
        }
        cout << "\n";
    return 0;

}

int main(){
    vector <string> vec;
    int N = vec.size();
    
    for(int i = 0; i < 3; i++){
        string letter;
        cin >> letter;
        vec.push_back(letter);  
    }

    print_vector(vec);
    sort(vec.begin(), vec.end());
    
    int o = 0;
    for(int i = 0; i < vec[0].size(); i++){
        if(vec[0][i] == 'o'){
            o++;
        }
    }

    print_vector(vec);
    cout << o;
}