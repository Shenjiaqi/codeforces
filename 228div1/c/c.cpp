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
int main()
{
  int n;
  scanf("%d",&n);
  int ans[2]={0};
  vector<int> v;
  FOR(i,0,n)
    {
      int num;
      scanf("%d",&num);
      FOR(j,0,num)
	{
	  int val;
	  scanf("%d",&val);
	  if(j<num/2)
	    ans[0]+=val;
	  else if(j>=num/2 && !(num&1 &&j==num/2))
	    ans[1]+=val;
	  else v.push_back(val);
	}
    }
  sort(v.begin(),v.end(),greater<int>());
  for(int i=0;i<v.size();++i)
    ans[i&1]+=v[i];
  cout<<ans[0]<<' '<<ans[1]<<endl;
  return 0;
}
