#pragma once
#include <iostream>

template <typename T>
class Stack
{
private:
	T** data; 
	size_t size; 
	size_t capacity; 

	void resize();

	void copyFrom(const Stack& other);
	void moveFrom(Stack&& other);
	void freeMem();

public:
	Stack();
	Stack(size_t capacity);

	Stack(const Stack& other);
	Stack& operator=(const Stack& other);

	Stack(Stack&& other) noexcept;
	Stack& operator=(Stack&& other) noexcept;

	size_t getSize() const;

	Stack& push(const T& elem);
	Stack& push(T&& elem);
	Stack& pop();
	T* popToBottom();

	const T& top() const;

	~Stack() noexcept;
};

template<typename T>
Stack<T>::Stack() : Stack(4)
{
}

template<typename T>
Stack<T>::Stack(size_t capacity) : size(0)
{
	this->capacity = capacity;
	data = new T*[this->capacity];
}

template<typename T>
Stack<T>::Stack(const Stack& other)
{
	copyFrom(other);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this != &other)
	{
		freeMem();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
Stack<T>::Stack(Stack&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack&& other) noexcept
{
	if (this != &other)
	{
		freeMem();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
size_t Stack<T>::getSize() const
{
	return size;
}

template<typename T>
Stack<T>& Stack<T>::push(const T& elem)
{
	if (size >= capacity)
	{
		resize();
	}

	data[size++] = elem.clone();

	return *this;
}

template<typename T>
Stack<T>& Stack<T>::push(T&& elem)
{
	if (size >= capacity)
	{
		resize();
	}

	data[size++] = new T(std::move(elem));

	return *this;
}

template<typename T>
Stack<T>& Stack<T>::pop()
{
	if (size == 0)
	{
		return *this;
	}

	delete data[--size];
	data[size] = nullptr;

	return *this;
}

template<typename T>
T* Stack<T>::popToBottom()
{
	if (size == 0)
	{
		throw std::logic_error("Empty stack.");
	}

	T* el = data[size - 1];
	for (size_t i = size - 1; i > 0; i--)
	{
		data[i] = data[i - 1];
	}
	data[0] = el;

	return el;
}

template<typename T>
const T& Stack<T>::top() const
{
	return *data[size - 1];
}

template<typename T>
Stack<T>::~Stack() noexcept
{
	freeMem();
}

template<typename T>
void Stack<T>::resize()
{
	capacity *= 2;
	T** newData = new T*[capacity];

	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
}

template<typename T>
void Stack<T>::copyFrom(const Stack& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new T* [capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i]->clone();
	}
}

template<typename T>
void Stack<T>::moveFrom(Stack&& other)
{
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template<typename T>
void Stack<T>::freeMem()
{
	for (size_t i = 0; i < size; i++)
	{
		delete data[i];
	}

	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}