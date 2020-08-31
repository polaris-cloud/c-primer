#include<vector>
#include<iostream>
#include<list>
#include<iterator>
using namespace std;
int main()
{
	vector<int>vec;list<int>lst{1,2,4,5,6,7};int i;
	  
	 copy(lst.cbegin(),lst.cend(), back_inserter(vec));
	 for(auto i:vec)cout<<i<<endl;
   vector<int>vet;
 fill_n(back_inserter(vec),10,1);
  for(auto i:vet)cout<<i<<endl; 


} 









