#include<iostream>
#include<deque>
#include<list>
#include<vector>
using namespace std;
void movenumber(const list<int>&li,deque<int>&deven,deque<int>&dodd)
{
    for(auto i:li)
    {
       i%2?dodd.push_back(i):deven.push_back(i);
    }
    return;
}
int main()
{
	vector<string>ds;
  auto i=ds.begin(); 
   string words; 
   while(cin>>words)
     {
   		 ds.insert(i,words);
     }
    for(auto k:ds){cout<<k<<endl;}
 /* list<int>l{1,2,3,4,5,6,7};
  deque<int>de,dod;

  movenumber(l,de,dod);
  cout<<"get"<<endl;
  for(auto i:de){cout<<i<<endl;}
  for(auto i:dod){cout<<i<<endl;}
*/
}