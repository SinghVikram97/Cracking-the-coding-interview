#include <bits/stdc++.h>
using namespace std;
// Clear all bits starting from left(MSB) to kth position
void clearBit3(int &n, int &k)
{
  int mask = (-1 << (k + 1)); //Sequence of 1's followed by k zeroes
  int result = (n & mask);    // Clears all set bits from kth position to LSB (0th index)
  n = result;
}
int main()
{
  int n, k;
  cout << "Enter the number" << endl;
  cin >> n;
  cout << "Enter position of bit to clear(0 index)" << endl;
  cin >> k;
  clearBit3(n, k);
  cout << "New Number is " << n;
}