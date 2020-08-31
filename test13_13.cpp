#include<iostream>
#include<memory>
#include<vector>
using namespace std; 

class myclass{
public:
	 myclass(){cout<<"constructor"<<endl;}
	 myclass(const myclass &s){cout<<"copy constructor"<<endl;}
     myclass& operator=(const myclass &s){cout<<"operator="<<endl;return *this;}
     ~myclass(){cout<<"destructor"<<endl;}
     void df(myclass ak){cout<<"hhjv"<<endl;}
}; 



int main() 
{
	myclass my,mc;  //constructor,constructor
	myclass mt=my;  //copy constructor
	myclass*mv=new myclass;  //constructor
    mc=mt;  //operator=   赋值
    vector<myclass>gh;
    gh.push_back(*mv);  //copy constructor  初始化
    delete mv; //deconstructor 
    auto mb=make_shared<myclass>(); //constructor
    mc.df(mc); //copy constructor
}