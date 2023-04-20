#include <iostream>
using namespace std;

class linklist
{
private :
    struct node {
        int data;
        node *next;
    }*head;

public:
    linklist()
    {
        head=NULL;
    }

    void append(int num)
    {
        node *t=head,*temp;
        if(head==NULL) {
            t=new node;
            t->data=num;
            t->next=NULL;
            head=t;
        }

        else {
            while(t->next!=NULL)
                t=t->next;

            temp=new node;
            temp->data=num;
            temp->next=NULL;
            t->next=temp;
        }
    }

    void combine(linklist a, linklist b)
    {
        node *x=a.head, *y=b.head,*temp1,*temp2;
        while(x!=NULL) {
            temp1=x->next;
            temp2=y->next;
            x->next=y;
            y->next=temp1;
            x=temp1;
            y=temp2;
        }
    }

    void display()
    {
        node *t=head;
        while(t!=NULL) {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }

    ~linklist()
    {
        node *t;
        while(head!=NULL) {
            t=head->next;
            delete head;
            head=t;
        }
    }
};

int main()
{
    linklist A,B;
    A.append(7);
    A.append(5);
    A.append(3);
    A.append(1);
    A.append(20);
    B.append(6);
    B.append(25);
    B.append(32);
    B.append(11);
    B.append(9);
    A.combine(A,B);
    A.display();
}
