#include <bits/stdc++.h>
using namespace std;
/******* cr_7 *****/
#define mod 1000000007
#define lli long long int


int t,p=1;
long long int N,M,X,K;
long long int sum;
string str;
long long int count_even,count_odd;
long long int numb_odd,numb_even;
int main()
{
	cin>>t;
	while(p<=t)
	{
		p++;
		count_even=0;
		count_odd=0;
		cin>>N>>M>>X>>K;
		cin>>str;
		
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='E')
			{
				count_even++;
			}
			else
			{
				count_odd++;
			}
		}
		
		if(M%2==1)
		{
			numb_even=M/2;
			numb_odd=numb_even+1;
		}
		else
		{
			numb_even=M/2;
			numb_odd=numb_even;
		}
		sum=min(min(count_even,X)*numb_even,count_even)+min(min(count_odd,X)*numb_odd,count_odd );
		//cout<<sum<<endl;
		 if(sum<N)
		{
			cout<<"no"<<endl;
		}
		else
		{
			cout<<"yes"<<endl;
		}
	}
	
	
	
	
	return 0;
}
