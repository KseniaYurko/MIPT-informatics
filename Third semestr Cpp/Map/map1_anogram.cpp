#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char, int> word_dictionary(const string &word){
    map<char, int> dictionary;
    for(const auto &letter : word){
        ++dictionary[letter];
    }
    return dictionary;
}

int main(){
    vector <string> answer;
    int N;
    cout << "Enter num of pairs of words:  ";
    cin >> N;

    cout << "Enter your pairs\n";
    string first_word, second_word;
    for(int i = 0; i < N; i++){
        cin >> first_word >> second_word;

        if (word_dictionary(first_word) == word_dictionary(second_word)){
            answer.push_back("YES");
        }
        else{
            answer.push_back("NO");
        }
    }

    for(auto x : answer){
        cout << x << "\n";
    }

    return 0;
}