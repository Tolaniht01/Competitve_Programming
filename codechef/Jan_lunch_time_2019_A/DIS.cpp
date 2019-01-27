#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define ll long long 
#define mod1 1000000007
int t,p=1;
int n;
int arr1[1000005];
int arr2[1000005];
int flag=0;
int main()
{
    cin>>t;
    while(p<=t)
    {
        p++;
        cin>>n;
        flag=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &arr1[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &arr2[i]);
        }
        if(arr1[n]!=arr2[1])
        {
            cout<<"No"<<endl;
            continue;
        }
        
        if(arr1[1]!=0 || arr2[n]!=0)
        {
            cout<<"No"<<endl;
            continue;
        }
        
        for(int i=2;i<=n-1;i++)
        {
            //cout<<arr1[i]<<" "<<arr2[i]<<" "<<arr1[n]<<endl;
            if(arr1[i]+arr2[i]<arr1[n])
            {
                flag=1;
                break;
            }
            else if(arr1[n]+arr2[i]<arr1[i])
            {
                flag=1;
                break;
            }
            else if(arr2[1]+arr1[i]<arr2[i])
            {
                flag=1;
                break;
            }
        }
        
        
        for(int i=1;i<=n;i++)
        {
            if(arr1[i]==0 && i!=1)
            {
                flag=1;
                break;
            }
            else if(arr2[i]==0 && i!=n)
            {
                flag=1;
                break;
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
