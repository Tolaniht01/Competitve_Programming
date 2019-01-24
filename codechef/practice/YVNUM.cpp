#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define mod1 1000000007

string str;
long long int ans,final_ans;
int t,p=1;
string n;
lld arr_pow[100003];

long long int power(int a,int b)
{
    lld pro=1;
    for(int i=1;i<=b;i++)
    {
        pro=pro*a;
    }
    return pro;
}

int main()
{
   cin>>t;
   arr_pow[0]=1;
   for(int i=1;i<=100002;i++)
   {
       arr_pow[i]=(arr_pow[i-1]*10)%mod1;
   }
   
   
   
   while(p<=t)
   {
       p++;
       cin>>n;
       int l1=n.size();
       ans=0;
       final_ans=0;
       //cout<<n<<" "<<l1<<endl;
       for(int i=0;i<l1;i++)
       {
          ans=((ans%mod1*10)%mod1+(n[i]-48))%mod1;
       }
       //cout<<ans<<endl;

       for(int i=0;i<l1;i++)
       {
           //cout<<"asn= "<<ans<<" final-ans= "<<final_ans<<endl;
           final_ans=(((final_ans%mod1)*(arr_pow[l1]%mod1))%mod1+(ans%mod1))%mod1;
           ans=(ans%mod1 - ((n[i]-48)*(arr_pow[l1-1]%mod1))%mod1)%mod1;
           
           ans=((ans%mod1*10)%mod1+(n[i]-48))%mod1;
       }
       //final_ans=final_ans%mod1;
       if(final_ans<0)
       {
           final_ans+=mod1;
       }
       
       cout<<final_ans<<endl;
   }
    
    return 0;
}
