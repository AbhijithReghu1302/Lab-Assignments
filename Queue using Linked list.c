#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
 struct node *front=NULL, *rear=NULL;

 void enqueue(int val)
{
struct node *newNode=malloc(sizeof(struct node));
newNode ->data=val;
newNode->next=NULL;
if(front==NULL && rear ==NULL)
    front=rear=newNode;
else
{
    rear->new=newNode;
    rear=newNode;
    }
}

void dequeue()
{
    struct node *temp;
    if(front==NULL)
        printf("Queue is empty")

}
