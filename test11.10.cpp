#include<map>
#include<iterator>
#include<vector>
#include<list>
#include<deque>
#include<iostream>
using namespace std; 
bool comparasize(const vector<int>::iterator &s1,const vector<int>::iterator &s2)
{
    return *s1<*s2;
}
bool comparasizep(const list<int>::iterator &s1,const list<int>::iterator &s2)  
{
    return *s1<*s2; 
}
int main()
{
	map<vector<int>::iterator,int,decltype(comparasize)*>inti(comparasize); //

	vector<int>k{1},j{2}; 
	list<int>g{3},p{4};
    inti[k.begin()]=1; 
    inti[j.begin()]=2;
     for(auto i:inti)
     {
     	cout<<i.second<<endl;
     }
    
	map<list<int>::iterator,int,decltype(comparasizep)*>intm(comparasizep); 
    intm[g.begin()]=3;
    intm[p.begin()]=4;
    for(auto i:intm)
    {
    	cout<<i.second<<endl;
    }
}