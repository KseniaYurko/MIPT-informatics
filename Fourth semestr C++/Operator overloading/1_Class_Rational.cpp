#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;


void reduction(int &a, int &b){
    int i = 2;
    while(i <= b && i <= abs(a)){
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
        int num;
        int denom;

    rational(){
        num = 0;
        denom = 1;
    }

    rational(int num_, int denom_){
        num = num_;
        denom = denom_; 

        if(denom < 0){
            change_sign(num, denom);
        }
        else if(denom == 0){
            throw invalid_argument("denom = 0");
        }  
        reduction(num, denom);
    }

//ELEMENTARY OPERATIONS------------------------------------------------------------------------//
    //sum
    rational operator+ (rational fr2){
        fr2.num = num * fr2.denom + fr2.num * denom; 
        fr2.denom = denom * fr2.denom;
        reduction(fr2.num, fr2.denom); 
        return fr2;
    }

    //substraction
    rational operator- (rational fr2){
        rational fr3;
        fr3.num = num * fr2.denom - fr2.num * denom;
        fr3.denom = denom * fr2.denom;
        reduction(fr3.num, fr3.denom);
        return fr3;
    }

    //multiply
    rational operator* (rational fr2){
        fr2.num = num * fr2.num; 
        fr2.denom = denom * fr2.denom;
        reduction(fr2.num, fr2.denom);
        return fr2;
    }

    //division
    rational operator/ (rational fr2){
        rational fr3;
        fr3.denom = fr2.denom;
        fr3.num = fr2.num;

        fr3.num = num * fr2.denom; 
        fr3.denom = denom * fr2.num;
        reduction(fr3.num, fr3.denom);
        return fr3;
    }

//COMPARISON OPERATIONS------------------------------------------------------------------------//
    //assigment
    rational operator= (rational fr2){
        num = fr2.num; 
        denom = fr2.denom; 
        return fr2;
    }

    //comparison
    bool operator== (rational fr2){
        if(num == fr2.num && denom == fr2.denom){
            return true;
        }
        else return false;
    }

    //more
    bool operator> (rational fr2){
        if(num * fr2.denom - fr2.num * denom > 0){
            return true;
        }
        else return false; 
    }

    //less
    bool operator< (rational fr2){
        if(num * fr2.denom - fr2.num * denom < 0){
            return true;
        }
        else return false; 
    }
};

//INPUT/OUTPUT OPERATIONS----------------------------------------------------------------------//
//display class
ostream& operator<< (ostream& os, rational fr){
    return os << fr.num << "/" << fr.denom << endl;
};

//enter class
istream& operator>> (istream& in, rational fr){
    return in >> fr.num >> fr.denom;
};


int main(){
    rational fr1(7, 14);
    rational fr2(13, 14);
    rational fr3(13, 14);
    rational fr4(3, 7);

    cout << "INPUT/OUTPUT OPERATIONS" << endl;
    cout << fr1 << fr2 << fr3 << fr4;
    rational fr;
    cin >> fr;
    cout << fr << endl;

    cout << "ELEMENTARY OPERATIONS" << endl;
    cout << fr1 << fr2 << endl;
    cout << fr1 + fr2 << " - sum" << endl;
    cout << fr1 - fr2 << " - substruction" << endl;
    cout << fr1 * fr2 << " - multiply" << endl;
    cout << fr1 / fr2 << " - divsion" << endl << endl;

    cout << "COMPARISON OPERATIONS" << endl;
    fr3 = fr1;
    cout << fr3 << " - assigment (fr3 = fr1)" << endl;

    bool result = fr1 == fr2;
    // printf("%d - comparison (fr1 == fr2)", result, fr1, fr2);
    cout << result << " - comparison (fr1 == fr2)" << endl;

    result = fr1 > fr2;
    cout << result << " - more (fr1 > fr2)" << endl;

    result = fr1 < fr2;
    cout << result << " - less (fr1 < fr2)" << endl;

}