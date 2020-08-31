#include<iostream>
#include<fstream>
#include<string>
#include<memory>
#include<vector>
using namespace std;

int main()  
{    const char*s1="qiu";
     const char*s2="jian"; 
     string s3=string(s1)+string(s2);
     string::size_type len=s3.size();
      const char*s4=s3.c_str();
	char*s=new char[len+1]; 
	for(int i=0;i<len;++i)
	{
	  s[i]=s4[i]; 
	}
	for(int i=0;i<len;++i)
	{
	  cout<<s[i]<<endl;
	}
	delete []s;
}