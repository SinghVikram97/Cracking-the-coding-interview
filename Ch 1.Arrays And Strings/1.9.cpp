// https://leetcode.com/problems/rotate-string/
#include<bits/stdc++.h>
using namespace std;
bool isRotation(string A,string B){
  // If s2 is a rotation of s1, then s2 will be a substring of s1+s1
  // All rotations of s1 are contained in s1+s1
  return A.length()==B.length() && (B+B).find(A)!=string::npos;
}
int main(){
  string s1,s2;
  cin>>s1>>s2;
  if(isRotation(s1,s2)){
    cout<<s2<<" is a rotation of "<<s1<<endl;
  }
  else{
    cout<<s2<<" not a rotation of "<<s1<<endl;
  }
}