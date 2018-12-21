/// Urlify string
/// Replace space by %20
#include<bits/stdc++.h>
using namespace std;

/// Using temporary string
string URLify1(string &s){
  int length=s.length();
  string result;
  for(int i=0;i<length;i++){
    if(s[i]!=' '){
      result.push_back(s[i]);
    }
    else{
      result+="%20";
    }
  }
  return result;
}

/// Assuming string has additional space at end
/// O(n^2)
/// Start from last
void URLify2(string &s){
  int n=s.length();
  for(int i=n-1;i>=0;i--){
    if(s[i]==' '){
        /// Shift each character by 2 starting from last
        /// Resize string by increasing length by 2
        s.resize(n+2);
        for(int j=n-1;j>i;j--){
          s[j+2]=s[j];
        }
        s[i]='%';
        s[i+1]='2';
        s[i+2]='0';
        n=n+2;
    }
  }
}

/// O(n) approach best approach
/// 1. Calculate no of spaces
void Urlify3(string &s){

  // Count no of spaces
  int spaceCount=0;
  int n=s.length();
  for(int i=0;i<n;i++){
    if(s[i]==' '){
      spaceCount++;
    }
  }
  // cout<<spaceCount<<endl;
  s.resize(n+(spaceCount*2));
  int index=n+(spaceCount*2); /// Total count of numbers after replacing with '%20'

  for(int i=n-1;i>=0;i--){
    if(s[i]==' '){
      s[index-1]='0';
      s[index-2]='2';
      s[index-3]='%';
      index=index-3;
    }
    // If not a space just shift it by one
    else{
      s[index-1]=s[i];
      index--;
    }
  }
}
int main(){
  cout<<"Enter a string"<<endl;
  string s;
  getline(cin,s);
  Urlify3(s);
  cout<<"String after URLification is "<<s<<endl;
}
