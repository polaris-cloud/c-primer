#include<iostream>
#include<string>
using namespace std; 
void reset(string &s,const string&oldVal,const string &newVal)
{   
    using  ssize=decltype(s.size());
    ssize os=oldVal.size();
    ssize ns=newVal.size(); 


//**下标版本
 	for(ssize i=0;i!=s.size();++i)
 	{
 	    if(s.substr(i,os)==oldVal)
 	    {  
 	       //  s.erase(i,os);
           //s.insert(i,newVal);
           s.replace(i,os,newVal);
            i=i+os-1; 

 	    }
 	    
 	}

 


}


int main()
{
	string s1("abcdefbcgbcbcbch");
	string s2("bc"); 
	string s3("bcqiujian");
	reset(s1,s2,s3);
	cout<<s1<<endl; 
}