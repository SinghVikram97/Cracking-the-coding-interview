#include<bits/stdc++.h>
using namespace std;
bool arePermutations(string a,string b){
  vector<int> freq(26); // Assuming only 26 characters are possible
  for(int i=0;i<a.length();i++){
    freq[a[i]-'a']++; // 65 is ASCII value of 'a'
  }
  for(int i=0;i<b.length();i++){
    freq[b[i]-'a']--;
  }
  // If they are permutations then freq array will only have zeroes
  for(int i=0;i<26;i++){
    if(freq[i]!=0){
      return false;
    }
  }
  return true;
}
int main(){
  cout<<"Enter string 1"<<endl;
  string a;
  cin>>a;
  cout<<"Enter string 2"<<endl;
  string b;
  cin>>b;
  if(arePermutations(a,b)){
    cout<<"Strings are permutation of each other"<<endl;
  }
  else{
    cout<<"They are not permutations"<<endl;
  }
}
