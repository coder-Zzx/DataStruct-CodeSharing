## T11 盛最多水的容器
> 题目描述：
>> 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。   
>
> 算法设计思路：暴搜法   
> 核心代码：
 ```c++
    class Solution {
    public:
    int maxArea(vector<int>& height) {
        vector<bowl> s;
        for (int k=0;k<height.size();k++){
            bowl b=bowl(k+1,height[k]);
            s.push_back(b);
        }
        vector<int> result;
        for (int i=0;i<height.size();i++){
            for (int j=i;j<height.size();j++){
                int c=s[i].getCapacity(s[j]);
                result.push_back(c);
            }
        }
        return max(result);
    }
    };
```
>> 不足：
>> 1. 时间复杂度O($n^2$)，对于大规模输入会超时。
>> 2. 没有非法输入的处理 

> 优化方法：动态规划与贪心，时间复杂度为O($n$)   
>> 思路描述：两个指针分别指向头和尾，此时底是最大的，此时移动指针，如果想要继续增加，则一定是让height更小的那个指针左移或右移，放弃掉较小的那条高已获得有更高的高的机会。   
> 贪心的体现：再选取新的高的时候循环判断一直找到比上一次较大的高更高的点时才进行计算。   
> 
> 核心代码：
```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1){
            return -1;
        }
        int i = 0,
            j = height.size()-1,
            h = min(height[i],height[j]),(),
            res = (j - i) * h;
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
        }
        return res;
    }
};
```
***
## T913
> 有数学知识盲区，先空着等我学习学习

***

## T940 不同的子序列II
> 题目描述
>> 给定一个字符串 s，计算 s 的 不同非空子序列 的个数。因为结果可能很大，所以返回答案需要对 10^9 + 7 取余 。   
>
> 思路描述：涉及到子字符串的问题则使用动态规划   
>> 设前i个字符有dp[i]个字符串（考虑空字符串），则  
>> 1. dp[0]=1 
>> 1. 第i+1个字符不重复时，dp[i+1]=2*dp[i],
>> 1. 用last[x]表示字符x上一次出现的位置，dp[i+1]=2*dp[i]-dp[last[i]] 
>   
> 代码如下：

```c++
class Solution {
public:
    int distinctSubseqII(string s){
        int n=s.size(),
            MOD=1000000007;
        if (n==0){
            return 0;
        }
        vector<int> dp(n+1);
        vector<int> last(26,-1);
        dp[0]=1;
        int i=1;
        for (int i=0;i<n;i++){
            dp[i+1]=dp[i]*2%MOD;
            if (last[s[i]-'a']>=0){
                dp[i+1]-=dp[last[s[i]-'a']];
            }
            dp[i+1]%=MOD;
            last[s[i]-'a']=i;
        }
        return (dp[n]-1+MOD)%MOD;
    }
};
```
> 这题超越了100%，不用优化

***

## T1688 比赛中的配对次数
> 题目描述
>> 给你一个整数 n ，表示比赛中的队伍数。比赛遵循一种独特的赛制：    
>> 1.如果当前队伍数是 偶数 ，那么每支队伍都会与另一支队伍配对。总共进行 n / 2 场比赛，且产生 n / 2 支队伍进入下一轮。    
>> 2.如果当前队伍数为 奇数 ，那么将会随机轮空并晋级一支队伍，其余的队伍配对。总共进行 (n - 1) / 2 场比赛，且产生 (n - 1) / 2 + 1 支队伍进入下一轮.   
>> 返回在比赛中进行的配对次数，直到决出获胜队伍为止。   
>> 决出冠军需要淘汰n-1个队伍，每配对一次淘汰一个队伍，所以就是n-1次配对   
> 代码如下：

```c++
class Solution {
public:
    int numberOfMatches(int n){
        // int result=0;
        // while (n!=1){
        //     if (n%2==0){
        //         n=n/2;
        //         result+=n;
        //     }
        //     else{
        //         n=n/2+1;
        //         result+=n-1;
        //     }
        // }
        return n-1;
    }
};
```
> 这题难度简单，我也超越了100%，我就不多说了。
