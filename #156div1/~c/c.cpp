#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
map<int,int> mapp;
int cal()
{
  int c=0;
  for(mapp<int,int>::iterator i;i!=mapp.end();++i)
    if(i->second>0)
      {
	if(c!=i->first)
	  break;
	++c;
      }
  return c;
}
int main()
{
  freopen("in","r",stdin);
  const ll N=881917;
  vector <ll> idx;
  vector <int> sp;
  idx.push_back(0);
  sp.push_back(0);
  vector <int> f(10,0);
  f[0]=1;
  for(int i=2;i<=N;++i)
    {
      int tmp=ceil(sqrt(i));
      for(;tmp<=i;++tmp)
	f[sp[tmp]]=1;
      for(int j=0;j<10;++j)
    }
  return 0;
}
