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

template <typename Iterator> 
Iterator uninitialized_copy(Iterator first, Iterator last, Iterator result)
{
	while (first != last)
	{
		new(static_cast<void*>(&*result)) typename Iterator::value_type(*first);
		++first;
		++result;
	}

	return result;
}

template <typename Iterator>
Iterator* uninitialized_copy(Iterator *first,  Iterator *last, Iterator *result)
{
	while (first != last)
	{
		new(result) Iterator(*first);
		++first;
		++result;
	}

	return result;
}

template <typename Iterator, typename T>
void uninitialized_fill(Iterator first, Iterator last, const T &val)
{
	while (first != last)
	{
		new(static_cast<void*>(first)) typename Iterator::value_type(val);
		++first;
	}
}

template <typename Iterator, typename T>
void uninitialized_fill(Iterator *first, Iterator *last, const T &val)
{
	while (first != last)
	{
		new(first) Iterator(val);
		++first; 
	}
}

template <typename Iterator>
Iterator copy_backward(Iterator first, Iterator last, Iterator result)
{
	while (first != last)
	{
		*(--result) = *(--last);
	}

	return result;
}

template <typename Iterator>
void copy(Iterator first, Iterator last, Iterator result)
{
	while (first != last)
	{
		*result = *first;
		++first;
		++result;
	}
}

template <typename T, typename Alloc = My_allocator<T> >
class  My_vector
{
public:
	typedef My_Normal_iterator_base<T>           iterator;
	typedef My_Normal_const_iterator_base<T>     const_iterator;
	typedef My_Reverse_iterator_base<T>          reverse_iterator;
	typedef My_Reverse_const_iterator_base<T>    const_reverse_iterator;
	typedef T                                    value_type;
	typedef T&                                   reference;
	typedef const T&                             const_reference;
	typedef size_t                               size_type;

	 My_vector()
	 	: first_iter(NULL), last_iter(NULL), end_iter(NULL)
	 {

	 } 

	 My_vector(size_type n, const value_type& val)
	 	: first_iter(NULL), last_iter(NULL), end_iter(NULL)
	 {
	 	first_iter = alloc.allocate(n);
	 	last_iter = first_iter + n;
	 	end_iter = last_iter;
	 	uninitialized_fill(&*first_iter, &*end_iter, val);
	 }
	 //此处应该用const 才合理
	 My_vector(My_vector &obj)
	 	: first_iter(NULL), last_iter(NULL), end_iter(NULL)
	 {
	 	iterator copy_new_alloc = alloc.allocate(obj.size());
	 	uninitialized_copy(&*obj.first_iter, &*obj.end_iter, &*copy_new_alloc);
	 	first_iter = copy_new_alloc;
	 	last_iter = first_iter + obj.size();
	 	end_iter = last_iter;
	 }

	 My_vector(iterator first, iterator last)
	 	: first_iter(NULL), last_iter(NULL), end_iter(NULL)
	 {
	 	size_type my_size = last - first;
	 	first_iter = alloc.allocate(my_size);
	 	uninitialized_copy(&*first, &*last, &*first_iter);
	 	last_iter = first_iter + my_size;
	 	end_iter = last_iter;
	 }

	~ My_vector()
	{
		for (iterator p = last_iter; p != first_iter; )
		{
			alloc.destroy(&*--p);
		}

		alloc.deallocate(&*first_iter, &*end_iter - &*first_iter);
	}

	size_type size() const
	{
		if (!end_iter)
		{
			return 0;
		}
		else
		{
			return last_iter - first_iter;
		}
	}

	size_type max_size() const
	{
		return size_type(-1);
	}

	bool empty() const
	{
		return !size();
	}

	void push_back(const value_type &val)
	{
		if (last_iter == end_iter)
		{
			reallocator();
		}
		alloc.construct(&*last_iter, val);
		++last_iter;
	}

	void pop_back()
	{
		alloc.destroy(&*--last_iter);
	}

	iterator begin()
	{
		return first_iter;
	}

	const_iterator begin() const
	{
		return first_iter;
	}

	iterator end()
	{
		return last_iter;
	}

	const_iterator end() const
	{
		return last_iter;
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(&*(last_iter - 1));
	}

	const_reverse_iterator rbegin() const
	{
		return reverse_iterator(&*(last_iter - 1));
	}

