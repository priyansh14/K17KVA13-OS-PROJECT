void calculateWaitTime(struct Process p[],int n,int waitTime[])
{
	int i,j;
	int rem[n];
	
	for( i=0;i<n;i++)
		rem[i]=p[i].burstTime;
		
	int completedProcesses=0,time=0,minimum=INT_MAX;
	int smallest=0,finishTime;
	boolean c=false;

while(completedProcesses!=n)
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
		waitTime[smallest]=finishTime-p[smallest].burstTime-p[smallest].arrivalTime;
		
		if(waitTime[smallest]<0)
		waitTime[smallest]=0;
	
	}
	
time++;



}


}
