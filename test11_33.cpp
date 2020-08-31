#include<iostream>
#include<map>
#include<fstream>
#include<sstream>
using namespace std;

map<string,string>& buildRules(ifstream& ifile,map<string,string>&table)
{   
    
     //map<string,string>table;
     string word;

      string key,value; 
 	  istringstream stringbuf;
      stringstream stringk;
     	while(getline(ifile,word))
     	{  
          stringk<<word;
     	   stringbuf.str(word);
           // istringstream stringbuf(word);
          cout<<stringbuf.str()<<endl;
            stringbuf>>key;
            stringbuf>>value;
            stringbuf.clear();
            stringk.clear();
           cout<<stringk.str().capacity()<<endl;

     	      table[key]=value;	
            
     	} 
      
     return table;
} 
const string& transform(const string& s,map<string,string>&rule)
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
    map<string,string>table; 
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