	reverse_iterator rend()
	{
		return reverse_iterator(&*(first_iter - 1));
	}

	reverse_iterator rend() const
	{
		return reverse_iterator(&*(first_iter - 1));
	}

	reference front()
	{
		return *first_iter;
	}

	const_reference front() const
	{
		return *first_iter;
	}

	reference back()
	{
		return *(last_iter - 1);
	}

	const_reference back() const
	{
		return *(last_iter - 1);
	}

	Alloc get_allocator() const
	{
		return alloc;
	}

	void clear()
	{
		if (size())
		{
			for (iterator p = last_iter; p != first_iter; )
			{
				alloc.destroy(&*--p);
			}
		}
	}

	size_type capacity() const
	{
		return end_iter - first_iter;
	}

	void reserve(size_type n)
	{
		iterator reserve_ptr = alloc.allocate(n);
		size_type len = size();
		uninitialized_copy(&*first_iter, &*last_iter, &*reserve_ptr);
		for (iterator p = last_iter; p != first_iter; )
		{
			alloc.destroy(&*--p);
		}
		alloc.deallocate(&*first_iter, end_iter - first_iter);
		first_iter = reserve_ptr;
		last_iter = first_iter + len;
		end_iter = first_iter + n;
	}

	void resize(size_type n)
	{
		if (n < size())
		{
			iterator p = last_iter;
			while (p != last_iter - (size() - n))
			{
				alloc.destroy(&*--p);
			}
			last_iter = p;
		}
		else
		{
			size_type len = size();
			if (n <= capacity())
			{
				uninitialized_fill(&*first_iter, &*(last_iter + (n - size())), value_type());
				last_iter = last_iter + (n - size());
			}
			else
			{
				reserve();
				iterator mid_ptr = last_iter;
				while (mid_ptr != end_iter)
				{
					push_back(value_type());
					++last_iter;
				}

				last_iter = mid_ptr;
			}
		}
	}

	void assign(size_type n, const value_type &val)
	{
		for (iterator p = last_iter; p != first_iter; )
		{
			alloc.destroy(&*--p);
		}

		if (n <= capacity())
		{
			last_iter = first_iter + n;
			uninitialized_fill(&*first_iter, &*last_iter, val);
		}
		else
		{
			alloc.deallocate(&*first_iter, capacity());
			first_iter = alloc.allocate(n);
			end_iter = last_iter;
			uninitialized_fill(&*first_iter, &*last_iter, val);
		}
	}

	void assign(iterator first, iterator last)
	{
		size_type n = last_iter - first_iter;
		for (iterator p = last_iter; p != first_iter; )
		{
			alloc.deallocate(&*--p);
		}

		if (n <= capacity())
		{
			uninitialized_copy(&*first, &*last, &*first_iter);
			last_iter = first_iter + n;
		}
		else
		{
			alloc.deallocate(&*first_iter, capacity());
			first_iter = alloc.allocate(n);
			last_iter = first_iter + n;
			end_iter = first_iter + n;
			uninitialized_copy(&*first, &*last, &*first_iter);
		}
	}

	void swap(My_vector &obj)
	{ 
		My_vector ret(*this);
		size_type len_own = capacity();
		size_type len_obj = obj.capacity();
		*this = obj;
		reserve(len_obj);
		obj = ret;
		obj.reserve(len_own);

	}

	void insert(iterator position, size_type n, const value_type &val)
	{
		if (position == last_iter)
		{
			for (size_type count = 0; count != n; ++count)
			{
				push_back(val);
			}
		}
		else
		{
			size_type num = position - first_iter;
			if (last_iter == end_iter)
			{
				reallocator();
			}

			position = first_iter + num;
			copy_backward(&*position, &*last_iter, &*(last_iter + n));
			iterator it = position;
			for (size_type count = 0; count != n; ++count, ++it)
			{
				*it = val;
			}
			last_iter = last_iter + n;

		}
	}

	void insert(iterator position, iterator first, iterator last)
	{
		size_type distance = last - first;
		if (position == last_iter)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		else
		{
			size_type num = position - first_iter;
			if (last_iter == end_iter)
			{
				reallocator();
			}
			position = first_iter + num;
			copy_backward(&*position, &*last_iter, &*(last_iter + distance));
			iterator it = position;
			while (first != last)
			{
				*it = *first;
				++it;
				++first;
			}
			last_iter = last_iter + distance;
		}
	}

