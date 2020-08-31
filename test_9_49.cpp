#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//查找第一个字符，查找下一个出现字符
void finda(const string&s1,const string&s2)
{
      decltype (s1.size()) cur=0,prev=0;
      decltype(s1.size()) len=0,pos=0;

 while((cur=s1.find_first_of(s2,cur))!=string::npos)
     {    
       if(cur-prev>len)
       {
           pos=prev;
          len=cur-prev;
       }
        prev=cur;   //比较之后，更新prev
         ++cur;
      
     }
      
     cout<<s1.substr(pos+1,len-1);

     cout<<endl; 
    
		
}
int main(int argc,char**argv)
{
	string s1{"bdfhpgh"};
  ifstream is(argv[1]);
    if(is)
    { 
      string words;
     // getline(is,words);
      is>>words;
      finda(words,s1);
    }
	
} 