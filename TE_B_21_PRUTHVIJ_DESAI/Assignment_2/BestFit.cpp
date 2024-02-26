#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Process{

public: 
	int PID;
	int Size;
	int Block_alot;
	//int Blkid;
	//int Blksize;
	int freg;
	
	void inputing(int PID,int Size)
	{
		this->PID=PID;
		this->Size=Size;
		freg=0;
		Block_alot=0;
	}
	void Display()
	{
		cout<<"P"<<PID<<"\t"<<Size<<"\n";
	}
	
	
};

class Block{

	public:
		int block_id;
		int block_size;
		int freg;
		
	
		void inputing(int block_id,int block_size)
		{
			this->block_id=block_id;
			this->block_size=block_size;
			freg=block_size;
		}

		
		void Display()
		{
			cout<<"B"<<block_id<<"\t"<<block_size<<"\n";
		}

};

void output(Process P[],Block B[],int n)
{
	for(int i=0;i<n;i++)
	{
		
		if(P[i].Block_alot==0)
		{
		cout<<"P"<<i+1<<"\t"<<P[i].Size<<"\t\t"<<"Not alloted"<<"\t"<<P[i].freg<<"\n";
		}
		else
		
		{cout<<"P"<<i+1<<"\t"<<P[i].Size<<"\t\t"<<"B"<<P[i].Block_alot<<"\t\t"<<P[i].freg<<"\n";}
	}	
}
int main()
{
	
	int n,m;
	cout<<"Enter Number of Process: ";
	cin>>n;
	Process P[n];
	
	int Size;
	int block_size;
	//process data
	for(int i=0;i<n;i++)
	{	cout<<"P"<<i+1<<"Size: ";
		cin>>Size;
		P[i].inputing(i+1,Size);
	}
	//block data
	cout<<"Enter Number of Blocks: ";
	cin>>m;
	Block B[m];
	for(int i=0;i<m;i++)
	{	
		cout<<"B"<<i+1<<"Size: ";
		cin>>block_size;
		B[i].inputing(i+1,block_size);
	}
	
	cout<<"Process Table\n";	
	for(int i=0;i<n;i++)
	{
	
		P[i].Display();
	}
	cout<<"Block Table\n";
	for(int i=0;i<m;i++)
	{
		B[i].Display();
		
	}
	
	for(int i=0;i<n;i++)
	{
		//sorting block
		Block Bnew;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m-1;j++)
			{
				if(B[j].freg>B[j+1].freg)
				{
					Bnew=B[j];
					B[j]=B[j+1];
					B[j+1]=Bnew;
				}
			}
		}
		for(int j=0;j<m;j++)
		{
			if(P[i].Size<B[j].freg)
			{
				P[i].Block_alot=B[j].block_id;
				B[j].freg=B[j].block_size-P[i].Size;
				P[i].freg=B[j].freg;
				break;
			}
		}
		
	}
	cout<<"Final output !!\n";
	output(P,B,n);
	
	
		
return 0;		
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
