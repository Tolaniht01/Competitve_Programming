#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define ll long long 
#define mod1 1000000007
int t,p=1;
string str;
long long int ans=0;
int arr[26];
vector <pair <ll,ll> > new_arr[676];
vector <string> strings;
vector <int> points;
int l;
bool myfunction (pair <int,int> i, pair <int,int> j)
{ 
    if(i.first>j.first)
    {
        return 1;
    }
    else if(i.first==j.first)
    {
        return i.second<j.second;
    }
    else
    {
        return 0;
    }
}



int main()
{
   cin>>t;
   
   while(p<=t)
   {
       p++;
       ans=0;
       cin>>l;
       
       cin>>str;
       //cout<<str.size()<<endl;
       int counter=1;
       
        for(int i=0;i<676;i++)
       {
           new_arr[i].clear();
       }
       
       strings.clear();
       points.clear();
       
       for(int i=0;i<26;i++)
       {
           arr[i]=0;
       }
       
       for(int i=1;i<l;i++)
       {
           if(str[i]==str[i-1])
           {
               counter++;
           }
           else
           {
               points.push_back(i-1);
               arr[str[i-1]-97]=max(arr[str[i-1]-97],counter);
               counter=1;
           }
       }
       points.push_back(str.size()-1);
       
       arr[str[str.size()-1]-97]=max(arr[str[str.size()-1]-97],counter);
       
       for(int i=0;i<26;i++)
       {
          ans=ans+(arr[i]); 
       }
       //cout<<ans<<" himanshu"<<endl;
       int start=0;
       
       //cout<<strings.size()<<endl;
       int len2=points.size();
       for(int i=0;i<len2;i++)
       {
           strings.push_back(str.substr(start,points[i]-start+1));
           start=points[i]+1;
       }
       
       int l1,l2;
       char a,b;
       //cout<<strings.size();
       int len=strings.size();
       for(int i=0;i<len-1;i++)
       {
           //cout<<"Himanshu "<<strings.size()-1<<endl;
           l1=strings[i].size();
           l2=strings[i+1].size();
           a=strings[i][0];
           b=strings[i+1][0];
           new_arr[(a-97)*26+(b-97)].push_back(make_pair(l1,l2));
       }
       int len3;
       for(int i=0;i<676;i++)
       {
           len3=new_arr[i].size();
           if(len3>0)
           {
               sort (new_arr[i].begin(),new_arr[i].end(), myfunction);
                //cout<<i<<" -----"<<endl;
               long long max_x=0,max_y=0;
               for(int j=0;j<new_arr[i].size();j++)
               {
                   //cout<<new_arr[i][j].first<<" "<<new_arr[i][j].second<<" "<<max_x<<" "<<max_y<<endl;
                   if(new_arr[i][j].first>max_x)
                   {
                       max_x=new_arr[i][j].first;
                       max_y=new_arr[i][j].second;
                       ans=ans+max_x*max_y;
                   }
                   else if(new_arr[i][j].first==max_x && new_arr[i][j].second>max_y)
                   {
                       ans=ans+max_x*(new_arr[i][j].second-max_y);
                       max_y=new_arr[i][j].second;
                   }
                   else if(new_arr[i][j].first<max_x && new_arr[i][j].second>max_y)
                   {
                       ans=ans+new_arr[i][j].first*(new_arr[i][j].second-max_y);
                       max_y=new_arr[i][j].second;
                   }
               }
               //cout<<endl;
           }
           
       }
       
       cout<<ans<<endl;
       

       
   }
    
    return 0;
}
