#include <iostream>
using namespace std;
#define MAX 100
/* coded by zzx 4.3 由于oj系统无法登录故没有针对oj上的测试用例测试，只是自己测试了一下，输入输出格式等都需要再更改 */

class Graph
{
public:
    int G[6][6];
    Graph(int num);
    int prim(int num);
};

Graph::Graph(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            this->G[i][j] = MAX;
        }
    }
    int n;
    cin >> n;
    int x, y, weight;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> weight;
        this->G[x][y] = weight;
        this->G[y][x] = weight;
    }
}

int Graph::prim(int num)
{
    int sum = 0,
        min = MAX,
        minid = 0;
    // int g[num][num] = this->G;
    int lowcost[num]; // lowcost[i]即表示起点到第i个点的最短路径
    int mst[num];     // mst[i]表示最小生成树中第i个结点的前驱结点
    for (int i = 1; i < num; i++)
    {
        //将第一个结点作为最小生成树的根节点
        lowcost[i] = this->G[0][i];
        mst[i] = 0;
    }
    mst[0] = 0;
    for (int i = 1; i < num; i++)
    {
        /* 找出n-1个点，所以从1循环到n-1 *
         * 不断循环找出每个点的最短路径   */
        min = MAX;
        minid = 0;
        for (int i = 1; i < num; i++)
        {
            if (lowcost[i] < min && lowcost[i] != 0)
            {

                min = lowcost[i];
                minid = i;
            }
        }
        sum += min;
        lowcost[minid] = 0; //找到了最小的结点，将其放入最小生成树中
        for (int i = 1; i < num; i++)
        {
            //
            if (this->G[minid][i] < lowcost[i])
            {
                lowcost[i] = this->G[minid][i];
                mst[i] = minid;
            }
        }
    }
    return sum;
}

int main()
{
    int num;
    cin >> num;
    Graph *g = new Graph(num);
    int w = g->prim(num);
    cout << "最小生成树的权值和为" << w << endl;
    return 0;
}
