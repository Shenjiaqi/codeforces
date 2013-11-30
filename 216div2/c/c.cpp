#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 100007
vector<ppi> p[N];
int n;
vector<int> ans;
void add(int f,int t,int v)
{
  p[f].push_back(ppi(t,v));
}
bool dfs(int v,bool b,int frm)
{
  bool s=false;
  FR(i,p[v])
    if(i->first!=frm && dfs(i->first,i->second==2,v))
      s=true;
  if(s)
    return true;
  if(b)
    {
      ans.push_back(v);
      return true;
    }
  return false;
}
int main()
{
  scanf("%d",&n);
  FOR(i,1,n)
    {
      int x,y,t;
      scanf("%d%d%d",&x,&y,&t);
      add(x,y,t);
      add(y,x,t);
    }
  dfs(1,false,0);
  printf("%d\n",(int)ans.size());
  FOR(i,0,ans.size())
    printf("%d ",ans[i]);
  return 0;
}