#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define ll long long 
#define mod1 1000000007
int t,p=1;
vector <pair <int,int> > v;
int arr[5001]={0};
int new_arr[5001]={0};
int n,q;
int a,b;
int max_ans;
int main()
{
    cin>>n>>q;
    int total_counter=0;
    max_ans=0;
    for(int i=1;i<=q;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
        for(int j=a;j<=b;j++)
        {
            if(arr[j]==0)
            {
                total_counter++;
            }
            arr[j]++;
        }
    }
    
   /* for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;*/
    
    for(int i=0;i<q;i++)
    {
        total_counter=0;
        new_arr[0]=0;
        //cout<<v[i].first<<" g "<<v[i].second<<endl;
        for(int j=1;j<=n;j++)
        {
            if(j>=v[i].first && j<=v[i].second)
            {
                if(arr[j]==1)
                {
                    new_arr[j]=0;
                }
                else if(arr[j]==2)
                {
                    new_arr[j]=1;
                    total_counter++;
                }
                else if(arr[j]>2)
                {
                    new_arr[j]=0;
                    total_counter++;
                }
                else
                {
                    new_arr[j]=0;
                }
            }
            else
            {
                if(arr[j]==1)
                {
                    new_arr[j]=1;
                    total_counter++;
                }
                else if(arr[j]>1)
                {
                    new_arr[j]=0;
                    total_counter++;
                }
                else
                {
                    new_arr[j]=0;
                }
            }
            new_arr[j]=new_arr[j]+new_arr[j-1];
            
            //cout<<new_arr[j]<<" ";
        }
        //cout<<endl;
        //cout<<total_counter<<endl;
        for(int j=i+1;j<q;j++)
        {
            int res=new_arr[v[j].second]-new_arr[v[j].first-1];
            if(total_counter-res>max_ans)
            {
                max_ans=total_counter-res;
            }
        }
        
    }
    
    cout<<max_ans<<endl;
    
    
    return 0;
}
