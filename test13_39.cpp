#include<string>
#include<iostream>
#include<utility>
#include<initializer_list> 
#include<algorithm>
#include<memory>
using namespace std; 

class StrVec{  
   private: 
     	 static allocator<string>alloc; //所有对象只需要一个空间分配器
   //using strPtr=decltype(alloc.allocate()); 
    string *elements; //指向分配内存中的首元素
    string *first_free; //指向创建了对象的元素之后的位置
    string *cap; //指向分配内存中末尾之后的位置

     pair<string*,string*> alloc_n_copy(const string*,const string*); //分配内存，并拷贝一定范围的元素；  
   	
   	 void chk_n_alloc(); //保证至少有容纳一个新元素的空间，如果没有，重新分配空间
     void reallocate();   //在内存用完后重新分配内存
     void free();       //销毁构造的元素，并释放内存
   public: 
   	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}; 
    StrVec(initializer_list<string>&li);
   	StrVec(const StrVec&);
   	StrVec& operator=(const StrVec &s);
   	~StrVec();
     void push_back(const string&);  
    // void pop_back(); 
     void reserve();
     size_t capacity()const {return cap-elements;} 
     size_t size()const {return first_free-elements;}
     void resize(size_t new_size,const string& s); 
     void reserve(size_t new_size);
     string* begin()const {return elements;} 
     string* end()const {return first_free;}
    void foreach() const;
};

allocator<string> StrVec::alloc;


void StrVec::push_back(const string &s)
{
	chk_n_alloc(); 
	alloc.construct(first_free++,s); 
}



pair<string*,string*> StrVec::alloc_n_copy(const string *b,const string *e)
{
	auto p=alloc.allocate(e-b);
	return{p,uninitialized_copy(b,e,p)};  //返回值给elements , first_free 
}
//销毁顺序为先destroy元素，在释放分配的内存空间  ,是否逆序销毁先实验再说
void StrVec::free()
{
	if(elements)
	{
		//for(auto p=elements;p!=first_free;++p)
		 //alloc.destroy(p);
      //alloc.deallocate(elements,cap-elements);
     for_each(begin(),end(),[](string&p){alloc.destroy(&p);});
     alloc.deallocate(elements,cap-elements);
	}
}



StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(const StrVec &s)
{
	auto iter=alloc_n_copy(s.begin(),s.end()); 
    free();
    elements=iter.first;
    first_free=cap=iter.second;
    return *this;
} 


 StrVec::StrVec(const StrVec& s)
{
	auto iter=alloc_n_copy(s.begin(),s.end()); 
    elements=iter.first; 
    first_free=cap=iter.second; 
   
}


void StrVec::reallocate()
{
 	auto newcapacity=size() ?2*size():1;   //当size为0 时，直接将其设置为1
 	auto newdata=alloc.allocate(newcapacity);
    auto temp=newdata;
 	for(auto p=elements;p!=first_free;++p)
 	{
 		alloc.construct(temp++,std::move(*p)); 
 	} 
 	free();
  elements=newdata;
  first_free=temp;
  cap=elements+newcapacity; 
} 

void StrVec::reserve(size_t new_size)
{
	auto newcapacity=new_size>capacity()?new_size:0; 
    if(newcapacity)
    {
    	auto newdata=alloc.allocate(newcapacity);
    auto temp=newdata;
 	for(auto p=elements;p!=first_free;++p)
 	{
 		alloc.construct(temp++,std::move(*p)); 
 	} 
 	free();
  elements=newdata;
  first_free=temp;
  cap=elements+newcapacity; 

    }  
} 


void StrVec::chk_n_alloc() 
{
	if(first_free==cap)
	{
		reallocate();
	} 
}


void StrVec::resize(size_t new_size,const string &s)
{
   size_t dif; 
    
	if(new_size>size())
	{
		dif=new_size-size();
      for(size_t i=0;i<dif;++i)
      {
      	push_back(s);
      }
  }else
    {
    	if(elements)
	   {
            dif=size()-new_size;
        string*p;
		 for(p=first_free;p!=first_free-dif;)
		 alloc.destroy(--p);
         first_free=p;
	   }

    }
} 


void StrVec::foreach() const 
{
   for(auto p=elements;p!=first_free;++p)
      {
         cout<<*p<<endl; 
      }
}

StrVec::StrVec(initializer_list<string>&li)
{
  for(auto i:li)
  {
     push_back(i);
  }
}



int  main()
{
   StrVec a; 
    string word; 
    cout<<"print word"<<endl;
    while(cin>>word && word!="&")
    {
       a.push_back(word);
       cout<<"capacity: "<<a.capacity()<<" size: "<<a.size()<<endl;
    }
   cin.clear(); 
   size_t pl;
   cout<<"print size:"<<endl;
    if(cin>>pl)
   a.reserve(pl);
   cout<<"capacity: "<<a.capacity()<<" size: "<<a.size()<<endl;
     
      cout<<"print size:"<<endl;
    if(cin>>pl)
    a.resize(pl,"g");
   cout<<"capacity: "<<a.capacity()<<" size: "<<a.size()<<endl;
    a.foreach();
}


