#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
    int pid,bt,wt,tat;
    struct node *next;
}*f=NULL,*r=NULL;

int isEmpty ();
void enqueue(int, int);
void calculate();
void display();

void main()
{
    int n,burst,id;
    printf("FCFS  algortihm!\n");
    printf("Enter number of processes \n");
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        printf("Enter burst time of process %d \n",i+1);
        scanf("%d",&burst);
        id=i+1;
        enqueue(id,burst);
    }
        
    calculate();

    display(n);
        
    

}
int isEmpty()
{
    if(f==NULL)
    return 1;
    else
    return 0;
}
void enqueue(int x,int y)
{
    struct node *p=(struct node *)malloc(sizeof(struct node ));
    if(!(p))
    {
        printf("queue is full");
    }
    else
    {
        p->pid=x;
        p->bt=y;
        p->next=NULL;
        if(f==NULL)
        f=r=p;
    else
    {
        r->next=p;
        r=p;
    }
    }
}

void calculate(){
    int sum = 0;
    for(struct node *i=f;i!=NULL;i=i->next){
        i->wt=sum;//wt=tat-bt
        sum+=i->bt;
        i->tat=sum;//tat=ct-at,at=0,tat=ct
    }

}   

void display(int n)
{

    int tot_wt=0,tot_tat=0;
    float avg_wt,avg_tat; 
    
    printf("Pid\t Burst \t Wait \t Turnaround \n");
    for(struct node *i=f;i!=NULL;i=i->next){
        //Prints each node by incrementing pointer  
        printf("%d \t %d \t %d \t %d \n",i->pid,i->bt,i->wt,i->tat);  
        tot_tat+=i->tat;
        tot_wt+=i->wt;
       
    }  
    
    avg_wt=(float)tot_wt/(float)n;
    avg_tat=(float)tot_tat/(float)n;

    printf("Total waiting time: %d\n",tot_wt);
    printf("Average waiting time: %f\n",avg_wt);

    printf("Total turnaround time: %d\n",tot_tat);
    printf("Average turnaround time: %f\n",avg_tat);
}