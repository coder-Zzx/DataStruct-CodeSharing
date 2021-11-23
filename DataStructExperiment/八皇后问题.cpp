/* 实验四 八皇后问题 */
/* coded by zzx */
/* 打印所有的解 */

#include <iostream>
#define BOARD_SIZE 1000 //将BOAERD_SIZE进行预编译，想要解决其他尺寸的问题则修改此处
using namespace std;

int num = 0; //用于记录解的数量

void print(int queen[BOARD_SIZE][BOARD_SIZE])
{
    //打印棋盘
    ++num;
    cout << "********************" << num << "********************" << endl;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (queen[j][i])
            {
                cout << "1"
                     << " ";
            }
            else
            {
                cout << "0"
                     << " ";
            }
        }
        cout << endl;
    }
    cout << "*****************************************" << endl;
    cout << endl;
}

bool check(int Queen[BOARD_SIZE][BOARD_SIZE], int row, int col)
{
    //判断该位置的皇后是否合法
    if (row == 0) //row=0，即第一个放置的皇后，必定合法，故直接return true
    {
        return true;
    }
    for (int i = 0; i < row; ++i) //判断纵向是否合法，因为是在每一行内对皇后逐个检验，所以横向一定合法
    {
        if (Queen[i][col] == 1)
        {
            return false;
        }
    }
    int x, y;
    x = row - 1;
    y = col - 1;
    while (x >= 0 && y >= 0) //判断主对角线是否合法，因为皇后是逐个放置逐个检验，所以只需要考虑被放置的皇后以前的皇后，即只需要让x，y>=0,并且递减即可
    {
        if (Queen[x][y] == 1)
        {
            return false;
        }
        --x;
        --y;
    }
    x = row - 1;
    y = col + 1;
    while (x >= 0 && y <= BOARD_SIZE - 1) //判断副对角线是否合法，思路与判断主对角线相似，不过注意此时y<BOARD_SIZE
    {
        if (Queen[x][y] == 1)
        {
            return false;
        }
        --x;
        ++y;
    }
    return true;
}

void solve(int Queen[BOARD_SIZE][BOARD_SIZE], int row)
{
    //递归法解决
    for (int col = 0; col < BOARD_SIZE; ++col) //对每一列都先放置一个皇后，然后判断是否合法，如果合法则转向下一行，不合法则收回此皇后并检验下一列
    {
        Queen[row][col] = 1;
        if (check(Queen, row, col))
        {
            if (row + 1 == BOARD_SIZE)
            {
                //在合法的情况下发现为最后一列，即为找到一个合法的放置方法，输出该方法
                print(Queen);
            }
            else
            {
                //此位置合法但未到最后一行，则回溯到下一行，进行递归
                solve(Queen, row + 1);
            }
        }
        Queen[row][col] = 0; //如若不合法则将此皇后收回，继续循环检验下一列
    }
}

int main()
{
    int Queen[BOARD_SIZE][BOARD_SIZE];
    for (int x = 0; x < BOARD_SIZE; x++)
    {
        //初始化棋盘
        for (int y = 0; y < BOARD_SIZE; y++)
        {
            Queen[x][y] = 0;
        }
    }
    solve(Queen, 0);
    cout << "该问题共有" << num << "个解" << endl;
    system("pause");
    return 0;
}
