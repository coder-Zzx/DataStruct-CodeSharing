#include<iostream>
using namespace std;
/* codede by zzx 1.1 */

int main()
{
    char s[100];
    gets(s);
    int i=0;
    while (s[i]!='\0')
    {
        if (s[i]=='x')
        {
            if (s[i+1]=='\0')
            {
                i+=1;
            }
            else
            {
                i+=2;
            }
        }
        else
        {
            cout<<s[i];
            i++;
        }
    }
    return 0;
}
