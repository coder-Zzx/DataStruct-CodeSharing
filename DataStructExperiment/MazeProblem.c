/* 实验十三 迷宫问题 */

#include <stdio.h>
#define MaxSize 100
#define M 8
#define N 8
int mg[M + 2][N + 2] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}; //构造地图
typedef struct
{
    int i;  //当前方块的行号
    int j;  //当前方块的列号
    int di; //di是下一可走相邻方位的方位号---上下左右的标记
} Box;
typedef struct
{
    Box data[MaxSize]; //是用来存储位置坐标的，当MaxSize<位置坐标的数目时，则程序出错，停止运行
    int top;           //栈顶指针
} StType;              //定义栈类型
//该栈中:每一个位置用于存储Box，该栈对应了一个int型的top作为指针，依次移动，方便对栈中每一个位置进行操作，而Box中，存储了该迷宫位置的横坐标，纵坐标，和从上一位置移动到该位置所对应的方向数值
int mgpath(int xi, int yi, int xe, int ye) //求解路径为:(xi,yi)->(xe,ye)
                                           //初位置横坐标，初位置纵坐标，终点横坐标，终点纵坐标
{
    int i, j, k, di, find;
    StType st;               //定义栈st
    st.top = -1;             //初始化栈顶指针
    st.top++;                //初始方块进栈
    st.data[st.top].i = xi;  //栈底一号存入横坐标数值
    st.data[st.top].j = yi;  //栈底一号存入纵坐标数值
    st.data[st.top].di = -1; //????????????????????????????????
    mg[xi][yi] = -1;
    while (st.top > -1) //栈不空时循环
    {
        i = st.data[st.top].i;
        j = st.data[st.top].j;
        di = st.data[st.top].di; //取栈顶方块
        if (i == xe && j == ye)  //找到了出口,输出路径
        {
            printf("迷宫路径如下:\n");
            for (k = 0; k <= st.top; k++)
            {
                printf("\t(%d,%d)", st.data[k].i, st.data[k].j);
                if ((k + 1) % 5 == 0) //每输出5个元素，就换行
                    printf("\n");
            }
            printf("\n");
            return 0; //找到路径之后，将所有路径打印出来，然后，程序结束
        }
        find = 0;
        while (di < 4 && find == 0) //找下一个可走方块
        {
            di++;
            switch (di)
            {
            case 0: //向上走
                i = st.data[st.top].i - 1;
                j = st.data[st.top].j;
                break;
            case 1: //向右走
                i = st.data[st.top].i;
                j = st.data[st.top].j + 1;
                break;
            case 2: //向下走
                i = st.data[st.top].i + 1;
                j = st.data[st.top].j;
                break;
            case 3: //向左走
                i = st.data[st.top].i;
                j = st.data[st.top].j - 1;
                break;
            }
            if (mg[i][j] == 0)
                find = 1; //mg[i][j]==0说明:该点可以走--------------(该点为此时所在点的下一预判点)
        }
        if (find == 1) //找到了下一个可走方块
        {
            st.data[st.top].di = di; //修改原栈顶元素的di值
            st.top++;                //下一个可走方块进栈
            st.data[st.top].i = i;
            st.data[st.top].j = j;
            st.data[st.top].di = -1; //再次初始化方向数值
            mg[i][j] = -1;           //避免重复走到该方块-----------------------//让每一个点都变成起点，因此，既满足递归的条件，也避免重复走到该位置
        }
        else //没有路径可走,则退栈
        {
            mg[st.data[st.top].i][st.data[st.top].j] = 0; //让该位置变为其他路径可走方块
            st.top--;                                     //将该方块退栈
        }
    }
    return (0); //表示没有可走路径,返回0
}
int main()
{
    int x, y, k, t;
    printf("终点坐标为:(8,8)\n");
    while (1)
    {
        printf("请输入起点坐标:\n");
        printf("(横坐标范围:0~9,纵坐标范围:0~9)\n");
        scanf("%d %d", &x, &y);
        if (mg[x][y] == 1)
        {
            printf("输入坐标有误，该位置为墙,请重新输入:\n");
        }
        else
        {
            break;
        }
    }
    mgpath(x, y, M, N);
    printf("\n\n图像表示:\n");
    for (t = 0; t < 10; t++)
    {
        printf("\t\t");
        for (k = 0; k < 10; k++)
        {
            if (mg[t][k] == 1)
            {
                printf("#");
            }
            else if (mg[t][k] == 0)
            {
                printf(" ");
            }
            else
            {
                printf("o");
            }
        }
        if (k == 10)
        {
            printf("\n");
        }
    }
    printf("\n此时，o所代表的图标为迷宫行走路径!!!\n");
    return 0;
}
