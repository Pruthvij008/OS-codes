#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Task{
public:
	int BurstTime;

	int idx;
	int waitTime;
	int TATime;
	void Taskinput(int BurstTime,int idx)
	{
		this->BurstTime=BurstTime;
		this->idx=idx;	
	}
	void display()
	{
		cout<<"T"<<idx<<"\t\t"<<BurstTime<<"\n";
	}
	void display_chart()
	{
		cout<<"T"<<idx<<"\t"<<BurstTime<<"\t\t"<<waitTime<<"\t\t"<<TATime<<"\n";
	}
};

int main()
{
	int COMTIME=0;
	int n,Burstime;
	cout<<"Enter number of task:";
	cin>>n;
	Task T[n];
    cout<<"Enter Burst Time for tasks !\n";
	for(int i=0;i<n;i++)
	{	cout<<"T"<<i+1<<": ";
		cin>>Burstime;
		T[i].Taskinput(Burstime,i+1);
	}
     cout<<"First Impression \n";
     for(int i=0;i<n;i++)
	{
		T[i].display();
	}
    cout<<"After Sort according to burst time \n";
    Task temp1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(T[j].BurstTime>T[j+1].BurstTime)
			{
				temp1=T[j];
				T[j]=T[j+1];
				T[j+1]=temp1;
					
			}
		}
	}
    for(int i=0;i<n;i++)
	{
		T[i].display();
	}

    T[0].waitTime=0;
	int avrgWT=0,avrgTT=0;
	for(int i=1;i<n;i++)
	{
		T[i].waitTime=T[i-1].waitTime+T[i-1].BurstTime;
		avrgWT+=T[i].waitTime;
	}
	//finding TA time for tasks
	for(int i=0;i<n;i++)
	{
		T[i].TATime=T[i].waitTime+T[i].BurstTime;
		avrgTT+=T[i].TATime;
	}

    cout<<"TIME CHART\n";
	cout<<"Task"<<"\tBrust Time"<<"\tWait Time"<<"\tTA Time\n";
    for(int i=0;i<n;i++)
	{
		T[i].display_chart();
	}
	
		cout<<"Avrg wait time:"<<(float)avrgWT/n;
		cout<<"\nAvrg TA time:"<<(float)avrgTT/n;


return 0;
}

