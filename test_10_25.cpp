#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<string>
#include<functional>
using namespace std;
using namespace std::placeholders;
bool check_size(const string& s,string::size_type sz)
{
    return s.size()>=sz;
}  
void biggies(vector<string>&words,vector<string>::size_type sz)
{      
      
       sort(words.begin(),words.end());
      words.erase(unique(words.begin(),words.end()),words.end());
      stable_sort(words.begin(),words.end(),[](const string&s1,const string&s2){return s1.size()<s2.size();});
     auto it=stable_partition(words.begin(),words.end(),bind(check_size,_1,sz) );

      for_each(words.begin(),it,[](const string&word){cout<<word<<endl;});
	  
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
  
   biggies(words,3);
   ofstream os(argv[2]); 
   if(os)
   {
   		for(auto i:words)
   		{
   			os<<i<<" ";
   		}
   }

} 