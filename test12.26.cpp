#include<memory>
#include<string>
#include<iostream>
using namespace std;
 
int main() 
{
	allocator<string>alloc;
	string word;
	int n;
	 cin>>n;
	auto p=alloc.allocate(n);
	auto q=p;
	while(cin>>word && q!=p+n)
	{
		alloc.construct(q++,word);
	} 
     
  while(q!=p)
  {  
    cout<<*(--q)<<endl;
    alloc.destroy(q);
  }
alloc.deallocate(p,n);

}