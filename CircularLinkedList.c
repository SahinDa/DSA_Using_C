#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *link;
};
struct node *head='\0';
void insert_Beg(int element){
	struct node *f,*t=(struct node*)malloc(sizeof(struct node));
     	t->data=element;
		if(head=='\0'){
			head=t;
	       t->link=head;
	      
	    } else {
	    	f=head;
	    	while(f->link!=head)
	    	  f=f->link;
	    	  t->link=head;
	    	  head=t;
	    	  f->link=head;   
		}
}
void insert_End(int element){
	struct node *f,*t=(struct node*)malloc(sizeof(struct node));
	t->data=element;
		if(head=='\0'){
			head=t;
	       t->link=head;
	    } else {
	    	f=head;
	    	while(f->link!=head)
	    	  f=f->link;
	    	  t->link=f->link;
	    	  f->link=t; 
		}
	        
}

void  insert_Specific_Position(int element,int specific_value){
	struct node *f,*t=(struct node*)malloc(sizeof(struct node));
	t->data=element;
		if(head=='\0'){
		   printf("Linked List is empty So you can't Insert in Specific position\n");
	    } else {
	    	f=head;
	    	while(f->data!=specific_value && f->link!=head)
	    	      f=f->link;
	    	      if(f->data==specific_value){
	    	  t->link=f->link;
	    	  f->link=t; 
	         } else printf("Insertion is not possible because %d is not present in the Linked List\n ",specific_value);
		}
	        
}

int delete_Beg(){
	struct node *f;
	int val;
	if(head=='\0')
	return 0;
	else {
		f=head;
		while(f->link!=head)
		f=f->link;
		val=head->data;
		head=head->link;
		f->link=head;
		return val;
	}
}
int delete_End(){
		struct node *f,*pre;
	int val;
	if(head=='\0')
	return 0;
	else {
		f=head;
		while(f->link!=head){
			pre=f;
		f=f->link;
	     }
	    val=f->data;
	    pre->link=head;
		return val;
	}
}
int delete_Specific_Position(int specific_value){
		struct node *f,*pre;
		int val;
	if(head=='\0')
	return 0;
	else {
		f=head;
		if(f->data==specific_value)
		val=delete_Beg(head);
		else { 
		 while(f->data!=specific_value){
			pre=f;
		f=f->link;
	     }
	     if(f->link==head)
	    pre->link=head;
	    else pre->link=f->link;
	    }
		return 1;
     }
}
void  travesal(){
	struct node *t=head;
	if(head=='\0')
	printf("Linked list is empty \n");
	else {
		while(t->link!=head){
			printf("%d ",t->data);
			t=t->link;
		}
		printf("%d \n",t->data);
	}
}
void search(int element){
	struct node *f,*pre;
	if(head=='\0')
	printf("Linked list is empty !!!\n");
	else {
		f=head;
	    while(f->data!=element && f->link!=head){
		f=f->link;
	     }
	      if(f->data==element)
	      printf("Search value found \n");
	      else 
	      printf("Serach value is not found \n");
	    }
}
int main(){
	int choice,p=1,element,specific_value;
	while(p==1){
		printf("Enter your Choice \n1.Insertion At Beginning\n2.Insertion At the End \n3.Insertion after any particular value\n4.Deleting from the Beginning \n5.Deleting from  the end\n6.Deleting after any specific value\n7.Traversing\n8.Searching\n9.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter a value To Insert in Linked List \n");
			        scanf("%d",&element);
			        insert_Beg(element);
			        break;
			case 2:  printf("Enter a value To Insert in Linked List \n");
			        scanf("%d",&element); 
					insert_End(element);
					break;  
			case 3:  printf("Enter a value To Insert in Linked List \n");
			         scanf("%d",&element); 
			         printf("Enter the value after you want to insert \n");
			         scanf("%d",&specific_value);
					 insert_Specific_Position(element,specific_value);
					 break; 
			case 4: element=delete_Beg();
			        printf("Deleted element is %d\n",element);
					break;	
			case 5: element=delete_End();
			        printf("Deleted element is %d\n",element);
					break;	
			case 6: printf("Enter the value which you want to delete  \n");
			         scanf("%d",&specific_value);
			         element=delete_Specific_Position(specific_value);
			         if(element==1)
			         printf("Deletion is successfull\n");
			         else printf("Deletion is not possible because value is not found \n");
					break;
			case 7:  travesal();
			        break;
			case 8: printf("Enter Searched Element \n");
			        scanf("%d",&element);
					search(element);
					break;
			case 9:	break;
			default:printf("Invalid choice !!!\n");					
								  
		}
		printf("Want to continue then press 1 \n");
		scanf("%d",&p);
	}
}
