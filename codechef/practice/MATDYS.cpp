#include <bits/stdc++.h>
using namespace std;
/******* cr_7 *****/
#define mod 1000000007
#define lli long long int

unsigned lli arr[65];
unsigned lli n,k;
int main()
{
	arr[0]=1;
	for(int i=1;i<=64;i++)
	{
		arr[i]=2*arr[i-1];
	}
	
	int t,p=1;
	cin>>t;
	
	while(p<=t)
	{
		p++;
	scanf("%llu %llu",&n,&k);
	
	unsigned lli temp =k;
	int bit_arr[65];
	int count=0;
	
	//cout<<binary.size()<<endl;
	
	int cpy[n];
	unsigned lli ans=0;
	/*while(temp!=0)
	{
		cpy[count]=temp%2;
		temp=temp/2;
		ans=ans+cpy[count]*arr[n-count-1];
		count++;
		
	}*/
	
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i]<=k)
		{
			k=k-arr[i];
			ans=ans+arr[n-i-1];
		}
		if(k==0)
		{
			break;
		}
	}
	
	printf("%llu\n",ans);
	
}	
	
	
	
	
	
	
	return 0;
}
