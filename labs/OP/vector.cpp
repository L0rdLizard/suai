#include <iostream>
#include <ostream>
using namespace std;

class vector_t
{
private:
    int *data;
    size_t size;

public:
    vector_t(size_t size)
    {
        this->size = size;
        data = (int *)malloc(sizeof(int) * size);
    }

    vector_t(vector_t &a)
    {
        size = a.size;
        data = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++)
            data[i] = a.data[i];
    }

    vector_t &operator=(vector_t &v)
    {
        if (&v == this)
            return *this;
        free(data);
        size = v.size;
        data = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++)
            data[i] = v.data[i];
    }

    int &operator[](size_t index)
    {
        return data[index];
    }

    friend ostream &operator<<(ostream &os, const vector_t &v)
    {
        for (int i = 0; i < v.size; i++)
            os << v.data[i] << " ";
        return os;
    }

    void push_back(int n)
    {
        size++;
        data = (int*)realloc(data, sizeof(int)*size);
        data[size - 1] = n;
    }

    ~vector_t()
    {
        free(data);
    }
};

int main()
{
    vector_t abc(3);
    abc[0] = 1;
    abc[1] = 2;
    abc[2] = 3;
    abc.push_back(4);
    cout << abc << endl;
    return 0;
}