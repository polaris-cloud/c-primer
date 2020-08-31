#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>ls{1,2,4,5};
	auto iter=ls.begin();
	ls.pop_back();
	cout<<*iter<<endl;

}
