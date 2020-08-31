#include<iostream>
#include<unordered_map>
#include<fstream>
#include<sstream>
using namespace std;
//用无序容器替代有序容器提高程序的性能
unordered_map<string,string>& buildRules(ifstream& ifile,unordered_map<string,string>&table)
{   
     //map<string,string>table;
      string word;
      string key,value; 
 	    istringstream stringbuf;
    
     	while(getline(ifile,word))
     	{  
     	      stringbuf.str(word);
            stringbuf>>key;
            stringbuf>>value;
            stringbuf.clear();
     	      table[key]=value;	     
     	} 
      cout<<table.bucket_count()<<endl;
      cout<<table.bucket("i")<<endl;
      cout<<table.load_factor()<<endl;
     return table;
} 
const string& transform(const string& s,unordered_map<string,string>&rule)
{
    
   auto map_it=rule.find(s);
   if(map_it!=rule.end())
   {
     return map_it->second;  
   }else 
     return s;

}


void wordRule(ifstream& rule,ifstream& input)
{
    unordered_map<string,string>table; 
    table=buildRules(rule,table); 
    for(auto i:table)
    { cout<<i.first<<" "<<i.second<<endl;}
    string word;
    istringstream is;
    while(getline(input,word))
    {
    	is.str(word);

		while(is>>word)
		{
            cout<<" "; 
		    cout<<transform(word,table);
  		}        
     cout<<endl;
    } 
}


int main(int argc,char**argv)
{
     ifstream rule(argv[1]),input(argv[2]);
     if(rule && input)
     {
        wordRule(rule,input);
     }
	
}