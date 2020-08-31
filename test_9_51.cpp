#include<string>
#include<iostream>
#include<vector>
using namespace std;
struct date{
	unsigned  year;
	unsigned  month;
	unsigned  day;
    date(const string&);
    inline void show(){cout<<year<<" "<<month<<" "<<day<<endl;}
};
string::size_type numcast(const string&s)
{
   if(s.find_first_of("0123456789")!=string::npos)
    {
    	return stod(s);
    }else 
       return string::npos;

}
string::size_type monthcast(const string&s1)
{  
    
	vector<string>s2={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
	int pos=0;
     for(auto i:s2)
     {  
         ++pos;
       if(s1.find(i)!=string::npos)
       {
            return pos;
       }

     }
return string::npos;

}
//January 1,1990 1/1/1990 Jan 1 1990
//首先只读取有效数据，先进行数据搜索，在进行数据转换
//读取间隔符
date::date(const string&s)
{
  string gap{" ,/"}; 
   decltype(s.size()) cur=0,prev=0,value=0; 
   vector<int>pos;
    
	while((cur=s.find_first_of(gap,cur))!=string::npos)
	   {  
	       pos.push_back(cur);
         ++cur;
	   } 	
      string sm=s.substr(0,pos[0]); 
      if((value=monthcast(sm))==string::npos)
         month=numcast(sm);
       else 
          month=value;
      string sd=s.substr(pos[0]+1,pos[1]-1); 
        day=numcast(sd);
      string sy=s.substr(pos[1]+1);
        year=numcast(sy);
} 


int main()
{
   date x("March 1,1990");
     x.show();
   date y("1/5/1980");
    y.show();

   date s("Aug 1 1990");
    s.show();

} 
