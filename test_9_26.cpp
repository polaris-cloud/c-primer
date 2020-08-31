#include<iostream>
#include<vector>
#include<list>
using namespace std; 
void  movenum(vector<int>&vi,list<int>&li)
{
 auto iter=vi.begin();
 auto iter_=li.begin();
  while(iter!=vi.end())
  {
     if(*iter%2==0)
     {
      iter=vi.erase(iter);  
     }else
      ++iter;
  }
  while(iter_!=li.end())
  {
  		if(*iter_%2)
  		{
  			iter_=li.erase(iter_);
  		}else
  		++iter_;
  }
}
int main()
{
    int ia[]={0,1,1,2,3,5,8,13,21,55,89};
    vector<int>vi(begin(ia),end(ia));
    list<int>li(begin(ia),end(ia)); 
    movenum(vi,li);
    for(auto i:vi){cout<<i<<" ";}
      cout<<endl;
    for(auto  i:li){cout<<i<<" ";}
       cout<<endl;
     

}