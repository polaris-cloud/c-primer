#include<string>
#include<iostream>
#include<memory>
using namespace std;


using strPtr=unique_ptr<char[]>;

char*saveString(char*s1,string word,size_t*strlen)
{
	string s=string(s1)+word; 
	delete[]s1; 
	string::size_type len=s.size();
	const char*s3=s.c_str(); 
	char*res=new char[len+1]; 
	for(int i=0;i<len+1;++i)
	{
	  res[i]=s3[i]; 
	}
	*strlen=len;
	return res;
}

strPtr& saveString(strPtr&sp,string word,size_t*strlen)
{
	string s=string(sp.get())+word;    //此处可以选择release 这个sp，然后在下面重新构造一个unique_ptr,
	//这里的做法是将原先的内存reset为新的内存
	string::size_type len=s.size();
	const char*s3=s.c_str(); 
     sp.reset(new char[len+1]); 
	for(int i=0;i<len+1;++i)
	{
	  sp[i]=s3[i]; 
	}
	*strlen=len;
	return sp;

}


void showString(const char *s,size_t len)
{
	for(size_t i=0;i<len;++i)
	{
		cout<<s[i]<<endl;
	}
}


void showString(strPtr&res,size_t len)
{
	 for(size_t i=0;i<len;++i)
	 {
	 	cout<<res[i]<<endl;
	 }
} 


int main()
{  string word;
  size_t i=0;
  size_t *xlen=&i; 

   char*s1=new char[1]();
	 while(cin>>word && word!="&")
	 {
	 	s1=saveString(s1,word,xlen);
	 }
  showString(s1,i);
  delete[] s1;
  
    strPtr sp(new char[1]());
    while(cin>>word && word!="&")
    {
    	saveString(sp,word,xlen);
    } 
  showString(sp,i);


} 