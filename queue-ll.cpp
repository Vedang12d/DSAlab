/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    if(rear==NULL){
        rear=new Node;
        rear->data=x;
        rear->next=NULL;
        front=rear;
    }else{
        Node *temp=new Node;
        temp->data=x;
        temp->next=NULL;
        rear->next=temp;
        rear=temp;
    }
}

void dequeue(){
    if(front==NULL)
        return;
    else{
        Node *q;
        q=front;
        front=front->next;
        delete q;
    }
}

void display(){
    while(front!=0){
        cout<<front->data<<" ";
        front=front->next;
    }    
}

int main()
{
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(12);
    dequeue();
    display();

    return 0;
}
