#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define ll long long 
#define mod1 1000000007
int t,p=1;

int arr1[1025][1025];
int arr2[1025][1025];
int color[1025];
vector < pair <int,int> > adj[1025];
int n;

int flag=0;
void dfs(int node, int col)
{
    //cout<<color[node]<<" "<<node<<" "<<col<<endl;
    if(color[node]!=0)
    {
        if(color[node]==col)
        {
            return;
        }
        else
        {
           flag=1;
           return;
        }
    }
    
    
    color[node]=col;
    for(int i=0;i<adj[node].size();i++)
    {
        dfs(adj[node][i].first,col*adj[node][i].second);
    }
}



int main()
{
    cin>>t;
    while(p<=t)
    {
        p++;
        cin>>n;
        flag=0;
        for(int i=0;i<n;i++)
        {
            adj[i].clear();
        }
        
        for(int i=0;i<n;i++)
        {
            color[i]=0;
            for(int j=0;j<n;j++)
            {
                scanf("%d",&arr1[i][j]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            color[i]=0;
            for(int j=0;j<n;j++)
            {
                scanf("%d",&arr2[i][j]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(arr1[i][j]==arr1[j][i] && arr2[j][i]==arr2[i][j] && arr1[i][j]==arr2[i][j])
                {
                    continue;
                }
                else if(arr1[i][j]==arr2[j][i] && arr2[i][j]==arr1[j][i])
                {
                    adj[i].push_back(make_pair(j,-1));
                    adj[j].push_back(make_pair(i,-1));
                }
                else if(arr1[i][j]==arr2[i][j] && arr1[j][i]==arr2[j][i])
                {
                    adj[i].push_back(make_pair(j,1));
                    adj[j].push_back(make_pair(i,1));
                }
                
                else
                {
                    flag=1;
                }
            }
        }
        
        if(flag==1)
        {
            cout<<"No"<<endl;
            continue;
        }
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==0)
            {
                dfs(i,1);
            }
        }
        
        if(flag==1)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
        
        
        
        
    }
    
    return 0;
}
