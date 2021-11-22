#include<iostream>
//可根据需要修改图中的最大节点数，注意增加字符集中的元素
#define NUM 9 
char str[NUM]={'A','B','C','D','E','F','G','H','I'};
using namespace std;

class Graph
{
public:
    int G[NUM][NUM];
    int *isvisited;
    int Nv;
    int Ne;
    Graph()
    {
        this->Nv=NUM;
        // this->G=new int*[NUM];
        this->isvisited=new int [NUM];
        for (int k=0;k<NUM;k++)
        {
            this->isvisited[k]=0;
        }
        for (int i=0;i<NUM;i++)
        {
            for (int j=0;j<NUM;j++)
            {
                int x;
                cin>>x;
                this->G[i][j]=x;
            }
        }
    }
    //广度优先
    void BFS(int vertex);
    //深度优先
    void DFS(int vertex);
    void reset();
};

void Graph::BFS(int vertex)
{
    //广度优先
    int Q[100];
    int front=-1,rear=-1;
    cout<<str[vertex];
    this->isvisited[vertex]=1;
    Q[++rear]=vertex;
    while (front!=rear)
    {
        vertex=Q[++front];
        for (int i=0;i<this->Nv;i++)
        {
            if (G[vertex][i]==1&&isvisited[i]==0)
            {
                cout<<str[i];
                this->isvisited[i]=1;
                Q[++rear]=i;
            }
        }
    }
}

void Graph::DFS(int vertex)
{
    //深度优先
    cout<<str[vertex];
    this->isvisited[vertex]=1;
    for (int i=1;i<=this->Nv;i++)
    {
        if (this->G[vertex][i]==1&&this->isvisited[i]==0)
        {
            this->DFS(i);
        }
    }
}

void Graph::reset()
{
    for (int i=0;i<NUM;i++)
    {
        this->isvisited[i]=0;
    }
}

int main()
{
    Graph *graph=new Graph();
    int now=0;
    graph->DFS(now);
    cout<<endl;
    graph->reset();
    graph->BFS(now);
}
