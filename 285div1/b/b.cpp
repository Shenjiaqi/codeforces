#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <cassert>
#include <string.h>

using namespace std;

const int N = 200007;

int p[N], q[N];
int sum[N];
int a[N], b[N];

int count(const int array[], int idx)
{
  int r(0);
  for (++idx; idx;)
    {
      r += array[idx];

      int lsb(idx & (-idx));

      idx ^= lsb;
    }

  return r;
}

void add(int array[], int idx, int n, int num)
{
  for (++idx, ++n; idx <= n;)
    {
      array[idx] += num;

      int lsb(idx & (-idx));
      idx += lsb;
    }
}

void getSum(const int array[], int n)
{
  memset(a, 0, sizeof(a));
  for (int i(0); i < n; ++i)
    {
      add(a, i, n, 1);
    }
  
  for (int i(0); i < n; ++i)
    {
      add(a, array[i], n, -1);
      
      int cnt(count(a, array[i]));

      sum[i] += cnt;
    }
}

int getTh(int idx, int n)
{
  int ans(0);
  for (int i(0), j(n - 1); i <= j;)
    {
      int m((i + j) / 2);

      int cnt(count(a, m));

      if (cnt >= idx)
        {
          j = m - 1;
          if (cnt == idx)
            {
              ans = m;
            }
        }
      else
        {
          i = m + 1;
        }
    }

  return ans;
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i(0); i < n; ++i)
    {
      scanf("%d", p + i);
    }
  for (int i(0); i < n; ++i)
    {
      scanf("%d", q + i);
    }

  getSum(p, n);
  
  getSum(q, n);

  for (int i(n - 1); i >= 0; --i)
    {
      int lim(n - 1 - i + 1);
      if (sum[i] >= lim)
        {
          if (i - 1 >= 0)
            {
              sum[i - 1] += sum[i] / lim;
            }
          sum[i] %= lim;
        }
    }

  memset(a, 0, sizeof(a));
  for (int i(0); i < n; ++i)
    {
      add(a, i, n, 1);
    }

  for (int i(0); i < n; ++i)
    {
      int val(getTh(1 + sum[i], n));

      printf("%d ", val);

      add(a, val, n, -1);
    }
  
  return 0;
}
