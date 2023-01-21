#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    vector <double> grades(N);

// Enter variables
    cout << "Input count of students:  ";
    cin >> N;

    cout << "Input grades of students:  ";
    for(int i = 0; i < N; i++){
        double a;
        cin >> a;
        grades.push_back(a);
    }

    cout << "\nVector: ";

    for (auto x : grades)
        cout << x << " ";
        cout << "\n ";


// Main programm

    int sum = 0;
 
    for(int j = 0; j < N; j++)
    {
        sum += grades[j];
    }

    for(int k = 0; k < N; k++)
    {
        if (grades[k] > sum/N)
        {
            cout << grades[k] << "\n";
        }
    }

}