	iterator erase(iterator position)
	{
		return erase(position, position + 1);
	}

	iterator erase(iterator first, iterator last)
	{
		size_type distance = last - first;
		if (last_iter == last)
		{
			while (last != first)
			{
				pop_back();
				--last;
			}
		}
		else
		{
			copy(&*last, &*last_iter, &*first);
			iterator p = last_iter;
			for (int i = 0; i < distance; ++i)
			{
				alloc.destroy(&*--p);
			}
			last_iter = last_iter - distance;
		}
		return first;
	}

	reference at(size_type index)
	{
		return *(first_iter + index);
	}

	const_reference at(size_type index) const
	{
		return *(first_iter + index);
	}

	reference operator[](size_type index)
	{
		return *(first_iter + index);
	}

	const_reference operator[](size_type index) const
	{
		return *(first_iter + index);
	}

	//此处应该用const 才合理
	My_vector& operator=(My_vector &obj)
	{
		if (first_iter == obj.first_iter && end_iter == obj.end_iter)
		{
			return *this;
		}

		iterator assignment_alloc = alloc.allocate(obj.size());
		uninitialized_copy(&*(obj.first_iter), &*(obj.last_iter), &*assignment_alloc);
		clear();
		alloc.deallocate(&*first_iter, end_iter - first_iter);
		first_iter = assignment_alloc;
		last_iter = first_iter + obj.size();
		end_iter = last_iter;

		return *this;
	}

private:
	void reallocator()
	{
		size_type curr_size = size();
		typename iterator::difference_type capacity_size = curr_size >= 1 ? 2* curr_size : 1;
		iterator new_alloc = alloc.allocate(capacity_size);
		uninitialized_copy(&*first_iter, &*last_iter, &*new_alloc);
		for (iterator p = end_iter; p != first_iter; )
		{
			alloc.destroy(&*--p);
		}
		alloc.deallocate(&*first_iter, end_iter - first_iter);
		first_iter = new_alloc;
		last_iter = first_iter + curr_size;
		end_iter = first_iter + capacity_size;
	}

	Alloc alloc;
	iterator first_iter;
	iterator last_iter;
	iterator end_iter;

};

template <typename T, typename Alloc>
bool operator==(const My_vector<T, Alloc> &lhs, const My_vector<T, Alloc> &rhs)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}

	if (lhs.size() > rhs.size())
	{
		return rhs == lhs;
	}

	for (int i = 0; i != lhs.size(); ++i)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}

	return true;
}

template <typename T, typename Alloc>
bool operator!=(const My_vector<T, Alloc> &lhs, const My_vector<T, Alloc> &rhs)
{
	return !(lhs == rhs);
}

template <typename T, typename Alloc>
bool operator<(const My_vector<T, Alloc> &lhs, const My_vector<T, Alloc> &rhs)
{
	if (lhs.size() < rhs.size())
	{
		for (int i = 0; i != lhs.size(); ++i)
		{
			if (lhs[i] != rhs[i])
			{
				return lhs[i] < rhs[i];
			}
		}
		return true;
	}
	else
	{
		for (int i = 0; i != rhs.size(); ++i)
		{
			if (lhs[i] != rhs[i])
			{
				return lhs[i] < rhs[i];
			}
		} 
		return false;
	}
}

template <typename T, typename Alloc>
bool operator>(const My_vector<T, Alloc> &lhs, const My_vector<T, Alloc> &rhs)
{
	if (lhs.size() > rhs.size())
	{
		for (int i = 0; i != lhs.size(); ++i)
		{
			if (lhs[i] != rhs[i])
			{
				return lhs[i] > rhs[i];
			}
		}
		return true;
	}
	else
	{
		for (int i = 0; i != rhs.size(); ++i)
		{
			if (lhs[i] != rhs[i])
			{
				return lhs[i] > rhs[i];
			}
		} 
		return false;
	}
}

template <typename T, typename Alloc>
bool operator>=(const My_vector<T, Alloc> &lhs, const My_vector<T, Alloc> &rhs)
{
	return !(lhs < rhs);
}

template <typename T, typename Alloc>
bool operator<=(const My_vector<T, Alloc> &lhs, const My_vector<T, Alloc> &rhs)
{
	return !(lhs > rhs);
}


}


#endif // __TEST_STL_VECTOR_H__