// https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not/0
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool getBit(ll n, ll k)
{
  ll mask = (1 << k);
  ll result = (n & mask);
  if (result != 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll n, k;
    cin >> n >> k;
    if (getBit(n, k))
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
}