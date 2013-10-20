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
  int n,k;
  cin>>n>>k;
  vector<int> square;
  square.resize(n);
  for(int i=0;i<n;++i)
    cin>>square[i];
  sort(square.begin(),square.end());
  if(n>=k)
    cout<<square[n-k]<<' '<<square[n-k];
  else cout<<-1;
  return 0;
}
