#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define dt int

struct node 
{
    int data;
    struct node *link;
};

class Queue{
private:
        dt *binary;
        int operations=0;
        struct node *head=NULL;
public:
        Queue(int n);
        void start();
        void enqueue();
        void dequeue();
        void display();
}; 
Queue::Queue(int n){
    int j,i=0;
    binary=(dt*)malloc(32*sizeof(dt));
    for(i=0 ; n>0 ; i++)    
	{    
		binary[i]=n%2;    
		n=n/2;    
	} 
    for(i=i-1;i>=0;i--)    
	{    
	        printf("%d",binary[i]);    
	} 
        printf("\n");
}
void Queue::start(){
        int i;
        for(i=0 ; i<32 ; i++)
                if (binary[i]==1)
                {
                        enqueue();
                }
                else
                {
                        dequeue();
                }
}
void Queue::enqueue()
{     
    if(head==NULL)
    {
        int random=(rand()%451)+50;
        operations++;
        head=(struct node *)malloc(sizeof(struct node));
        head->data=random;
        head->link=NULL;
        printf("OPERATION #%d : %d\n",operations,head->data);
    }
    else
    {
        int random=(rand()%451)+50;
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        struct node *traverse=(struct node *)malloc(sizeof(struct node));
        traverse=head;
        temp->data=random;
        temp->link=NULL;
        while(traverse->link!=NULL)
        {
            traverse=traverse->link;
        }
        traverse->link=temp;
        operations++;
        printf("OPERATION #%d : %d\n",operations,temp->data);
    }
}
void Queue::dequeue()
{
    if (head==NULL)
    {
        operations++;
        printf("OPERATION #%d : E\n",operations);
    }
    else
    {   operations++;
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp=head;
        head=head->link;
        printf("OPERATION #%d : %d\n",operations,temp->data);
        free(temp);
        temp=NULL;
    }
}
void Queue::display()
{
    int count=0;
    if(head==NULL)
    {
        printf("LIST IS EMPTY");
    }
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=head;
    while(temp!=NULL)
    {
        count++;
        printf("Element #%d : %d\n",count,temp->data);
        temp=temp->link;
    }
    printf("\n");
}
int main()
{
    int n;
    printf("ENTER THE NUMBER : \n");
    scanf("%d",&n);
    n+=1378056032;
    Queue q1(n);
    q1.start();
    printf("FINAL STATUS : \n");
    q1.display();
    return 0;
}