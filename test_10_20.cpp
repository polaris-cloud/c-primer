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
   cout<<count_if(words.begin(),words.end(),[](const string&s){return s.size()>6;})<<endl;
  

} 