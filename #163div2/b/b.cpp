#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
using namespace std;
int main()
{
  freopen("in","r",stdin);
  int n,t;
  string s;
  cin>>n>>t>>s;
  for(int i=0;i<t;++i)
    for(int j=1;j<n;++j)
      if(s[j]=='G' && s[j-1]!='G')
	s[j]='B',s[j-1]='G',++j;
  cout<<s;
  return 0;
}
