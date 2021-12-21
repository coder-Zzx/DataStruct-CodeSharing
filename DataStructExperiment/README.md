# <center>数据结构与算法实验实验报告<center>  
<p align="right">coder-Zzx</p>

***
## 实验一  背包问题的求解  

* 问题描述
    > 假设有一个能装入总体积为T的背包和n件体积分别为w1,w2,…wn的物品，能否从n件物品中挑选若干件恰好装满背包，即使w1+w2+…+wm=T，要求找出所有满足上述条件的解。 
    >> 例如：当T=10，各件物品的体积{1,8,4,3,5,2}时，可找到下列4组  解：(1,4,3,2)，(1,4,5)，(8,2)，(3,5,2)。

* 主要代码
    > 代码放在[这里](https://github.com/coder-Zzx/DataStruct-CodeSharing/blob/main/DataStructExperiment/KnapsackProblem.cpp)   
    > 核心代码如下   
    > ![](https://s3.bmp.ovh/imgs/2021/12/ffc7f964bdd9ba1b.png)
    >> 思路描述：利用贪心算法，
    >>1. 设置一个栈，用来存放放入背包的物品小标，
    >>2. 当栈非空且有物品未被放入背包中时，循环检测放入背包的物品   的重量，直至所有物品都被放入过。
    >>    1. 若加入的物品的重量与背包内现有质量之和小于T，则该物品入栈且放入下一个物品；
    >>    2. 若相等则将现有栈内元素输出，相当于找到一个解；
    >>    3. 若大于则该物品不入栈，检测下一个物品。
    >>3. 输出所有的解。

* 结果展示  
    >     请输入背包可以放入的物品重量:20
    >     请输入物品数量.6
    >     请分别输入6个物品重量.
    >     6 7 5 4 9 13
    >     所有解为:
    >     { 6 5 9 }
    >     { 7 4 9 }
    >     { 7 13 }
    >     共有3个解
    >     请按任意键继续. . .

***
## 实验四  八皇后问题

* 问题描述
    > 设在初始状态下在国际象棋的棋盘上没有任何棋子（这里的棋子指皇后棋子）。然后顺序在第1行，第2行……第8行上布放棋子。在每一行中共有8个可选择的位置，但在任一时刻棋盘的合法布局都必须满足3个限制条件（1）任意两个棋子不得放在同一行（2）任意两个棋子不得放在同一列上（3）任意棋子不得放在同一正斜线和反斜线上。
    > 编写求解并输出此问题的一个合法布局的程序。

* 主要代码
    > 代码放在[这里](https://github.com/coder-Zzx/DataStruct-CodeSharing/blob/main/DataStructExperiment/8QueensProblem.cpp)       
    > 核心代码如下   
    > ![](https://s3.bmp.ovh/imgs/2021/12/2afc5186267e773e.png)   
    >> 思路描述：利用回溯法
    >> 1. 设置棋盘，首先在第一列放置一个皇后，然后检查是否合法；
    >> 2. 如果合法则转向下一行；不合法则将该位置重置，然后转向下一列；
    >> 3. 直至到最后一列，进行输出

    >       void solve(int Queen[BOARD_SIZE][BOARD_SIZE], int row)
    >       {
    >           //递归法解决
    >           for (int col = 0; col < BOARD_SIZE; ++col) //对每一列都>           先放置一个皇后，然后判断是否合法，如果合法则转向下一行，不合>           法则收回此皇后并检验下一列
    >           {
    >               Queen[row][col] = 1;
    >               if (check(Queen, row, col))
    >               {
    >                   if (row + 1 == BOARD_SIZE)
    >                   {
    >                       //在合法的情况下发现为最后一列，即为找到一个合法的放置方法，输出该方法
    >                       print(Queen);
    >                   }
    >                   else
    >                   {
    >                       //此位置合法但未到最后一行，则回溯到下一行，进行递归
    >                       solve(Queen, row + 1);
    >                   }
    >               }
    >               Queen[row][col] = 0; //如若不合法则将此皇后收回，继续循环检验下一列
    >           }
    >       }

* 结果展示

> ![八皇后问题结果](https://s3.bmp.ovh/imgs/2021/12/f5477d548644264a.png)

***

## 实验七 二叉排序树与平衡二叉树的实现  

* 问题描述  
    > 分别采用二叉链表和顺序表作存储结构，实现对二叉排序树与平衡二叉树的操作。

* 主要代码
    > 代码放在[这里](https://github.com/coder-Zzx/DataStruct-CodeSharing/blob/main/DataStructExperiment/BinarySearchTree&BalencedBinaryTree.cpp)   
    > 核心代码如下   
    > ![](https://s3.bmp.ovh/imgs/2021/12/ad098c75252465f6.png)   
    >> 由于这道题基本就是书上的东西，所以思路就不写了

* 结果展示
    > ![二叉搜索树结果展示](https://i.bmp.ovh/imgs/2021/12/138358820e5367ac.png)
    > ![平衡二叉树结果展示](https://i.bmp.ovh/imgs/2021/12/d81338d6bebca36b.png)

***

## 实验十三  迷宫问题

* 问题描述
    > 迷宫实验是取自心理学的一个古典实验。在该实验中，把一只老鼠从一个无顶大盒子的门放入，在盒中设置了许多墙，对行进方向形成了多处阻挡。盒子仅有一个出口，在出口处放置一块奶酪，吸引老鼠在迷宫中寻找道路以到达出口。对同一只老鼠重复进行上述实验，一直到老鼠从入口到出口，而不走错一步。老鼠经多次试验终于得到它学习走迷宫的路线。

* 主要代码
    > 代码放在[这里](https://github.com/coder-Zzx/DataStruct-CodeSharing/blob/main/DataStructExperiment/MazeProblem.c)   
    > 核心代码如下   
    > ![](https://s3.bmp.ovh/imgs/2021/12/f6aa33e3309860a4.png)      
    > ![](https://s3.bmp.ovh/imgs/2021/12/e6d51b643ea2fcc8.jpeg)   
    >> 思路描述：
    >> 1. 用一个box存放位置和下一可走相邻方位，用1，0分别表示墙和路
    >>      1. i，j，di分别表示横纵坐标和方位
    >>      2. 如果下一方位是路则修改原方块的di值然后下一个可走方块入栈
    >>      3. 如果无路可走则出栈

* 结果展示  

    > ![迷宫问题结果展示](https://i.bmp.ovh/imgs/2021/12/24bad5b0a7be6a29.png)


<!-- https://github.com/coder-Zzx/DataStruct-CodeSharing -->
