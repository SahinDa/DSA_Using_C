#include<stdio.h>
#include<stdlib.h>
struct circularQueue {
	int front;
	int rear;
	int size;
	int *arr;	
};
int isFull(struct circularQueue *);
int isEmpty(struct circularQueue*);
void enqueue(struct circularQueue *p){
	int val;
	if(!isFull(p)){
		printf("Enter value to insert in queue ");
		scanf("%d",&val);
	     p->rear=(p->rear+1)%p->size;
	     p->arr[p->rear]=val;
	     printf("%d ",p->rear);
	} else {
		printf("Queue is fully!!! New value insertion is not possible \n");
	}
}
void dequeue(struct circularQueue *p){
	int val;
	if(!isEmpty(p)){
	        p->front=(p->front+1)%p->size;
		     val=p->arr[p->front];
		  printf("Deleted Element is : %d ",val);
	} else {
		printf("Queue is empty !!! So deletion can't perform \n");
	}
	
}
int isFull(struct circularQueue *p){
	if((p->front==-1 &&p->rear==p->size-1)||(p->rear==p->front-1))
	return 1;
	else return 0;
}
int isEmpty(struct circularQueue *p){
	int n;
	if(p->rear==-1)
	n=1;
	else if(p->rear==p->front){
		if(isFull(p))
		n=0;
		else n=1;
	} else n=0;
	return n;
	
	
}
void peek(struct circularQueue *p){
	int val;
	if(!isEmpty(p)){
		val=p->arr[p->front];
	printf("Peek value is %d\n",val );
     }
	else 
		printf("Circular Queue is Empty \n");
}
int main()
{
	struct circularQueue *p=(struct circularQueue*)malloc(sizeof(struct circularQueue));
//	struct circularQueue *p=&s;
    int choice,n=1;
	p->size=2;
	p->front=-1;
	p->rear=-1;
	p->arr=(int*)malloc(sizeof(int)*(p->size));
	while(n){
	
     printf("Enter your choice\n 1.Insert \n2.Delete \n3.Peek \n4.Exit");
     scanf("%d",&choice);
     switch(choice){
     	case 1: enqueue(p);
     	        break;
     	case 2 : dequeue(p);
		         break;
		case 3: peek(p);
		         break;
	    case 4 : break;
		default : printf("Invalid choice\n ");
					 		        
	 }
	 printf("\n Press 1 to continue ");
	 scanf("%d",&n);
   }
   return 0;
} 
