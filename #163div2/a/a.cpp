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
  int n;
  string stone;
  cin>>n>>stone;
  int ans(0);
  for(int i=0,j=0;i<n;++i)
    if(j==stone[i])
      ++ans;
    else
      j=(int)stone[i];
  cout<<ans;
  return 0;
}
