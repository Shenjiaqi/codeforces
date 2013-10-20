#include <cstdio>
#include <algorithm>
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
  cin>>n;
  vector<int> array;
  array.resize(n);
  for(int i=0;i<n;++i)
    cin>>array[i];
  vector<int> ans;
  ans.resize(n);
  for(int i=n-1,j=0;i>=0;--i)
    {
      if(array[i]>j)
	ans[i]=1;
      j=abs(array[i]-j);
    }
  for(int i=0,k=0;i<n;++i)
    {
      cout<<(ans[i]^k?'+':'-');
      k^=ans[i];
    }
  return 0;
}
