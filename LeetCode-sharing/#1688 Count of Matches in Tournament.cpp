class Solution {
public:
    int numberOfMatches(int n){
        int result=0;
        while (n!=1){
            if (n%2==0){
                n=n/2;
                result+=n;
            }
            else{
                n=n/2+1;
                result+=n-1;
            }
        }
        return result;
    }
};
