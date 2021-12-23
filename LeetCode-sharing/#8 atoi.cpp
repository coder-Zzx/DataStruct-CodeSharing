class Solution {
public:
    int myAtoi(string s) {
      int flag=1;
      int i=0;
      long sum=0;
      while (s[i]==' ')
      {
        i++;
      }
      if (s[i]=='-')
      {
        flag=-1;
      }
      if (s[i]=='+'||s[i]=='-')
      {
        i++;
      }
      while (i<s.size()&&isdigit(s[i]))
      {
        int bit=(int)(s[i]-48);
        if (sum>INT_MAX/10||(sum==INT_MAX/10&&bit>7))
        {
          return flag>0?pow(2,31)-1:-pow(2,31);
        }
        sum=sum*10+bit;
        i++;
      }
      return flag*sum;
    }
};
