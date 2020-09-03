#include<fstream>
#include<string>
#include<iostream> 
#include<algorithm>
#include<vector>
#include<iterator>

using namespace std;

class anonymous
{
	     
    public:
 		bool operator()(string&word,int size)const{return word.size()==size;}
    bool operator()(string&s1,string&s2)const{return s1.size()<s2.size();}
};
int main(int argc,char**argv)
{
   int a[10]={};
	anonymous l;
	string word;
	ifstream ifile(argv[1]); 
  
  if(!ifile) return 0;
  istream_iterator<string>is(ifile),eof;
  vector<string>vec(is,eof);
	
  sort(vec.begin(),vec.end(),l);
  int  i=1;
 for(auto pas=vec.begin();pas!=vec.end();)
   {
      
     if(l(*pas,i)){++a[i-1];++pas;}
       else ++i; 
     if(i==11) break;
    
  } 
  for(auto i:a)
  {
      cout<<i<<endl;
  } 
} 