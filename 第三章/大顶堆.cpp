#include <iostream>
using namespace std;
/* coded by zzx 3.4 */

class MaxHeap
{
private:
    int *data;
    int size;

public:
    MaxHeap()
    {
        this->data = new int[100];
        this->size = 0;
        this->data[0] = 1000000;
    }
    void Create(int *data, int n);
    void Predown(int n);
    void Print();
};

void MaxHeap::Create(int *data, int n)
{
    for (int i = 0; i < n; i++)
    {
        this->data[++size] = data[i];
    }
    for (int i = this->size / 2; i > 0; i--)
    {
        this->Predown(i);
    }
}

void MaxHeap::Predown(int n)
{
    int x = this->data[n];
    int parent, child;
    for (parent = n; parent * 2 <= this->size; parent = child)
    {
        child = parent * 2;
        if ((child != this->size) && this->data[child] < this->data[child + 1])
        {
            child++;
        }
        if (x >= this->data[child])
        {
            break;
        }
        else
        {
            this->data[parent] = this->data[child];
        }
    }
    this->data[parent] = x;
}

void MaxHeap::Print()
{
    for (int i = 1; i <= this->size; i++)
    {
        cout << this->data[i] << " ";
    }
}

int main()
{
    int *data = new int[100];
    string input[100];
    int size = 0;
    int a;
    while (cin>>a)
    {
        data[size++]=a;
    }
    MaxHeap maxheap = MaxHeap();
    maxheap.Create(data, size);
    maxheap.Print();
    return 0;
}
