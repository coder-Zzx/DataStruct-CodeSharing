#include <iostream>
using namespace std;
/* coded by zzx 2.4 */

int len(char *p)
{
    int n=0;
    for (;*(p+n)!='\0';n++);
    return n;
}
void cal_next(char *str, int *next, int len)
{
    // int len = strlen(a); ///先求字符串的长度，便于循环赋值
    int i = 0, j = -1;
    next[0] = -1;
    while (i < len)
    {
        if (j == -1 || str[i] == str[j])
        {
            next[++i] = ++j;
        }
        else
            j = next[j];
    }
}
int KMP(char *str, int slen, char *ptr, int plen)
{
    int *next = new int[plen];
    cal_next(ptr, next, plen);
    int k = -1;
    for (int i = 0; i < slen; i++)
    {
        while (k > -1 && ptr[k + 1] != str[i])
            k = next[k];
        if (ptr[k + 1] == str[i])
            k = k + 1;
        if (k == plen - 1)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    char s[20] = {'a','b','a','a','b','a','c','a','b','a','b','d','e','a','d','c','d','e'};
    // char *str=s;
    // char *ptr;
    char in[15];
    cin>>in;
    // char *p=in;
    int slen = len(s);
    int plen = len(in);
    int a = KMP(s, slen, in, plen);
    if (a)
    {
        cout << "匹配成功" << endl;
    }
    else
    {
        cout << "匹配未成功" << endl;
    }
    int n[plen];
    // int *next = n;
    cal_next(in, n, plen);
    for (int i = 0; i < plen; i++)
    {
        cout << n[i];
    }
    return 0;
}
