#include <iostream>
#include "TestStlVector.h"


using namespace base;
using namespace std;

int main()
{
	My_allocator<int> alloc;
	int *p = alloc.allocate(10);
	alloc.construct(p, 10);

	printf("%d, %d\n", *p, *(p + 1));
}