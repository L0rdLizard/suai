#include <iostream>
#include <ostream>
#include <fstream>
#include "yaml-cpp/yaml.h"

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

void operator << (YAML::Emitter& out, const point& p)
{
    out << YAML::BeginMap;
    out << YAML::Key << "x" << YAML::Value << p.x;
    out << YAML::Key << "y" << YAML::Value << p.y;
    out << YAML::Key << "z" << YAML::Value << p.z;
    out << YAML::EndMap;
}


template <typename T>
class vector_t
{
    public:
        vector_t(size_t size, const T& value);
        ~vector_t();
        void push_back(const T& value);
        void erase(size_t i);
        T& at(size_t i);
        size_t size();
        T& operator[](size_t i);
        void insert(size_t i, const T& value);
        void saveyaml(const std::string& filename);
        void loadyaml(const std::string& filename);
    private:
        T* data;
        size_t size_p;
};

template <typename T>
vector_t<T>::vector_t(size_t size, const T& value)
{
    size_p = size;
    data = new T[size];
    for (size_t i = 0; i < size; i++)
    {
        data[i] = value;
    }
}

template <typename T>
vector_t<T>::~vector_t()
{
    delete[] data;
}

template <typename T>
void vector_t<T>::push_back(const T& value)
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
void vector_t<T>::erase(size_t i)
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
T& vector_t<T>::at(size_t i)
{
    if (i >= size_p)
    {
        throw std::out_of_range("Out of range");
    }
    return data[i];
}

template <typename T>
size_t vector_t<T>::size()
{
    return size_p;
}

template <typename T>
T& vector_t<T>::operator[](size_t i)
{
    return data[i];
}

template <typename T>
void vector_t<T>::insert(size_t i, const T& value)
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

template <typename T>
void vector_t<T>::saveyaml(const std::string& filename)
{
    YAML::Emitter out;
    out << YAML::BeginSeq;
    for (size_t i = 0; i < size_p; i++)
    {
        out << data[i];
    }
    out << YAML::EndSeq;
    std::ofstream fout(filename);
    fout << out.c_str();
}

template <typename T>
void vector_t<T>::loadyaml(const std::string& filename)
{
    YAML::Node node = YAML::LoadFile(filename);
    size_p = node.size();
    data = new T[size_p];
    for (size_t i = 0; i < size_p; i++)
    {
        data[i] = node[i].as<T>();
    }
}



    
