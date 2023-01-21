#include <iostream>
#include <vector>
using namespace std;

int print_vector(vector <int> &vec){
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << " ";
        }
        cout << "\n";
    return 0;

}


int standart_sort(vector <int> &vec){
    int N = vec.size();
    for(N - 1; N > 0; N--){
        for(int i = 0; i < N; i++){
            if(vec[i] > vec[i + 1]){
                swap(vec[i], vec[i+1]);
            }
        }
    }
    return 0;
}


int ascending_sort(vector <int> &vec){
    int N = vec.size();
    cout << N << "\n";
    int i = 0;
    int j = 0;

    while(i < N-1){
        print_vector(vec);
        
        while(vec[N-1] < vec[j]){
            j++;
            cout << j << "\n";
        }
        

        cout << i << " " << j << "\n";
        if(j == i){
            swap(vec[N-1], vec[j]);
        }
        else{
            swap(vec[j], vec[i]);
        }

        i++;
        j = i;
    }

    return 0;
    
}




int main(){

    // vector <int> vec = {6, 5, 1, 3, 8, 4, 7, 9, 2};
    // vector <int> vec = {2, 3, 6, 1, 9, 10, 4, 5, 7};
    // vector <int> vec = {3, 5, 7, 1, 8, 2, 4};
    vector <int> vec = {17, 1, 16, 2, 3, 4, 9, 8, 5, 100};

    standart_sort(vec);
    cout << "Sorted vector:  ";
    print_vector(vec);  

    return 0;
}