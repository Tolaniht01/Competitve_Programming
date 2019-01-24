#include <bits/stdc++.h>
using namespace std;
/******* cr_7 *****/
#define mod 1000000007
#define lli long long int


int count_edge=0;
vector <pair <int,int> > edge;
int count_degree[100005]={0};
vector <int> G[100005];
int rev[200005];
int node_visited[100005];
int visited[200005];




int n,e;
void DFS(int v)
{
    //printf("Himanshu\n");
    node_visited[v]=1;
	for(int i=0;i<G[v].size();i++)
	{
	   int k=G[v][i];
	   if(rev[k])
	   	continue;

	   pair <int,int> p=edge[k];
	   count_edge++;
       int d=p.first^p.second^v;
       //printf("d= %d H %d\n",d,p.second);
	   if(p.first==v)
	   {
	   		rev[k]=1;
	   }
	   else
	   {
	   		rev[k]=2;
	   }

	   if(!node_visited[d])
	   	DFS(d);


	}
}
int main() 
{
	cin>>n>>e;
	//cout<<e<<n<<endl;
	int a,b;
	for(int i=0;i<e;i++)
	{
		scanf("%d %d",&a,&b);
		count_degree[a]++;
		count_degree[b]++;
		edge.push_back(make_pair(a,b));
		G[a].push_back(edge.size()-1);
		G[b].push_back(edge.size()-1);
	}
	
	//cout<<"Himanshu"<<endl;


	for(int i=1;i<=n;i++)
		visited[i]=0;
	for(int i=1;i<=n;i++)
	{

		if(count_degree[i]%2==1 || count_degree[i]==0) 
		{
			printf("NO\n");
			return 0;
		}
	}

	
	
	


	DFS(1);
    map <pair<int,int>,int > :: iterator it;
    if(count_edge==e)
    {

    printf("YES\n");
	pair <int,int> t;
    for(int i=0;i<edge.size();i++)
    {
    	pair <int,int> pp =edge[i];
    	if(rev[i]==1)
    	{
    		printf("%d %d\n",pp.first,pp.second);
    	}

    	else if(rev[i]==2)
    	{
    		printf("%d %d\n",pp.second,pp.first);
    	}
    }
}

else
{
	printf("NO\n");
}	
	
	
	
	return 0;
}

