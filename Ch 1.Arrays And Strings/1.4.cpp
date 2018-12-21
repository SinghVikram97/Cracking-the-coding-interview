https://www.hackerearth.com/problem/algorithm/palindrome-check-2-1/
#include<bits/stdc++.h>
using namespace std;
bool isPalindromePermutation1(string &s){

  unordered_map<char,int> freq;
  for(int i=0;i<s.length();i++){
    freq[s[i]]++;
  }

  int evenCount=0,oddCount=0;
  int totalCount=0;
  for(auto it=freq.begin();it!=freq.end();it++){
    if(it->second%2==0){
        evenCount++;
    }
    else{
        oddCount++;
    }
    totalCount++;
  }

  if(evenCount==totalCount){
    return true;
  }
  else if(evenCount==totalCount-1 && oddCount==1){
    return true;
  }
  else{
    return false;
  }
}
bool isPalindromePermutation2(string &s){

  bitset<256> bit(0); /// Initially all bits off
  for(int i=0;i<s.length();i++){
    int val=s[i];
    bit.flip(val); /// Toggle the bit
  }
  /// Atmost one set bit in the number (because if even occurences bit will be off)
  if(bit.count()==0 || bit.count()==1){
    return true;
  }
  else{
    return false;
  }
}
int main(){
  string s;
  cin>>s;
  if(isPalindromePermutation2(s)){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
