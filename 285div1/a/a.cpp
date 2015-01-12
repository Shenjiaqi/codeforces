#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

const int N = (1 << 17);

int degree[N];
int xorSum[N];

int main()
{
  int n;
  scanf("%d", &n);

  queue<int> que;
  for (int i(0); i < n; ++i)
    {
      scanf("%d%d", degree + i, xorSum + i);

      if (degree[i] == 1)
        {
          que.push(i);
        }
    }

  vector<pair<int,int> > edge;
  for (; !que.empty(); que.pop())
    {
      int v(que.front());

      if (degree[v] != 1)
        {
          continue;
        }

      int leftV(xorSum[v]);
      edge.push_back(make_pair(v, leftV));

      xorSum[leftV] ^= v;
      --degree[leftV];
      if (1 == degree[leftV])
        {
          que.push(leftV);
        }
    }

  printf("%d\n", (int)edge.size());
  for (auto i: edge)
    {
      printf("%d %d\n", i.first, i.second);
    }
  
  return 0;
}
