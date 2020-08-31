#include<utility>
#include<map>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
int main(int argc,char**argv)
{
     ifstream ifile(argv[1]); 
     ifstream ifile1(argv[2]); 
     istream_iterator<string>pipe_str(ifile),eof;
     istream_iterator<int>pipe_int(ifile1),end;
     vector<string>vec_str(pipe_str,eof); 
     vector<int>vec_int(pipe_int,end); 
     vector<pair<string,int>>vec_couple;
     auto k=vec_int.begin();
      for(auto i=vec_str.begin();i!=vec_str.end();++i,++k)
     {
          vec_couple.push_back({*i,*k});
     } 
      
   ofstream ofile(argv[3]); 
   for(auto i=vec_couple.begin();i!=vec_couple.end();++i)
   {
     ofile<<i->first<<" "<<i->second<<"\n"; 

   } 
   ofile<<endl;
}