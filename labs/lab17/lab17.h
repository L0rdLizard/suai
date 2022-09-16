#include <iostream>
#include <ostream>

struct point
{
    int x;
    int y;
    int z;

    friend std::ostream& operator<<(std::ostream& os, const point& p)
    {
        os << p.x << ", " << p.y << ", " << p.z;
        return os;
    }
};

// class vector(size_t size, const T& value) on template type T using new delete declarations function push_back, erase(size_t i) (trow exception), at (trow exception), size, operator[], insert(size_t i, const T& value) (trow exception), 
template <typename T>
class vector
{
    public:
        vector(size_t size, const T& value);
        ~vector();
        void push_back(const T& value);
        void erase(size_t i);
        T& at(size_t i);
        size_t size();
        T& operator[](size_t i);
        void insert(size_t i, const T& value);
    private:
        T* data;
        size_t size_p;
};

template <typename T>
vector<T>::vector(size_t size, const T& value)
{
    size_p = size;
    data = new T[size];
    for (size_t i = 0; i < size; i++)
    {
        data[i] = value;
    }
}

template <typename T>
vector<T>::~vector()
{
    delete[] data;
}

template <typename T>
void vector<T>::push_back(const T& value)
{
    T* temp = new T[size_p + 1];
    for (size_t i = 0; i < size_p; i++)
    {
        temp[i] = data[i];
    }
    temp[size_p] = value;
    delete[] data;
    data = temp;
    size_p++;
}

template <typename T>
void vector<T>::erase(size_t i)
{
    if (i >= size_p)
    {
        throw std::out_of_range("Out of range");
    }
    T* temp = new T[size_p - 1];
    for (size_t j = 0; j < i; j++)
    {
        temp[j] = data[j];
    }
    for (size_t j = i; j < size_p - 1; j++)
    {
        temp[j] = data[j + 1];
    }
    delete[] data;
    data = temp;
    size_p--;
}

template <typename T>
T& vector<T>::at(size_t i)
{
    if (i >= size_p)
    {
        throw std::out_of_range("Out of range");
    }
    return data[i];
}

template <typename T>
size_t vector<T>::size()
{
    return size_p;
}

template <typename T>
T& vector<T>::operator[](size_t i)
{
    return data[i];
}

template <typename T>
void vector<T>::insert(size_t i, const T& value)
{
    if (i >= size_p)
    {
        throw std::out_of_range("Out of range");
    }
    T* temp = new T[size_p + 1];
    for (size_t j = 0; j < i; j++)
    {
        temp[j] = data[j];
    }
    temp[i] = value;
    for (size_t j = i + 1; j < size_p + 1; j++)
    {
        temp[j] = data[j - 1];
    }
    delete[] data;
    data = temp;
    size_p++;
}



    
