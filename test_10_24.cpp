#include<functional>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
using namespace std::placeholders;
bool check_size(const string &s,string::size_type sz)
{
	return s.size()<sz;
}
int main() 
{
	string sa{"fasdf"};
    vector<int>vi{1,2,3,4,5,6,7};
   auto i=find_if(vi.begin(),vi.end(),bind(check_size,sa,_1));
   cout<<*i<<endl; 
}