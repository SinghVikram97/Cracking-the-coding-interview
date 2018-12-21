#include<bits/stdc++.h>
using namespace std;
// O(N) space and time
string compress1(string &s){
  string result;
  int count=1;
  int n=s.length();
  for(int i=0;i<n;i++){
    if(i<n-1 && s[i]==s[i+1]){
      count++;
    }
    else{
      result.push_back(s[i]);
      /// If count is 12 then it will be an array
      string a=to_string(count);
      /// cout<<a<<endl;
      result+=a;
      count=1;
    }
  }
  return result;
}
/// O(1) space O(N) time
void compress2(string &s){
  int index=0;
  int n=s.length();
  if(n==0){
    return;
  }
  int i=0;
  while(i<n){
    char ch=s[i];
    int j=i;
    while(j<n && s[j]==s[i]){
      j++;
    }
    int count=j-i;
    if(count==1){
        s[index]=s[i];
        index++;
        i++;
        j++;
    }
    else{
      s[index]=ch;
      index++;
      string a=to_string(count);
      for(int k=0;k<a.length();k++){
        s[index]=a[k];
        index++;
       }
        i=j; /// Set it to first unmatching character
    }
  }
  for(int i=0;i<index;i++){
    cout<<s[i];
  }
}
int main(){
  string s;
  cin>>s;
  /// aabbbbbbbbbbb
  compress2(s);
}
