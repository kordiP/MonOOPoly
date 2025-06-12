/*
    Atanas Kordov, 5MI0600508
*/

#include "../../Headers/Utilities/MyString.h"

void MyString::freeMem()
{
    delete[] str;
    str = nullptr;
}

void MyString::copyFrom(const MyString& other)
{
    size = other.size;
    str = new char[size + 1];
    strcpy_s(str, size + 1, other.str);
    str[size] = '\0';
}

MyString::MyString() :str(nullptr), size(0) {}

MyString::MyString(const char* strn)
{
    if (strn == nullptr)
    {
        throw std::invalid_argument("Cannot create string with nullptr.");
    }

    size = strlen(strn);
    str = new char[size + 1];
    strcpy_s(str, size + 1, strn);
    str[size] = '\0';
}

MyString::MyString(const MyString& other)
{
    copyFrom(other);
}

const char* MyString::c_str() const
{
    return str;
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        freeMem();
        copyFrom(other);
    }

    return *this;
}

MyString::~MyString()
{
    freeMem();
}

MyString::MyString(MyString&& other) noexcept
{
    str = other.str;
    other.str = nullptr;

    size = other.size;
    other.size = 0;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
    if (this != &other)
    {
        freeMem();

        str = other.str;
        other.str = nullptr;

        size = other.size;
        other.size = 0;
    }
    return *this;
}

const char& MyString::operator[](int index) const
{
    if (index < 0 || index > size)
    {
        throw std::out_of_range("Index not in range.");
    }

    return str[index];
}

char& MyString::operator[](int index)
{
    if (index < 0 || index > size)
    {
        throw std::out_of_range("Index not in range.");
    }

    return str[index];
}

MyString& MyString::operator+=(const MyString& mstr)
{
    size_t finalSize = size + mstr.size;
    MyString tmp(*this);

    size = finalSize;
    str = new char[size + 1];

    strcpy_s(str, size + 1, tmp.str);
    strcat_s(str, size + 1, mstr.str);
    str[size] = '\0';

    return *this;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
    if (strcmp(lhs.c_str(), rhs.c_str()) != 0)
    {
        return false;
    }

    return true;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
    if (strcmp(lhs.c_str(), rhs.c_str()) > 0)
    {
        return false;
    }

    return true;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
    return rhs < lhs;
}

bool operator >=(const MyString& lhs, const MyString& rhs)
{
    return !(lhs > rhs);
}

bool operator <=(const MyString & lhs, const MyString & rhs)
{
    return !(rhs < lhs);
}

size_t MyString::find(char symbol, size_t skip) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (str[i] == symbol)
        {
            if (skip > 0)
            {
                skip--;
                continue;
            }
            return i;
        }
    }
    return -1;
}

MyString MyString::substring(size_t start, size_t length) const
{
    if (start >= this->size)
        return MyString();

    if (start + length > this->size || length == 0)
        length = this->size - start;

    MyString result;
    result.size = length;
    result.str = new char[length + 1];

    for (size_t i = 0; i < length; ++i)
    {
        result.str[i] = this->str[start + i];
    }
    result.str[length] = '\0';

    return result;
}

std::ostream& operator<<(std::ostream& os, const MyString& mstr)
{
    os << mstr.str;
    return os;
}

std::istream& operator>>(std::istream& is, MyString& mstr)
{
    const int bSize = 1024;
    char buff[bSize];
    
    is >> buff;
    delete[] mstr.str;

    mstr.size = strlen(buff);
    mstr.str = new char[mstr.size + 1];
    strcpy_s(mstr.str, (mstr.size) + 1, buff);
    mstr.str[mstr.size] = '\0';

    return is;
}

std::istream& getline(std::istream& is, MyString& mstr)
{
    const int bSize = 1024;
    char buff[bSize];

    is.getline(buff, bSize);
    delete[] mstr.str;

    mstr.size = strlen(buff);
    mstr.str = new char[mstr.size + 1];
    strcpy_s(mstr.str, mstr.size + 1, buff);

    return is;
}

MyString operator+(const MyString& lhs, char sym)
{
    size_t newLen = lhs.size + 1;
    char* newData = new char[newLen + 1];

    for (size_t i = 0; i < lhs.size; i++)
        newData[i] = lhs.str[i];

    newData[newLen - 1] = sym;
    newData[newLen] = '\0';

    MyString result(newData);
    delete[] newData;
    return result;
}

MyString operator+(char sym, const MyString& lhs)
{
    size_t newLen = lhs.size + 1;
    char* newData = new char[newLen + 1];

    newData[0] = sym;
    for (size_t i = 1; i < newLen; i++)
        newData[i] = lhs.str[i - 1];

    newData[newLen] = '\0';

    MyString result(newData);
    delete[] newData;
    return result;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    MyString fin(lhs);
    fin += rhs;
    return rhs;
}
