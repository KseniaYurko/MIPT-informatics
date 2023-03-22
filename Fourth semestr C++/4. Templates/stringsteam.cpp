#include <iostream>
#include <vector>
#include <sstream>

int main()
{
	std::vector<int> vec { 6, 3, 8, -9, 1, -2, 8 };

	std::stringstream ss;
	for (auto it = vec.begin(); it != vec.end(); it++)	{
		if (it != vec.begin()) {
			ss << " ";
		}
		ss << *it;
	}

	std::cout << ss.str() << std::endl;

	return 0;
}