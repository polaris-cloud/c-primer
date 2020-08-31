#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using std::string;

class HasPtr {
 public: 
    HasPtr(const string&s=" "):ps(new string(s)),i(0){} 
    HasPtr(const HasPtr& p):ps(new string(*p.ps)),i(p.i){std::cout<<"拷贝构造"<<std::endl;}
   // HasPtr& operator=(const HasPtr &); 
    HasPtr& operator=( HasPtr);
    ~HasPtr(){delete ps;}
  void swap(HasPtr&ls,HasPtr& hs); 
  bool operator<(const HasPtr& hs)const {std::cout<<"operator<"<<std::endl;return *ps<*(hs.ps); }
  void print(){std::cout<<*ps<<std::endl;}
  private:
    string*ps; 
    int i;	


};
void HasPtr::swap(HasPtr &ls, HasPtr &hs)
{    using std::swap; 
	swap(ls.ps,hs.ps); 
	swap(ls.i,hs.i); 
  std::cout<<"qiu"<<std::endl;

}
// HasPtr& HasPtr::operator=(const HasPtr &p)
// {
// 	auto k=new string(*p.ps); 
// 	delete ps; 
// 	ps=k;
// 	i=p.i;
// 	return*this; 

// }

HasPtr& HasPtr::operator=(HasPtr ls)
{
	swap(*this,ls);
  std::cout<<"operator=="<<std::endl; 
	return*this;

}

int main()
{
	  HasPtr a,c;
    HasPtr b=a; 
    c=a; 
    std::cout<<"——————————分割线——————————"<<std::endl;
  std::vector<HasPtr>vec{HasPtr("do"),HasPtr("b")}; 
   std::cout<<"——————————分割线——————————"<<std::endl;
  sort(vec.begin(),vec.end()); 
   std::cout<<"——————————分割线——————————"<<std::endl;
  for(auto i:vec)
  {
     i.print();
  }

} 
