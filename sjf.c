#include <stdio.h>

struct pcb{
    int wt,bt,tat,pid;
};


int main(void)
{
    struct pcb p[10],temp;
    int wtot=0,tat_tot=0,n,sum=0;
    float wavg=0,tat_avg=0;

    printf("SJF non-preemptive algortihm!\n");
    printf("Enter number of processes \n");
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        printf("Enter burst time of process %d \n",i+1);
        scanf("%d",&p[i].bt);
        p[i].pid=i+1;
    }

    for (int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].bt>p[j+1].bt){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    for (int i=0;i<n;i++){
        p[i].wt=sum;//wt=tat-bt
        sum+=p[i].bt;
        p[i].tat=sum;//tat=ct-at,at=0,tat=ct
    }

    
    printf("Pid\t Burst \t Wait \t Turnaround \n");

    for (int i=0;i<n;i++){
        printf("%d \t %d \t %d \t %d \t %d \n",p[i].pid,p[i].bt,p[i].wt,p[i].tat);
        wtot+=p[i].wt;
        tat_tot+=p[i].tat;
    }

    wavg=(float)wtot/(float)n;
    tat_avg=(float)tat_tot/(float)n;

    printf("Total waiting time: %d\n",wtot);
    printf("Average waiting time: %d\n",wavg);

    printf("Total turnaround time: %d\n",tat_tot);
    printf("Average turnaround time: %d\n",tat_avg);






}