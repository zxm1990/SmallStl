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
	typedef T            value_type;
	typedef T*           pointer;
	typedef const T*     const_pointer;
	typedef ptrdiff_t    difference_type;

	My_Normal_iterator_base()
		: ptr(NULL)
	{

	}

	My_Normal_iterator_base(pointer p)
		: ptr(p)
	{

	}

	value_type& operator*()
	{
		return *ptr;
	}

	const value_type& operator*() const
	{
		return *ptr;
	}

	pointer operator->()
	{
		return ptr;
	}

	const_pointer operator->() const
	{
		return ptr;
	}

	//前置
	My_Normal_iterator_base& operator++()
	{
		++ptr;
		return *this;
	}

	//后置
	My_Normal_iterator_base operator++(int)
	{
		My_Normal_iterator_base ret = *this;
		++ptr;
		return ret;
	}

	My_Normal_iterator_base& operator--()
	{
		--ptr;
		return *this;
	}

	My_Normal_iterator_base operator--(int)
	{
		My_Normal_iterator_base ret = *this;
		--ptr;
		return ret;
	}

	bool operator!() const
	{
		if (!ptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend My_Normal_iterator_base operator+(const My_Normal_iterator_base &obj, difference_type n)
	{
		return My_Normal_iterator_base(obj.ptr + n);
	}

	friend My_Normal_iterator_base operator-(const My_Normal_iterator_base &obj, difference_type n)
	{
		return My_Normal_iterator_base(obj.ptr - n);
	}

	friend difference_type operator-(const My_Normal_iterator_base &lhs,
									 const My_Normal_iterator_base &rhs)
	{
		return lhs.ptr - rhs.ptr;
	}

	//通常情况下赋值运算符应该为成员函数
	friend My_Normal_iterator_base& operator+=(My_Normal_iterator_base &obj,
												difference_type n)
	{
		obj = obj + n;
		return obj;
	}

	friend My_Normal_iterator_base& operator-=(My_Normal_iterator_base &obj,
												difference_type n)
	{
		obj = obj - n;
		return obj;
	}

	friend bool operator==(const My_Normal_iterator_base &lhs,
							const My_Normal_iterator_base &rhs)
	{
		return lhs.ptr == rhs.ptr;
	}

	friend bool operator!=(const My_Normal_iterator_base &lhs,
							const My_Normal_iterator_base &rhs)
	{
		return lhs.ptr != rhs.ptr;
	}

	friend bool operator<(const My_Normal_iterator_base &lhs,
							const My_Normal_iterator_base &rhs)
	{
		return lhs.ptr < rhs.ptr;
	}

	friend bool operator>(const My_Normal_iterator_base &lhs,
							const My_Normal_iterator_base &rhs)
	{
		return lhs.ptr > rhs.ptr;
	}

	friend bool operator<=(const My_Normal_iterator_base &lhs,
							const My_Normal_iterator_base &rhs)
	{
		return lhs.ptr <= rhs.ptr;
	}

	friend bool operator>=(const My_Normal_iterator_base &lhs,
							const My_Normal_iterator_base &rhs)
	{
		return lhs.ptr >= rhs.ptr;
	}

private:
	pointer ptr;
	
};


template <typename T> class My_Normal_const_iterator_base
{
public:
	typedef T            value_type;
	typedef T*           pointer;
	typedef const T*     const_pointer;
	typedef ptrdiff_t    difference_type;

	My_Normal_const_iterator_base()
		: ptr(NULL)
	{

	}

	My_Normal_const_iterator_base(const_pointer p)
		: ptr(p)
	{

	}

	const value_type& operator*() const
	{
		return *ptr;
	}

	const_pointer operator->() const
	{
		return ptr;
	}

	//前置
	My_Normal_const_iterator_base& operator++()
	{
		++ptr;
		return *this;
	}

	//后置
	My_Normal_const_iterator_base operator++(int)
	{
		My_Normal_const_iterator_base ret = *this;
		++ptr;
		return ret;
	}

	My_Normal_const_iterator_base& operator--()
	{
		--ptr;
		return *this;
	}

	My_Normal_const_iterator_base operator--(int)
	{
		My_Normal_const_iterator_base ret = *this;
		--ptr;
		return ret;
	}

	bool operator!() const
	{
		if (!ptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend My_Normal_const_iterator_base operator+(const My_Normal_const_iterator_base &obj, difference_type n)
	{
		return My_Normal_const_iterator_base(obj.ptr + n);
	}

	friend My_Normal_const_iterator_base operator-(const My_Normal_const_iterator_base &obj, difference_type n)
	{
		return My_Normal_const_iterator_base(obj.ptr - n);
	}

	friend difference_type operator-(const My_Normal_const_iterator_base &lhs,
									 const My_Normal_const_iterator_base &rhs)
	{
		return lhs.ptr - rhs.ptr;
	}

	friend My_Normal_const_iterator_base& operator+=(My_Normal_const_iterator_base &obj,
												difference_type n)
	{
		obj = obj + n;
		return obj;
	}

	friend My_Normal_const_iterator_base& operator-=(My_Normal_const_iterator_base &obj,
												difference_type n)
	{
		obj = obj - n;
		return obj;
	}

	friend bool operator==(const My_Normal_const_iterator_base &lhs,
							const My_Normal_const_iterator_base &rhs)
	{
		return lhs.ptr == rhs.ptr;
	}

	friend bool operator!=(const My_Normal_const_iterator_base &lhs,
							const My_Normal_const_iterator_base &rhs)
	{
		return lhs.ptr != rhs.ptr;
	}

	friend bool operator<(const My_Normal_const_iterator_base &lhs,
							const My_Normal_const_iterator_base &rhs)
	{
		return lhs.ptr < rhs.ptr;
	}

	friend bool operator>(const My_Normal_const_iterator_base &lhs,
							const My_Normal_const_iterator_base &rhs)
	{
		return lhs.ptr > rhs.ptr;
	}

	friend bool operator<=(const My_Normal_const_iterator_base &lhs,
							const My_Normal_const_iterator_base &rhs)
	{
		return lhs.ptr <= rhs.ptr;
	}

	friend bool operator>=(const My_Normal_const_iterator_base &lhs,
							const My_Normal_const_iterator_base &rhs)
	{
		return lhs.ptr >= rhs.ptr;
	}

private:
	const_pointer ptr;
	
};


template <typename T> class My_Reverse_iterator_base
{
public:
	typedef T            value_type;
	typedef T*           pointer;
	typedef const T*     const_pointer;
	typedef ptrdiff_t    difference_type;

	My_Reverse_iterator_base()
		: ptr(NULL)
	{

	}

	My_Reverse_iterator_base(pointer p)
		: ptr(p)
	{

	}

	value_type& operator*()
	{
		return *ptr;
	}

	const value_type& operator*() const
	{
		return *ptr;
	}

	pointer operator->()
	{
		return ptr;
	}

	const_pointer operator->() const
	{
		return ptr;
	}

	//前置
	My_Reverse_iterator_base& operator++()
	{
		--ptr;
		return *this;
	}

	//后置
	My_Reverse_iterator_base operator++(int)
	{
		My_Reverse_iterator_base ret = *this;
		--ptr;
		return ret;
	}

	My_Reverse_iterator_base& operator--()
	{
		++ptr;
		return *this;
	}

	My_Reverse_iterator_base operator--(int)
	{
		My_Reverse_iterator_base ret = *this;
		++ptr;
		return ret;
	}

	bool operator!() const
	{
		if (!ptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend My_Reverse_iterator_base operator+(const My_Reverse_iterator_base &obj, difference_type n)
	{
		return My_Reverse_iterator_base(obj.ptr - n);
	}

	friend My_Reverse_iterator_base operator-(const My_Reverse_iterator_base &obj, difference_type n)
	{
		return My_Reverse_iterator_base(obj.ptr + n);
	}

	friend difference_type operator-(const My_Reverse_iterator_base &lhs,
									 const My_Reverse_iterator_base &rhs)
	{
		return lhs.ptr - rhs.ptr;
	}

	friend My_Reverse_iterator_base& operator+=(My_Reverse_iterator_base &obj,
												difference_type n)
	{
		obj = obj + n;
		return obj;
	}

	friend My_Reverse_iterator_base& operator-=(My_Reverse_iterator_base &obj,
												difference_type n)
	{
		obj = obj - n;
		return obj;
	}

	friend bool operator==(const My_Reverse_iterator_base &lhs,
							const My_Reverse_iterator_base &rhs)
	{
		return lhs.ptr == rhs.ptr;
	}

	friend bool operator!=(const My_Reverse_iterator_base &lhs,
							const My_Reverse_iterator_base &rhs)
	{
		return lhs.ptr != rhs.ptr;
	}

	friend bool operator<(const My_Reverse_iterator_base &lhs,
							const My_Reverse_iterator_base &rhs)
	{
		return lhs.ptr > rhs.ptr;
	}

	friend bool operator>(const My_Reverse_iterator_base &lhs,
							const My_Reverse_iterator_base &rhs)
	{
		return lhs.ptr < rhs.ptr;
	}

	friend bool operator<=(const My_Reverse_iterator_base &lhs,
							const My_Reverse_iterator_base &rhs)
	{
		return lhs.ptr >= rhs.ptr;
	}

	friend bool operator>=(const My_Reverse_iterator_base &lhs,
							const My_Reverse_iterator_base &rhs)
	{
		return lhs.ptr <= rhs.ptr;
	}

private:
	pointer ptr;
	
};

template <typename T> class My_Reverse_const_iterator_base
{
public:
	typedef T            value_type;
	typedef T*           pointer;
	typedef const T*     const_pointer;
	typedef ptrdiff_t    difference_type;

	My_Reverse_const_iterator_base()
		: ptr(NULL)
	{

	}

	My_Reverse_const_iterator_base(const_pointer p)
		: ptr(p)
	{

	}

	const value_type& operator*() const
	{
		return *ptr;
	}

	const_pointer operator->() const
	{
		return ptr;
	}

	//前置
	My_Reverse_const_iterator_base& operator++()
	{
		--ptr;
		return *this;
	}

	//后置
	My_Reverse_const_iterator_base operator++(int)
	{
		My_Reverse_const_iterator_base ret = *this;
		--ptr;
		return ret;
	}

	My_Reverse_const_iterator_base& operator--()
	{
		++ptr;
		return *this;
	}

	My_Reverse_const_iterator_base operator--(int)
	{
		My_Reverse_const_iterator_base ret = *this;
		++ptr;
		return ret;
	}

	bool operator!() const
	{
		if (!ptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend My_Reverse_const_iterator_base operator+(const My_Reverse_const_iterator_base &obj, difference_type n)
	{
		return My_Reverse_const_iterator_base(obj.ptr - n);
	}

	friend My_Reverse_const_iterator_base operator-(const My_Reverse_const_iterator_base &obj, difference_type n)
	{
		return My_Reverse_const_iterator_base(obj.ptr + n);
	}

	friend difference_type operator-(const My_Reverse_const_iterator_base &lhs,
									 const My_Reverse_const_iterator_base &rhs)
	{
		return lhs.ptr - rhs.ptr;
	}

	friend My_Reverse_const_iterator_base& operator+=(My_Reverse_const_iterator_base &obj,
												difference_type n)
	{
		obj = obj + n;
		return obj;
	}
	//调用了减法算术运算符
	friend My_Reverse_const_iterator_base& operator-=(My_Reverse_const_iterator_base &obj,
												difference_type n)
	{
		obj = obj - n;
		return obj;
	}

	friend bool operator==(const My_Reverse_const_iterator_base &lhs,
							const My_Reverse_const_iterator_base &rhs)
	{
		return lhs.ptr == rhs.ptr;
	}

	friend bool operator!=(const My_Reverse_const_iterator_base &lhs,
							const My_Reverse_const_iterator_base &rhs)
	{
		return lhs.ptr != rhs.ptr;
	}

	friend bool operator<(const My_Reverse_const_iterator_base &lhs,
							const My_Reverse_const_iterator_base &rhs)
	{
		return lhs.ptr > rhs.ptr;
	}

	friend bool operator>(const My_Reverse_const_iterator_base &lhs,
							const My_Reverse_const_iterator_base &rhs)
	{
		return lhs.ptr < rhs.ptr;
	}

	friend bool operator<=(const My_Reverse_const_iterator_base &lhs,
							const My_Reverse_const_iterator_base &rhs)
	{
		return lhs.ptr >= rhs.ptr;
	}

	friend bool operator>=(const My_Reverse_const_iterator_base &lhs,
							const My_Reverse_const_iterator_base &rhs)
	{
		return lhs.ptr <= rhs.ptr;
	}

private:
	const_pointer ptr;
	
};


}


#endif // __TEST_STL_VECTOR_H__