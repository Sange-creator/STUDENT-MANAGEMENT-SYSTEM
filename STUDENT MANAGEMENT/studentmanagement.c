#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*
head is a global pointer of Type Student
which will point to the first node in the created linked list.
The main merit of declaring head global is we can directly 
use it in any function without passing it as a parameter.
*/

struct Student
{
    int rollnumber;
    char name[100];
    char phone[100];
    float percentage;
    struct Student *next;
    
}* head;

/*
The insert function accepts student details as an argument.
It creates a new node with the student details
passed to the function and then inserts the new
node at the beginning of the linked list.*/

void insert(int rollnumber, char* name, char* phone, float percentage)
{
    
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->rollnumber = rollnumber;
    strcpy(student->name, name);
    strcpy(student->phone, phone);
    student->percentage = percentage;
    student->next = NULL;
    
    if(head==NULL){
        // if head is NULL
        // set student as the new head
        head = student;
    }
    else{
        // if list is not empty
        // insert student in beginning of head
        student->next = head;
        head = student;
    }
    
}

/*
The search function searches the record based on the roll number. 
The search function accepts 1 parameter that is the roll number of the student we want to search.
The function traverses all the nodes of the linked list to find the required record.*/

void search(int rollnumber)
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->rollnumber==rollnumber){
            printf("Roll Number: %d\n", temp->rollnumber);
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            printf("Percentage: %0.4f\n", temp->percentage);
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}

/*
The update function first searches for the node with the required roll number. 
If the node is found, the program asks the user to enter new updated values.
*/

void update(int rollnumber)
{
    
    struct Student * temp = head;
    while(temp!=NULL){
        
        if(temp->rollnumber==rollnumber){
            printf("Record with roll number %d Found !!!\n", rollnumber);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("Enter new percentage: ");
            scanf("%f",&temp->percentage);
            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;
        
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
    
}

/*
Delete works similar to search. 
We search for the record by it’s roll number. 
If the record is found, we delete it from the linked list.
*/

void Delete(int rollnumber)
{
    struct Student * temp1 = head;
    struct Student * temp2 = head; 
    while(temp1!=NULL){
        
        if(temp1->rollnumber==rollnumber){
            
            printf("Record with roll number %d Found !!!\n", rollnumber);
            
            if(temp1==temp2){
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1); 
            }
            
            printf("Record Successfully Deleted !!!\n");
            return;
            
        }
        temp2 = temp1;
        temp1 = temp1->next;
        
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
    
}

/*
Display function traverse the linked list and 
print all the details of each node of the linked list.
*/

void display()
{
    struct Student * temp = head;
    while(temp!=NULL){
        
        printf("\nRoll Number: %d\n", temp->rollnumber);
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        printf("Percentage: %0.4f\n\n", temp->percentage);
        temp = temp->next;
        
    }
}
int main()
{
    head = NULL;
    int choice;
    char name[100];
    char phone[100];
    int rollnumber;
    float percentage;
    printf("(1) Insert student details\n(2) Search for student details\n(3) Delete student details\n(4) Update student details\n(5) Display all student details");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &rollnumber);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter percentage: ");
                scanf("%f", &percentage);
                insert(rollnumber, name, phone, percentage);
                break;
            case 2:
                printf("Enter roll number to search: ");
                scanf("%d", &rollnumber);
                search(rollnumber);
                break;
            case 3:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollnumber);
                Delete(rollnumber);
                break;
            case 4:
                printf("Enter roll number to update: ");
                scanf("%d", &rollnumber);
                update(rollnumber);
                break;
            case 5:
                display();
                break;
        }
        
    } while (choice != 0);

    return 0;
}