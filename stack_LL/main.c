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
struct Stack{
    int top;
struct Node *head,*tail;
};

void printEmployee(struct Employee em);
struct Employee fillEmployee(void);
struct Node* createNode(struct Employee m);
struct Stack* createStack();
void pop(struct Stack *st);
void push(struct Stack *st, struct Employee em );

int main()
{
    struct Employee emp,emp1,emp2,emp3;
     struct Stack* st = createStack();
   struct Stack *st2 = createStack();


     emp=fillEmployee();
     emp1=fillEmployee();
     emp2=fillEmployee();
    emp3=fillEmployee();

     push(st,emp); //first
     push(st,emp1); //last

    push(st2,emp2); //first
     push(st2,emp3); //last



     pop(st);


    pop(st2); //dequeue first which i emp
     //pop(st2); //same here ^

    return 0;
}
struct Stack* createStack(){



        struct Stack *stptr;

        stptr = (struct Stack*) malloc(sizeof(struct Stack));
        if(stptr){
            stptr-> head = NULL;
            stptr -> tail= NULL;
            stptr -> top=0;
        }

        return stptr;
}

struct Node* createNode(struct Employee m){
    struct Node *ptr;
    ptr= (struct Node*) malloc(sizeof(struct Node));

    if (ptr){
        ptr -> emp.id = m.id;
        ptr -> emp.salary = m.salary;
        strcpy(ptr -> emp.name ,m.name );
        ptr -> next = NULL;
    }
return ptr;
}

void push(struct Stack *st, struct Employee m){
        struct Node *ptr;
        ptr=createNode(m);
        if(ptr){
            if (st->head == NULL){
                st-> head = st -> tail = ptr;
            }
            else{
                st -> tail -> next = ptr;
                st -> tail = ptr;

            }


           (st->top)++;

        }
}

void pop(struct Stack *st){

         struct Node *ptr,*temp;


            if(st-> head == NULL ){
                printf("stack is EMPTY! \n");
            }
            else{
                ptr =st -> head;
                for(int i=0; i<(st->top)-1; i++){
                    ptr = ptr->next;

                                }

                temp = st-> tail;
                st->tail=ptr;
                (st->top)--;

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
