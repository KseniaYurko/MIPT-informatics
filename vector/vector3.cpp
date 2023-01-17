#include <iostream>
#include <vector>
#include <string>

void my_sort(std::vector <int> &w);

int main()
{
    std::vector<int> v = {7, 5, 16, 8};

    my_sort(v);
    for(int i = 0; i < 4; i++)
        std::cout << v[i] << " ";
}

void my_sort(std::vector <int> &w)
{
    int n = std::size(w);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
            if(w[j + 1] > w[j])
                std::swap(w[j], w[j + 1]);
}