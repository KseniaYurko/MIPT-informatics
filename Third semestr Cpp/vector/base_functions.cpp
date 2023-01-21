#include <iostream>
#include <vector>
#include "base_functions.h"

int print_vector(vector <int> &vec){
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << " ";
        }
        cout << "\n";
    return 0;

}