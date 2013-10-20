#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
  freopen("in","r",stdin);
  int a,b,n;
  cin>>a>>b>>n;
#define N (100001)
  char out[N];
  int t=(b-(a*10)%b)%b;
  if(t<10)
    {
      cout<<a<<t;
      for(int i=1;i<n;++i)
	cout<<0;
    }
  else cout<<-1;
  return 0;
}
