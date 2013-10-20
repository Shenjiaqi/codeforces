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
  int n,m,k;
  cin>>n>>m>>k;
  vector<int> a;
  a.resize(n);
  for(int i=0;i<n;++i)
    cin>>a[i];
  sort(a.begin(),a.end(),greater<int>());
  //for(int i=0;i<n;++i)
  //cout<<a[i]<<endl;
  int ans=0;
  if(m>k)
    for(ans=1;ans<=n && m>k+a[ans-1]-1;++ans)
      k+=a[ans-1]-1;
  cout<<((ans<=n)?ans:-1);
  return 0;
}
