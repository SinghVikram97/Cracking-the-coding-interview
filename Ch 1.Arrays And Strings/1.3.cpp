// Urlify string
// Replace space by %20
#include<bits/stdc++.h>
using namespace std;

// Using temporary string
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

// Assuming string has additional space at end
void URLify2(string &s){
  
}
int main(){
  cout<<"Enter a string"<<endl;
  string s;
  getline(cin,s);
  URLify(s);
  cout<<"String after URLification is "<<s<<endl;
}
