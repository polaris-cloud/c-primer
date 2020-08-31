#include<iostream>
using namespace std; 
int main()
{
 int a=10;
  auto f=[&]()mutable->bool{ int b=a;while(a>0)--a;return b?true:false;} ;
  cout<<f()<<endl;
  cout<<f()<<endl;
} 