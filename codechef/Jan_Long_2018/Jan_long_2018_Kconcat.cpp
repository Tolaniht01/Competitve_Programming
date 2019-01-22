#include <bits/stdc++.h>
using namespace std;
/******* cr_7 *****/
#define mod 1000000007
#define lli long long int

int t,p=1;
int n,k;
long long int sum=0;
int arr[200004];
long long int cum[100004];
long long int rev_cum[100004];
int starting,ending;
long long int max_so_far=0;

lli maxSubArraySum(int size)
{
   long long int  max_ending_here = 0,s=0;
       starting =0, ending = 0;
       max_so_far = INT_MIN;
 
    for (int i=0; i< size; i++ )
    {
        max_ending_here += arr[i];
 
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            starting = s;
            ending = i;
        }
 
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    //cout << "Maximum contiguous sum is "
       // << max_so_far << endl;
   // cout << "Starting index "<< starting
        //<< endl << "Ending index "<< ending << endl;
        
        return max_so_far;
}

int min_val()
{
	int max_val=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]>max_val)
		{
			max_val=arr[i];	
		}	
	}	
	return max_val;
}

long long int maximum(lli a,lli b)
{
	if(a>b)
	{
		return a;
	}
	
	return b;
}

int main()
{
	cin>>t;
	while(p<=t)
	{
		p++;
		cin>>n>>k;
		int count=0;
		sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			arr[n+i]=arr[i];
			if(arr[i]<0)
			{
				count++;
			}
			
		}
		
		if(count==n)
		{
			int ans=min_val();
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				cum[i]=arr[i];
			}
			else
			{
				cum[i]=cum[i-1]+arr[i];
			}
		}
		for(int i=n-1;i>=0;i--)
		{
			if(i==n-1)
			{
				rev_cum[i]=arr[i];
			}
			else
			{
				rev_cum[i]=rev_cum[i+1]+arr[i];
			}
		}
		
		long long int max1=0,max2=0;
		for(int i=n-1;i>=0;i--)
		{
		    if(rev_cum[i]>max1)
		    {
		        max1=rev_cum[i];
		    }
		}
		
		for(int i=0;i<=n-1;i++)
		{
		    if(cum[i]>max2)
		    {
		        max2=cum[i];
		    }
		}
		
		lli sum1=maxSubArraySum(2*n);
		lli sum2=maxSubArraySum(n);
		
		if(k>=2)
		{
			sum=maximum(sum,sum1);
			sum=maximum(sum,cum[n-1]*(k-2)+max1+max2);
		}
		
		sum=maximum(sum,sum2);
		sum=maximum(sum,cum[n-1]*k);
		
		
		
		
		
		cout<<sum<<endl;
		
		
		
		
	}
	return 0;
}
