#include<iostream>
#include<string>
#include<vector>
using namespace std;
int cal(const vector<string> &s)
{   int x=0;
	 for(auto i:s)
	 {
	 	x+=stoi(i);
	 } 
	 return x;
}
int main()
{
	vector<string>s1{"0","1","2"}; 
	cout<<cal(s1)<<endl;  
	
} 