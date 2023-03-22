#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

void search_minNum(vector <int> list_num, int num){
    vector<int>::iterator iter = find_if(list_num.begin(), list_num.end(), 
        [] (int element){
            return (element > num);
        });
};

void display_numbers(){

}

int main(){
    vector <int> numbers = {1, 5, 4, 6, 2, 51, 7, 100, 43, 32, 10, 9};

}