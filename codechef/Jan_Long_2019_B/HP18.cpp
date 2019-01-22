#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define mod1 1000000007

int t,p=1;
int n,a,b;
int arr[200004];
int count_a,count_b,count_c;
int main()
{
   cin>>t;
   while(p<=t)
   {
       p++;
       cin>>n>>a>>b;
       count_a=0;
       count_b=0;
       count_c=0;
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
           if(arr[i]%a==0 && arr[i]%b==0)
           {
               count_c++;
           }
           else if(arr[i]%a==0)
           {
               count_a++;
           }
           else if(arr[i]%b==0)
           {
               count_b++;
           }
       }
       
       
       if(count_a>count_b)
       {
           cout<<"BOB"<<endl;
       }
       else if(count_b>count_a)
       {
           cout<<"ALICE"<<endl;
       }
       else
       {
           if(count_c==0)
           {
               cout<<"ALICE"<<endl;
           }
           else
           {
               cout<<"BOB"<<endl;
           }
       }
   }
    
    return 0;
}
