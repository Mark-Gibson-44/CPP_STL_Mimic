#include "vec.h"
#include "list.h"

int main(){


	Vector<int> v1(1,2,3);
	auto v2 = Vector<int>(2,4,3);

	v2.push_back(4);

	auto start = v2.rbegin();

	//std::cout << "Forwards:\n";
	/*for(auto a: v2)
		std::cout << a  << "\n";
	std::cout << "Backwards:\n";




	while(start != v2.rend()){
		std::cout << *start << '\n';
		start++;
	}


	List<int> l1(1);
	l1.append(3);

	l1.emplace(new List<int>(5));
	*/


	auto func = [](auto& a){ a *= 2; };

	v2.for_each(func);

	for(auto& a: v2)
		std::cout << a << '\n';
	return 0;
}
