#include<iostream>
#include<initializer_list>
#include<algorithm>
#include<vector>
using namespace std;

class mov
{
	private:
		std::vector<int>data;
	public:
       mov sorted() &&;  //右值引用版本
       mov sorted() const &;

       mov(initializer_list<int>li):data(li){cout<<"constructor"<<endl;}; 
       mov(mov&&m):data(std::move(m.data)){cout<<"move constructor"<<endl;} 
       mov(const mov&m):data(m.data){cout<<"copy constructor"<<endl;}
       mov& operator=(mov &&m); 
       mov& operator=(const mov& m) ;
       ~mov(){cout<<"delete"<<endl;}
};


mov& mov::operator=(const mov&m)
{
  if(this==&m) return *this;
  vector<int>vec{m.data.begin(),m.data.end()};
  data.erase(data.begin(),data.end());
  for(auto i:m.data)
  {
    data.push_back(i);
  }
	cout<<"operator="<<endl;
  return*this; 
}

mov& mov::operator=(mov && m) 
{
  if(this!=&m)
  {
     data.erase(data.begin(),data.end());
     for(auto i:m.data)
    {
       data.push_back(std::move(i));
    }
  }
  cout<<"operator rvalue"<<endl;
  return *this;
} 

mov mov::sorted() &&
{
	sort(data.begin(),data.end());
	cout<<"sorted &&"<<endl;
	return *this;
}

mov mov::sorted() const &
{
  mov ret(*this);
	sort(ret.data.begin(),ret.data.end());
	cout<<"sorted const &"<<endl;
  return ret;
	
}

//编译指令
//g++ -std=c++11 -fsanitize=address -fno-elide-constructors  test13.56.cpp -o ts
//可看到拷贝控制操作的完整调用

int main()
{
	mov  value({2,4,5,6,3,5,3,5,3});  //constructor
   value.sorted();//sorted const &
    cout<<"---------------"<<endl;
    mov temp=value;  //copy constructor
    mov anot=move(temp);  //move constructor
    mov te({1,2,4,5,52}); //constructor
    te=anot;//operator=
     te= move(anot);//operator rvalue
     mov cc=mov{4,6,1,5,7,4,7,2,5}.sorted();//sorted &&

    
} 