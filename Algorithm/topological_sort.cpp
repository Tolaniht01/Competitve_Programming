#include <bits/stdc++.h>
using namespace std;
/******* cr_7 *****/
#define mod 1000000007
#define lli long long int

vector <int> G[100003];

int n,m;
int visited[10003];
stack <int> st;


void DFS(int v)
{
	visited[v]=1;
	
	for(int i=0;i<G[v].size();i++)
	{
		if(visited[G[v][i]]==0)
		{
			DFS(G[v][i]);
		}
	}
	
	st.push(v);
}

void solve()
{
	for(int i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			DFS(i);
		}
	}
	
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
}

int main() 
{
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		G[a].push_back(b);
	}
	solve();	
	return 0;
}

