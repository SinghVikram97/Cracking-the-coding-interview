https://leetcode.com/problems/contains-duplicate/

#include<bits/stdc++.h>
using namespace std;
// O(n^2) time O(1) space
bool isUnique1(string &s,int length){
  for(int i=0;i<length-1;i++){
    for(int j=i+1;j<length;j++){
      if(s[i]==s[j]){
        return false;
      }
    }
  }
  return true;
}
// O(n) time O(26)=>O(1) space
bool isUnique2(string &s,int length){
  unordered_set<char> mySet;
  for(int i=0;i<length;i++){
    // Element already exists in set then it is duplicate
    if(mySet.find(s[i])!=mySet.end()){
      return false;
    }
    // Insert new element
    else{
      mySet.insert(s[i]);
    }
  }
  return true;
}
// Without using any data structure
// O(nlogn) and O(1) space
bool isUnique3(string &s,int length){
  sort(s.begin(),s.end());
  for(int i=1;i<length;i++){
    if(s[i]==s[i-1]){
      return false;
    }
  }
  return true;
}

// A bitset is an array of bool but each Boolean value is not stored separately instead
// bitset optimizes the space such that each bool takes 1 bit space only,
// so space taken by bitset bs is less than that of bool bs[N] and vector bs(N).
// However, a limitation of bitset is, N must be known at compile time, i.e., a constant
// (this limitation is not there with vector and dynamic array)

bool isUnique4(string &s,int length){

  // Intialize all bits with 0
  // 256 possible characters
  bitset<256> bits(0);
	for(int i = 0; i < s.length(); i++) {
		int val = s[i];
		if(bits.test(val) > 0) {
			return false;
		}
		bits.set(val);
	}
	return true;
}

int main(){
  string s;
  cin>>s;
  if(isUnique4(s,s.length())){
    cout<<"No duplicates found";
  }
  else{
    cout<<"It contains duplicates";
  }
}
