#include <iostream>

using namespace std;

void reduction(int &a, int &b){
    cout << a << " " << b << endl;
    int i = 2;
    while(i <= b && i <= a){
        if(b % i == 0 && a % i == 0){
            b = b / i;
            a = a / i;
        }
        else i++;
    }
}

int main(){
    int a = 2;
    int b = 4;
    reduction(a, b);
    cout << a << " " << b << endl;

}