#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;


void reduction(int &a, int &b){
    int i = 2;
    while(i <= b && i <= a){
        if(b % i == 0 && a % i == 0){
            b = b / i;
            a = a / i;
        }
        else i++;
    }
}


void change_sign(int &a, int &b){
    b = -1 * b;
    a = -1 * a;
}



class rational {
    public:
        int numerator;
        int denominator;

    rational(){
        numerator = 0;
        denominator = 1;
    }

    rational(int numerator_, int denominator_){
        numerator = numerator_;
        denominator = denominator_; 

        if(denominator < 0){
            change_sign(numerator, denominator);
        }
        else if(denominator = 0){
            throw invalid_argument("denominator = 0");
        }  
        else denominator = denominator_;

        reduction(numerator, denominator);
        // cout << numerator << " " << denominator << " - reduction" << endl;
    }

    //sum
    rational operator+ (rational fr2){
        numerator = numerator * fr2.denominator + fr2.numerator * denominator; 
        denominator = denominator * fr2.denominator;
        reduction(numerator, denominator); 
        return *this;
    }

    //substraction
    rational operator- (rational fr2){
        numerator = numerator * fr2.denominator - fr2.numerator * denominator; 
        denominator = denominator * fr2.denominator;
        reduction(numerator, denominator);
        return *this;
    }
};

//display class
ostream& operator<< (ostream& os, rational fr){
    return os << fr.numerator << "/" << fr.denominator << endl;
};


int main(){
    rational fr1(1, 2);
    rational fr2(2, -4);

    cout << fr1 << endl;
    cout << fr2 << endl;
    cout << fr1 - fr2 << endl;
}
