#include<iostream>
#include<string>
using namespace std; 
const string& addfix(string& oldname,const string& pre, const string& suf)
{
	auto i=oldname.begin(); 
    oldname.insert(0,pre);
    oldname.append(suf);
    return oldname;	
}
int main() 
{
     string s1("qiu");
     string s2("mr");
     string s3("jianfeng");
	cout<<addfix(s1,s2,s3)<<endl;
}