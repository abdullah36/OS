/SJF(non preemptive) Scheduling

#include<stdio.h>
int b[10],no[10],wt[10],ta[10],st;
void main()
{
int i,j,sb=0,n,l,temp,c;
float avgw,tw=0,tt=0,avgt;
printf("Enter no of processes\n");
scanf("%d",&n);
for(i=0;i<n;i++)
    no[i]=i;

for(i=0;i<n;i++)
   {
    printf("Enter Burst Time for process %d\n",i);
    scanf("%d",&b[i]);
   }
for(i=0;i<n-1;i++)
   for(j=0;j<n-1-i;j++)
      if(b[j]>b[j+1])
       {
        temp=b[j];
        b[j]=b[j+1];
        b[j+1]=temp;
        temp=no[j];
        no[j]=no[j+1];
        no[j+1]=temp;
        }
l=0;

for(i=0;i<n;i++)
   {
    if(i==0)
      sb=l;
    else
    {
    sb=sb+b[i-1];
    st=sb;
    wt[i]=st;
    }

   }
for(i=0;i<n;i++)
  ta[i]=wt[i]+b[i];

for(i=0;i<n;i++)
  tw=tw+wt[i];
avgw=tw/n;

for(i=0;i<n;i++)
  tt=tt+ta[i];
avgt=tt/n;
printf("\tGnatt Chart :\n");
printf("\t+");

for(i=0;i<n;i++)
printf("-------+");
printf("\n");
printf("\t|");
for(i=0;i<n;i++)
printf("   %d   |",no[i]);
printf("\n");
printf("\t+");
for(i=0;i<n;i++)
printf("-------+");
printf("\n\t%d",l);
c=l;
for(i=0;i<n;i++)
  {
    c=c+b[i];
    printf("\t%d",c);
  }
printf("\n\n");

printf("\tProcess\t\tBT\t\tWT\t\tTAT\n");
for(i=0;i<n;i++)
printf("\t%d\t\t%d\t\t%d\t\t%d\n",no[i],b[i],wt[i],ta[i]);

printf("\nAverage WT is %f\n",avgw);
printf("\nAverage TAT is %f\n",avgt);
}


