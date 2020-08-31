#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
bool judge(const string&s)
{
	return s.size()>4;
}
int main(int argc,char**argv)
{
   ifstream is(argv[1]);
   vector<string>words;
   if(is)
   {
   		string temp;
   		while(is>>temp)
   		{
   		 	words.push_back(temp);
   		}
   }
   auto it=partition(words.begin(),words.end(),judge);
   words.erase(it,words.end());
   sort(words.begin(),words.end());
   ofstream os(argv[2]); 
   if(os)
   {
   		for(auto i:words)
   		{
   			os<<i<<" ";
   		}
   }

} 