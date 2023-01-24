#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Student {
    private:
        string name;
        int age;
        double average_score;

    public:
        void set_name(string &in_name){
            name = in_name;
        }
        void get_name(){
            cout << name << endl;
        }

        void set_age(int in_age){
            age = in_age;
        }
        int get_age(){
            cout << age << endl;
            return age;
        }

        void set_average_score(double in_average_score){
            if(in_average_score <= 10 && in_average_score >= 0)
                average_score = in_average_score;
        }
        double get_average_score(){
            cout << average_score << endl;
            return average_score;
        }

        void botat(){
            cout << "BOTAYU!!!" << endl;
            if(average_score < 10)
                average_score++;
        }

        Student(string &in_name)
        {
            set_name(in_name);
            set_age(18);
            set_average_score(0);
            cout << "I was born!" << endl;
        }
        ~Student()
        {
            cout << "Sdoh..." << endl;
        }
};

int main(){
    vector <class Student*> students;
    string name;

    name = "Ksenia";
    class Student st1(name);
    students.push_back(&st1);
    students[0] -> set_age(20);

    
    name = "Hagi Vagi";
    class Student st2(name);
    students.push_back(&st1);
    students[1] -> set_age(1000);
    
    name = "Kissi Missi";
    class Student st3(name);
    students.push_back(&st1);
    students[2] -> set_age(1000);
    
    name = "Pes";
    class Student st4(name);
    students.push_back(&st1);
    students[3] -> set_age(19);
    
    name = "Kit";
    class Student st5(name);
    students.push_back(&st1);
    students[4] -> set_age(18);

    for(int i = 0; i < 10; i++){
        srand(time(NULL));
        int num = rand() % (5);

        students[num]->botat();
        cout << "\n" << num << endl;
    }

    double sum_average_score;
    for (int i = 0; i < students.size(); i++)
    {
        students[i] -> get_name();
        sum_average_score += students[i]->get_average_score();
    }

    cout << "ALL STUDENTS " << sum_average_score/students.size() << endl;

    return 0;
}