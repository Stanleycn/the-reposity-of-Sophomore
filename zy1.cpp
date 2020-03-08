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
//�����������ͣ�
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
//���������ͣ�
	Type<float>::print();
	Type<double>::print();
	Type<long double>::print();
//ָ������
	Type<int*>::print();
	Type<int(*)()>::print();  
	Type<void(Polymorph::*)()>::print();
	Type<void*>::print();
//ö������
	Type<Bit>::print();
	Type<Intensity>::print();
	return 0;
}
