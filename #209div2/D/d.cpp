#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 300001
int p[N];
int di[N][20];
//int mi[N][20];
int gcd(int a,int b)
{
  return (a%b==0)?b:gcd(b,a%b);
}
int gdi(int f,int t)
{
  int r=p[f];
  int len=t-f+1;
  for(int i=1,ii=0;i<=len;i<<=1,++ii)
    if(i&len)
      r=gcd(r,di[f][ii]),f+=i;
  return r;
}
int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    scanf("%d",p+i);
  for(int i=0;i<n;++i)
    di[i][0]=p[i];
  for(int i=2,j=1;i<=n;i<<=1,++j)
    for(int k=0;k+i<=n;++k)
      di[k][j]=gcd(di[k][j-1],di[k+(i>>1)][j-1]);
  int ansl=-1;
  vector<int> ansi;
  for(int i=0;i<n;++i)
    {
      int j=i;
      for(int f=i,t=n-1;f<=t;)
	{
	  int m=(f+t)>>1;
	  if((gdi(i,m)%p[i])==0)
	    j=m,f=m+1;
	  else t=m-1;
	}
      int k=i;
      for(int f=0,t=i;f<=t;)
	{
	  int m=(f+t)>>1;
	  if((gdi(m,i)%p[i])==0)
	    k=m,t=m-1;
	  else f=m+1;
	}
      int len=j-k;
      if(len>ansl)
	{
	  ansl=len;
	  ansi.resize(0);
	  ansi.push_back(k);
	}
      else if(len==ansl)
	ansi.push_back(k);
    }
  ansi.resize(unique(ansi.begin(),ansi.end())-ansi.begin());
  printf("%d %d\n",(int)ansi.size(),ansl);
  for(int i=0;i<ansi.size();++i)
    printf("%d ",ansi[i]+1);
  return 0;
}
