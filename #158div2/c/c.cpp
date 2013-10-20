#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
  freopen("in","r",stdin);
  int n,x;
  cin>>n>>x;
#define N (100011)
  ll num[N];
  for(int i=0;i<n;++i)
    cin>>num[i];
  --x;
  int pos=x;
  for(int i=0,j=x;i<n;++i,j=(j+n-1)%n)
    if(num[j]<num[pos])
      pos=j;
  ll k=0;
  if(pos!=x)
    for(int i=(pos+1)%n;;i=(i+1)%n)
      {
	--num[i],++k;
	if(i==x)
	  break;
      }
  ll o=(ll)n*num[pos]+k;
  for(int i=0;i<n;++i)
    if(i==pos)
      cout<<o<<' ';
    else cout<<(num[i]-num[pos])<<' ';
  return 0;
}
