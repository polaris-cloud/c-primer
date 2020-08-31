#include<iostream>
#include<string>
#include<stack>
#include<cctype>
using namespace std;
/*
 **两个栈，stack1和stack2
 **stack1:（初始化为一个最低优先级的符号），将表达式中的所有符号压入栈1中。
 **将数字压入stack2中，当新的符号优先级低于statck1的栈顶符号(不包括左运算符)时，将两个数字和栈顶的符号进行计算，并出栈，结果压入stack2中。并重复判断直到栈顶符号优先级小于新的符号，将新符号压入栈中
 **遇到右括号前面全部出栈，右括号均丢弃，
 **无元素，全出栈
 */

//将一个运算符和两个操作数进行运算

void cal(stack<char>& sta1,stack<int>&sta)
{ 
  int ch1=sta.top();
     sta.pop();
   int ch2=sta.top(); 
    sta.pop();
  int res;
  char oper=sta1.top(); 
  sta1.pop();
	switch(oper)
	{
		case '+': 
		res=ch1+ch2;
	     break;

	    case '-':
	    res=ch1-ch2;
	     break;

	    case '/':
	     res=ch1/ch2;
	     break; 

	    case '*': 
	      res=ch1*ch2;
	      break;
           
	}
	sta.push(res); 
	
}
int symvalue(char ch)
{   int value;
	switch(ch)
	{

	  case '+': 
	  case '-':
	     value=1;
	     break;

	  case '*':
	  case '/':
	     value=2; 
	     break;
	  default: value=0;
	} 
	return value;
}  
void  dealSymbol(stack<char>&sta1,stack<int>&sta2,char ch)
{  
  char top=sta1.top();
       
      if(top=='(')
         {
         	sta1.push(ch); 
         	return;
          }
            while(!(symvalue(top)<symvalue(ch)))
            {
              cal(sta1,sta2);
            } 
     sta1.push(ch);
        
  
}


int trans(const string &s)
{    
   
    stack<char>sta1;
    sta1.push('#');
    stack<int>sta2;

   for(auto i:s)
   {

         if(i==')')
         {
           while(sta1.top()!='(')
           {
               cal(sta1, sta2); 
           } 
             sta1.pop();
         } 
         else if(i=='(')
         {
            sta1.push(i);
         }
         else if(isdigit(i))
         { 
           sta2.push(i-0x30); 
         } 
         else{
           
            dealSymbol(sta1,sta2,i); 
         } 

   }
   
  while(sta1.top()!='#')
   {
      cal(sta1,sta2);
   } 
 return sta2.top();

}
int main()
{
	 string s{"(((3+5)*7))+8"};
	cout<<trans(s)<<endl; 

}