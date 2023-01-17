#include <iostream>
#include <vector>

int main(){
    int N;
    std::vector <double> grades(N);

// Enter variables
    std::cout << "Input count of students:  ";
    std::cin >> N;

    std::cout << "Input grades of students:  ";
    for(int i = 0; i < N; i++){
        double a;
        std::cin >> a;
        grades.push_back(a);
    }

    std::cout << "\nVector: ";

    for (auto x : grades)
        std::cout << x << " ";
        std::cout << "\n ";


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
            std::cout << grades[k] << "\n";
        }
    }

}

