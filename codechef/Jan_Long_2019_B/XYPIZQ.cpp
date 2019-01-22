#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define mod1 1000000007

int t,p=1;
lld n,x,y,z;
int type;


long long int GCD(long long int a, long long int b)
{
    while( 1 )
    {
        a = a % b;
		if( a == 0 )
			return b;
		b = b % a;
        if( b == 0 )
			return a;
    }
}




int main()
{
   cin>>t;
   lld e,f;
   while(p<=t)
   {
       p++;
       cin>>n>>type>>x>>y>>z;
       if(type==1)
       {
           if(x<y && y<z)
           {
               e=2*n-y;
               f=2*n+1;
           }
           else if(x>y && y<z)
           {
               e=y+1;
               f=2*n+1;
           }
           else if(x>y && y>z)
           {
               e=2*n-y+2;
               f=2*n+1;
           }
           else if(x<y && y>z)
           {
               e=y-1;
               f=2*n+1;
           }
       }
       else if(type==2)
       {
           if(x<y && y<z)
           {
               e=2*n+1-2*y;
               f=2*n+1;
           }
           else if(x>y && y>z)
           {
               e=2*n+1-2*y;
               f=2*n+1;
           }
       }
       else if(type==4)
       {
           if(x<y && y<z)
           {
               e=2*n+1-2*y;
               f=2*n+1;
           }
           else if(x>y && y>z)
           {
               e=2*n+1-2*y;
               f=2*n+1;
           }
       }
       
       else if(type==3)
       {
           if(x<y && y<z)
           {
               e=2*n-y+2;
               f=2*n+1;
           }
           else if(x>y && y<z)
           {
               e=y+1;
               f=2*n+1;
           }
           else if(x>y && y>z)
           {
               e=2*n-y;
               f=2*n+1;
           }
           else if(x<y && y>z)
           {
               e=y-1;
               f=2*n+1;
           }
       }
       
       
       lld g=GCD(e,f);
       cout<<e/g<<" "<<f/g<<endl;
       
       
   }
    
    return 0;
}
