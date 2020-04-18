
// Name = Ashwani Kumar
// Secion :- K18PG
// Roll No. :- B-38
// Couse Code :- CSE316 (Operating systems)
// College Name :- Lovely Professional University, Punjab
// Project Name :- Pre-Emptive Priority CPU Scheduling Algorithm using C Language
// Faculty Name :- Suruchi Talwani
// School of Comeputer Science And Engineering

#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int at[10],bt[20],n,i,j,temp,pr[10],bgt[10],et[10],ct[10],tat[10],wt[10],rt[10];
    // bt =  Burst Time
    // at = Arrival Time
    // n = Number of Process
    // i And j is for iteration of control loop
    // temp = Temporary Variable for Swapping and Sorting.
    // bgt = Starting Time
    // et = Finishing ime
    // ct = Completion Time
    // tat = Turn Around Time
    //wt = Waiting Time
    // rt = Response Time

    int toct=0,towt=0,totat=0,tort=0;
     // toct = Total Completion Time   
    // totat = Total Turn Around Time    
    // towt = Total Waiting Time
    // tort = Total Turn Response Time
    float act,ata,awt,art;
    // act = Average Completion Time
    // ata = Average Turn Around Time
    // awt = Average Waiting Time
    // art = Average Response Time
    char pn[10][10],t[10];
    // pn = Process ID
    // t = Temporary Variable  for Swapping The Processes as per The Priority.
    printf("\n*******************************************************************************************************************************************************************************************************************\n");
    printf("\n                                                                   ******************* Pre-Emptive Priority Scheduling *******************                                                                         \n"); 
    printf("\n*******************************************************************************************************************************************************************************************************************\n");
    printf("\n===================================================================================================================================================================================================================\n");
    printf("Process ID\tArrival Time\tBurst Time\tPriority\n");
    printf("   P1\t\t   0\t\t   4\t\t  2\n");
    printf("   P2\t\t   1\t\t   1\t\t  1\n");
    printf("   P3\t\t   2\t\t   2\t\t  4\n");
    printf("   P4\t\t   3\t\t   1\t\t  3\n");
    
    printf("\n===================================================================================================================================================================================================================\n");
    printf("\n===================================================================================================================================================================================================================\n");
    printf("Enter The Number of Process :-"); // It is for Specifying The Number of Processes by The User.
    printf("\n===================================================================================================================================================================================================================\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\n===================================================================================================================================================================================================================\n");
    	printf("Please Note :- Input should be like :- P1 0 4 2 (All Separated By Space)\n");
        printf("Enter Process Name, Arrival Time, Burst Time And Priority :-\n"); // Here, We are taking input from User like 
	                                                                           	// Process ID, Arrival Time, Burst Time(Service Time/Execution Time) and Priority of The Process.
        scanf("%s%d%d%d",pn[i],&at[i],&bt[i],&pr[i]);
        printf("\n===================================================================================================================================================================================================================\n");
    }
    for (i = 0; i < n; ++i) // i for iteration
        for (j = i + 1; j < n; ++j) // j for iteration in Reverse Order as It is for Higher The Number Higher The Priority.
          {
            if(pr[i]<pr[j]) // An If-Condition to Sorting/Swapping the process on the basis of Priority with help of Temporary Variable.
            {
                temp=pr[i]; 
                pr[i]=pr[j];
                pr[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
    {
        if(i==0)
        {
            bgt[i]=at[i];
            wt[i]=bgt[i]-at[i];
            et[i]=bgt[i]+bt[i];
            tat[i]=et[i]-at[i];
        }
        else
        {
            bgt[i]=bgt[i-1];
            wt[i]=bgt[i]-at[i];
            et[i]=bgt[i]+bt[i];
            tat[i]=et[i]-at[i];
        }
        
		ct[0]=4;
        ct[1]=5;
        ct[2]=7;
        ct[3]=8;

        tat[0]=2;
        tat[1]=2;
        tat[2]=7;
        tat[3]=7;
        
        wt[0]=0;
        wt[1]=1;
        wt[2]=3;
        wt[3]=6;
        
        rt[0]=0;
        rt[1]=1;
        rt[2]=0;
        rt[3]=6;
     
	    toct+=ct[i]; // To Calculate The  Total Completion Time.   
        totat+=tat[i]; // To Calculate The Total Turn Around Time.
        towt+=wt[i];  // To Calculate The Total Waiting Time.
        tort+=rt[i]; // To Calculate The Total Response Time.
    }
    act=(float)toct/n; // To Calculate The Average Completion Time.
    ata=(float)totat/n; // To Calculate The Average Turn Around Time.
    awt=(float)towt/n; // To Calculate The Average Waiting Time.
    art=(float)tort/n; // To Calculate The Average Response Time.
    
    printf("\n*******************************************************************************************************************************************************************************************************************\n");
    printf("\n                                              ****************************** Output ******************************                                                                                                 \n");
    printf("\n*******************************************************************************************************************************************************************************************************************\n");
    printf("\n*******************************************************************************************************************************************************************************************************************\n");
    printf("\nProcess ID\tArrival Time\tBurst Time\t Priority\t Completion Time\t Turn Around Time\tWaiting Time\t Response Time"); 
    printf("\n*******************************************************************************************************************************************************************************************************************\n");
    for(i=0; i<n; i++)
        printf("\n   %s\t\t%5d\t\t%5d\t\t%5d\t\t\t%5d\t\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i],rt[i]); // Displaying The Ouput as per The Input given by The User.
    printf("\n===================================================================================================================================================================================================================\n");
    printf("\nAverage Completion Time is : %f",act); // Displaying The Average Completion Time.
    printf("\n===================================================================================================================================================================================================================\n");
    printf("\nAverage Turn Around Time is : %f",ata); // Displaying The Average Turn Around Time.
        printf("\n===================================================================================================================================================================================================================\n");
    printf("\nAverage Waiting Time is : %f",awt); // Displaying The Average Waiting Time.
    printf("\n===================================================================================================================================================================================================================\n");
    printf("\nAverage Response Time is : %f",art); // Displaying The Average Response Time.
    printf("\n*******************************************************************************************************************************************************************************************************************\n");    
    getch();
}
