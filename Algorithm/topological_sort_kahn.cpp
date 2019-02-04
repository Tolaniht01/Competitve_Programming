#include <bits/stdc++.h>
using namespace std;
/******* cr_7 *****/
#define mod 1000000007
#define lli long long int

vector <int> G[100003];

int n,m;
int visited[10003];
priority_queue <int,vector <int>,greater<int> > q;
int in_deg[10003];
int count1=0;
vector <int > order;


void solve()
{
	
	
	for(int i=1;i<=n;i++)
	{
		if(in_deg[i]==0)
		{
			q.push(i);
		}
	}
	
	
	
	while(!q.empty())
	{
		int v=q.top();
		//cout<<"v= "<<v<<endl;
		q.pop();
		order.push_back(v);
		
		in_deg[v]=-1;
		
	
		for(int i=0;i<G[v].size();i++)
		{
		    
			in_deg[G[v][i]]--;
			//cout<<G[v][i]<<" H "<<in_deg[G[v][i]]<<endl;
			
			if(in_deg[G[v][i]]==0)
			{
				q.push(G[v][i]);
				//cout<<"push = "<<G[v][i]<<endl;
			}
		}
			//cout<<endl;
		
			
		
		count1++;
		
		
	}
	
	//cout<<count1<<" count"<<endl;
	if(count1==n)
	{
		for(int i=0;i<order.size();i++)
		{
			printf("%d ",order[i]);
		}
	}
	
	else 
	{
		printf("Sandro fails.");
	}
	//printf("\n");
}

int main() 
{
	cin>>n>>m;
	int a,b;
	
	for(int i=1;i<=n;i++)
	{
		visited[i]=0;
		in_deg[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		in_deg[b]++;
	}
	solve();	
	return 0;
}


