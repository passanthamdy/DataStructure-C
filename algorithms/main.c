#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct Employee{
int id;
char name[10];
int salary;
};

struct Employee fillEmployee(void);
void addEmployee(struct Employee employees[SIZE]);
void displayAll(struct Employee employees[SIZE]);
void printEmployee(struct Employee em);
void showMenu(void);
void swap(struct Employee *e1, struct Employee *e2);
void mergeSort(struct Employee em[SIZE], int l, int h);
void merge(struct Employee em[SIZE], int l,int mid, int h);
void bubbleSort(struct Employee emp[SIZE]);
int binarySearch(struct Employee em[SIZE], int l, int h, int id);
int cntr=0;
int main()
{
    showMenu();
    struct Employee employees[SIZE];
     int f=1;


 while(f){
    /// variable for switch case
    int c;
    int h,l,fnd,id;
    scanf("%d", &c);
    switch(c){
    case 1:
        addEmployee(employees);
         break;
    case 2:
       displayAll(employees);
        break;

    case 3:
           bubbleSort(employees);
            displayAll(employees);
            break;
    case 4:
        printf("enter high\n");
        scanf("%d", &h);
        printf("enter low \n");
        scanf("%d", &l);
       mergeSort(employees, l,h);
       displayAll(employees);
       break;
    case 5:
        printf("enter high\n");
        scanf("%d", &h);
        printf("enter low \n");
        scanf("%d", &l);
        printf("enter the id of employee\n");
        scanf("%d", &id);
        bubbleSort(employees);
        printf("sorted\n");
        fnd=binarySearch(employees,l,h,id);
        printf("here\n");
        if (fnd==-1){
            printf("employee not found");
        }
        else{
                printf("employee found at location %d \n and his data :  ", fnd);
                printEmployee(employees[fnd]);

        }
        break;
    case 6:
        f=0;
        break;

}
}

return 0;
}
void showMenu(void){
    printf("1- Add Employee\n");
    printf("2- Display all employees\n");
     printf("3- Sort by ID\n");
      printf("4- Sort by name\n");
       printf("5- Search by ID \n");
    printf("6- Exit menu\n");
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
//DONE
void addEmployee(struct Employee employees[SIZE]){

    if (cntr<SIZE){

            employees[cntr] = fillEmployee();

            cntr++;

                    }
    else{
        printf("Your capacity is FULL!\n");
    }



}
//done
void displayAll(struct Employee employees[7]){
for (int i=0; i<SIZE && i<cntr; i++){
    printEmployee(employees[i]);
}
}
void printEmployee(struct Employee em){
      printf("the id of employee: %d \n", em.id);
     printf("the name of employee : %s \n", em.name);
       printf("the salary of employee: %d \n", em.salary);
        printf("\n");
}

void swap(struct Employee *e1, struct Employee *e2){
struct Employee temp;
temp = *e1;
*e1=*e2;
*e2=temp;
}

void bubbleSort(struct Employee emp[7]){
        for(int i=0; i<SIZE-1 && i< cntr-1; i++){
            for (int j=0; j<(SIZE-i-1) && j <cntr-1 ; j++){
                if(emp[j].id > emp[j+1].id){
                    swap(&emp[j], &emp[j+1]);
                }


            }
        }
}

void merge(struct Employee em[], int l,int mid, int h){
   struct Employee temp[7];
   int l1,l2,res;
   l1=l;
   l2=mid+1;
   int i=l;
   while(l1<=mid && l2 <=h){
    res=strcmp(em[l1].name , em[l2].name);
    if (res< 0)
    {
        temp[i] = em[l1];
        i++;
        l1++;
    }
    else{
        temp[i]=em[l2];
        i++;
        l2++;
    }

   }
   while(l1<=mid){
    temp[i]=em[l1];
    l1++;
    i++;
   }
   while (l2<=h){
    temp[i]=em[l2];
    l2++;
    i++;
   }
   for (i =l; i<=h; i++){
    em[i]=temp[i];
       }
}
void mergeSort(struct Employee em[], int l, int h){
 int mid = (l+h)/2;
 if(l<h){
 mergeSort(em,l,mid);
 mergeSort(em, mid+1, h);
 merge(em, l, mid, h);
 }
}

int binarySearch(struct Employee em[], int l, int h, int id){
    int mid ;
    int loc=-1;
    while (l<=h &&  loc== -1)
        {
            mid=(l+h)/2;
        if (em[mid].id == id){
            loc=mid;
        }
        else if(em[mid].id<id){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return loc;
}

