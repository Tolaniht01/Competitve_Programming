#include <bits/stdc++.h>
using namespace std;
/******* cr_7 *****/
#define mod 1000000007
#define lli long long int


int t,p=1;
int arr[37];
string s;
int check(int start)
{
	for(int i=start;i<=start+3;i++)
	{
		if(s[i]!='c' && s[i]!='h' && s[i]!='e' && s[i]!='f')
		{
			for(int j=start;j<=i;j++)
				arr[s[j]-96]=0;
			return i;
		}
		else
		{
			int k=s[i];
			//cout<<k<<" H "<<start<<endl;
			arr[k-96]++;
		}
	}
	
	if(arr[3]==1 && arr[5]==1 && arr[6]==1 && arr[8]==1)
	{
	    arr[3]=0;
	    arr[5]=0;
	    arr[6]=0;
	    arr[8]=0;
	    
		return -1;
	}
	else
	{
	    //cout<<arr[3]<<" "<<arr[5]<<" "<<arr[6]<<" "<<arr[8]<<endl;
	    arr[3]=0;
	    arr[5]=0;
	    arr[6]=0;
	    arr[8]=0;
		return -2;
	}
	
	
}

int main()
{
	cin>>t;
	int count=0;
	for(int i=0;i<=26;i++)
	{
		arr[i]=0;
	}
	
	while(p<=t)
	{
		p++;
		cin>>s;
		count=0;
		//cout<<s.size()<<endl;
		
		for(int i=0;i<=s.size()-4;i++)
		{
		    if(i+4>s.size())
		    {
		        break;
		    }
			int ans=check(i);
			//cout<<ans<<" "<<i<<endl;
			if(ans==-1)
			{
				count++;
			}
			else if(ans>=0)
			{
				i=ans;
			}
		}
		
		if(count>0)
		{
			cout<<"lovely "<<count<<endl;
		}
		else
		{
			cout<<"normal"<<endl;
		}
		
		
			
	}	
	
	
	
	return 0;
}
