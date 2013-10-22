#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#define N 100
int main()
{
  //freopen("in.txt","r",stdin);
  int a,b;
  cin>>a>>b;
  string s;
  cin>>s;
  int n=s.length();
  int p[N][2];
  if(a==0 && b==0)
    {
      cout<<"Yes";
      return 0;
    }
  for(int x=0,y=0,i=0;i<n;++i)
    {
      if(s[i]=='U')
	y+=1;
      else if(s[i]=='D')
	y-=1;
      else if(s[i]=='L')
	x-=1;
      else x+=1;
      p[i][0]=x,p[i][1]=y;
      if(x==a && y==b)
	{
	  cout<<"Yes";
	  return 0;
	}
    }
  int c=p[n-1][0],d=p[n-1][1];
  for(int i=0;i<n;++i)
    {
      int x=p[i][0],y=p[i][1];
      int e,f;
      if(c==0 && d==0)
	{
	  if(x==a && y==b)
	    {
	      cout<<"Yes";
	      return 0;
	    }
	}
      else if(c==0 && d)
	{
	  if(x==a && (b-y)%d==0 && (b-y)/d>=0)
	    {
	      cout<<"Yes";
	      return 0;
	    }
	}
      else if(c && d==0)
	{
	  if(y==b && (a-x)%c==0 && (a-x)/c>=0)
	    {
	      cout<<"Yes";
	      return 0;
	    }
	}
      else if((a-x)%c==0 && (b-y)%d==0 &&
	      (a-x)/c==(b-y)/d && (a-x)/c>=0)
	{
	  cout<<"Yes";
	  return 0;
	}
    }
  cout<<"No";
  return 0;
}
