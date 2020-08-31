#include<forward_list>
#include<iostream>

using namespace std;
//删除奇数元素
void deleteOdd(forward_list<int>&fi)
{
  auto iterb=fi.before_begin();
  auto iter=fi.begin(); 
	while(iter!=fi.end())
	 {
 		if(*iter%2)
 		{
 		  iter=fi.erase_after(iterb);
 		  //iterb=iterb; 删除一个元素，前置元素不变
 		}else {
 		  iterb=iter;  //先将当前元素设置为下一个元素的前置元素
 		  ++iter;  //然后更新元素
 		}
	     
	 }
}
void addOdd(forward_list<int>&fi)
{
	//auto interb=fi.before_begin(); 
	auto iterb=fi.begin(),iter=iterb;

	while(iter!=fi.end())
	{
	 	if(*iter%2==0)
	 	{
	 		iterb=fi.insert_after(iterb,*iter+1);
	 		iter=++iterb; 
	 	}else{
	 		iterb=iter;
	 		++iter;
	 	}
	}
}
int main()
{
  forward_list<int>k{0,1,2,3,4,5,6,7,8,9};
  deleteOdd(k);
  for(auto i:k){cout<<i<<" ";}
  cout<<endl; 
  addOdd(k);
   for(auto i:k){cout<<i<<" ";}
   	cout<<endl;
}
