/* 实验七 二叉排序树与平衡二叉树的实现 */

/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
#include<cmath>
using namespace std;

class Node
{
public:
    int elem;
    int height;
    Node *left;
    Node *right;
    Node(int _elem)
    {
        elem=_elem;
        left=NULL;
        right=NULL;
        height=0;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root=NULL;
    }
    void insert(int n);
    void insert(Node *p,int n);
    Node* search(int n);
    Node* search(Node *p,int n);
    void inorder(Node *p);
    void asl(int num);
    Node* pop(Node *p,int n);
    Node* get_parent(Node *p);
    Node* findmin();
};

class AVL:public BST
{
public:
    AVL()
    {
        root=NULL;
    }
    Node* insert(int n);
    Node* insert(Node *p,int n);
    int getheight(Node *p);
    int max(int a,int b);
    Node* ll(Node *p);
    Node* lr(Node *p);
    Node* rr(Node *p);
    Node* rl(Node *p);
};

void BST::insert(int n)
{
    if (root==NULL)
    {
        root=new Node(n);
    }
    else
    {
        insert(root,n);
    }
}

void BST::insert(Node *p,int n)
{
    if (n>p->elem)
    {
        if (p->right==NULL)
        {
            p->right=new Node(n);
        }
        else
        {
            insert(p->right,n);
        }
    }
    if (n<p->elem)
    {
        if (p->left==NULL)
        {
            p->left=new Node(n);
        }
        else
        {
            insert(p->left,n);
        }
    }
}

Node* BST::get_parent(Node *p)
{
    Node *q=root;
    if (p==root) return NULL;
    while (true)
    {
        if (q->right==p||q->left==p)
        {
            return q;
        }
        if (p->elem>q->elem)
        {
            q=q->right;
        }
        else
        {
            q=q->left;
        }
    }
}

Node* BST::search(int n)
{
    return search(root,n);
}

Node* BST::search(Node *p,int n)
{
    if (p==NULL)
    {
        return NULL;
    }
    if (p->elem==n)
    {
        return p;
    }
    else
    {
        if (p->elem>n)
        {
            return search(p->left,n);
        }
        else
        {
            return search(p->right,n);
        }
    }
}

void BST::inorder(Node *p)
{
    Node *q=p;
    if (q==NULL) return;
    inorder(q->left);
    cout<<q->elem<<" ";
    inorder(q->right);
}

void BST::asl(int num)
{
    double ASL=((num+1)/num)*(log(num+1)/log(2))-1;
    cout<<"该树成功查找的平均查找长度为"<<ASL<<endl;
}

Node* BST::pop(Node *p,int n)
{
    if (!p)
    {
        return p;
    }
    else
    {
        if (n<p->elem)
        {
            p->left=pop(p->left,n);
        }
        else
        {
            if (n>p->elem)
            {
                p->right=pop(p->right,n);
            }
            else
            {
                if (p->left&&p->right)
                {
                    Node *tmp=findmin();
                    p->elem=tmp->elem;
                    p->right=pop(p->right,tmp->elem);
                }
                else
                {
                    Node *tmp=p;
                    if (!p->left)
                    {
                        p=p->right;
                    }
                    else
                    {
                        if (!p->right)
                        {
                            p=p->left;
                        }
                    }
                    delete tmp;
                }
            }
        }
    }
    return p;
}

Node* BST::findmin()
{
    Node *cur=root;
    if (cur==NULL)
    {
        return NULL;
    }
    while (cur)
    {
        if (cur->left==NULL)
        {
            return cur;
        }
        else
        {
            cur=cur->left;
        }
    }
}

Node* AVL::insert(int n)
{
    if (root==NULL)
    {
        root=new Node(n);
        return root;
    }
    else
    {
        return insert(root,n);
    }
}

Node* AVL::insert(Node *p,int n)
{
    if (!p)
    {
        p=new Node(n);
        p->height=0;
        p->left=NULL;
        p->right=NULL;
    }
    if (n<p->elem)
    {
        p->left=insert(p->left,n);
        int rheight=getheight(p->right);
        int lheight=getheight(p->left);
        if (lheight-rheight==2)
        {
            if (n<p->left->elem)
            {
                p=ll(p);
            }
            else
            {
                p=lr(p);
            }
        }
    }
    else
    {
        if (n>p->elem)
        {
            p->right=insert(p->right,n);
            int rheight=getheight(p->right);
            int lheight=getheight(p->left);
            if (rheight-lheight==2)
            {
                if (n>p->right->elem)
                {
                    p=rr(p);
                }
                else
                {
                    p=rl(p);
                }
            }
        }
    }
    p->height=max(getheight(p->left),getheight(p->right));
    return p;
}

int AVL::getheight(Node *p)
{
    if (!p)
    {
        return 0;
    }
    else
    {
        return p->height;
    }
}

int AVL::max(int a,int b)
{
    return (a>b)?a:b;
}

Node* AVL::ll(Node *p)
{
    Node *tmp=p->left;
    p->left=tmp->right;
    tmp->right=p;
    p->height=max(getheight(p->left),getheight(p->right));
    tmp->height=max(getheight(tmp->left),getheight(tmp->right));
    return tmp;
}

Node* AVL::rr(Node *p)
{
    Node *tmp=p->right;
    p->right=tmp->left;
    tmp->left=p;
    p->height=max(getheight(p->left),getheight(p->right));
    tmp->height=max(getheight(p->left),getheight(p->right));
    return tmp;
}

Node* AVL::lr(Node *p)
{
    p->left=rr(p->left);
    return ll(p);
}

Node* AVL::rl(Node *p)
{
    p->right=ll(p->right);
    return rr(p);
}

int main()
{
    int val,x,
        num=0,
        choice;
    cout<<"请选择建立二叉排序树或平衡二叉树："<<endl<<"1.二叉排序树"<<endl<<"2.平衡二叉树"<<endl;
    cin>>choice;
    cout<<"请输入数据："<<endl;
    if (choice==1)
    {
        BST *bst=new BST();
        while (1)
        {
            cin>>val;
            bst->insert(val);
            num++;
            if (cin.get()=='\n') break; 
        }
        Node *Root=bst->root;
        bst->inorder(Root);
        cout<<endl;
        bst->asl(num);
        cout<<"请输入要查找的x：";
        cin>>x;
        if (bst->search(x))
        {
            bst->pop(Root,x);
            bst->inorder(Root);
            cout<<endl;
        }
        else
        {
            cout<<"无"<<x<<endl; 
        }
    }
    else if (choice==2)
    {
        AVL *avl=new AVL();
        while (1)
        {
            cin>>val;
            avl->insert(val);
            num++;
            if (cin.get()=='\n') break; 
        }
        Node *Root=avl->root;
        avl->inorder(Root);
        cout<<endl;
        avl->asl(num);
    }
    
    
    system("pause");
    return 0;
}
