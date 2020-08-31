#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<iterator>
using namespace std; 
using namespace std::placeholders;
bool isequal(const string &s1,const string &s2) {
  return s1==s2;
}
int main() 
{
	vector<string>words;
	string word; 
	cout<<"please enter: ";
	while(cin>>word)
	{
	  words.push_back(word);
	}
	sort(words.begin(),words.end());
    auto i=unique(words.begin(),words.end(),bind(isequal,_1,_2));
    ostream_iterator<string>oi(cout," ");
    for_each(words.begin(),i,[&oi](const string& s){oi=s;});
    //for_each(words.begin(),i,[](const string&s){cout<<s<<endl;});
} 