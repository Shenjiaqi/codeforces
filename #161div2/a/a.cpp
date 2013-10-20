#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <string>
using namespace std;
int main()
{
  freopen("in","r",stdin);
  int matrix[5][5];
  for(int i=0;i<5;++i)
    for(int j=0;j<5;++j)
      cin>>matrix[i][j];
  for(int i=0;i<5;++i)
    for(int j=0;j<5;++j)
      {
	if(matrix[i][j]==1)
	  {
	    cout<<(abs(i-2)+abs(j-2));
	    return 0;
	  }
      }
  return 0;
}
