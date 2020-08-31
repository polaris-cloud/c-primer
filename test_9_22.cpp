#include<vector>
#include<iostream>
using namespace std;
void insertVal(vector<int>&iv,int some_val)
{
	vector<int>::iterator iter=iv.begin(),
	 mid=iv.begin()+iv.size()/2;
    auto msize=iv.size()/2;
    while(iter!=mid)
    {
    	if(*iter==some_val)
    	  {
    	    iter=iv.insert(iter,2*some_val)+2;
             ++msize;
    	   mid=iv.begin()+msize;
        }else
    	       ++iter; 
    	
    } 
}
int main()
{

vector<int>iv{1,4,4,4,5,6,7,8,9};
 insertVal(iv,4); 
 for(auto i:iv){cout<<i<<endl;}
    cout<<"one sequence"<<endl; 
 

}