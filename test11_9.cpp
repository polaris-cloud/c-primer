#include<iostream>
#include<map>
#include<fstream>
#include<list>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(int argc,char**argv){
	 map<string,list<int>>wordmap;
     ifstream ifile(argv[1]);
     string::size_type pos=0,line=1,prev=pos;
     if(!ifile) return 0;
	// istream_iterator<string>pipe(ifile),eof;
     string words,word;
     while(getline(ifile,words))
     {   
    	 while((pos=words.find_first_of(" ",pos))!=string::npos)
    	 {  
            
            if(prev!=pos)
            {    
                
                word=words.substr(prev+1,pos-prev-1);
                wordmap[word].push_back(line);
                prev=pos;

            }
            
           ++pos;
    	 }
         pos=0;prev=pos;
         ++line; 
    }

	 ofstream ofile(argv[2]);
    if(!ofile) return 0;
    ostream_iterator<string>topipe(ofile);
    
     for(const auto w:wordmap)
     {
     	 topipe=w.first; 
     	 topipe=": "; 
     	 for(const auto  k:w.second)
     	 	{ofile<<k<<" ";}
           ofile<<endl;
     }
}