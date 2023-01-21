Vector



## vector1_students.cpp
**Task:** Есть `N` студентов, у каждого есть оценка `(double)`. На вход подается
натуральное число `N` и потом оценка каждого студента. Вывести номера
студентов с оценкой выше среднего.


    ```cpp
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
    ```




## vector2_flip.cpp 
**Task:** Перевернуть `vector` задом наперед. сделать это в функции, передать
по ссылке. полученный вектор вывести в `main`.


    ```cpp
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
    ```




## vector3_sort.cpp 
**Task:** отсортировать `vector` по убыванию. сделать это в функции, передать по ссылке. полученный вектор вывести в `main`. с помощью `sort` **нельзя**, ручками.


    ```cpp
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

            ascending_sort(vec);
            cout << "Sorted vector:  ";
            print_vector(vec);  

            return 0;
        }
    ```



## vector4_minMax.cpp  
**Task:**  Найти номер наименьшего элемента вектора, большего заданного
числа. На вход подается это число, длина вектора и сам вектор.


    ```cpp
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
    ```

## vector5_dictionary.cpp 
**Task:** Записать три слова, введҷнные с клавиатуры в вектор, вывести их
на экран, отсортированные по алфавиту, определить сколько в первом
слове букв `о`. Тут **можно** пользоваться `sort`.


    ```cpp
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
    ```
