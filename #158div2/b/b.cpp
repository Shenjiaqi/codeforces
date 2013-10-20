#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#define NUM(a) ((a)-'0')
string check(const string & str,int l)
{
  for(int i=0;i<10;++i)
    if(i==2 || i==5)
      {
	if(str[l+i]!='-')
	  return "";
      }
    else if(str[l+i]>'9' || str[l+i]<'0')
      return "";
  int a=NUM(str[l])*10+NUM(str[l+1]);
  int b=NUM(str[l+3])*10+NUM(str[l+4]);
  int c=NUM(str[l+6])*1000+NUM(str[l+7])*100+NUM(str[l+8])*10+NUM(str[l+9]);
  if(c>2015 || c<2013)
    return "";
  if(b<1 || b>12)
    return "";
  if(b==1 || b==3 || b==5 || b==7 || b==8 || b==10 || b==12)
    {
      if(a>31 || a<1)
	return "";
    }
  else if(b==2)
    {
      if(a>28 || a<1)
	return "";
    }
  else if( a>30 || a<1)
    return "";
  return str.substr(l,10);
}
int main()
{
  freopen("in","r",stdin);
  string str;
  cin>>str;
  int l=str.length();
  string ans="";
  int num(0);
  map<string,int> mapp;
  for(int i=0;i<=l-10;++i)
    {
      string tmp=check(str,i);
      if(tmp!="")
	if(num<++mapp[tmp])
	  {
	    num=mapp[tmp];
	    ans=tmp;
	  }
    }
  cout<<ans;
  return 0;
}
