#include <bits/stdc++.h>
using namespace std;
/******* cr_7 *****/
#define mod 1000000007
#define lli long long int

int t,p=1;
int n,m;
char a[5002],b[5002];
int arr[5002][5002];
int main() 
{
	cin>>t;
	
	while(p<=t)
	{
		p++;
		cin>>m>>n;
		for(int i=0;i<m;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
		}
		
		//cin>>a>>b;
		string A="",B="";
		arr[0][1]=1;
		arr[0][0]=0;
			for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				arr[i][j]=0;
			}
		}
		
		
		A.push_back(a[0]);
		B.push_back(b[0]);
		
		for(int i=1;i<m;i++)
		{
			if(a[i]==a[i-1])
			{
				continue;
			}
			else
			{
				A.push_back(a[i]);
			}
		}
		
		for(int i=1;i<n;i++)
		{
			if(b[i]==b[i-1])
			{
				continue;
			}
			else
			{
				B.push_back(b[i]);
			}
		}
		
	
		
	
		for(int i=0;i<=A.size();i++)
		{
			for(int j=0;j<=B.size();j++)
			{
				
				if(i==0 || j==0)
				{
					arr[i][j]=0;	
				}
				else if(A[i-1]==B[j-1])
				{
					arr[i][j]=1+arr[i-1][j-1];
				}
				else
				{
					arr[i][j]=max(arr[i-1][j],arr[i][j-1]);	
				}	
			
			}
		}
		
		/*for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}*/
		
		cout<<A.size()+B.size()-arr[A.size()][B.size()]<<endl;
			
	}	
	
	
	
	return 0;
}

