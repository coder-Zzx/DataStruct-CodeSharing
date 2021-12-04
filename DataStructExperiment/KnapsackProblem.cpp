/* 实验一 背包问题求解 */
/* coded by zzx */

#include <iostream>
#include <stack>
#include <list>
using namespace std;

class BagProblemSolver
{
private:
    int *stuffWeight; //stuffweight用于存放物品重量数组
    int s;            //s用于存放背包重量
    int n;            //n表示物品数量
    list<list<int> *> allResultHolder; //存放所有解
    void insertResultToList(stack<int> bagStack);

public:
    BagProblemSolver(int s, int n, int *stuffWeight)
    {
        this->s = s;
        this->n = n;
        this->stuffWeight = new int[n];
        for (int i = 0; i < n; ++i)
            this->stuffWeight[i] = stuffWeight[i];
    }
    ~BagProblemSolver()
    {
        delete[] stuffWeight;
    }
    list<list<int> *> getAllResult();
};

list<list<int> *> BagProblemSolver::getAllResult()
{
    if (s <= 0)
        return allResultHolder;
    int currentWeight = 0;
    stack<int> indexStack;
    int i = 0;
    do
    {
        while (currentWeight < s && i < n)
        {
            if (currentWeight + stuffWeight[i] <= s)
            {
                indexStack.push(i);
                currentWeight += stuffWeight[i];
            }
            i++;
        }
        if (currentWeight == s)
        {
            insertResultToList(indexStack);
            i = indexStack.top();
            indexStack.pop();
            currentWeight -= stuffWeight[i];
            i++;
        }
        else if (!indexStack.empty())
        {
            i = indexStack.top();
            indexStack.pop();
            currentWeight -= stuffWeight[i];
            i++;
        }
    } while (!indexStack.empty() || i < n);
    return allResultHolder;
}

void BagProblemSolver::insertResultToList(stack<int> bagStack)
{
    stack<int> tempStack; //用于将解以正序存入list
    while (!bagStack.empty())
    {
        tempStack.push(bagStack.top());
        bagStack.pop();
    }
    list<int> *resultList = new list<int>();
    while (!tempStack.empty())
    {
        resultList->push_back(stuffWeight[tempStack.top()]);
        tempStack.pop();
    }
    allResultHolder.push_back(resultList);
}

int main()
{
    int solve_num=0;
    cout << "请输入背包可以放入的物品重量:";
    int s = 0;
    cin >> s; //背包可以放入的物品重量
    cout << "请输入物品数量.";
    int n = 0; //物品数量
    cin >> n;
    int *stuffWeight = new int[n];
    cout << "请分别输入" << n << "个物品重量." << endl;
    for (int i = 0; i < n; ++i)
        cin >> stuffWeight[i];
    BagProblemSolver test(s, n, stuffWeight);
    list<list<int> *> ls = test.getAllResult();
    if (ls.empty())
    {
        cout << "此问题无解!" << endl;
    }
    else
    {
        cout << "所有解为:" << endl;
        while (!ls.empty())
        {   
            cout<<"{ ";
            list<int> *temp = ls.front();
            ls.pop_front();
            while (!temp->empty())
            {
                cout << temp->front() << " ";
                temp->pop_front();
            }
            cout << "}" << endl;
            delete temp;
            solve_num++;
        }
    }
    cout<<"共有"<<solve_num<<"个解"<<endl;
    system("pause");
    return 0;
}
