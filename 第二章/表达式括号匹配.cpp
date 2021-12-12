#include <iostream>
#include <stack>
#define MAX_SIZE 100
using namespace std;
/* coded by zzx 2.1 */

char left[3] = {'(', '[', '{'};
char right[3] = {')', ']', '}'};

int len(char *s)
{
    int i;
    char *p = s;
    for (; s[i] != '\0'; i++)
        ;
    return i;
}

int main()
{

    char left[3] = {'(', '[', '{'};
    char right[3] = {')', ']', '}'};
    stack<char> s;
    char i[100];
    char a;
    int l = 0;
    int k,j;
    while (cin>>a)
    {
        i[l++] = a;
    }
    for (j = 0; j < l; j++)
    {
        if (i[j] == '(' || i[j] == '[' || i[j] == '{')
        {
            s.push(i[j]);
        }
        else
        {
            if (i[j]==')'||i[j]==']'||i[j]=='}')
            {
                for (k=0;right[k]!=i[j];k++);
                if (!s.empty()&&left[k]==s.top())
                {
                    s.pop();
                }
                else break;
            }
        }
    }
    if (s.empty()&&j==l)
    {
        cout << "匹配成功" << endl;
    }
    else
    {
        if (s.empty())
        {
            cout<<"缺少"<<left[k]<<"括号"<<endl;
        }
        else
        {
            if (j==l)
            {
                cout<<"缺少"<<right[k+1]<<"括号"<<endl;
            }
        }
    }
    return 0;
}
