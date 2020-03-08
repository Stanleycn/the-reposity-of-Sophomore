#include <iostream>
#include <typeinfo>
template <typename T>
struct Type
{
	static void print()
 {
	 std::cout<<"sizeof("<<typeid(T).name()<<")="
		       <<sizeof(T)<<std::endl;
 }
};
struct Polymorph
{
	virtual ~Polymorph(){}
};
enum Bit{zero,one};
enum Intensity{black=0,brigthtest=100};
int main()
{
//基本整形类型：
	Type<bool>::print(); 
	Type<char>::print();
	Type<signed char>::print();
	Type<unsigned char>::print();
	Type<wchar_t>::print();
	Type<signed short>::print();
	Type<unsigned short>::print();
	Type<signed int>::print();
	Type<unsigned int>::print();
	Type<signed long>::print();
	Type<unsigned long>::print();
#ifdef LONGLONG_EXIT
	Type<signed long long>::print();
	Type<unsigned long long>::print();
#endif
//基本浮点型：
	Type<float>::print();
	Type<double>::print();
	Type<long double>::print();
//指针类型
	Type<int*>::print();
	Type<int(*)()>::print();  
	Type<void(Polymorph::*)()>::print();
	Type<void*>::print();
//枚举类型
	Type<Bit>::print();
	Type<Intensity>::print();
	return 0;
}
