#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
void biggies(vector<string>&words,vector<string>::size_type sz)
{      
       auto it=partition(words.begin(),words.end(),[sz](const string&word){return word.size()>=sz;} );
         words.erase(it,words.end());

       sort(words.begin(),words.end());
        words.erase(unique(words.begin(),words.end()),words.end());
 
       stable_sort(words.begin(),words.end(),[](const string&s1,const string&s2){return s1.size()<s2.size();});
      for_each(words.begin(),words.end(),[](const string&word){cout<<word<<endl;});
	  
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