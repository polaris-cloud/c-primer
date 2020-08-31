#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>
//#include<iterator>
using namespace std; 
int main(int argc,char**argv)
{   
    ifstream ifile(argv[1]);
    ofstream ofile(argv[2]);
    map<string,vector<string>>family;
    multimap<string,string>family_div; 
    string lastname,firstname;
    if(ifile){
    	
	  
	while(ifile>>firstname>>lastname)
	{      
          
  		 family[firstname].push_back(lastname);
  		 family_div.emplace(firstname,lastname);
	} 
	
	if(ofile)
	{
	   for(auto i:family){ofile<<i.first<<": ";for(auto k:i.second){ofile<<k<<" ";}ofile<<endl;}
	}
    }

	  //ostream_iterator<string>pipe(ofile,"\n");

       //copy(family_div.begin(),family_div.end(),pipe); 

      for_each(family_div.begin(),family_div.end(),[](const pair<string,string>& s){cout<<s.first<<" "<<s.second<<endl;});


	
}