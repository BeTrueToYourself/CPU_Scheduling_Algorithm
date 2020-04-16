
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
    int at[10],bt[20],n,i,j,temp,pr[10],bgt[10],et[10],wt[10],tat[10];
    // bt =  Burst Time
    // at = Arrival Time
    // n = Number of Process
    // i And j is for iteration of control loop
    // temp = Temporary Variable for Swapping and Sorting.
    // bgt = Starting Time
    // et = Finishing ime
    //wt = Waiting Time
    // tat = Turn Around Time
    int towt=0,totat=0;
    // towt = Total Waiting Time
    // totat = Total Turn Around Time
    float awt,ata;
    // awt = Average Waiting Time
    // ata = Avaerage Turn Around Time
    char pn[10][10],t[10];
    // pn = Process ID
    // t = Temporary Variable  for Swapping The Processes as per The Priority.
    printf("\n*******************************************************************************************************************************************************************************************************************\n");
    printf("\n                                                                   ******************* Pre-Emptive Priority Scheduling *******************                                                                         \n"); 
    printf("\n*******************************************************************************************************************************************************************************************************************\n");
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
        totat+=tat[i]; // To Calculate The Total Turn Around Time.
        towt+=wt[i];  // To Calculate The Total Waiting Time.
    }
    ata=(float)totat/n; // To Calculate The Average Turn Around Time.
    awt=(float)towt/n; // To Calculate The Average Waiting Time.
    printf("\n*******************************************************************************************************************************************************************************************************************\n");
    printf("\n                                              ****************************** Output ******************************                                                                                                 \n");
    printf("\n*******************************************************************************************************************************************************************************************************************\n");
    printf("\n*******************************************************************************************************************************************************************************************************************\n");
    printf("\nProcess ID\tArrival Time\tBurst Time\t Priority\tWaiting Time\tTurn Around Time"); 
    printf("\n*******************************************************************************************************************************************************************************************************************\n");
    for(i=0; i<n; i++)
        printf("\n   %s\t\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],bt[i],pr[i],wt[i],tat[i]); // Displaying The Ouput as per The Input given by The User.
    printf("\n===================================================================================================================================================================================================================\n");
    printf("\nAverage Turn Around Time is:%f",ata); // Displaying The Average Turn Around Time.
    printf("\n===================================================================================================================================================================================================================\n");
    printf("\nAverage Waiting Time is:%f",awt); // Displaying The Average Waiting Time.
    printf("\n*******************************************************************************************************************************************************************************************************************\n");    
    getch();
}
