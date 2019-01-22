#include <bits/stdc++.h>
using namespace std;
/******* cr_7 *****/
#define mod 1000000007
#define lli long long int

int tr,p=1;
vector <int> arr[27];
string str;
int count_odd=0;
int t[100005];
int counter;
int main()
{
	
	cin>>tr;
	while(p<=tr)
	{
		p++;
		cin>>str;
		count_odd=0;
		counter=0;
		
		
		for(int i=0;i<str.size();i++)
		{
			arr[str[i]-96].push_back(i+1);
		}
		
		for(int i=1;i<=26;i++)
		{
			if(arr[i].size()%2==1)
			{
				count_odd++;
			}
			
			/*for(int j=0;j<arr[i].size();j++)
			{
				cout<<arr[i][j]<<" H ";
			}
			cout<<endl;*/
		}
		
		if(count_odd>1)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			if(count_odd==1)
			{
				
				for(int i=1;i<=26;i++)
				{	
					if(arr[i].size()%2==0)
					{
					
						for(int j=0;j<arr[i].size();j=j+2)
						{
							t[counter]=arr[i][j];
							t[str.size()-1-counter]=arr[i][j+1];
							counter++;
						}
					}
					
					else
					{
						t[(str.size()-1)/2]=arr[i][arr[i].size()-1];
						for(int j=0;j<arr[i].size()-1;j=j+2)
						{
							t[(str.size()-1)/2-(j/2)-1]=arr[i][j];
							t[(str.size()-1)/2+(j/2)+1]=arr[i][j+1];
						}
					}
				}
			}
			else
			{
				for(int i=1;i<=26;i++)
				{
					for(int j=0;j<arr[i].size();j=j+2)
					{
						t[counter]=arr[i][j];
						t[str.size()-1-counter]=arr[i][j+1];
						counter++;
					}
				}
			}
			
			
			for(int i=0;i<str.size();i++)
			{
				cout<<t[i]<<" ";
			}
			cout<<endl;
		}
		
		for(int i=1;i<=26;i++)
		{
			arr[i].erase(arr[i].begin(),arr[i].end());
		}

		
	}
	
	
	return 0;
}
