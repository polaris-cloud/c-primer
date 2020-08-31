#include<iostream>
#include<forward_list>
#include<string>
using namespace std;
void what(forward_list<string>&fs,const string&s1,const string&s2)
{
  auto  iterb=fs.before_begin(),iter=fs.begin(); 
  	while(iter!=fs.end())
  	{  
  	   if(*iter==s1)
  	   {
  	   	 break;
  	   }else{
  		iterb=iter;
 		++iter; 
  	   }
     
  	}
     if(iter==fs.end())
    {
      fs.insert_after(iterb,s2);
    }else  
       fs.insert_after(iter,s2);
}
using namespace std;
int main()
{
	 forward_list<string>fs={"a","b","c","d"};
  what(fs,"v","ads");
  for(auto i:fs){cout<<i<<" ";}
    cout<<endl;

}