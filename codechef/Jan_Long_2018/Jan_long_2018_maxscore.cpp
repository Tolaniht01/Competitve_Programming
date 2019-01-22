#include <bits/stdc++.h>
using namespace std;
/******* cr_7 *****/
#define mod 1000000007
#define lli long long int


int t,p=1;
int n;
vector < int > arr [3700];
int a;

int main()
{

	cin>>t;
	while(p<=t)
	{
		p++;
		cin>>n;
		
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a;
				arr[i].push_back(a);
			}
		}
		
		for(int i=0;i<n;i++)
		{
			sort(arr[i].begin(),arr[i].end());
		}
		
		int current=n-2;
		int prev_element=arr[n-1][n-1];
		long long int sum=arr[n-1][n-1];
		for(int i=n-1;i>=0;i--)
		{
			//cout<<i<<" H "<<arr[current][i]<<" "<<current<<endl;
			if(current==-1)
			{
				break;
			}
			
			if(arr[current][i]<prev_element)
			{
				//cout<<arr[current][i]<<" "<<current<<endl;
				sum=sum+arr[current][i];
				prev_element=arr[current][i];
				current--;
				i=n;
			}
		}
		
		if(current==-1)
		{
			cout<<sum<<endl;
		}
		else
		{
			cout<<"-1"<<endl;
		}
		
		for(int i=0;i<n;i++)
		{
			arr[i].erase(arr[i].begin(),arr[i].end());
		}
		
		
		
		
	}
	
	
	return 0;
}
