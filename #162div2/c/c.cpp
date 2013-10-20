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
  string stone;
  cin>>stone;
  vector<int> l,r;
  for(int i=0;i<stone.length();++i)
    if(stone[i]=='l')
      l.push_back(i);
    else if(stone[i]=='r')
      r.push_back(i);
    else break;
  for(int i=0;i<r.size();++i)
    cout<<(r[i]+1)<<endl;
  for(int i=l.size()-1;i>=0;--i)
    cout<<(l[i]+1)<<endl;
  return 0;
}
