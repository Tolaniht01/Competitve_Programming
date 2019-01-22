#include <bits/stdc++.h>
using namespace std;
/******* cr_7 *****/
#define mod 1000000007
#define lli long long int


int t,p=1;
int n;
double arr[100005];
double c,d,s;
long double sum=0;
double maxi;

int main()
{
	cin>>t;
	while(p<=t)
	{
		p++;
		sum=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cin>>c>>d>>s;
		sum=arr[0];
		maxi=arr[0];
		for(int i=1;i<n;i++)
		{
			if(arr[i]>maxi)
			{
				sum=sum+arr[i]-maxi;
				maxi=arr[i];
			}
		}
		//cout<<sum<<" "<<c-1<<" "<<c<<endl;
		cout<<fixed<<setprecision(7)<<(c-1)*sum<<endl;
		
		
		
	}
	
	
	
	return 0;
}
