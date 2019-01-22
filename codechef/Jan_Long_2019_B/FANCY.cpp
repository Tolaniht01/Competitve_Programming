#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
#define mod1 1000000007
int t,p=1;
string str;
//string str1="not";
string str2=" not";
string str3="not ";
string str4=" not ";
int main()
{
   cin>>t;
   getline(std::cin, str);
   while(p<=t)
   {
       p++;
       //cin>>str;
       getline(std::cin, str);
       //cout<<str<<endl;
       //size_t f1=str.find(str1);
       size_t f2=str.find(str2);
       size_t f3=str.find(str3);
       size_t f4=str.find(str4);
       
       if(str=="not")
       {
           cout<<"Real Fancy"<<endl;
       }
       else if(f4<str.size())
       {
           cout<<"Real Fancy"<<endl;
       }
       else if(f2<str.size() && str[f2+4]=='\0')
       {
           cout<<"Real Fancy"<<endl;
       }
       
       else if(f3<str.size() && f3==0)
       {
           cout<<"Real Fancy"<<endl;
       }
       else
       {
            cout<<"regularly fancy"<<endl;
       }
   }
    
    return 0;
}
