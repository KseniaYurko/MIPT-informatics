#include <bits/stdc++.h>

using namespace std;

class student {
    private:
        string name;
        int age;
        double mark;
    public:
        void set_name(string &in_name){
            name = in_name;
        }
        void get_name(){
            cout << name << endl;
        }

        void set_age(int in_age){
            if(in_age <= 50 && in_age >= 18) 
                age = in_age;
        }
        int get_age(){
            cout << age << endl;
            return age;
        }

        void set_mark(double in_mark){
            if(in_mark <= 10 && in_mark >= 0)
                mark = in_mark;
        }
        double get_mark(){
            cout << mark << endl;
            return mark;
        }

        void botat(){
            cout << "YA BOTAYU" << endl;
            if(mark < 10)
                mark++;
        }

        student(string &in_name)
        {
            set_name(in_name);
            set_age(18);
            set_mark(0);
            cout << "YA RODILSYA" << endl;
        }
        ~student()
        {
            cout << "YA SDOH" << endl;
        }
        
};

int main()
{
    vector <class student*> students;

    string name;

    name = "Kozak AS";
    class student st1(name);
    students.push_back(&st1);
    students[0]->set_age(19);

    name = "Bozhik NS";
    class student st2(name);
    students.push_back(&st2);
    students[1]->set_age(18);

    name = "Scubachevskiy AA";
    class student st3(name);
    students.push_back(&st3);
    students[2]->set_age(29);

    students[0]->botat();
    students[1]->botat();
    students[2]->botat();
    students[0]->botat();
    students[0]->botat();
    students[0]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();
    students[2]->botat();

    double sum_mark;
    for (int i = 0; i < students.size(); i++)
    {
        students[i]->get_name();
        sum_mark += students[i]->get_mark();
    }

    cout << "ALL STUDENTS " << sum_mark/students.size() << endl;
}