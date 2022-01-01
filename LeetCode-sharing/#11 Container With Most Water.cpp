class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1){
            return -1;
        }
        int i = 0,
            j = height.size()-1,
            h = min(height[i],height[j]),
            // maxh = height.max(),
            res = (j - i) * h;
            // res = 0;
        while(i < j){
            if (height[i] < height[j]){
                while (i < j && height[i] <= h){
                    i++;
                }
            }
            else{
                while (i < j && height[j] <= h){
                    j--;
                }
            }
            h=min(height[i],height[j]);
            res=max(res,min(height[i],height[j]) * (j -i ));
            // if ()
        }
        return res;
    }
};
