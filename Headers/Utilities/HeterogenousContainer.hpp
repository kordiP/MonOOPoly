#pragma once
#include <iostream>

template <class T>
class HeterogeneousContainer {
private:
	T** data = nullptr;
	size_t size = 0;
	size_t capacity = 4;

	void resize();

	void copyFrom(const HeterogeneousContainer& other);
	void moveFrom(HeterogeneousContainer&& other) noexcept;
	void freeMem();
public:
	HeterogeneousContainer();
	HeterogeneousContainer(const HeterogeneousContainer& other);
	HeterogeneousContainer(HeterogeneousContainer&& other) noexcept;

	HeterogeneousContainer<T>& operator=(const HeterogeneousContainer& other);
	HeterogeneousContainer<T>& operator=(HeterogeneousContainer&& other) noexcept;
	~HeterogeneousContainer();

	void pushBack(const T& obj);
	void pushBack(T* obj);
	void removeAt(size_t index);

	size_t getSize() const;

	const T* operator[](size_t index) const;
	T* operator[](size_t index);
	void swap(size_t pos1, size_t pos2);
};

template<class T>
size_t HeterogeneousContainer<T>::getSize() const
{
	return size;
}

template<class T>
void HeterogeneousContainer<T>::removeAt(size_t index)
{
	if (index >= size) 
	{
		throw std::out_of_range("Invalid index.");
	}

	delete data[index];

	for (int i = index; i < size - 1; i++)
	{
		data[i] = data[i + 1];
	}

	data[size - 1] = nullptr;
	size--;
}

template<class T>
const T* HeterogeneousContainer<T>::operator[](size_t index) const
{
	if (index >= size) 
	{
		throw std::invalid_argument("Invalid index");
	}

	return data[index];
}

template<class T>
T* HeterogeneousContainer<T>::operator[](size_t index)
{
	if (index >= size)
	{
		throw std::invalid_argument("Invalid index");
	}

	return data[index];
}

template<class T>
void HeterogeneousContainer<T>::swap(size_t pos1, size_t pos2)
{
	std::swap(data[pos1], data[pos2]);
}

template<class T>
HeterogeneousContainer<T>::~HeterogeneousContainer()
{
	freeMem();
}

template<class T>
void HeterogeneousContainer<T>::resize()
{
	capacity *= 2;
	T** tmp = new T* [newCap];

	for (int i = 0; i < size; i++)
	{
		tmp[i] = data[i];
	}

	delete[] data;
	data = temp;
}

template<class T>
void HeterogeneousContainer<T>::copyFrom(const HeterogeneousContainer& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new T* [capacity];

	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i]->clone();
	}
}

template<class T>
void HeterogeneousContainer<T>::moveFrom(HeterogeneousContainer&& other) noexcept
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;
}

template<class T>
void HeterogeneousContainer<T>::freeMem()
{
	for (int i = 0; i < size; i++)
	{
		delete data[i];
	}

	delete[] data;
}

template<class T>
HeterogeneousContainer<T>::HeterogeneousContainer()
{
	data = new T* [capacity];
}

template<class T>
HeterogeneousContainer<T>::HeterogeneousContainer(const HeterogeneousContainer& other)
{
	copyFrom(other);
}

template<class T>
HeterogeneousContainer<T>::HeterogeneousContainer(HeterogeneousContainer&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
HeterogeneousContainer<T>& HeterogeneousContainer<T>::operator=(const HeterogeneousContainer& other)
{
	if (this != &other) 
	{
		freeMem();
		copyFrom(other);
	}

	return *this;
}

template<class T>
HeterogeneousContainer<T>& HeterogeneousContainer<T>::operator=(HeterogeneousContainer&& other) noexcept
{
	if (this != &other) 
	{
		freeMem();
		moveFrom(std::move(other));
	}

	return *this;
}

template<class T>
void HeterogeneousContainer<T>::pushBack(const T& obj)
{
	if (size + 1 >= capacity) 
	{
		resize();
	}

	data[size++] = obj.clone();
}

template<class T>
void HeterogeneousContainer<T>::pushBack(T* ptr)
{
	if (ptr == nullptr) 
	{
		throw std::invalid_argument("Null pointer invalid.");
	}

	if (size + 1 >= capacity) 
	{
		resize();
	}

	data[size++] = ptr;
}