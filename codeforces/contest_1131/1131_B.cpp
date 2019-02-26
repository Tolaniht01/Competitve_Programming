#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define ll long long 
#define mod1 1000000007
int t,p=1;
long long int ans=0;
pair <lld,lld> v[10004];
int n;
int a,b;
int main()
{
    cin>>n;
    v[0]=make_pair(0,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        v[i]=make_pair(a,b);
    }
    int maxi,mini;
    ans=1;
    for(int i=1;i<=n;i++)
    {
        if(v[i].first==v[i-1].first && v[i].second==v[i-1].second)
        {
            continue;
        }
        else
        {
            
            if(v[i-1].first==v[i-1].second)
            {
               mini=min(v[i].first,v[i].second);
               if(mini-v[i-1].first>=0)
               ans+=mini-v[i-1].first;
               //cout<<"added value= "<<mini-v[i-1].first<<endl;
            }
            else
            {
            
                maxi=max(v[i-1].first,v[i-1].second);
                mini=min(v[i].first,v[i].second);
                if (mini-maxi>=0)
                    ans+=mini-maxi+1;
                //cout<<maxi<<" "<<mini<<endl;
                //<<"value added= "<<mini-maxi+1<<endl;
            //cout<<ans<<endl;
            }
            //cout<<ans<<endl;
        }
        
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    
    
    
    
    return 0;
}
