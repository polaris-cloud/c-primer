#include<vector>
#include<algorithm>
#include<iostream>
using namespace std; 
struct Test
{
   Test(int b):a(b){} 
	int a;
};

bool camparevalue(const Test&t1,const Test&t2)
{
  return t1.a>t2.a;
}
int main()
{
	
    vector<Test>a{3,12,452,65,768,235,723,123,8234,82,154,82,143}; 
    //stable_sort(a.begin(),a.end(),camparevalue);
     stable_sort(a.begin(),a.end(),[](const Test& s1,const Test&s2){return s1.a>s2.a;});
    for(auto i:a){
         cout<<i.a<<endl;
    } 
}