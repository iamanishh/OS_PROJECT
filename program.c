#include<stdio.h>
#include<conio.h>
int main()

{
 int TSlice,ProcessID[10],need[10],WaitingTime[10],tat[10],i,j,n,n1;
 int BurstTime[10],flag[10],TurnAroundTime=0,twt=0;
 float aWaitingTime,atat;

printf("\t\t\t\t\t\tROUND ROBIN SCHEDULING \n"); 
printf("\t\t\t\t\t***********************************\n");
printf("\t\t\t\t\t___________________________________\n"); 

printf("Enter the number of Processors : \n");
scanf("%d",&n);
n1=n;
 
printf("\nEnter the Timeslice : \n");
scanf("%d",&TSlice);

for(i=1;i<=n;i++)
{
printf("\t\t\t\t Enter the arrival time of process %d: ",i);
scanf("%d",&ProcessID[i]);
 
printf("\t\t\t\t Enter the Burst Time for the process :  "); 
scanf("%d",&BurstTime[i]);
   need[i]=BurstTime[i];
   }

for(i=1;i<=n;i++) 
{
  flag[i]=1;
  WaitingTime[i]=0;
 }
 
while(n!=0)
{
   for(i=1;i<=n;i++)
   
{
if(need[i]>=TSlice)
     
{
    for(j=1;j<=n;j++)
       
{
	if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
	  
WaitingTime[j]+=TSlice;
}

need[i]-=TSlice;
      
 if(need[i]==0)
      
 {
	 flag[i]=0;
	 n--;
       }
     }
     
else
    
 {
       for(j=1;j<=n;j++)
      
 {
	  if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
	  
WaitingTime[j]+=need[i];
       }
       
need[i]=0;
       
n--;
       
flag[i]=0;
  
 }
 }
}

for(i=1;i<=n1;i++)

{
  tat[i]=WaitingTime[i]+BurstTime[i];
  
twt=twt+WaitingTime[i];
  
TurnAroundTime=TurnAroundTime+tat[i];
}

aWaitingTime=(float)twt/n1;

atat=(float)TurnAroundTime/n1;


printf("\n\n\n\t\t\t\t\t\ROUND ROBIN SCHEDULING ALGORITHM \n\n");

printf("___________________________________________________________________________________________________________________");

printf("\n\n Process \t\t Arrival time  \t\tBurstTime \t\t Waiting Time \t\t TurnaroundTime \n ");

for(i=1;i<=n1;i++)
{
 
 printf("\n%5d \t\t\t %5d \t\t\t %5d \t\t\t %5d \t\t\t %5d \n", i,ProcessID[i],BurstTime[i],WaitingTime[i],tat[i]);
}
printf("___________________________________________________________________________________________________________________");

printf("\n The average Waiting Time=4.2",aWaitingTime);

printf("\n The average Turn around Time=4.2",atat);
getch();
}         

