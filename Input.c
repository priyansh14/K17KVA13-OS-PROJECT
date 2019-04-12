#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
void ScreenShow()
{
	
}

void calculate()
{
	
}

void display()
{
	
}


int main()
{
	FILE *fp = fopen("CPU_BURST.txt", "r");
     int burstTime[20],p[20],waitTime[20],tat[20],i=0,j,n=5,total=0,pos,temp;
     float avg_wt,avg_tat;
     printf("\nReading CPU_BURST.txt File\n");
     while((getc(fp))!=EOF)
     {

         fscanf(fp, "%d", &burstTime[i]);
         if(burstTime[i]>0){
            p[i]=i+1;  
		    i++;
		}         

     }
     printf("PROCESS\t BURST TIME\n");
for(j=0;j<n;j++)
{
	
	printf("P%d\t %d\n",p[j],burstTime[j]);
}

for(i=0;i<n;i++)
{
	
	for(j=i+1;j<n;j++)
	{
		if(burstTime[i]>burstTime[j])
		{
			temp=burstTime[i];
			burstTime[i]=burstTime[j];
			burstTime[j]=temp;
			pos=p[i];
			p[i]=p[j];
			p[j]=pos;
		}
	}
}


}
