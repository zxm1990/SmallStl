#ifndef __TEST_STL_VECTOR_H__
#define __TEST_STL_VECTOR_H__

#ifndef NULL
#define NULL 0
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#ifndef SIZE_T
#ifndef _SIZE_T
#ifndef _SIZE_T_
#define SIZE_T typedef unsigned long int size_t;
#endif
#endif
#endif

#ifndef PTRDIFF_T
#ifndef _PTRDIFF_T
#ifndef _PTRDIFF_T_
#define PTRDIFF_T typedef long int ptrdiff_t;
#endif
#endif
#endif

namespace base
{

template <typename T> class  My_allocator
{
public:
	typedef T*          pointer;
	typedef const T*    const_pointer;
	typedef T&          reference;
	typedef const T&    const_reference;
	typedef T           value_type;
	typedef size_t      size_type;

	pointer address(reference x) const
	{
		return &x;
	}

	const_pointer address(const_reference x)
	{
		return &x;
	}

	pointer allocate(size_type n)
	{
		if (!n)
		{
			return NULL;
		}
		else
		{
			pointer p = static_cast<pointer>(operator new(n * sizeof(value_type)));
			return p;
		}

	}

	void deallocate(pointer p, size_type n)
	{
		if (!n)
		{
			return;
		}
		else
		{
			operator delete(static_cast<void*>(p));
		}
	}

	//对于operator new分配的初始内存使用定位new来初始化
	void construct(pointer p, const_reference val)
	{
		new (p) value_type(val);
	}

	void destroy(pointer p)
	{
		p->~value_type();
	}
	
};

template <typename T> class My_Normal_iterator_base
{
public:
	My_Normal_iterator_base();
	~My_Normal_iterator_base();
	
};

}


#endif // __TEST_STL_VECTOR_H__