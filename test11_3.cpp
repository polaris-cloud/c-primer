#include<vector>
#include<string>
#include<map>
#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;

int main(int argc,char**argv) 
{
	ifstream ifile(argv[1]);
	map<string,string::size_type>wordcounts;
	string words;
  string symbol{",."};
  string::size_type pos=0;
     if(ifile)
     {
          	while(ifile>>words)
     	    {
            if((pos=words.find_first_of(symbol,0))!=string::npos)
                   words.erase(pos);
            if(isupper(words[0]))
                {
                 words[0]=tolower(words[0]);
                }
     	   	    ++wordcounts[words];
        }
     }
   
    ofstream ofile(argv[2]);
      if(ofile)
      {
      	 for(auto i:wordcounts)
        {
       	ofile<<i.first<<"="<<i.second<<endl;
        }
      }
}