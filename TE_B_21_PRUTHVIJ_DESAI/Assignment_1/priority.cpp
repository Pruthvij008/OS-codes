

#include<iostream>
using namespace std;

struct task
{
	int tno;
	int at;
	int bt;
	int wt;
	int tat;
	int pr;
};

void getdata(task t[],int n)
{
	for (int i=0; i<n; i++)
	{
		cout<<"\nFor Task "<<i+1<<" : "<<endl;
		cout<<"\tEnter Task Number: ";
		cin>>t[i].tno;
		cout<<"\tEnter Arrival Time: ";
		cin>>t[i].at;
		cout<<"\tEnter Burst Time: ";
		cin>>t[i].bt;
		cout<<"\tEnter Priority: ";
		cin>>t[i].pr;
	}
}

void displaydata(task t[],int n)
{
	cout<<"\n\tTask AT   BT  Priority "<<endl;
	for (int i=0; i<n; i++)
	{
		cout<<"\n\tT"<<t[i].tno<<"\t"<<t[i].at<<"\t"<<t[i].bt<<"\t"<<t[i].pr<<endl;
	}
	
}

void sgf(task t[],int n)
{
	int i,j;
	task temp;
	for (i=0; i<n-1; i++)
	{
		for (j=0; j<n-i-1; j++)
		{
			if (t[j].bt > t[j+1].bt)
			{
				temp=t[j];
				t[j]=t[j+1];
				t[j+1]=temp;
			}
		}
	}
	cout<<"\n\tTask Arrival Burst Time Wating Turn Around"<<endl;
	for (int i=0; i<n; i++)
	{
		cout<<"\n\tT"<<t[i].tno<<"\t"<<t[i].at<<"\t"<<t[i].bt<<"\t"<<t[i].wt<<"\t"<<t[i].tat<<endl;
	}	
}

void prio(task t[],int n)
{
	int i,j;
	task temp;
	for (i=0; i<n-1; i++)
	{
		for (j=0; j<n-i-1; j++)
		{
			if (t[j].pr > t[j+1].pr)
			{
				temp=t[j];
				t[j]=t[j+1];
				t[j+1]=temp;
			}
			else if (t[j].pr == t[j+1].pr)
			{
				if (t[j].bt > t[j+1].bt)
				{
					temp=t[j];
					t[j]=t[j+1];
					t[j+1]=temp;
				}
			}
		}	
	}	
}

void wt_tat(task t[],int n)
{
	t[0].wt=0;
	t[1].tat=t[0].bt;
	
	for (int i=0;i<n;i++)
	{
		int ct=0;
		for (int j=0;j<i;j++)
		{
			ct=ct+t[j].bt;
		}
		t[i].wt=ct-t[i].at;
		t[i].tat = t[i].wt + t[i].bt;
	}
	
	cout<<"\n\tTask AT   BT   WT   TAT"<<endl;
	for (int i=0; i<n; i++)
	{
		cout<<"\n\tT"<<t[i].tno<<"\t"<<t[i].at<<"\t"<<t[i].bt<<"\t"<<t[i].wt<<"\t"<<t[i].tat<<endl;
	}
}

void cal_avg(task t[],int n)
{
	float sum_wt=0;
	for (int i=0;i<n;i++)
	{
		sum_wt += t[i].wt;
	}
	float avg_wt = sum_wt/n;
	cout<<"\nAverage Waiting Time: "<<avg_wt<<endl;
	
	float sum_tat=0;
	for (int i=0;i<n;i++)
	{
		sum_tat += t[i].tat;
	}
	float avg_tat = sum_tat/n;
	cout<<"\nAverage Waiting Time: "<<avg_tat<<endl;
}

int main()
{
	task obj[5];
	int n;
	cout<<"\nEnter the No. of Tasks: ";
	cin>>n;
	
	getdata(obj,n);
	cout<<"\nGiven Data"<<endl;
	displaydata(obj,n);

	//cout<<"\n\tSGF"<<endl;
	//sgf(obj,n);
	cout<<"\n\tPriority"<<endl;
	prio(obj,n);
	wt_tat(obj,n);
	cal_avg(obj,n);
	return 0;
}

/*
Output
kkw@kkw-HP-280-Pro-G6-Microtower-PC:~/Desktop/B_58$ g++ priority.cpp
kkw@kkw-HP-280-Pro-G6-Microtower-PC:~/Desktop/B_58$ ./a.out

Enter the No. of Tasks: 4

For Task 1 : 
	Enter Task Number: 1
	Enter Arrival Time: 0
	Enter Burst Time: 7
	Enter Priority: 4 

For Task 2 : 
	Enter Task Number: 2
	Enter Arrival Time: 0
	Enter Burst Time: 4
	Enter Priority: 3

For Task 3 : 
	Enter Task Number: 3
	Enter Arrival Time: 0
	Enter Burst Time: 1
	Enter Priority: 2

For Task 4 : 
	Enter Task Number: 4
	Enter Arrival Time: 0
	Enter Burst Time: 3
	Enter Priority: 1

Given Data

	Task AT   BT  Priority 

	T1	0	7	4

	T2	0	4	3

	T3	0	1	2

	T4	0	3	1

	Priority

	Task AT   BT   WT   TAT

	T4	0	3	0	3

	T3	0	1	3	4

	T2	0	4	4	8

	T1	0	7	8	15

Average Waiting Time: 3.75

Average Waiting Time: 7.5

*/
