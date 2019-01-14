// https://www.wikihow.com/Subtract-Binary-Numbers
// https://drive.google.com/open?id=1QQiQtZdoth7nPfLmds_hdvO7SKbKjDts
#include <bits/stdc++.h>
using namespace std;
// Clear all bits starting from left(MSB) to kth position
void clearBit2(int &n, int &k)
{
  int mask = (1 << k); // All 0 except 1 at kth position
  mask = mask - 1;     // Sequence of 0's from MSB to kth position followed by k ones
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
  clearBit2(n, k);
  cout << "New Number is " << n;
}