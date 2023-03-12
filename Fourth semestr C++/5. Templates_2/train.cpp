#include <iostream>

using namespace std;

int pow(int x) {
    return x * x;
}

double pow(double x) {
    return x * x;
}

int main () {
    int t = 2;
    cout << pow(t) << endl;
    return 0;
}