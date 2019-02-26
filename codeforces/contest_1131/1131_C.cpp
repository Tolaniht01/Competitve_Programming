#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define ll long long 
#define mod1 1000000007
//int t,p=1;
int n;
int arr[101];
int ans[101];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            ans[i/2]=arr[i];
        }
        else
        {
            ans[n-1-(i-1)/2]=arr[i];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}
