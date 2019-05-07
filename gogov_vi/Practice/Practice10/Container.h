#ifndef _CONTAINER_H_
#define _CONTAINER_H_
#include <exception>

template<typename T, int max_size>
class Container 
{
	T* arr;
	int count;
public:
	Container();
	Container(const Container&);
	~Container();
	bool is_full() const;
	bool is_empty() const;
	int find_elem(T) const;
	void add_elem(T);
	void delete_elem(T);
	T& operator[](int) const;
	void print();
};

template<typename T, int max_size>
Container<T, max_size>::Container()
{
	count = 0;
	arr = new T[max_size];
}

template<typename T, int max_size>
Container<T, max_size>::Container(const Container& x)
{
	count = x.count;
	arr = new T[max_size];
	for (int i = 0; i < count; i++)
		arr[i] = x.arr[i];
}

template<typename T, int max_size>
Container<T, max_size>::~Container()
{
	delete[] arr;
}

template<typename T, int max_size>
bool Container<T, max_size>::is_full() const
{
	return (count == max_size) ? 1 : 0;
}

template<typename T, int max_size>
bool Container<T, max_size>::is_empty() const
{
	return (count == 0) ? 1 : 0;
}

template<typename T, int max_size>
T& Container<T, max_size>::operator[](int idx) const
{
	if (idx >= count)
		throw std::out_of_range("Выход за границы.\n");
	return arr[idx];
}

template<typename T, int max_size>
int Container<T, max_size>::find_elem(T x) const
{
	for (int i = 0; i < count; i++)
		if (x == arr[i])
			return i;
	return -1;
}

template<typename T, int max_size>
void Container<T, max_size>::add_elem(T x)
{
	if(is_full())
		throw std::out_of_range("Контейнер полный.\n");
	arr[count] = x;
	count++;
}

template<typename T, int max_size>
void Container<T, max_size>::delete_elem(T x)
{
	int idx = find_elem(x);
	if (idx == -1)
	{
		throw "Элемент не найден \n";
	}
	T tmp = arr[idx];
	arr[idx] = arr[count - 1];
	arr[count - 1] = tmp;
	count--;
}

template<typename T, int max_size>
void Container<T, max_size>::print()
{
	for (int i = 0; i < count; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}










///////////////////////////////////////////////////////////////////////////////

template<typename T, int max_size>
class Container<T*, max_size>
{
	T** arr;
	int count;
public:
	Container<T*, max_size>();
	Container<T*, max_size>(const Container&);
	~Container<T*, max_size>();
	bool is_full() const;
	bool is_empty() const;
	int find_elem(T) const;
	void add_elem(T);
	void delete_elem(T);
	T*& operator[](int) const;
	void print();
};

template<typename T, int max_size>
Container<T*, max_size>::Container()
{
	count = 0;
	arr = new T*[max_size];
	for (int i = 0; i < max_size; i++)
		arr[i] = new T;
}

template<typename T, int max_size>
Container<T*, max_size>::Container(const Container& x)
{
	delete[] arr;
	arr = nullptr;
	count = x.count;
	arr = new T*[max_size];
	for (int i = 0; i < count; i++)
	{
		arr[i] = new T(**(x.arr + i));
	}
}

template<typename T, int max_size>
Container<T*, max_size>::~Container()
{
	for (int i = 0; i < count; i++)
		delete arr[i];
	delete arr;
}

template<typename T, int max_size>
bool Container<T*, max_size>::is_full() const
{
	return (count == max_size) ? 1 : 0;
}

template<typename T, int max_size>
bool Container<T*, max_size>::is_empty() const
{
	return (count == 0) ? 1 : 0;
}

template<typename T, int max_size>
T*& Container<T*, max_size>::operator[](int idx) const
{
	if (idx >= count)
		throw std::out_of_range("Выход за границы.\n");
	return arr[idx];
}

template<typename T, int max_size>
int Container<T*, max_size>::find_elem(T x) const
{
	for (int i = 0; i < count; i++)
		if (x == **(arr + i))
			return i;
	return -1;
}

template<typename T, int max_size>
void Container<T*, max_size>::add_elem(T x)
{
	if (is_full())
		throw std::out_of_range("Контейнер полный.\n");
	T* tmp = new T;
	*tmp = x;
	**(arr + count) = *tmp;
	delete tmp;
	count++;
}

template<typename T, int max_size>
void Container<T*, max_size>::delete_elem(T x)
{
	int idx = find_elem(x);
	if (idx == -1)
	{
		throw "Элемент не найден. \n";
	}
	delete arr[idx];
	arr[idx] = arr[count - 1];
	count--;

}

template<typename T, int max_size>
void Container<T*, max_size>::print()
{
	for (int i = 0; i < count; i++)
		std::cout << *(arr[i]) << " ";
	std::cout << "\n";
}

#endif 