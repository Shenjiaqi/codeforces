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
char s[N];
int cnt[N][3],rx,ry,rz;
int main()
{
  int m;
  scanf("%s%d",s,&m);
  int l=strlen(s);
  FOR(i,0,l)
    {
      if(s[i]=='x')
	++rx;
      else if(s[i]=='y')
	++ry;
      else ++rz;
      cnt[i][0]=rx,cnt[i][1]=ry,cnt[i][2]=rz;
    }
  FOR(i,0,m)
    {
      int l,r;
      scanf("%d%d",&l,&r);
      if(r-l+1<3)
	printf("YES\n");
      else
	{
	  --l,--r;
	  int num[3];
	  FOR(j,0,3)
	    num[j]=cnt[r][j]-(l>0?cnt[l-1][j]:0);
	  bool f=true;
	  FOR(j,0,3)
	    {
	      int a=j,b=j+1,c=j+2;
	      b%=3,c%=3;
	      if(num[b]==num[c])
		{
		  if(abs(num[a]-num[b])<=1)
		    {
		      f=false;
		      break;
		    }
		}
	    }
	  if(f)
	    printf("NO\n");
	  else printf("YES\n");
	}
    }
  return 0;
}
