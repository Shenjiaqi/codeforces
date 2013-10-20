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
  vector<int> pri;
  bool ispri[1001]={0};
  for(int i=2;i<=1000;++i)
    if(!ispri[i])
      {
	pri.push_back(i);
	for(int j=i*i;j<1001;j+=i)
	  ispri[j]=1;
      }
  int ans[100001]={0};
  int n;
  cin>>n;
  vector<int> val;
  val.resize(n);
  for(int i=0;i<n;++i)
    cin>>val[i];
  int tmp[30];
  for(int i=0;i<n;++i)
    {
      int num=0,mm=0;
      for(int j=0,k=sqrt(val[i])+1;j<pri.size() && pri[j]<=k;++j)
	{
	  if((val[i]%pri[j])==0)
	    {
	      mm=max(mm,ans[pri[j]]);
	      for(;0==(val[i]%pri[j]);)
		val[i]/=pri[j];
	      tmp[num++]=pri[j];
	      if(pri[j]>val[i])
		break;
	    }
	}
       if(val[i]>1)
	{
	  mm=max(mm,ans[val[i]]);
	  tmp[num++]=val[i];
	}
      ++mm;
      for(int j=0;j<num;++j)
	ans[tmp[j]]=mm;
      //cout<<mm<<endl;
    }
  int res=1;
  for(int i=0;i<=100000;++i)
    res=max(res,ans[i]);
  cout<<res;
  return 0;
}
