/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include <iostream>
#include<string>
using namespace std;

class Node{
public:
    char name;
    int num;
    Node *next;
    void getData()
    {
        cin>>this->name;
        cin>>this->num;
    }
};

class Nlist{
public:
    Nlist(){
        head=NULL;
    }
    void insert(Node *node);
    void print();
    Node *head;
};

void Nlist::insert(Node *node){
    if (head==NULL){
        head=node;
        return;
    }
    Node *current=head;
    while (current->next!=NULL){
        current=current->next;
    }
    current->next=node;
    return;
}

void Nlist::print(){
    if (head==NULL){
        return;
    }
    Node *current=head;
    while (current->next!=NULL){
        cout<<current->name<<' '<<current->num<<',';
        current=current->next;
    }
    cout<<current->name<<' '<<current->num<<';'<<endl;
    return;
}

void update(Nlist L,Nlist Lin){
    Node *p,*q,*tmp;
    p=L.head;
    q=Lin.head;
    while (q!=NULL){
        while (p->next!=NULL&&p->next->name<q->name){
            p=p->next;
        }
        if (p->next==NULL){
            p->next=q;
            return;
        }
        if (p->name==q->name){
            p->num+=q->num;
            q=q->next;
        }
        else if (p->next->name==q->name){
            p->next->num+=q->num;
            q=q->next;
        }
        else if (q->name<p->next->name){
            tmp=q->next;
            q->next=p->next;
            p->next=q;
            q=tmp;
            p=p->next;
        }
        else{
            p->next->num+=q->num;
            q=q->next;
        }
    }
    return;
}


int main(){   
    Nlist base_list,in_list;
    char base[80],
         in[80];
    int i,j;
    while (true)
    {
        Node *node =new Node();
        node->getData();
        base_list.insert(node);
        if (cin.get()==';')
        {
            break;
        }
    }
    while (true)
    {
        Node *node =new Node();
        node->getData();
        in_list.insert(node);
        if (cin.get()==';')
        {
            break;
        }
    }
    update(base_list,in_list);
    base_list.print();
    return 0;
}
