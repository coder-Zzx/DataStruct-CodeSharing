#include <iostream>
using namespace std;
/* coded by zzx 3.3 */

class AVL
{
public:
    int data;
    int height;
    AVL *lchild;
    AVL *rchild;
    AVL *Insert(AVL *avl, int data);
    AVL *Delete(AVL *avl, int data);
    AVL *SingleLeftRotation(AVL *avl);
    AVL *SingleRightRotation(AVL *avl);
    AVL *DoubleLeftRightRotation(AVL *avl);
    AVL *DoubleRightLeftRotation(AVL *avl);
    AVL *Create(int* data,int size);
    int getHeight(AVL *avl);
    int Max(int a, int b);
    AVL *FindMin(AVL *avl);
};

class qNode
{
public:
    AVL *avl=new AVL();
    qNode *next;
    qNode(AVL *_avl)
    {
        avl=_avl;
        next=NULL;
    }
};

class queue
{
public:
    qNode *f;
    qNode *r;
    queue()
    {
        f=NULL;
        r=NULL;
    }
    void push(AVL *avl)
    {
        if (f==NULL)
        {
            f=new qNode(avl);
            r=f;
            return;
        }
        qNode q=new qNode(avl);
        r->next=p;
        r=p;
    }
    void pop()
    {
        qNode p=f->next;
        f->next=p->next;
        if (p==r)
        {
            r=f;
        }
        delete(p);
    }
    AVL * front()
    {
        return f;
    }
};

AVL *AVL::Insert(AVL *avl, int x)
{
    //平衡二叉树为空，则构建根节点
    if (!avl)
    {
        avl = new AVL;
        avl->data = x;
        avl->height = 0;
        avl->lchild = avl->rchild = NULL;
    }
    else if (x < avl->data)
    { //若data小于根节点的值，则插入到左子树
        avl->lchild = avl->Insert(avl->lchild, x);
        int rheight = this->getHeight(avl->rchild); //右子树高度
        int lheight = this->getHeight(avl->lchild); //左子树高度
        //如果插入导致左子树失衡，即左子树比右子树高2
        if (lheight - rheight == 2)
        {
            if (x < avl->lchild->data)
            {
                //插入的结点比左孩子的键值小
                //那么一定是插入到左孩子的左子树上，故进行LL旋转
                avl = this->SingleLeftRotation(avl);
            }
            else
            { //否则是插入到左孩子的右子树上，故要进行LR旋转
                avl = this->DoubleLeftRightRotation(avl);
            }
        }
    }
    else if (x > avl->data)
    { //若data小于根节点的值，则插入到左子树
        avl->rchild = avl->Insert(avl->rchild, x);
        int rheight = this->getHeight(avl->rchild); //右子树高度
        int lheight = this->getHeight(avl->lchild); //左子树高度
        //如果插入导致右子树失衡，即右子树比左子树高2
        if (rheight - lheight == 2)
        {
            if (x > avl->rchild->data)
            {
                //插入的结点比右孩子的键值大
                //那么一定是插入到右孩子的右子树上，故进行RR旋转
                avl = this->SingleRightRotation(avl);
            }
            else
            { //否则是插入到右孩子的左子树上，故要进行RL旋转
                avl = this->DoubleRightLeftRotation(avl);
            }
        }
    }
    //更新结点的高度
    avl->height = this->Max(this->getHeight(avl->lchild), this->getHeight(avl->rchild)) + 1;
    return avl;
}

AVL *AVL::Delete(AVL *avl, int data)
{
    if (!avl)
    { //树空时，直接返回NULL
        return avl;
    }
    else if (data < avl->data)
    {
        //data小于根节点时，到左子树去删除data,则有可能使右子树比左子树高2
        avl->lchild = this->Delete(avl->lchild, data);
        int rheight = this->getHeight(avl->rchild); //右子树高度
        int lheight = this->getHeight(avl->lchild); //左子树高度
        if (rheight - lheight == 2)
        { //右子树比左子树高2时
            if (data > avl->rchild->data)
            {
                //如果是data比右子树的键值大，在右子树的右子树上，则进行RR旋转
                avl = this->SingleRightRotation(avl);
            }
            else
            { //否则是data比右子树的键值小，在右子树的左子树上，则进行RL旋转
                avl = this->DoubleRightLeftRotation(avl);
            }
        }
    }
    else if (data > avl->data)
    {
        //data大于根节点时，到右子树去删除data
        avl->rchild = this->Delete(avl->rchild, data);
        int rheight = this->getHeight(avl->rchild); //右子树高度
        int lheight = this->getHeight(avl->lchild); //左子树高度
        if (lheight - rheight == 2)
        { //左子树比右子树高2时
            if (data < avl->lchild->data)
            {
                //如果是data比左子树的键值小，在左子树的左子树上，则进行LL旋转
                avl = this->SingleLeftRotation(avl);
            }
            else
            { //否则是data比左子树的键值大，在左子树的右子树上，则进行LR旋转
                avl = this->DoubleLeftRightRotation(avl);
            }
        }
    }
    else
    { //data等于根节点时
        if (avl->lchild && avl->rchild)
        {
            //左右子树都不空时，用右子树的最小来代替根节点
            AVL *tmp = this->FindMin(avl->rchild);
            avl->data = tmp->data;
            //删除右子树的最小结点
            avl->rchild = this->Delete(avl->rchild, tmp->data);
        }
        else
        { //当左右子树都为空或者有一个空时
            AVL *tmp = avl;
            if (!avl->lchild)
            { //左子树为空时
                avl = avl->rchild;
            }
            else if (!avl->rchild)
            { //右子树为空时
                avl = avl->lchild;
            }
            delete tmp;
        }
    }
    return avl;
}

