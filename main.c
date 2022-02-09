#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

void Print_Linked_List(struct Node* n){

while (n != NULL){
printf(" %d ", n->data);
n=n->next;
}
}//END OF FUNCTION


/* Given a reference (pointer to pointer) to the head of a list and an int,  inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data){
/* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    /* 2. put in the data  */
    new_node->data  = new_data;
  
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
  
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;

}

void insertAfter(struct Node* prev_node, int new_data){

/*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
    printf("the given previous node cannot be NULL");    
    return;
    }
         
    /* 2. allocate new node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
 
    /* 3. put in the data */
    new_node->data = new_data;
 
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
 
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;

}


void append(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    struct Node *last = *head_ref;  /* used in step 5*/
  
    /* 2. put in the data  */
    new_node->data  = new_data;
 
    /* 3. This new node is going to be the last node, so make next
          of it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    } 
      
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
  
    /* 6. Change the next of last node */
    last->next = new_node;
    return;   
}


int main(void) {

struct Node* Head = NULL;
struct Node* Second = NULL;
struct Node* Tail = NULL;

    // allocate 3 nodes in the heap
Head = (struct Node*)malloc(sizeof(struct Node));
Second = (struct Node*)malloc(sizeof(struct Node));
Tail = (struct Node*)malloc(sizeof(struct Node));


//assigns the first node to a value(which is stored in data)
Head->data = 1;

//links the 2 nodes
Head->next = Second;

//repeat for other nodes...
Second->data = 2;
Second->next = Tail;
Tail->data=3;

//FOR THE FINAL LINK, MAKE NEXT NULL
Tail->next = NULL;

Print_Linked_List(Head);
int choice = 1;
int INSERT;
do{
printf("\nMENU:\n");
printf("Press '1' to Add a new Head Node.\n");
printf("Press '2' to Add a new Body Node.\n");
printf("Press '3' to Add a new Tail Node.\n");
printf("Press '0' to Kill The Program.\n");
scanf("%d", &choice);
switch(choice){

//NEW HEAD
case 1:
printf("\nINPUT A VALUE: ");
scanf("%d", &INSERT);
push(&Head, INSERT);
break;

//NEW BODY
case 2:
printf("\nINPUT A VALUE: ");
scanf("%d", &INSERT);
insertAfter(Head->next, INSERT);//THIS WILL INPUT A NEW NODE AFTER SECOND
break;

//NEW TAIL
case 3: 
printf("\nINPUT A VALUE: ");
scanf("%d", &INSERT);
append(&Head, INSERT);

break;

//KILL
case 0: break;

default: printf("\nINVALID CHOICE\n"); break;

}

}while(choice != 0);



Print_Linked_List(Head);

  return 0;
}