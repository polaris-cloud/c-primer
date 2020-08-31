#include<algorithm>
#include<iostream>
#include<vector>
#include<numeric>
#include<iterator>
using namespace std; 
int main() 
{
	/*
	vector<int>s{1,2,3,4,7,8};
	vector<int>v{2,3,4,5}; 
	vector<double>f{1.2,2.4,4.5};
	cout<<accumulate(f.cbegin(),f.cend(),0)<<endl; 
	cout<<accumulate(f.cbegin(),f.cend(),0.0)<<endl;
	cout<<count(s.begin(),s.end(),6)<<endl; 
	cout<<equal(s.begin(),s.end(),v.begin())<<endl ;
	vector<string>a{"qwe"};
	vector<string>b{"qwer"};
    cout<<equal(a.begin(),a.end(),b.begin())<<endl;
    */
  vector<int>vec;
  auto it=back_inserter(vec);
  it=58; 
  it=543;
  for(auto i:vec){cout<<i<<endl;} 

} 