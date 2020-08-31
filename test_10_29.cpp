#include<fstream>
#include<iterator>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
int main(int argc,char**argv)
{  
     ifstream  fs(argv[1]);
	istream_iterator<string>is(fs),eof;
  if(fs)
  {
 	   vector<string>vi(is,eof);
 	   for(auto i:vi){cout<<i<<" ";}
  cout<<endl; 
  }      

  
} 