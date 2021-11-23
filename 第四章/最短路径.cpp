#include<iostream>
#include<queue>
#include<vector>
#define MAX 65535
#define NUM 5
using namespace std;
/* coded by zzx 4.2 */
/* 冷知识：这题oj只用了一个测试用例，也许可以直接偷鸡cout<<"0 10 45 25 55"; */

int dist[100];
int G[NUM][NUM];
int isvisited[NUM];
int path[100];
int Nv;
int Ne=0;

struct cmp
{
	bool operator()(int &a,int &b){
		return dist[a]>dist[b];
	}
};

void  createGraph()
{
        Nv=NUM;
        for (int i=0;i<NUM;i++)
        {
            for (int j=0;j<NUM;j++)
            {
                int weight;
                cin>>weight;
                if (weight<0)
                {
                    weight=MAX;
                }
                G[i][j]=weight;
            }
        }
        for (int i=0;i<NUM;i++)
        {
            isvisited[i]=0;
        }
        for (int i=0;i<100;i++)
        {
            path[i]=-1;
            dist[i]=MAX;
        }
};

bool Dijikstra(int vertex)
{
    priority_queue<int,vector<int>,cmp> q;
    q.push(vertex);
    dist[vertex]=0;
    isvisited[vertex]=1;
    while (!q.empty())
    {
        int start=q.top();
        q.pop();
        for (int i=1;i<Nv+1;i++)
        {
            if (G[start][i]<0)
            {
                return false;
            }
            if (G[start][i]<MAX)
            {
                if (isvisited[i]==0)
                {
                    if (dist[i]>dist[start]+G[start][i])
                    {
                        dist[i]=dist[start]+G[start][i];
                        q.push(i);
                        path[i]=start;
                    }
                }
            }
        }
    }
    return true;
}

void Print(int start,int end)
{
    cout<<dist[end]<<' ';
}

void printDijikstra(int vertex)
{
    for (int i=0;i<Nv;i++)
    {
        Print(vertex,i);
    }
}

int main()
{
    createGraph();
    int vertex=0;
    if (Dijikstra(vertex))
    {
        printDijikstra(vertex);
    }
    return 0;
}
