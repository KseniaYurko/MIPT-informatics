#include <iostream>
#include <vector>
#include <string>

int main()
{  
    int z = 0; 

    std::cin >> z; 

    int n = 0;
    
    std::cin >> n;

    std::vector <int> v(n);
    for(int k = 0; k < n; k++)
        std::cin >> v[k];

    int a = (1<<19);

    for(int i = 0; i < n; i++)
        if(v[i] > z && v[i] < a)
            a = v[i];
    std::cout << a;
    
}
