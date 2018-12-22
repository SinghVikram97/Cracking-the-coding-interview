/// https://leetcode.com/problems/rotate-image/submissions/
#include<bits/stdc++.h>
using namespace std;
void rotate1(vector<vector<int>>& matrix) {

   int m=matrix.size();
   if(m==0){
    return;
   }

   int n=matrix[0].size();

   vector<vector<int> > rotatedMatrix(m,vector<int> (n));

   for(int i=m-1;i>=0;i--){
     for(int j=0;j<n;j++){
        rotatedMatrix[j][(m-1)-i]=matrix[i][j];
     }
   }

   matrix=rotatedMatrix;

}
void rotate2(vector<vector<int> > &v){

  if(v.size()==0 || v.size()!=v[0].size()){
    return;
  }
  int n=v.size();
  /// No of layers=n/2
  for(int layer=0;layer<(n/2);layer++){

    int first=layer;
    int last=n-1-layer;

    // Do some work for every layer
    for(int i=first;i<last;i++){

      int offset=i-first;

      // Store top
      int top=v[first][i];

      // left->top
      v[first][i]=v[last-offset][first];

      // bottom -> left
      v[last-offset][first]=v[last][last-offset];

      // right -> bottom
      v[last][last-offset]=v[i][last];

      // top -> right 
      v[i][last]=top;
    }
  }
}
int main(){

  int m,n;
  cin>>m>>n;

  vector<vector<int> > v(m,vector<int>(n));

  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cin>>v[i][j];
     }
   }
   rotate2(v);

   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
   }
}

