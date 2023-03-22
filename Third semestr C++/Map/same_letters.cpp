#include <iostream> 
#include <string> 
#include <map> 
#include <algorithm> 
 
using namespace std;


int main(){ 
    string first = "dictionary";
    string second = "fiction";  
    // cout << "enter the first word: \n"; 
    // cin >> first;  
    // cout << "enter the second word: \n"; 
    // cin >> second;  
 
    map <char, int> letters; 
 
    for (int i = 0; i < first.length(); i++) { 
       letters.insert(make_pair(first[i], 1)); 
    } 
 
    for (int i = 0; i < second.length(); i++) { 
        for(auto& it: letters){
            if(it.first == second[i]){
                it.second += 1;
            }
        }
    } 
 
    for (auto& it : letters) { 
        if (it.second > 1) { 
            cout << it.first << ' '; 
        } 
    }
}