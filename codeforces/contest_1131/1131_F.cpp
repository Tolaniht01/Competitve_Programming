#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define ll long long 
#define mod1 1000000007
int t,p=1;
vector <int> v[150002];
int parent[150002];
int n;
int a,b;
vector <int> temp;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        v[i].push_back(i);
    }
    
    
    for(int i=1;i<n;i++)
    {
        
        scanf("%d %d",&a,&b);
        //cout<<a<<" "<<b<<endl;
        if(v[parent[a]].size()<v[parent[b]].size())
        {
            int size_v=v[parent[a]].size();
            int current_parent=parent[a];
            for(int j=0;j<size_v;j++)
            {
                
                v[parent[b]].push_back(v[current_parent][j]);
                parent[v[current_parent][j]]=parent[b];
            }
            v[current_parent].clear();
        }
        else
        {
            //cout<<parent[a]<<" "<<parent[b]<<endl;
            int size_v=v[parent[b]].size();
            int current_parent=parent[b];
            for(int j=0;j<size_v;j++)
            {
                v[parent[a]].push_back(v[current_parent][j]);
                parent[v[current_parent][j]]=parent[a];
            }
            v[current_parent].clear();
        }
        
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            printf("%d ",v[i][j]);
        }
    }
    cout<<endl;
    
    return 0;
}
