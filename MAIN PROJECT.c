#include <stdio.h> //Standard Input Output Library , used for basic operations in C language.
#include <stdlib.h> //Standard Library which contains all the functions related to File Handling
#include <string.h>// For using inbuilt string functions
#include<windows.h>//  Used for Sleep() system call and CreateFile() system call
#include<stdbool.h>// Boolean is not a primitive data type in C language.This header file provides functions for Bool variables.
#include<winbase.h> //Used for SetFileSecurity() System Call only

//System Calls implemented -Sleep(),CreateFile(),System(color);


//I have taken process as a structure with attributes- Arrival Time,Burst Time and Process No/ID
struct Process{
	int p_no,arrivalTime,burstTime;
};

//Function for opening screen and main menu and color changes
void ScreenShow()
{
		system("cls");
	printf("\n\n\n\n");
	system("color 0B");
	printf("\t\t\t  CSE316 :: Operating Systems Project ");
	
	printf("\n");
	printf("\n");
	printf("\n");
	Sleep(1000);
	system("color 0A");
	printf("\t\t\t  Name :: Priyansh Tiwari ");
	printf("\n");
	printf("\n");
	printf("\n");
	
	Sleep(1200);
	system("color 04");
	printf("\t\t\t  Reg. Number :: 11711226");
	printf("\n");
	printf("\n");
	printf("\n");
	Sleep(1200);
	system("color 06");
	printf("\t\t\t  Roll Number :: 13");
	printf("\n");
	printf("\n");
	printf("\n");
	Sleep(1200);
	system("color 0D");
	printf("\t\t\t  Section :: K17KV");
	printf("\n");
	printf("\n");
	printf("\n");
	Sleep(1200);
	system("color 0A");
	printf("\t\t\t  Submitted to :: Sumit Mittu Sir on 14th April 2019 ");
	Sleep(1500);
	system("cls");
	printf("\t\t Welcome To Algo Implementer\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t What would you like to do? Enter your choice" );
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t 1. Read Problem Statement ");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t 2. Solution :: Choosing this option will implement SRTF algo and show Ave. Waiting and Turnaround Time ");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t 3. Information about the System Calls used and code");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t 4. Exit");
	printf("\n");
	int choice;
	scanf("%d",&choice);
	char ch;
	FILE *file=fopen("Problem Statement.txt","r");
				if (file == NULL){
      			perror("Error while opening the file.\n");
      			exit(EXIT_FAILURE);
   			}
   			 FILE *file2=fopen("Information.txt","r");
				if (file2 == NULL){
      			perror("Error while opening the file.\n");
      			exit(EXIT_FAILURE);
   			}
	switch(choice)
		{
			case 1:
				system("cls");
				system("color 04");
				printf("\n\n\n\n\n");
			    while((ch = fgetc(file)) != EOF)
      			printf("%c", ch);
 
			   	fclose(file);
			   	printf("\n\n\t\tPress any key to go back");
			   	if(getch())
			   	ScreenShow();
 				break;
			case 2:
				system("cls");
				printf("\n");
				system("color 09");
				mainfunc();
				
			   	printf("\n\n\t\tPress any key to go back");
			   	if(getch())
			   	ScreenShow();
				break;
			case 3:
				system("cls");
				system("color 06");
				
				 
			    while((ch = fgetc(file2)) != EOF)
      			printf("%c", ch);
 
			   	fclose(file2);
			   	printf("\n\n \t\tPress any key to go back");
			   	if(getch())
				   ScreenShow();
 				break;
 			case 4:
 				exit(0);
		}

	
}

//Function which calculates the waiting time.This function implements Preemptive SJF or SRTF Algorithm.
void calculateWaitTime(struct Process p[],int n,int waitTime[])
{
	int i,j;
	int rem[n];
	
	for( i=0;i<n;i++)
		rem[i]=p[i].burstTime;
		
	int completedProcesses=0,time=0,minimum=INT_MAX;
	int smallest=0,finishTime;
	boolean c=false;

while(completedProcesses!=n)  //until all processes are finished
{
	for(j=0;j<n;j++)
	{
		if((p[j].arrivalTime<=time)&&(rem[j]<minimum)&&rem[j]>0){
		minimum=rem[j];
		c=true;
		smallest=j;	
		}
	}
	if(c==false){
		time+=1;
		continue;
		
	}
	rem[smallest]--;
	minimum=rem[smallest];
	if(minimum==0)
	minimum=INT_MAX;
	
	if(rem[smallest]==0)
	{
		completedProcesses+=1;
		c=false;
		finishTime=time+1;
		
		//Calculation of waiting time
		waitTime[smallest]=finishTime-p[smallest].burstTime-p[smallest].arrivalTime;
		
		if(waitTime[smallest]<0)
		waitTime[smallest]=0;
	
	}
	
time++;



}


}

//Function which calculates the TurnAround Time
void calculateTurnAroundTime(struct Process p[],int n,int waitTime[],int tat[])
{
	int i,j;
	//Turnaround Time can directly be written as the sum of burst time and waiting time.
	for(i=0;i<n;i++)
	tat[i]=p[i].burstTime+waitTime[i];
}

//Function which calculates Average Waiting and TA time

void calculateAverageTime(struct Process p[],int n)
{
	int i,j,waitTime[n],tat[n],totalWaitTime=0,totalTA=0;
	
	calculateWaitTime(p,n,waitTime);
	calculateTurnAroundTime(p,n,waitTime,tat);
	printf("Process \t Arrival Time \t Burst Time \t Waiting Time \t Turnaround Time\n");  
	
	for(i=0;i<n;i++)
	{
	totalWaitTime+=waitTime[i];
	totalTA+=tat[i];
	printf("%d \t\t %d \t\t %d \t\t %d \t\t %d\n",p[i].p_no,p[i].arrivalTime,p[i].burstTime,waitTime[i],tat[i]);		
	}
	
	printf("\n Average Waiting Time --> %f",(float)totalWaitTime/(float)n );
	printf("\n Average TA Time --> %f",(float)totalTA/(float)n );
}

void mainfunc()
{
		int n=5;
	int a=0,number;
	int i=0,j,k=0,count=0;
	char ch;
	struct Process p[5];
	
	int temp[10];
	
	//Reading integers from the file and storing it in an array
	printf("\n");
	FILE *file;
	file=fopen("CPU_BURST.txt","r");
	 while ( fscanf(file, "%d", & number ) == 1 )  
             { 
              
              	if(number<=0)
              	{
              		printf("THERE ARE NEGATIVE NUMBERS IN THE FILE AND THEY ARE INVALID.EXITING PROGRAM NOW.");
              		exit(1);
				  }
            	temp[i]=number;
            	i++;
			 } 
	p[0].burstTime=6;
	p[1].burstTime=9;
	p[2].burstTime=5;
	p[3].burstTime=1;
	p[4].burstTime=12;
	
	for(i=0;i<5;i++)
	{
		p[i].arrivalTime=i*3;  //According to question,the processes arrive every 3 second.
			
		p[i].p_no=i+1; //Process no of the processes is given here.
			
	}
	
    calculateAverageTime(p,n);
}
int main()
{
ScreenShow();
   
return 0;
}


