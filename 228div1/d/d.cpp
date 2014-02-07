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
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const ll mod=1e7;
ll cnt[40];
int getl(int v)
{
  int cnt=0;
  for(;v>1;v>>=1,++cnt)
    ;
  return 1<<cnt;
}
int cal(int left,int right)
{
  ll tmp=left^right;
  if(tmp==(tmp&(-tmp)))
    {
      tmp=__builtin_ctz(tmp);
      int r=cnt[tmp];
      if(right^tmp)
	r=(cnt[tmp+1]-r+mod)%mod;
      return r;
    }
  tmp=getl(tmp);
  return (cal(left,tmp|left)+cal(tmp|left,right))%mod;
}
int main()
{
  cnt[0]=1;
  for(int i=1;i<40;++i)
    cnt[i]=(cnt[i-1]+)%mod;
  int k;
  cin>>k;
  if(k)
    cout<<cal(0,k+1)<<endl;
  else cout<<1<<endl;
  int cnt=0;
  for(int i=0;i<(1<<3);++i)
    {
      vector<int> a;
      for(int j=0;(1<<j)<=i;++j)
	if((1<<j)&i)
	  a.push_back(j+1);
      int c=true;
      for(int j=0;c && j<a.size();++j)
	for(int k=j+1;c && k<a.size();++k)
	  if(((1<<((a[j]^a[k])-1))&i)==0)
	    c=false;
      if(c)
	{
	  for(auto num : a)
	    cout<<num<<'!';cout<<' '<<cnt<<endl;
	  ++cnt;
	}
    }
  cout<<cnt<<endl;
  return 0;
}
