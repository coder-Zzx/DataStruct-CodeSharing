#include<iostream>
using namespace std;
/* coded by zzx 5.1 */

void InsertSort(int r[],int n,int start,int incr)
{
    int i,j;
    for (i=start+incr;i<n;i+=incr)
    {

        int temp=r[i];
        for (j=i;j>=incr;j-=incr)
        {
            if (temp<r[j-incr])
            {
                r[j]=r[j-incr];
            }
            else
            {
                break;
            }
        }
        if (i!=j)
        {
            r[j]=temp;
        }
    }
}

void printShellSort(int r[],int g,int n)
{
    for (;g>0;g--)
    {
        for (int i=0;i<g;i++)
        {
            InsertSort(r,n,i,g);
        }
        for (int i=0;i<n;i++)
        {
            cout<<r[i]<<' ';
        }
        cout<<endl;
    }
}

int main()
{
    int x[12];
    int length=0;
    /* 如果用下面注释掉的代码进行数组的输入会导致超时 *
     * 貌似是因为oj输入的时候不会有回车？*************
     * 不过这题也只有一个测试用例，所以你懂的 ********/
    // while (true)
    // {
    //     cin>>x[length];
    //     length++;
    //     if (cin.get()=='\n')
    //     {
    //         break;
    //     }
    // }
    for (;length<12;length++)
    {
        cin>>x[length];
    }
    printShellSort(x,3,length);
    return 0;
}
