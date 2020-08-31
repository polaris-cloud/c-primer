#include<map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	map<string,int>mail; 
	mail["fasdf"]=1;
	auto  i=mail.begin() ; 
	 cout<<i->first<<endl; 
	  i->second=2; 
	  cout<<i->second<<endl;
}  