#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>
#include <stdexcept>
#include <map>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

class worker {
    public:
        string name;
        int age;
        int salary;

    worker(){
            name = "no name";
            age = 0;
            salary = 0;
        }

    worker(string name_, int age_, int salary_){
        name = name_;
        age = age_;
        salary = salary_;

        if(salary < 100){
            delete this;
        }
    };



//FUNCTIONS OF CLASS--------------------------------------------------------------------------------//

    // void doWork(){
    //     fstream fout;
    //     fout.open("work_result.txt", ios::app);
    //     fout << name << " -  age: " << age << "; salary: " << salary << endl;
    //     --salary;
    //     fout.close();
    // }
};

mutex g_lock;

void doWork(worker &wk){
    for(int i; i < 100; i++){
        try{
            g_lock.lock();

            fstream fout;
            fout.open("work_result.txt", ios::app);
            fout << wk.name << " -  age: " << wk.age << "; salary: " << wk.salary << endl;
            --wk.salary;
            fout.close();

            g_lock.unlock();
        }
        catch(exception &ex){
            cout << "the worker was fired" << ex.what() << endl;
        }
        throw exception();
    }
    
}

int main(){
    vector <int> workers_salary = {1011, 200, 150, 102, 180};

    worker wk1("Ksyu", 20, workers_salary[0]);
    worker wk2("Anton", 16, workers_salary[1]);
    worker wk3("Sanya", 18, workers_salary[2]);
    worker wk4("David", 19, workers_salary[3]);
    worker wk5("Vlad", 19, workers_salary[4]);

    vector <class worker> workers = {wk1, wk2, wk3, wk4, wk5};

    thread thr1(doWork,  ref(wk1));
    thread thr2(doWork,  ref(wk2));
    thread thr3(doWork,  ref(wk3));
    thread thr4(doWork,  ref(wk4));
    thread thr5(doWork,  ref(wk5));
    
    thr1.join();
    thr2.join();
    thr3.join();
    thr4.join();
    thr5.join();
    
    return 0;
   
      


}