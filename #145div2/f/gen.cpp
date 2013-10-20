#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N (200)
int main()
{
  freopen("input.txt","w",stdout);
  int n=N;
  printf("%d\n",n);
  printf("%d %d\n",min(rand()%10000,10000),min(10000,rand()%10000));
  for(int i=0;i<n;++i)
    printf("%d\n",rand()%200);
  return 0;
}
