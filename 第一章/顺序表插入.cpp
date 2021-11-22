#include <iostream>
using namespace std;
/* coded by zzx 1.2 */

int main()
{
    char s[100];
    int p; 
    int n = 0;
    while (true)
    {
        cin>>s[n];
        if (cin.get()=='\n')
        {
            break;
        }
        n++;
    }
    n++;
    cin >> p;
    while (true)
    {
        if (n == p - 1)
        {
            break;
        }
        s[n] = s[n - 1];
        n--;
    }
    s[n] = 'x';
    for (int j = 0; s[j] != '\0'; j++)
    {
        cout << s[j] << " ";
    }
    return 0;
}
