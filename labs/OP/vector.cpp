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
        // data = (int*)realloc(data, sizeof(int)*size);
        int *cur_data = (int *)malloc(sizeof(int) * size);
        cur_data[0] = n;
        for (int i = 0; i < size - 1; i++)
            cur_data[i] = data[i];
        free(data);
        data = cur_data;
        data[size - 1] = n;
    }

    void push_front(int n)
    {
        size++;
        int *cur_data = (int *)malloc(sizeof(int) * size);
        for (int i = 1; i < size; i++)
            cur_data[i] = data[i - 1];
        free(data);
        data = cur_data;
        data[0] = n;
    }

    void erase(int n, int pos)
    {
        size++;
        int *cur_data = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < pos; i++)
            cur_data[i] = data[i];
        cur_data[pos] = n;
        for (int i = pos + 1; i < size; i++)
            cur_data[i] = data[i - 1];
        free(data);
        data = cur_data;
    }

    ~vector_t()
    {
        free(data);
    }
};
// Нася тут была (Люблю Максю)
int main()
{
    // int mass[] = {1, 2, 3};
    // mass[5] = 10;
    vector_t abc(3);
    abc[0] = 1;
    abc[1] = 2;
    abc[2] = 3;
    abc.erase(6, 2);
    abc.push_back(6);
    abc.push_front(6);
    cout << abc << endl;
    return 0;
}
// Тю <3