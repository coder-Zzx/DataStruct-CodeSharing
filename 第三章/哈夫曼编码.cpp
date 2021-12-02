#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
/* coded by zzx 3.3 oj上的输入没有回车，之前使用的不限定输入个数的方法不能用了，只能限定8个输入 */

char Arr[10000];

class HuffmanTree
{
public:
    int weight;
    string huffmancode;
    HuffmanTree *left;
    HuffmanTree *right;
    void createHuffmancode(HuffmanTree *root, char *Arr, int top);
    void Set(int num, HuffmanTree *left, HuffmanTree *right);
    bool isLeaf(HuffmanTree *root);
    void printHuffmancode(HuffmanTree *root);
    HuffmanTree* find(HuffmanTree* node,int wei);
};

void HuffmanTree::Set(int num, HuffmanTree *left, HuffmanTree *right)
{
    this->weight = num;
    this->left = left;
    this->right = right;
}

struct cmp
{
    bool operator()(HuffmanTree *node1, HuffmanTree *node2)
    {
        return node1->weight > node2->weight;
    }
};

HuffmanTree *createHuffmanTree(int *data, int size)
{
    priority_queue<HuffmanTree *, vector<HuffmanTree *>, cmp> q;
    for (int i = 0; i < size; i++)
    {
        HuffmanTree *root = new HuffmanTree;
        root->Set(data[i], NULL, NULL);
        q.push(root);
    }
    while (q.size() != 1)
    {
        HuffmanTree *left = q.top();
        q.pop();
        HuffmanTree *right = q.top();
        q.pop();
        HuffmanTree *root = new HuffmanTree;
        root->Set(left->weight + right->weight, left, right);
        q.push(root);
    }
    HuffmanTree *root = q.top();
    q.pop();
    return root;
}

void HuffmanTree::createHuffmancode(HuffmanTree *root, char *Arr, int top)

{
    if (root->left)
    {
        Arr[top] = '0';
        createHuffmancode(root->left, Arr, top + 1);
    }
    if (root->right)
    {
        Arr[top] = '1';
        createHuffmancode(root->right, Arr, top + 1);
    }
    if (this->isLeaf(root))
    {
        int i;
        for (i = 0; i < top; i++)
        {
            if (Arr[i - 1] == '\0' && Arr[i] != '\0')
            {
                break;
            }
        }
        string code="";
        for (int j=i;j<top;j++)
        {
            code += Arr[j];
        }
        root->huffmancode = code;
    }
}

void HuffmanTree::printHuffmancode(HuffmanTree *root)
{
    priority_queue<HuffmanTree*,vector<HuffmanTree*>,cmp> q;
    q.push(root);
    while (!q.empty())
    {
        HuffmanTree *cur=q.top();
        q.pop();
        if (cur->left)
        {
            q.push(cur->left);
        }
        if (cur->right)
        {
            q.push(cur->right);
        }
        if (this->isLeaf(cur))
        {
            cout<<cur->weight<<" "<<cur->huffmancode<<endl;
        }
    }
}

bool HuffmanTree::isLeaf(HuffmanTree *root)
{
    return !root->left && !root->right;
}

HuffmanTree* HuffmanTree::find(HuffmanTree* node,int wei)
{
    HuffmanTree* ret=NULL;
    if (node)
    {
        if (node->weight==wei)
        {
            ret=node;
        }
        else
        {
            if (!ret)
            {
                ret=this->find(node->left,wei);
            }
            if (!ret)
            {
                ret=this->find(node->right,wei);
            }
        }
    }
    return ret;
}

int main()
{
    int data[8];
    int n = 0;
    for (n=0;n<8;n++)
    {
        cin>>data[n];
    }
    HuffmanTree *root;
    root = createHuffmanTree(data, n);
    root->createHuffmancode(root, Arr, n);
    // root->printHuffmancode(root);
    for (int i=0;i<n;i++)
    {
        HuffmanTree *node=root->find(root,data[i]);
        cout<<node->huffmancode;
    }
    return 0;
}