AVL *AVL::SingleLeftRotation(AVL *avl)
{
    //注意：avl必须有一个左子结点tmp
    //将avl与tmp做左单旋，更新avl与tmp的高度，返回新的根结点tmp
    AVL *tmp = avl->lchild;
    avl->lchild = tmp->rchild;
    tmp->rchild = avl;
    avl->height = this->Max(this->getHeight(avl->lchild), this->getHeight(avl->rchild)) + 1;
    tmp->height = this->Max(this->getHeight(tmp->lchild), this->getHeight(avl)) + 1;
    return tmp;
}

AVL *AVL::SingleRightRotation(AVL *avl)
{
    //注意：avl必须有一个右子结点tmp
    //将avl与tmp做右单旋，更新avl与tmp的高度，返回新的根结点tmp
    AVL *tmp = avl->rchild;
    avl->rchild = tmp->lchild;
    tmp->lchild = avl;
    avl->height = this->Max(this->getHeight(avl->lchild), this->getHeight(avl->rchild)) + 1;
    tmp->height = this->Max(this->getHeight(tmp->rchild), this->getHeight(avl)) + 1;
    return tmp;
}

AVL *AVL::DoubleLeftRightRotation(AVL *avl)
{
    //注意：avl必须有一个左子结点B，且B必须有一个右子结点C
    //将avl、B与C做两次单旋，返回新的根结点C
    //首先对avl的左子树进行单右旋即RR旋转
    avl->lchild = this->SingleRightRotation(avl->lchild);
    //然后对avl进行单左旋即LL旋转
    return this->SingleLeftRotation(avl);
}

AVL *AVL::DoubleRightLeftRotation(AVL *avl)
{
    //注意：avl必须有一个左子结点B，且B必须有一个右子结点C
    //将avl、B与C做两次单旋，返回新的根结点C
    //首先对avl的右子树进行单左旋即LL旋转
    avl->rchild = this->SingleLeftRotation(avl->rchild);
    //然后对avl进行单右旋即RR旋转
    return this->SingleRightRotation(avl);
}

AVL *AVL::FindMin(AVL *avl)
{
    AVL *cur = avl;
    //搜索树为空时，返回NULL
    if (cur == NULL)
    {
        return NULL;
    }
    while (cur)
    {
        //左子树为空时，返回该节点
        if (cur->lchild == NULL)
        {
            return cur;
        }
        else
        { //否则在左子树里找最小值
            cur = cur->lchild;
        }
    }
}

AVL *AVL::Create(int* data,int size){
			AVL* avl = NULL; 
			for(int i = 0 ; i < size ; i++){
				avl = this->Insert(avl,data[i]);
			}
			return avl;
		}

int AVL::getHeight(AVL *avl)
{
    if (!avl)
    {
        return 0;
    }
    return avl->height;
}

int AVL::Max(int a, int b)
{
    return (a > b) ? a : b;
}

void LevelOrderTraversal(AVL* T){
			queue queue;
			AVL* cur = T;
			//头结点入队 
			queue.push(cur);
			//队列为空时循环结束 
			while(!queue.empty()){
				//队列头元素出队 
				cur = queue.front();
				queue.pop();
				cout<<cur->data<<" ";
				//左孩子不为空入队 
				if(cur->lchild != NULL){
					queue.push(cur->lchild);
				}
				//右孩子不为空时入队 
				if(cur->rchild != NULL){
					queue.push(cur->rchild);
				}
			} 
		}

int main()
{
    AVL *tree = new AVL;
    int size=1;
    int *vals=new int[100];
    while (true)
    {
        cin >> vals[size-1];
        ++size;
        // tree->Insert(tree, val);
        if (getchar() == '\n')
            break;
    }
    tree=tree->Create(vals,size-1);
    LevelOrderTraversal(tree);
    return 0;
}
