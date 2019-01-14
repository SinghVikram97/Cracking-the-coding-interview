#include <bits/stdc++.h>
using namespace std;
void clearBit(int &n, int &k)
{
  int mask = (1 << k); /// All 0 except 1 at kth bit
  mask = ~(mask);      /// All 1 except 0 at kth bit
  int result = (n & mask);
  n = result;
}
int main()
{
  int n, k;
  cout << "Enter the number" << endl;
  cin >> n;
  cout << "Enter position of bit to clear(0 index)" << endl;
  cin >> k;
  clearBit(n, k);
  cout << "New Number is " << n;
}