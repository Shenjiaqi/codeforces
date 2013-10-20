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
  vector<int> tree;
  cin>>n;
  tree.resize(n);
  for(int i=0;i<n;++i)
    cin>>tree[i];
  int time=n-1;
  for(int i=0,h=0;i<n;++i)
    {
      time+=(abs(tree[i]-h)+1);
      h=tree[i];
    }
  cout<<time;
  return 0;
}
