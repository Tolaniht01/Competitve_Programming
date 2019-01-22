#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define mod1 1000000007

int n,m;
int arr1[200005];
int arr2[200005];
int min1=1e9,min_index1,max2=-1*1e9,max_index2;
int counter=0;
unordered_map <int,int> ma;
vector <pair <int,int> > v;
int main()
{
   cin>>n>>m;
   for(int i=0;i<n;i++)
   {
       cin>>arr1[i];
       if(min1>arr1[i])
       {
           min1=arr1[i];
           min_index1=i;
       }
       
   }
   
   for(int j=0;j<m;j++)
   {
       cin>>arr2[j];
       if(max2<arr2[j])
       {
           max2=arr2[j];
           max_index2=j;
       }
   }
   
   for(int i=0;i<n;i++)
   {
       v.push_back(make_pair(i,max_index2));
   }
   for(int j=0;j<m;j++)
   {
       if(j!=max_index2)
        v.push_back(make_pair(min_index1,j));
   }
   
   
   for(int i=0;i<v.size();i++)
   {
      printf("%d %d\n",v[i].first,v[i].second);
   }
    
    return 0;
}
