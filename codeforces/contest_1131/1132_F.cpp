#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define ll long long 
#define mod1 1000000007
//int t,p=1;
int n;
char str[500];
char str_cpy[500];
int dp[500][500];

int calc(int start, int end)
{
    //cout<<start<<" "<<end<<endl;
    if(dp[start][end]!=-1)
    {
        return dp[start][end];
    }
    else
    {
        dp[start][end]=1+calc(start+1,end);
        for(int i=start+1;i<=end;i++)
        {
            if(str_cpy[i]==str_cpy[start])
            {
                dp[start][end]=min(dp[start][end],calc(start+1,i-1)+calc(i,end));
            }
        }
    }
    
    return dp[start][end];
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    str_cpy[0]=str[0];
    int counter=1;
    for(int i=1;i<n;i++)
    {
        if(str[i]==str[i-1])
        {
            continue;
        }
        else
        {
            str_cpy[counter++]=str[i];
        }
    }
    
    for(int i=0;i<counter;i++)
    {
        for(int j=0;j<counter;j++)
        {
            if(i==j)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=-1;
            }
        }
    }
    
    int ans=calc(0,counter-1);
    cout<<ans<<endl;
    
    return 0;
}
