#include <iostream>
#include <vector> 
#include "base_functions.h"
#include <algorithm>

using namespace std;

int main(){
    vector <int> vec = {17, 1, 16, 2, 3, 4, 9, 8, 5, 100};
    int N = vec.size();

    int number;
    cin >> number;
    vector <int> maximums;

    for(int i = 0; i < N; i++){

        if(vec[i] > number){
            maximums.push_back(vec[i]);
            }
    }

    int minmax = *min_element(maximums.begin(), maximums.end());

    cout << minmax;

    return 0;
}