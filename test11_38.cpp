#include<map>
#include<unordered_map>
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main(int argc,char**argv)
{
	string word; 
	ifstream ifile(argv[1]);
	unordered_map<string,string::size_type>wordcount; 
	if(ifile)
	{
		while(ifile>>word)
		{
			++wordcount[word]; 
		}

	} 
  for(auto i: wordcount)
  {
  	cout<<i.first<<" "<<i.second<<endl;
  }
  




} 