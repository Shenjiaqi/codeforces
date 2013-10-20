#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
using namespace std;
int main()
{
  freopen("in","r",stdin);
  int n,m;
  cin>>n>>m;
  cout<<(n+m-min(n,m)-1)<<' '<<min(n,m);
  return 0;
}
