#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define ll long long 
#define mod1 1000000007
int t,p=1;
int n,k;
int a,b;
vector <int> row;
vector <int> column;
int maxi=1e7;
int main()
{
    cin>>t;
    while(p<=t)
    {
        p++;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            row.push_back(i);
            column.push_back(i);
        }
        
        for(int i=0;i<k;i++)
        {
            cin>>a>>b;
            row[a-1]=maxi;
            column[b-1]=maxi;
        }
        
        sort(row.begin(),row.end());
        sort(column.begin(),column.end());
        int ans=n-k;
        printf("%d ",ans);
        for(int i=0;i<n-k;i++)
        {
            printf("%d %d ",row[i],column[i]);
        }
        cout<<endl;
        
        row.clear();
        column.clear();
    }
    
    
    return 0;
}
