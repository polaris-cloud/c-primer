#include<vector>
#include<memory>
#include<fstream>
#include<string>
#include<initializer_list>
#include<exception>
#include<iostream>
using namespace std; 
class strControlPtr;
class strControl 
{
   friend class strControlPtr;
   using strVec=vector<string>;
   using strlen=vector<string>::size_type;
  public:
	strControl(initializer_list<string>li):data(make_shared<strVec>(li)){} //用一个列表初始化string;
	strControl(const strVec&s1):data(make_shared<strVec>(s1)){}
	//s1的拷贝
  strControl(strControlPtr s,strControlPtr e);

	strControl():data(make_shared<strVec>()){}
    //空的string 
   strlen size()const {return data->size();}  //返回size
   void  push_back(const string& s1){data->push_back(s1);}
   void  pop_back();//删除
   bool  empty(){return data->empty();} //是否为空
   string& front(); 
   string& back();  //对于空的元素，front()和back()的行为是未定义的，因此需要判断
   strControlPtr begin() const;
   strControlPtr end() const;            


private:
   shared_ptr<strVec>data;
  //需要一个函数来判断vector的size
  void check(strlen len,const string& msg)const;
};

void strControl::check(strlen len,const string&msg) const
{
	 if(len>=data->size()) 
	    throw out_of_range(msg); 

}

string& strControl::front()
{
	check(0,"no element");  
	return data->front(); 
}

string& strControl::back()
{
	check(0,"no element"); 
	return data->back();
}

void strControl::pop_back()
{
	check(0,"no element"); 
    data->pop_back(); 
}


//weak_ptr 使用的是弱共享
//weak_ptr是为了配合shared_ptr而引入的一种智能指针，它更像是shared_ptr的一个助手而不是智能指针，因为它不具有普通指针的行为，没有重载operator*和->,它的最大作用在于协助shared_ptr工作，像旁观者那样观测资源的使用情况.

class strControlPtr
{
public:
  using strvec=vector<string>;
  using strlen=vector<string>::size_type;
  using spv=shared_ptr<strvec>;
  strControlPtr():index(0){}
	strControlPtr(const strControl &sc,strlen index_=0):wp(sc.data),index(index_){ }

   string& operator*() const ; 
   strControlPtr& operator++();
   bool operator!=(const strControlPtr& scp) const; 
   
 private:
    weak_ptr<strvec>wp;
    strlen index;
    spv check(strlen index_) const ; 
   

};


strControlPtr strControl::begin() const
{
   return strControlPtr(*this); 
}

strControlPtr strControl::end() const
{
  return strControlPtr(*this,data->size()); 
}

strControlPtr::spv strControlPtr::check(strlen index_) const 
{
    auto res=wp.lock(); 
    if(!res) throw runtime_error("unbound strControl"); 
    if(index>=res->size())
    throw out_of_range("out of range");
    return res;  
}

string& strControlPtr::operator*() const 
{ 
    auto res=check(index); 
    return (*res)[index];
}

strControlPtr& strControlPtr::operator++()
{ 
    check(index); 
    ++index;
    return *this;
}


bool strControlPtr::operator!=(const strControlPtr& scp) const
{
   return this->index!=scp.index;
}

strControl::strControl(strControlPtr s,strControlPtr e)
{   
    vector<string>vec; 
    while(s!=e)
    {
      vec.push_back(*s);
      ++s;
    }
    data=make_shared<strVec>(vec);
}





int main(int argc,char**argv)
{
  const strControl sc({"a","b","c"}); 
   //strControlPtr scp(sc);
   for(auto i=sc.begin();i!=sc.end();++i)
   {
      cout<<*i<<endl;
   }
  ifstream ifile(argv[1]);
   strControl scc;
   string word;
  if(ifile)
  {
     while(ifile>>word)
     {
      scc.push_back(word); 
     }
  }

  for(auto i=scc.begin();i!=scc.end();++i)
   {
      cout<<*i<<endl;
   }

}


