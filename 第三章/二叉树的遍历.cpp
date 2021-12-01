#include<iostream>
using namespace std;

int len(char s[])
{
    int i;
    for (i=0;s[i]!='\0';i++);
    return i;
}

class BST
{
public:
    char *data;
    BST()
    {
        this->data=new char[100];
        gets(this->data);
    }
    void prePrint(int i);
    void inPrint(int i);
    void postPrint(int i);
    void visit(int i);
};

void BST::visit(int i)
{
    cout<<this->data[i];
}

void BST::prePrint(int i)
{
    if (this->data[i]=='\0')
    {
        return;
    }
    visit(i);
    if (this->data[2*i+1]!='0' && (2*i+1)<len(this->data))
    {
        this->prePrint(2*i+1);
    }
    if (this->data[2*i+2]!='0' && (2*i+1)<len(this->data))
    {
        this->prePrint(2*i+2);
    }
}

void BST::inPrint(int i)
{
    if (this->data[i]=='\0')
    {
        return;
    }
    if (this->data[2*i+1]!='0' && (2*i+1)<len(this->data))
    {
        this->inPrint(2*i+1);
    }
    visit(i);
    if (this->data[2*i+2]!='0' && (2*i+1)<len(this->data))
    {
        this->inPrint(2*i+2);
    }
}

void BST::postPrint(int i)
{
    if (this->data[i]=='\0')
    {
        return;
    }
    if (this->data[2*i+1]!='0' && (2*i+1)<len(this->data))
    {
        this->postPrint(2*i+1);
    }
    if (this->data[2*i+2]!='0' && (2*i+1)<len(this->data))
    {
        this->postPrint(2*i+2);
    }
    visit(i);
}

int main()
{
    BST *t=new BST();
    t->prePrint(0);
    cout<<endl;
    t->inPrint(0);
    cout<<endl;
    t->postPrint(0);
    cout<<endl;
    return 0;
}
