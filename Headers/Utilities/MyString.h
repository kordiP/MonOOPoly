#pragma once
#include <iostream>

class MyString
{
private:
	char* str;
	size_t size;

	void freeMem();
	void copyFrom(const MyString& other);
public:
	MyString();
	MyString(const char* strn);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;

	const char& operator[](int index) const;
	char& operator[](int index);

	MyString& operator+=(const MyString& mstr);
	MyString& operator+=(int number);
	MyString& operator+=(char c);

	friend std::ostream& operator<<(std::ostream& os, const MyString& mstr);
	friend std::istream& operator>>(std::istream& is, MyString& mstr);
	friend std::istream& getline(std::istream& is, MyString& mstr);

	size_t find(char symbol, size_t skip = 0) const;
	MyString substring(size_t start, size_t length = 0) const;

	friend MyString operator+(const MyString& lhs, char sym);
	friend MyString operator+(char sym, const MyString& lhs);

	const char* c_str() const;
};

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);

bool operator<(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);

MyString operator+(const MyString& lhs, const MyString& rhs);