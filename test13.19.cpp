#include<iostream>
#include<string>
using namespace std; 

class employee
{
private:
	string name; 
	size_t id;
	static  size_t idSeed;
public:
	employee()=default; 
	employee(const string &s):name(s),id(idSeed++){}
	employee(const employee& em):name(em.name),id(idSeed++){}
    employee& operator=(const employee &e){name=e.name;return*this;}
   void print(){cout<<name<<": "<<id<<endl;}

};  
size_t employee::idSeed=0; 

int main() 
{
    employee t("asdf"),a(t),c(a); 
   t.print(); 
   a.print(); 
   c.print(); 
  
}
