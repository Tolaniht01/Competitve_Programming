#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define ll long long 
#define mod1 1000000007
int t,p=1;

long long int w1,h1,w2,h2;
int main()
{
    cin>>w1>>h1>>w2>>h2;
    long long int ans;
    if(w1==w2)
    {
        ans=w1*2+(h1+h2+2)*2;
    }
    else
    {
        ans=h1+h2+2+w2+w1+h2+(w1-w2)+h1+2;
    }
    cout<<ans<<endl;
    
    return 0;
}
