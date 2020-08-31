#include<string>
#include<iostream>
using namespace std;
void findA(const string &s,const string&s1)
{ 
  decltype(s.size()) pos=0;
    while((pos=s.find_first_of(s1,pos))!=string::npos)
     {  
        cout<<s[pos]<<endl;
        ++pos;
        }
}
void findB(const string &s,const string &s1)
{
   decltype(s.size()) pos=0;
    while((pos=s.find_first_not_of(s1,pos))!=string::npos)
     {  
        cout<<s[pos]<<endl;
        ++pos;
        }
} 

int main()
{
	string s1{"ab2c3d7R4E6"}; 
	string s2{"abcdRE"};
	string s3{"23746"};
	findA(s1,s2);
	findA(s1,s3);

  findB(s1,s3);
  findB(s1,s2);

}