#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define mod1 1000000007

vector <long long int>  v;
int t,p=1;
int n;
int counter=0;
vector <int> ans;
vector <int> ind1;
vector <int> ind2;

int check_prime(int n)
{
    for(int i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

void get_table()
{
    int visited[400][400];
    for(int i=0;i<400;i++)
    {
        for(int j=0;j<400;j++)
        {
            if(i==j)
                visited[i][j]=1;
            else
                visited[i][j]=0;
        }
    }
    int index[400];
    for(int i=0;i<400;i++)
    {
        index[i]=0;
    }
    counter=0;
    int current=0;
    int flag=0;
    while(counter<=50000)
    {
        
        if(visited[current][index[current]]==0)
        {
            //cout<<current<<" "<<index[current]<<endl;
            ans.push_back(v[current]*v[index[current]]);
            visited[current][index[current]]=1;
            visited[index[current]][current]=1;
            
            ind1.push_back(current);
            ind2.push_back(index[current]);
            //cout<<current<<" "<<index[current]<<endl;
            current=index[current];
            index[current]++;
            counter++;
            
        }
        else
        {
            //cout<<current<<" yes "<<index[current]<<endl;
            flag=0;
            while(visited[current][index[current]]!=0)
            {
                index[current]++;
                //cout<<index[current]<<endl;
                if(index[current]>=400)
                {
                    flag=1;
                    break;
                }
            }
            
            if(flag==1)
            {
                //cout<<"breaking "<<current<<" "<<counter<<" "<<index[current]<<endl;
                
                ind1.push_back(current);
                ind2.push_back(400);
                ans.push_back(v[current]*v[400]);
                ind1.push_back(400);
                ind2.push_back(200);
                ans.push_back(v[400]*v[200]);
                current=200;
                //break;
            }
        }
    }
    
}

int main()
{
   int counter=0;
   v.push_back(2);
   for(int i=3;i<=620000;i+=2)
   {
       int res=check_prime(i);
       if(res==1)
       {
           counter++;
           v.push_back(i);
       }
       if(counter==404)
       {
           //cout<<i<<endl;
           break;
       }
   }

   //cout<<v.size()<<endl;
   cin>>t;
   //cout<<index<<endl;
   //cout<<v[3401]*v[3402]<<endl;
   get_table();
   while(p<=t)
   {
       p++;
       cin>>n;
       
       for(int i=0;i<n-3;i++)
       {
           cout<<ans[i]<<" ";
       }
       cout<<v[ind2[n-4]]*v[401]<<" "<<v[401]*v[402]<<" "<<v[402]*v[ind1[0]]<<endl;
       

   }
   
    
    return 0;
}
