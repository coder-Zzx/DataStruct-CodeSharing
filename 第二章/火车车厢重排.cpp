#include<iostream>
#include<queue>
#include<stack>
using namespace std;
/* coded by zzx 2.3 */
/* 注意中文编码 貌似是GBK2312？ */

int main()
{
    int length=0,
        nowOut=1;
    int a;
    int h=3;
    queue<int> bufferRail[h];	
    stack<int> inRail;			//注意书写形式与输出形式的差别，
    stack<int> outRail;			//输出和输出轨实际上都是栈。
    while (cin>>a)
    {
        inRail.push(a);
    }
    while (!inRail.empty())
    {
        if (inRail.top()==nowOut)
        {
	    	//如果输入轨第一个车厢直接符合要求
            outRail.push(inRail.top());
            inRail.pop();
            nowOut++;
        }
        else
        {
            for (int i=0;i<h;i++)
            {
				//依次检查个缓冲轨是否有空轨或符合输入要求的轨道
                if (bufferRail[i].empty()||inRail.top()>bufferRail[i].back())
                {
                    bufferRail[i].push(inRail.top());
                    inRail.pop();
                    break;
                }
                if (i==h-1)
                {
					//查找到最后一个缓冲轨仍无符合要求的
                    cout<<"重排失败"<<endl;
                    return 0;
                }
            }
        }
        for (int i=0;i<h;i++)
        {
			//对缓冲轨依次检查是否符合输出要求
            if (!bufferRail[i].empty()&&bufferRail[i].front()==nowOut)
            {
                outRail.push(bufferRail[i].front());
                bufferRail[i].pop();
                nowOut++;
            }
        }
    }
    while (!outRail.empty())
    {
        cout<<outRail.top()<<" ";
        outRail.pop();
    }
    return 0;
}
