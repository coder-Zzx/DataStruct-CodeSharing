#include <iostream>
using namespace std;
/* coded by zzx 2.2 */

long long fab(int n)
{
    if (n==1 || n==0)
    {
        return 1;
    }
    else
    {
        return n*fab(n-1);
    }
}

long long C(int n,int m)
{
    return fab(n-1)/(fab(m-1)*fab(n-m));
}

int main()
{
    int line;
    cin>>line;
    if (line>=100)
    {
        cout<<"队列已满"<<endl;
    }
    else
    {
        for (int i=1;i<=line;i++)
        {
            cout<<C(line,i)<<' ';
        }
    } 
    return 0;
}
