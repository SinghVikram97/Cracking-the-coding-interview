#include<bits/stdc++.h>
using namespace std;
void setBit(int &n,int &k){
  int mask=(1<<k); /// All zero except 1 at kth position
  int result=(n|mask);
  n=result;
}
int main(){
  int n,k;
  cout<<"Enter the number"<<endl;
  cin>>n;
  cout<<"Enter position of bit to set"<<endl;
  cin>>k;
  setBit(n,k);
  cout<<"New Number is "<<n<<endl;
}
