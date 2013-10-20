#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int,int> pp;
int main()
{
  freopen("in","r",stdin);
  int n;
  cin>>n;
  vector<pp>poi[2]; 
  for(int i=0,c,s;i<n;++i)
    {
      cin>>c>>s;
      poi[c].push_back(pp(s,1+i));
    }
  sort(poi[0].begin(),poi[0].end(),greater<pp>());
  sort(poi[1].begin(),poi[1].end(),greater<pp>());
  for(int i=1,j=0,k=0;i<n;++i)
    {
      int v=min(poi[0][j].first,poi[1][k].first);
      poi[0][j].first-=v;
      poi[1][k].first-=v;
      cout<<poi[0][j].second<<' '<<poi[1][k].second<<' '<<v<<endl;
      if(poi[0][j].first==0 && poi[1][k].first==0)
	{
	  if(k+1<poi[1].size())
	    ++k;
	  else ++j;
	}
      else if(poi[0][j].first==0)
	++j;
      else ++k;
    }
  return 0;
}
