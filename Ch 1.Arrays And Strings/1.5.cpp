#include<bits/stdc++.h>
using namespace std;
bool isOneEditAway1(string s1,string s2){

  unordered_map<char,int> freq;
  if(s1.length()<s2.length()){
    swap(s1,s2);
  }
  for(int i=0;i<s1.length();i++){
    freq[s1[i]]++;
  }
  for(int i=0;i<s2.length();i++){
    freq[s2[i]]--;
  }
  //for(auto it=freq.begin();it!=freq.end();it++){
  //  cout<<(it->first)<<" "<<(it->second)<<endl;
  // }

  int oneCount=0,zeroCount=0,negCount=0,totalCount=0;
  for(auto it=freq.begin();it!=freq.end();it++){
    if(it->second==-1){
        negCount++;
    }
    else if(it->second==0){
        zeroCount++;
    }
    else if(it->second==1){
        oneCount++;
    }
    totalCount++;
  }

    if(negCount+zeroCount+oneCount==totalCount){
        if(zeroCount==totalCount || (zeroCount==totalCount-1 && oneCount==1) || (zeroCount==totalCount-2 && oneCount==1 && negCount==1)){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }

}
bool isOneEditAway2(string &s1,string &s2){

  /// Make s1 as the longer string
  if(s1.length()<s2.length()){
    swap(s1,s2);
  }
  int n=s1.length();
  int m=s2.length();

  /// More than one diff in their length
  if(n-m>1){
    return false;
  }

  /// Traverse both simultaneosuly
  int i=0,j=0;
  int countDiff=0; /// Count the no of differences
  while(i<n && j<m){

    if(s1[i]==s2[j]){
      /// Match so move ahead
      i++;
      j++;
    }
    else{
      countDiff++;
      if(countDiff>1){
        return false;
      }
      /// Move longer string ahead by one
      if(n==m){
        i++;
        j++;
      }
      else{
        i++;
      }
    }
  }
  /// If extra character left in the end
  if(i<n || j<m){
    cout<<i<<" "<<m<<endl;
    countDiff++;
  }
  if(countDiff>1){
    return false;
  }
  else{
    return true;
  }
}
int main(){

    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        if(isOneEditAway2(s1,s2)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}
