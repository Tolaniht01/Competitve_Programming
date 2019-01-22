#include <bits/stdc++.h>
using namespace std;
/******* cr_7 *****/
#define mod 1000000007
#define lli long long int


long long int x,n;
int t,p=1;
long long int summ=0;
long long int sum1=0;
long long int sum=0;
int arr[1000006];



int main() 
{
	cin>>t;
	while(p<=t)
	{
		p++;
		//cout<<summ<<endl;
		cin>>x>>n;
		summ=(n*(n+1))/2;
		if((summ-x)%2==1 || n-1==1)
		{
			cout<<"impossible"<<endl;
		}
		else
		{
			for(long long int i=1;i<=n;i++)
			{
				arr[i]=0;
			}
			sum1=0;
			
			arr[x]=2;
			sum=(summ-x)/2;
			//cout<<sum<<endl;
			for(long long int i=n;i>=1;i--)
			{
				//cout<<i<<" "<<sum<<endl;
				if(i==x)
				{
					continue;
				}
				else if(sum==0)
				{
					break;
				}
				else if(i>sum)
				{
					arr[i]=0;
					continue;
				}
				
				else
				{
					arr[i]=1;
					sum=sum-i;
					sum1=sum1+i;
					if(sum==2 && x==2)
					{
						arr[i]=0;
						sum=sum+i;
					}
					if(sum==1 && x==1)
					{
						arr[i]=0;
						sum=sum+i;
					}
					
				}
			}
			
			if(sum!=0)
			{
				//cout<<sum<<endl;
				cout<<"impossible"<<endl;
			}
			else
			{
			
			
				for(long long int i=1;i<=n;i++)
				{
					cout<<arr[i];
				}
				cout<<endl;
				
				//cout<<"sum1= "<<sum1<<endl;
			
			}
		}
			
	}	
	
	
	
	return 0;
}

