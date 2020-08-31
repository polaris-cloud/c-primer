#include<iterator>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;
int main(int argc,char**argv)
{  
   ifstream ifs(argv[1]);
   ofstream ofs(argv[2]),ofs1(argv[3]);

   istream_iterator<int>is(ifs),eof;
   ostream_iterator<int>ois(ofs," "),ois1(ofs1,"\n");
  
    while(is!=eof)
    {
    	if(*is%2)
    	{
             ois=*is++;
    	}else
    	   ois1=*is++;
    }  




}