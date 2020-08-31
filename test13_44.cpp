#include<utility>
#include<memory>
#include<algorithm>
#include<iostream>
//using namespace std;


class  string{
  static std::allocator<char>alloc; 
  private: 
 	 char*first;   //元素首指针
 	 char*endPtr;   //元素尾指针
 	 char*cap;  //内存尾指针
  std::pair<char*,char*> alloc_n_copy(const char*b,const char*e) const ;
  // void chk_n_alloc();  //检测内存
   void free(); 
   //void reallocate();  //重新分配内存
  public:
    string():first(nullptr),endPtr(nullptr),cap(nullptr){} 
    string(const char*ch);
    string(const string&s); 
    string& operator=(const string&s); 
    ~string(); 
   size_t size()const {return endPtr-first;};
   char* begin()const{return first;} 
   char* end() const {return endPtr;}
 friend std::ostream& operator<<(std::ostream &stream,const string&s);
};

std::allocator<char> string::alloc;

std::pair<char*,char*>string::alloc_n_copy(const char*b,const char*e) const //拷贝元素并进行分配
{
	auto p=alloc.allocate(e-b);
    return{p,std::uninitialized_copy(b,e,p)}; 
}


void string::free() 
{
   if(first)
   {
   		std::for_each(first,endPtr,[](char&ch){alloc.destroy(&ch);});
   	    alloc.deallocate(first,cap-first);

   }
   
}


string::~string() 
{
	free();
}

string::string(const string &s)
{
	auto newdata=alloc_n_copy(s.begin(),s.end());
	first=newdata.first; 
	endPtr=cap=newdata.second; 

}

string& string::operator=(const string& s)  //处理自赋值 第一种：拷贝并交换 第二种：普通的引用传值，将值先
//保存在临时变量中
{
	auto newdata=alloc_n_copy(s.begin(),s.end());//假设*this=s，则需要先保存值，再free
	free();  //删除旧值
    first=newdata.first; 
    endPtr=cap=newdata.second;
    return *this; 
} 




string::string(const char*ch)
{
	auto p=ch;
    while(*p)
    {
       ++p; 
    }     
   auto res=alloc_n_copy(ch, p);
   first=res.first;
   endPtr=cap=res.second;
}

std::ostream& operator<<(std::ostream&stream,const string&s)
{
  std::for_each(s.first,s.endPtr,[&](const char ch){ stream<<ch;});
  return stream;
}

int main()
{
   string  b("qiujianfeng");
  // std::cout<<"dfadsf"<<std::endl;
  std::cout<<b<<std::endl;
  std::cout<<b.size()<<std::endl;
} 


