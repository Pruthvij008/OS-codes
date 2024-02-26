#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Task{
public:
	//int ArvTime;
	int BurstTime,B2;
	int ComTime;
	int idx;
	int waitTime;
	int TATime;
	void Taskinput(int BurstTime,int idx)
	{
		ComTime=0;
		this->BurstTime=BurstTime;
		this->B2=this->BurstTime;
		this->idx=idx;	
		
	}
	void display()
	{
		cout<<"T"<<idx<<"\t\t"<<BurstTime<<"\n";
	}
	void display_chart()
	{
		cout<<"T"<<idx<<"\t"<<BurstTime<<"\t\t"<<waitTime<<"\t\t"<<ComTime<<"\t\t"<<TATime<<"\n";
	}
};

int main()
{
	queue<Task> tsk;
	int COMTIME=0;
	int n,Burstime;
	cout<<"Enter number of task: ";
	cin>>n;
	Task T[n];
	 cout<<"Enter Burst Time for tasks !\n";
	for(int i=0;i<n;i++)
	{	cout<<"T"<<i+1<<": ";
		cin>>Burstime;
		T[i].Taskinput(Burstime,i+1);
		tsk.push(T[i]);
	
	}
	int Tmsc;
	cout<<"Enter time slice: ";
	cin>>Tmsc;
	
	while(tsk.size()!=0)
	{
		Task Tk;
		Tk=tsk.front();
		tsk.pop();
		if(Tk.B2<=Tmsc)
		{
			COMTIME+=Tk.B2;
			T[Tk.idx-1].ComTime=COMTIME;
			

		}
		else
		{
			Tk.B2-=Tmsc;
			COMTIME+=Tmsc;
			tsk.push(Tk);
		}	
	
	
	}
	T[0].waitTime=0;
	int avrgWT=0,avrgTT=0;

	for(int i=0;i<n;i++)
	{
		T[i].waitTime=T[i].ComTime-T[i].BurstTime;
		avrgWT+=T[i].waitTime;
		
	}
	for(int i=0;i<n;i++)
	{
		T[i].TATime=T[i].BurstTime+T[i].waitTime;
		avrgTT+=T[i].TATime;
	}
	
	cout<<"Task"<<"\tBrust Time"<<"\tWait Time"<<"\tComp Time"<<"\tTA Time\n";
	for(int i=0;i<n;i++)
	{
		T[i].display_chart();
	}
	
		cout<<"Avrg wait time:"<<(float)avrgWT/n;
		cout<<"\nAvrg TA time:"<<(float)avrgTT/n;
	




return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	



