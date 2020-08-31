#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>f={1,3};
vector<int>vb={2,5,10,14};
auto bi=vb.begin();
auto ei=vb.end();
auto fi=f.begin();
//swap(f,vb);
//f.assign(bi,ei);
//if(f.begin()==bi)cout<<"assign is equal"<<endl;
//if(f.begin()==bi)cout<<"swap is equal"<<endl;
//cout<<*(fi)<<" "<<*(f.begin())<< endl;
//cout<<*(fi)<<endl;
 //cout<<" return "<<endl;
 cout<<*(vb.insert(vb.begin(),f.begin(),f.end()))<<endl;
 for(auto i: vb)
 {
    cout<<i<<endl ;
 }
}
