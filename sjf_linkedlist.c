#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct node{
    int pid,bt,wt,tat;
    struct node *next;
}*head=NULL;


//definition of functions required
void linkedlist(int pid,int bt);
void sort();
void calculate();
void display();


//linked list creation for insertng process id and burst time of process
void linkedlist(int x,int y){
    struct node* temp;
    temp = (struct node* )malloc(sizeof(struct node));
    temp->pid= x;
    temp->bt=y;
    temp->next = NULL;
    
    if(head == NULL){
        head = temp;
        return;//when linked list is empty
    }
    else{
        struct node* p=head;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last node.The last node always points to NULL.
        }
        p->next = temp;//Point the previous last node to the new node created.
    }
}

int main(void)
{
    
    struct node* curr = head;
    
    int n,burst,id;
    printf("SJF non-preemptive algortihm!\n");
    printf("Enter number of processes \n");
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        printf("Enter burst time of process %d \n",i+1);
        scanf("%d",&burst);
        id=i+1;
        linkedlist(id,burst);
        
    }

    sort();

    calculate(n);

    display(n);

}

    
    
    



//selection sorting(recursive) all processes acc 2 BT
void sort() {  
        //Node current will point to head  
        struct node *current = head, *index = NULL;  
        int temp;  
          
        if(head == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                //Node index will point to node next to current  
                index = current->next;  
                  
                while(index != NULL) {  
                    //If current node's burst time is greater than index's node burst time, 
                    //swap them  
                    if(current->bt > index->bt) {  
                        temp = current->bt;  
                        current->bt = index->bt;  
                        index->bt = temp;  
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
        }  
    }  

void calculate(int n){
    int sum = 0;
    struct node *curr = head;  

    while(curr!=NULL){
        curr->wt=sum;//wt=tat-bt
        sum+=curr->bt;
        curr->tat=sum;//tat=ct-at,at=0,tat=ct
        curr=curr->next;
    }

}   
//display() will display all the nodes present in the list  
void display(int n) {  
    int tot_wt=0,tot_tat=0;
    float avg_wt,avg_tat; 
    struct node *current = head;  
    
    printf("Pid\t Burst \t Wait \t Turnaround \n");
    while(current != NULL) {  
        //Prints each node by incrementing pointer  
        printf("%d \t %d \t %d \t %d \n",current->pid,current->bt,current->wt,current->tat);  
        tot_tat+=current->tat;
        tot_wt+=current->wt;
        current = current->next;  
    }  
    
    avg_wt=(float)tot_wt/(float)n;
    avg_tat=(float)tot_tat/(float)n;

    printf("Total waiting time: %d\n",tot_wt);
    printf("Average waiting time: %f\n",avg_wt);

    printf("Total turnaround time: %d\n",tot_tat);
    printf("Average turnaround time: %f\n",avg_tat);
}  