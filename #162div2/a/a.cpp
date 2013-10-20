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
  string s,t;
  cin>>s>>t;
  int pos=0;
  for(int i=0;i<t.length();++i)
    if(t[i]==s[pos])
      ++pos;
  cout<<(1+pos);
  return 0;
}
