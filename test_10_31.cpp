#include<iterator>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
   istream_iterator<int>is(cin),eof;
  
   vector<int>vi(is,eof);
    sort(vi.begin(),vi.end());
    
    ostream_iterator<int>fs(cout,"\n");
   unique_copy(vi.begin(),vi.end(),fs);
}