// https://leetcode.com/problems/set-matrix-zeroes/submissions/
// First find position of all zeroes and store them
// Because on finding a zero it will generate more zeroes for which we don't need to do anything
#include<bits/stdc++.h>
using namespace std;
void findPosZeroes(vector<vector<int> > &matrix,vector<pair<int,int> > &v){
        int m=matrix.size();
        if(m==0){
            return;
        }
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    v.push_back(make_pair(i,j));
                }
            }
        }
}
    void setRowCol(vector<vector<int> > &matrix,int a,int b,int m,int n){
        // Set bth column to zero
        for(int i=0;i<m;i++){
            matrix[i][b]=0;
        }
        // Set ath row to zero
        for(int j=0;j<n;j++){
            matrix[a][j]=0;
        }
    }
    void setZeroes(vector<vector<int>> &matrix) {

        int m=matrix.size();
        if(m==0){
            return;
        }
        int n=matrix[0].size();
        vector<pair<int,int> > v;
        findPosZeroes(matrix,v);
        for(int i=0;i<v.size();i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
            setRowCol(matrix,v[i].first,v[i].second,m,n);
        }
    }
    void nullnifyRow(vector<vector<int> > &matrix,int rowNum,int m,int n){
      for(int j=0;j<n;j++){
        matrix[rowNum][j]=0;
      }
    }
    void nullnifyCol(vector<vector<int> > &matrix,int colNum,int m,int n){
      for(int i=0;i<m;i++){
        matrix[i][colNum]=0;
      }
    }
    void setZeroes1(vector<vector<int> > &matrix){

      int m=matrix.size();
      if(m==0){
        return;
      }
      int n=matrix[0].size();
      bool rowHasZero=false;
      bool colHasZero=false;
      for(int i=0;i<m;i++){
        if(matrix[i][0]==0){
          colHasZero=true;
          break;
        }
      }
      for(int j=0;j<n;j++){
        if(matrix[0][j]==0){
          rowHasZero=true;
          break;
        }
      }
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          // If zero at [i,j] set matrix[i][0]=0 and matrix[0][j]=0
          if(matrix[i][j]==0){
            matrix[i][0]=0;
            matrix[0][j]=0;
          }
        }
      }
      // matrix[i][0]=0 then there is a zero in ith row
      // matrix[0][j]=0 then there is a zero in jth col
      for(int i=1;i<m;i++){
        if(matrix[i][0]==0){
          nullnifyRow(matrix,i,m,n);
        }
      }
      for(int j=1;j<n;j++){
        if(matrix[0][j]==0){
          nullnifyCol(matrix,j,m,n);
        }
      }

      if(rowHasZero){
        nullnifyRow(matrix,0,m,n);
      }

      if(colHasZero){
        nullnifyCol(matrix,0,m,n);
      }
    }
  int main(){
  int m,n;
  cin>>m>>n;
  vector<vector<int> > matrix(m,vector<int>(n));
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cin>>matrix[i][j];
    }
  }
  //setZeroes(matrix);
  setZeroes1(matrix);
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}
