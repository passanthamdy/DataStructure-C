#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee {
int id;
char name[10];
int salary;

};
struct Node{
struct Employee emp;
struct Node *prev;
struct Node *next;
        };
struct Node *head = NULL;
struct Node *tail=NULL;

struct Node * createNode(struct Employee empdata);
int addNode(struct Employee empdata);
struct Node * searchNodeById(int id);
void displayNode(struct Node *ptremp);
void displayAllNodes(void);
int deleteNode( int loc);
int insertNode(struct Employee em, int loc);
void FreeList(void);
void ShowMenu();
void checkReturnValue(int a);
struct Employee fillEmployee(void);
int main()
{
    struct Node *p1;
    ShowMenu();
    struct Employee em;
int f=1;
 while(1){
    /// variable for switch case
    int c,d,rtval;
    scanf("%d", &c);
    switch(c){
        ///Add one student
    case 1:
        em = fillEmployee();
        rtval =addNode(em);
        checkReturnValue(rtval);
         break;
         ///Display certain student
    case 2:
        printf("please insert location to add employee in \t");
        scanf("%d", &d);
        em=fillEmployee();
        rtval =insertNode(em,d);
        checkReturnValue(rtval);
        break;
        ///display all students
    case 3:
        displayAllNodes();
        break;
        ///exit program
    case 4:
        printf("Please enter the id of employee\n");
        scanf("%d", &d);
        p1 =searchNodeById(d);
        displayNode(p1);
        break;
    case 5:
        printf("Please enter the location of employee");
        scanf("%d", &d);
        rtval=deleteNode(d);
        checkReturnValue(rtval);
        break;
    case 6:
        FreeList();
        break;
    case 7:
        f=0;
        break;
            }

}
return 0;
}
void checkReturnValue(int a){
if(a)
            printf("Operation DONE\n");
        else
            printf("Failed!\n");
}
struct Node * createNode(struct Employee empdata){
        struct Node* ptr;
        ptr = (struct Node* )malloc(sizeof(struct Node));
        if(ptr){
            ptr -> emp.id = empdata.id;
            ptr -> emp.salary = empdata.salary;
            strcpy(ptr->emp.name, empdata.name);
             ptr -> prev=NULL;
             ptr -> next =NULL;

}


return ptr;
}

///function that add nodde in tail of linkedlist
int addNode(struct Employee empdata){
    int ret =0;
    struct Node* ptr;
    ptr= createNode(empdata);
    if(ptr){
            /// we dont have list
        if (head == NULL){
            head = tail = ptr;
        }
    ///there's a list exist
        else{
            ptr -> prev=tail;
           tail -> next = ptr;
            tail=ptr;
        }
        ret=1;
    }

    return ret;


}
struct Node * searchNodeById(int id){
    struct Node *ptr;
    ptr=head;
    while((ptr->emp.id != id) && (ptr)){
        ptr = ptr -> next;
    }

    return ptr;
}
void displayNode(struct Node *ptremp){
    if(ptremp){
    printf("the data belongs to the id %d \n his name is %s \n and his salary is %d \n",
            ptremp -> emp.id, ptremp -> emp.name,ptremp -> emp.salary);
    }
    else{
        printf("NOT FOUND");
    }


}
void displayAllNodes(void){
    struct Node *ptr;
    ptr=head;
    while(ptr){
        printf("the data belongs to the id %d \n his name is %s \n and his salary is %d \n \n \n",
            ptr -> emp.id, ptr -> emp.name,ptr -> emp.salary);

        ptr = ptr-> next;
    }

}
int insertNode(struct Employee em, int loc){
        int rt=0;
        struct Node *ptr, *ptrcur;
        ptr = createNode(em);
        if (ptr){

            if(!head){
                head=tail=ptr;
                    }
            else{
                if (loc ==0){
                        ptr -> next = head;
                        head -> prev = ptr;
                        ptr=head;

                            }
                else {
                    ptrcur = head;
                    for(int i=0; i<loc-1 && (ptrcur); i++){
                        ptrcur = ptrcur -> next;
                                                }
                        if(ptrcur == tail || ptrcur == NULL){
                            tail -> next = ptr;
                            ptr -> prev = tail;
                            tail = ptr;
                        }
                        else
                            {
                            ptr -> prev = ptrcur;
                            ptr -> next = ptrcur -> next;
                            ptrcur -> next -> prev = ptr;
                            ptrcur -> next = ptr;
                            }
                    }

                }
               rt=1;
            }
            return rt;
        }
void FreeList(void){
    struct Node *ptr;
    while(head){
        ptr = head;
        head = head -> next;
        free(ptr);
    }
    tail=NULL;

}
int deleteNode( int loc){
    int f=0;
    struct Node *ptr;
    if (loc==0){
        ptr=head;
        head = ptr -> next;
        f=1;
        free(ptr);
                }
    else {
        ptr = head;
        for(int i=0; (i<loc) && (ptr); i++){
            ptr = ptr -> next;
                                            }
        if(ptr == tail )
            {
                ptr=tail;
                tail = ptr -> prev;
                tail->next = NULL;
            }

            else {
                ptr -> prev -> next = ptr -> next;
                ptr -> next -> prev = ptr -> prev;

            }
            f=1;
            free(ptr);

        }
    // if flag =0 so delete is done successfully, if f = 1 so loc given is wrong
    return f;

}
void ShowMenu(){
///Display the menu
    printf("1- Add Employee\n");
    printf("2-Insert Employee \n");
    printf("3- Display all Employees\n");
    printf("4-Search by id\n");
    printf("5-Delete Employee\n");
    printf("6-Delete all employees\n");
    printf("7-Exit menu\n");
    }

struct Employee fillEmployee(void){
    struct Employee em;
    printf("Enter the id of employee : ");
    scanf("%d", &em.id );
    printf("Enter the Name of Employee : ");
    scanf("%s", em.name );
        printf("Enter salary of employee : ");
        scanf("%d", &em.salary );

    return em;
}
