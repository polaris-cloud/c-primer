#include<iterator>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
void  pl (vector<int>::reverse_iterator ri){ } 
int main()
{
	//	vector<int>::reverse_iterator ri(vi.end()); 
	 
   //pl(vector<int>::reverse_iterator(vi.end())); //显示构造函数，防止隐式转换
	//cout<<*ri<<endl;


	vector<int>vi{1,2,3,4,5,6,7}; 
	//反向迭代器 10_34
	for(auto i=vi.crbegin();i!=vi.crend();++i)
	{
	 	cout<<*i<<" ";

	} 
	cout<<endl;

    //正向的迭代器  10_35
	 for(auto i=vi.end()-1;i!=vi.begin()-1;--i)
	 {
	 	cout<<*i<<" ";
	 } 
	 cout<<endl;
   //10_36 解
  list<int>li{1,2,3,0,4,5,0,1};
 auto ri=--find(li.rbegin(),li.rend(),0);
cout<<*(ri)<<endl;


  //10_37解 1
   vector<int>vii{3,5,4,7,1,8,9,0,21,45};
   list<int>lii;
   sort(vii.begin()+2,vii.begin()+7);
   copy(vii.begin()+2,vii.begin()+7,front_inserter(lii));
    for(auto i:lii){cout<<i<<" ";}
    	cout<<endl;
//解2
   vector<int>vij{3,5,4,7,1,8,9,0,21,45};
    list<int>lij;
    sort(vij.rbegin()+3,vij.rend()-2);
    copy(vij.begin()+2,vij.end()-3,back_inserter(lij));
   for(auto i:lij){cout<<i<<" ";}
   	cout<<endl;

} 