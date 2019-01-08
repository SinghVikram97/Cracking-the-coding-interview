#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// Set kth bit
int clearKthBit(ll n, ll k)
{
  ll mask = ~(1 << k); // all 1 except a 0 at kth position
  ll result = (n & mask);
  return result;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll n, k;
    cin >> n >> k;
    cout << clearKthBit(n, k) << endl;
  }
}