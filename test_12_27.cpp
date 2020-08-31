#include<map>
#include<set>
#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<exception>
#include<memory>
#include<sstream>
using namespace std; 

using vecstr=vector<string>;
using mapstr=map<string,set<size_t>>;
using vecPtr=shared_ptr<vector<string>>;
using mapPtr=shared_ptr<map<string,set<size_t>>>;
class QueryResult;
class TextQuery
{
  vecPtr strvec;  //一个指向动态分配内存的智能指针，内容为vector
  mapPtr strmap; // 内容为map
 public:
   TextQuery():strvec(make_shared<vecstr>()),strmap(make_shared<mapstr>()){}
   TextQuery(ifstream &ifile);
   QueryResult creatResult(); //const ;
};

class QueryResult
{
   vecPtr vecRes; 
   mapPtr mapRes; 
 public: 
 	 QueryResult(vecPtr vp,mapPtr mp):vecRes(vp),mapRes(mp){}
    void  print(const string &word,ofstream& ofile);

};

TextQuery::TextQuery(ifstream &ifile):strvec(new vecstr),strmap(new mapstr)
{
	 string words,word;
	// vecstr vec;
	// mapstr strline;
	 istringstream iss;
	 size_t lineNum=1;
	if(ifile)
	{
      while(getline(ifile,words))
      {  
        
 		    iss.str(words); 
 		    strvec->push_back(words);
        while(iss>>word)
        {
       		(*strmap)[word].insert(lineNum);
         
        } 
         ++lineNum;
         iss.clear();
      }

	}else throw runtime_error("can't open the file");

  //  strvec=make_shared<vecstr>(vec); 
   // strmap=make_shared<mapstr>(strline);
}

QueryResult TextQuery::creatResult()  //const 
{  

	return QueryResult(strvec,strmap);
}


void QueryResult::print(const string &word,ofstream& ofile)
{
	if(!ofile) throw runtime_error("can't open the file"); 
  // cout<<mapRes.use_count()<<endl;
 //  if(!mapRes->count(word)) {cout<<"can't find this word"<<endl;return;}; 
 	 ofile<<word<<" have occured "<<(*mapRes)[word].size()<<" lines"<<endl;
 	 size_t linenum;
 	 for(auto i:(*mapRes)[word])
 	 {  
 	 	ofile<<"(line"<<i<<" )"<<": "<<(*vecRes)[i-1]<<endl; 
 	 } 
}

int main(int argc,char**argv)
{
     ifstream ifile(argv[1]); 
     ofstream ofile(argv[2]); 
     TextQuery con(ifile); 
     QueryResult res=con.creatResult();
     string word;
     cout<<"enter the word"<<endl;
    while(true)
    {
    	if(!(cin>>word) || word=="&")  break; 
       else  cout<<"enter again or quit"<<endl;
    	res.print(word,ofile);
    }
    
}

