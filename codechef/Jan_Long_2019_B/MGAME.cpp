#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define mod1 1000000007

long long int sum=0;
long long int t,pp=1;
long long int n,p;
long long int i,j,k;

int main()
{
   cin>>t;
   while(pp<=t)
   {
       pp++;
       sum=0;
       cin>>n>>p;
       i=n/2+1;
       
       if(i==n)
       {
          sum=sum=p*p*p;
       }
       
       else
       {
        sum=sum+(p-(n%i))*(p-(n%i));
        //cout<<sum<<endl;
        sum=sum+(p-n)*(p-(n%i));
        sum=sum+(p-n)*(p-n);
       }
       cout<<sum<<endl;
       
   }
    
    return 0;
}
