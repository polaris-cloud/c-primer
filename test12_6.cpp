#include<iostream>
#include<vector>
#include<memory>
#include<fstream>
#include<initializer_list>
using namespace std;
namespace A{
vector<int> *makeVector(initializer_list<int>li)
{ 
   // vector<int>*p=new vector<int> (li);
   return  new vector<int>(li);
   //return p;
} 

vector<int>* readNum(ifstream&ifile,vector<int>*list)
{    
    int a;
    if(ifile)
    {  
       while(ifile>>a)
       list->push_back(a); 
    }
	return list;
}

void printNum(vector<int> *list)
{
    for(auto i:*list)
    {
      cout<<i<<" ";
    }
  cout<<endl;
  delete list;
}

};

namespace  B{

 shared_ptr<vector<int>> makeVector(initializer_list<int>li)
{ 
  return make_shared<vector<int>>(li);
} 

shared_ptr<vector<int>> readNum(ifstream&ifile,shared_ptr<vector<int>>sp)
{    
     if(sp.unique())cout<<"one"<<endl;
    int a;
    if(ifile)
    {  
       while(ifile>>a)
       sp->push_back(a); 
    }
  return sp;
}

int printNum(shared_ptr<vector<int>>sp)
{
    if(sp.unique())cout<<"one"<<endl;
    for(auto i:*sp)
    {
      cout<<i<<" ";
    }
  cout<<endl； 
 
}






};
int main(int argc,char**argv)
{
   ifstream ifile(argv[1]);
   ifstream ifile1(argv[1]);
	 A::printNum(A::readNum(ifile,A::makeVector({})));
   cout<<B::printNum(B::readNum(ifile1,B::makeVector({})))<<endl;




}