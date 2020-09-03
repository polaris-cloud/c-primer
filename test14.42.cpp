#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
using namespace std;
using std::placeholders::_1; 
using std::placeholders::_2;
int main()
{
	 vector<int> vec{1,5164,12365,62,24,12,1024};
	 vector<string>words{"ads","fasd","pooh"};
	cout<<count_if(vec.begin(),vec.end(),bind(greater<int>{},_1,1024))<<endl;
	 //其中 greater<int>{} 为一个标准库函数临时对象(此处调用了默认构造函数)，可解析为 greater<int> gt;bind(gt,_1,1024);
   auto p=find_if(words.begin(),words.end(),bind(not_equal_to<string>(),_1,"pooh"));
   cout<<*p<<endl;

  
   transform(vec.begin(),vec.end(), vec.begin(), bind(multiplies<int>(),_1,2));
   for(auto i:vec)
   {
   	  cout<<i<<endl;
   } 
} 