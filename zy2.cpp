#include <iostream>
#include <limits>
#include<typeinfo> 
template <typename T>
struct Type
{
	static void print()
	{
		std::cout<<typeid(T).name()<<": range is("
			<<std::numeric_limits<T>::min()<<","
			<<std::numeric_limits<T>::max()<<")\n";
	}
};
int main()
{
	Type<char>::print();
	Type<short>::print();
	Type<int>::print();
	Type<long>::print();
	Type<float>::print();
	Type<double>::print();
	Type<unsigned>::print();
	return 0;
}

