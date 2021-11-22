#include<iostream>
#include<vector>
#include<stack>
#include<deque>
#include<iterator>
#include<algorithm>
using namespace std;
 /* coded by zzx 2.3 */
 
//辅函数：更新缓冲铁轨上的min_buf、min_tra
void updata(vector<stack<int>> & tracks_buf,int & min_buf,int & min_tra)
{
	for (int i = 0;i<tracks_buf.size();i++)
	{
		if(!tracks_buf[i].empty() && min_buf>tracks_buf[i].top())
		{
			min_buf = tracks_buf[i].top();
			min_tra = i;
		}
	}
}
//辅函数：将车厢移到缓冲铁轨上
bool trans(int n,int d,vector<stack<int>> & tracks_buf,int & min_buf,int & min_tra)
{
	//先查找最优缓冲铁轨
	int min_gap = n+1;//d与个缓冲铁轨顶端上大于的车厢与d之间的最小间隔
	int prefer_track = -1;//最优铁轨
	for (int i = 0;i<tracks_buf.size();i++)
	{
		if (!tracks_buf[i].empty() && tracks_buf[i].top()>d && (tracks_buf[i].top()-d)<min_gap)
		{
			min_gap = tracks_buf[i].top()-d;
			prefer_track = i;
		}
	}
	if(-1!=prefer_track)//找到最优缓冲铁轨
	{
		tracks_buf[prefer_track].push(d);
		updata(tracks_buf,min_buf,min_tra);
		return true;
	}
	else
	{
		//再查找是否存在空铁轨
		for (int i = 0;i<tracks_buf.size();i++)
		{
			if(tracks_buf[i].empty())
			{
				tracks_buf[i].push(d);
				updata(tracks_buf,min_buf,min_tra);
				return true;
			}
		}
		//否则返回false;
		return false;
	}
}
 
/*  火车车厢重排问题
*	datas：火车车厢在入轨上时的序列
*   n : 火车车厢的总节数
*	k ：缓冲铁轨的条数
*/
//主要函数
bool fun(vector<int> &datas,deque<int> & results,int n,int k)
{
	int min_buf = n+1;//缓冲铁轨上最小的车厢号
	int min_tra = 0;//最小的车厢所在的缓冲铁轨编号
	vector<stack<int>> tracks_buf(k);//缓冲铁轨数组
 
	int need = 1;//出轨处需要挂上的车厢号
	while (!datas.empty())
	{
		int d = datas.back();
		datas.pop_back();
		if (d==need)//符合要求直接移到出轨
		{
			results.push_front(need);
			need++;
			//再到缓冲铁轨中查找是否有下一个符合的车厢
			while(min_buf == need)//找到
			{
				results.push_front(need);
				need++;
				//移除缓冲铁轨
				tracks_buf[min_tra].pop();
				//更新min_buf、min_tra
				min_buf = n+2;
				min_tra = 0;
				updata(tracks_buf,min_buf,min_tra);
			}
		}
		else//不符合要求移到缓冲铁轨上
		{
			if(!trans(n,d,tracks_buf,min_buf,min_tra))
			{
				return false;
			}
		}
	}
		return true;
}
int main()
{
	// int array[] = {4,2,1,3,5};
    int array[5];
    for (int y=0;y<5;y++)
    {
        cin>>array[y];
    }
	deque<int> results;
	vector<int> vec(array,array+sizeof(array)/sizeof(array[0]));
	int n = vec.size();
	int k = 3;//3条缓冲铁轨
 
	if (fun(vec,results,n,k))
	{
		// cout<<k<<"条缓冲铁轨可以将按照";
		copy(vec.begin(),vec.end(),ostream_iterator<int>(cout));
		// cout<<"此序列的"<<n<<"节车厢重新排好挂到火车头上。"<<endl;
		// cout<<"排好后的序列是："<<endl;
		// copy(results.begin(),results.end(),ostream_iterator<int>(cout));
        for(deque<int>::const_iterator it=results.begin();it!=results.end();it++)
        {
            cout<<*it<<" ";
        }
		cout<<endl;
	}
	else
	{
		cout<<"重排失败"<<endl;
	}
}
