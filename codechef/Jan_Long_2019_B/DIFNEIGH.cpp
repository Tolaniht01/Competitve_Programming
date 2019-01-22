#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define mod1 1000000007
int t,p=1;
int n,m;
int arr[52][52];
int main()
{
   cin>>t;
   while(p<=t)
   {
       p++;
       cin>>n>>m;
       
       
       
       if(n>=3 && m>=3)
       {
           cout<<"4"<<endl;
           
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<m;j++)
               {
                   if(i%2==0)
                   {
                       if((i/2)%2==0)
                       {
                           if((j/2)%2==0)
                           {
                               arr[i][j]=1;
                           }
                           else
                           {
                               arr[i][j]=2;
                           }
                       }
                       else
                       {
                           if((j/2)%2==0)
                           {
                               arr[i][j]=2;
                           }
                           else
                           {
                               arr[i][j]=1;
                           }
                       }
                   }
                   else
                   {
                       if((i/2)%2==0)
                       {
                           if((j/2)%2==0)
                           {
                               arr[i][j]=4;
                           }
                           else
                           {
                               arr[i][j]=3;
                           }
                       }
                       else
                       {
                           if((j/2)%2==0)
                           {
                               arr[i][j]=3;
                           }
                           else
                           {
                               arr[i][j]=4;
                           }
                       }
                   }
               }
           }
           
           
           
       }
       else if(n==1 && m==1)
       {
           cout<<"1"<<endl;
           arr[0][0]=1;
       }
       else if(n==1 && m>2)
       {
           cout<<"2"<<endl;
           for(int i=0;i<m;i+=2)
           {
               if((i/2)%2==0)
               {
                   arr[0][i]=1;
                   arr[0][i+1]=1;
               }
               else
               {
                   arr[0][i]=2;
                   arr[0][i+1]=2;
               }
           }
       }
       else if(n>2 && m==1)
       {
           cout<<"2"<<endl;
           for(int i=0;i<n;i+=2)
           {
               if((i/2)%2==0)
               {
                   arr[i][0]=1;
                   arr[i+1][0]=1;
               }
               else
               {
                   arr[i][0]=2;
                   arr[i+1][0]=2;
               }
           }
       }
       
       else if(n==2 && m==2)
       {
           cout<<"2"<<endl;
           arr[0][0]=1;
           arr[0][1]=2;
           arr[1][0]=1;
           arr[1][1]=2;
       }
       else if(n==2 && m>2)
       {
           cout<<"3"<<endl;
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<m;j++)
               {
                   arr[i][j]=(j%3)+1;
               }
           }
       }
       
        else if(m==2 && n>2)
       {
           cout<<"3"<<endl;
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<m;j++)
               {
                   arr[i][j]=(i%3)+1;
               }
           }
       }
       
       else if(n==1 && m==2)
       {
           cout<<"1"<<endl;
           arr[0][0]=1;arr[0][1]=1;
       }
       else if(m==1 && n==2)
       {
           cout<<"1"<<endl;
           arr[0][0]=1;arr[1][0]=1;
       }
       
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               cout<<arr[i][j]<<" ";
           }
           cout<<endl;
       }
       
   }
    
    return 0;
}
