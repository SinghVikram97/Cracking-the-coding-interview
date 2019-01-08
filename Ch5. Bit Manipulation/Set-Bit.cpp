#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// Set kth bit
int setBit(ll n, ll k)
{
  ll mask = (1 << k);
  ll result = (n | mask);
  return result
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll n, k;
    cin >> n >> k;
    cout << setBit(n, k) << endl;
  }
}