#include <stdio.h>
#include <stdlib.h>
struct Employee {
int id;
char name[10];
int salary;
};
struct Node{
struct Employee emp;
struct Node *next;
};
struct Queue{
struct Node *head;
struct Node *tail;
};
struct Queue* createQueue();
struct Node* createNode(struct Employee m);
void enQueue(struct Queue *q, struct Employee m);
void deQueue(struct Queue *q);
void printEmployee(struct Employee em);
struct Employee fillEmployee(void);
int main()
{
    struct Employee emp,emp1,emp2;
     struct Queue* q = createQueue();
     struct Queue *q2 = createQueue();


     emp=fillEmployee();
     emp1=fillEmployee();
     emp2=fillEmployee();

     enQueue(q,emp); //first
     enQueue(q,emp1); //last
     enQueue(q2,emp); //first
     enQueue(q2,emp2); //last

     deQueue(q); //dequeue first which i emp
     deQueue(q2); //same here ^



    return 0;
}
struct Node* createNode(struct Employee m){
struct Node *ptr ;
ptr= (struct Node*) malloc(sizeof(struct Node));
if (ptr){
    ptr -> emp.id = m.id;
    ptr -> emp.salary = m.salary;
    strcpy(ptr -> emp.name ,m.name );
    ptr -> next = NULL;
}
return ptr;

}

struct Queue* createQueue(){
struct Queue *ptrq;
ptrq = (struct Queue*) malloc(sizeof(struct Queue));
if(ptrq){
    ptrq -> head = NULL;
    ptrq -> tail = NULL;

}
return ptrq;

}
void enQueue(struct Queue *q, struct Employee m){

    struct Node *ptr = createNode(m);
    if(ptr){
    if (q -> head == NULL){
        q->head = q->tail = ptr;
    }else{
        q -> tail -> next = ptr;
        q->tail =ptr;
    }

    }

}

void deQueue(struct Queue *q){
         struct Node *ptr;
    if (q-> head ==NULL){
        printf("Queue is EMPTY!\n");
    } else{

            ptr=q->head;
            q->head = ptr -> next;
            printEmployee(ptr->emp);
            free(ptr);

    }

}
void printEmployee(struct Employee em){
      printf("the id of employee: %d \n", em.id);
     printf("the name of employee : %s \n", em.name);
       printf("the salary of employee: %d \n", em.salary);
        printf("\n");
}
struct Employee fillEmployee(void){
    struct Employee emp;
    printf("Enter the id of employee : ");
    scanf("%d", &emp.id );
    printf("Enter the Name of employee : ");
    scanf("%s", emp.name );
   printf("Enter the salary of employee: ");
   scanf("%d", &emp.salary);
    return emp;
}
