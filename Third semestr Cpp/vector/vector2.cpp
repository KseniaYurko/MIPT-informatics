#include <iostream>
#include <vector>

using namespace std;

int flip_vector(vector <int> &vec){

    for(int i = 0; i < vec.size()/2; ++i){

        int a = vec[i];
        
        vec[i] = vec[vec.size() - i - 1];
        vec[vec.size() - i - 1] = a;
        a = 0;
    }
        //Checking intermediate vectors
        // cout << "intermediate result:  ";
        // for(int i = 0; i < vec.size(); i++){
        //     cout << vec[i] << " ";
        //     }
        // }
        // cout << "\n";

    return 0;
}

int main(){

    vector <int> vec = {1, 2, 3, 4, 5};
    flip_vector(vec);

    cout << "\n" << "flipped vector is:  ";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }

    return 0;
}
