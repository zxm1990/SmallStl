#include <iostream>
#include "TestStlVector.h"


using namespace base;
using namespace std;

template <typename T> void test_normal_iter(T)
{
	printf("test %s\n", typeid(T).name());
	char str[100] = "123456789";

	T nor_iter = T(str + 5);
	printf("%c\n", *nor_iter);

	++nor_iter;
	printf("%c\n", *nor_iter);

	nor_iter++;
	printf("%c\n", *nor_iter);

	nor_iter--;
	printf("%c\n", *nor_iter);

	--nor_iter;
	printf("%c\n", *nor_iter);

	nor_iter = nor_iter + 2;
	printf("%c\n", *nor_iter);

	nor_iter = nor_iter - 1;
	printf("%c\n", *nor_iter);

	nor_iter += 3;
	printf("%c\n", *nor_iter);
	
	nor_iter -= 1;
	printf("%c\n", *nor_iter);

	T nor_iter2 = T(str + 3);
	typename T::difference_type len = nor_iter - nor_iter2;
	printf("%ld\n", len);

	if (nor_iter != nor_iter2)
	{
		printf("!= is true\n");
		if (nor_iter > nor_iter2)
		{
			printf("> is true\n");
		}
		else 
		{
			printf("<= is true\n");
		}
	}
	else
	{
		printf("== is true\n");
	}


}

void tes_vector()
{
	My_vector<char> vec(10, 'w');
	cout << typeid(vec).name() << endl;

	vec.push_back('a');
	cout << vec.size() << endl;

	vec.insert(vec.begin() + 2, 3, '2');
	vec.insert(vec.begin() + 1, vec.begin() + 2, vec.begin() + 5);
	vec.erase(vec.end() - 1);
	vec.erase(vec.begin() + 1);
	for (My_vector<char>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << endl;
	}

	vec.assign(10, '3');
	for (My_vector<char>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << endl;
	}

	My_vector<char> vec2(10, 'g');
	vec.swap(vec2);
	for (My_vector<char>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << endl;
	}

}

int main()
{
	My_allocator<int> alloc;
	int *p = alloc.allocate(10);
	alloc.construct(p, 10);

	printf("%d, %d\n", *p, *(p + 1));

	My_Normal_iterator_base<char> nor_iter;
	My_Normal_const_iterator_base<char> const_nor_iter;
	My_Reverse_iterator_base<char> rever_nor_iter;
	My_Reverse_const_iterator_base<char> rever_const_iter;

	test_normal_iter(nor_iter);
	test_normal_iter(const_nor_iter);
	test_normal_iter(rever_nor_iter);
	test_normal_iter(rever_const_iter);

	tes_vector();

	

}