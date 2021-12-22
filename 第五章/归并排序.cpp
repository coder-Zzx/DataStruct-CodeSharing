#include <iostream>
using namespace std;
/* 5.2 归并排序 */
 
int anser[5][20];
int sort_floor=-1;

void merge(int data[], int s, int middle, int t,int depth)
{
    int i = s, 
        j = middle+1,
        k = s;
    int d[20];
    while (i <= middle && j <= t)
    {
        if (data[i] <= data[j])
        {
            d[k] = data[i];
            k++;
            i++;
        }
        else
        {
            d[k] = data[j];
            k++;
            j++;
        }
    }
    while (i <= middle)
    {
        d[k] = data[i];
        k++;
        i++;
    }
    while (j <= t)
    {
        d[k] = data[j];
        k++;
        j++;
    }
    for (i = s;i <= t;i++)
    {
        anser[depth][i] = d[i];
        data[i] = d[i];
    }
    if (sort_floor < depth)
    {
        sort_floor = depth;
    }
}
 
 
 
 
 
void Msort(int data[], int s, int t,int depth)
{
    int middle;
    middle = (s + t - 1) / 2; //
    if (s == t)
    {
        anser[depth][s] = data[s];
    }
    else
    {
        Msort(data, s, middle, depth + 1);
        Msort(data, middle + 1, t, depth + 1);
        merge(data, s, middle, t, depth);
    }
}
 
 
int main()
{
    int j = 0, t = 0;
    int a[20];
    char b;
    int x,
        length=0;
    while (cin>>x)
    {
        a[length++]=x;
    }
    Msort(a, 0, length, 0);
    for (j = sort_floor;j >= 0;j--)
    {
        for (t = 0;t < length;t++)
        {
            cout<<anser[j][t]<<" ";
        }
        if (j>0)
        {
            cout<<endl;
        }
    }
    return 0;
}
 
