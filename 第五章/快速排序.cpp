#include <iostream>
using namespace std;
int j = 1;

void quickSort(int arr[], int low, int high)
{
    int first = low;
    int last = high;
    int key = arr[first];
    if (low >= high)
        return;
    while (first < last)
    {
        while (first < last && arr[last] > key)
        {
            last--;
        }
        arr[first] = arr[last];

        while (first < last && arr[first] < key)
        {
            first++;
        }
        arr[last] = arr[first];
    }
    arr[first] = key;
    int i;
    if (j <= 6)
    {
        for (i = 0; i < 12; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        j++;
        quickSort(arr, low, first - 1);
        quickSort(arr, first + 1, high);
    }
}

int main()
{
    int length = 0;
    int x;
    int a[20];
    while (cin >> x)
    {
        a[length++] = x;
    }
    quickSort(a, 0, length - 1);
    return 0;
}
