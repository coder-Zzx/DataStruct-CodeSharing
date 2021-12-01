#include <iostream>
using namespace std;

int main()
{
    int num,
        i,
        killed = 0,
        s = 0,
        t = 0;
    cin>>num;
    if (num==2)
    {
        cout<<"1 2";
        return 0;
    }
    int sur[num + 1];
    for (int i = 0; i <= num; i++)
    {
        sur[i] = 1;
    }
    do
    {
        ++t;
        if (t > num)
        {
            t = 1;
        }
        if (sur[t] == 1)
        {
            s++;
        }
        if (s == 3)
        {
            s = 0;
            sur[t] = 0;
            killed++;
        }
    } while (num - killed > 2);
    for (int j = 1; j < num; j++)
    {
        if (sur[j] == 1)
            cout<<j<<" ";
    }
}
