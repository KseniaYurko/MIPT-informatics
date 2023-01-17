#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector <string> w(3);
    for(int i = 0; i < 3; i++)
        cin >> w[i];

    sort(w.begin(), w.end());
    for(int k = 0; k < 3; k++)
        cout << w[k] << " ";

    int c = 0;
    for(int j = 0; j < size(w[0]); j++)
        if(w[0][j] == 'o')
            c++;
    cout << endl << c << endl;
}