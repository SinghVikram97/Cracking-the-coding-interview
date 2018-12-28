#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
  int no_of_vertices;
  unordered_map<T,list<T> > adjList;
  public:
    Graph(int numOfVertices);
    void addEdge(T v1,T v2,bool bidirectional=false);
    void printAdjList();
    void dfs();
    void dfs_helper(T start,map<T,bool> &isVisited);
};
template<typename T>
Graph<T>::Graph(int numOfVertices){
  no_of_vertices=numOfVertices;
}
template<typename T>
void Graph<T>::addEdge(T v1,T v2,bool bidirectional){
  adjList[v1].push_back(v2);
  if(bidirectional){
    adjList[v2].push_back(v1);
  }
}
template<typename T>
void Graph<T>::printAdjList(){
  for(auto it=adjList.begin();it!=adjList.end();it++){
    cout<<(it->first)<<"-->";
    for(auto it1=adjList[it->first].begin();it1!=adjList[it->first].end();it1++){
      cout<<(*(it1))<<" ";
    }
    cout<<endl;
  }
}
template<typename T>
void Graph<T>::dfs_helper(T start,map<T,bool> &isVisited){
  isVisited[start]=true;
  cout<<start<<" ";
  for(auto it=adjList[start].begin();it!=adjList[start].end();it++){
    if(!isVisited[(*it)]){
      dfs_helper((*it),isVisited);
    }
  }
}
template<typename T>
void Graph<T>::dfs(){
  map<T,bool> isVisited;
  for(auto it=adjList.begin();it!=adjList.end();it++){
    if(!isVisited[(it->first)]){
      dfs_helper(it->first,isVisited);
    }
  }
}
int main(){
  cout<<"Enter the number of vertices"<<endl;
  int numOfVertices;
  cin>>numOfVertices;
  Graph<int> g(numOfVertices);
  cout<<"Enter number of edges"<<endl;
  int numOfEdges;
  cin>>numOfEdges;
  for(int i=0;i<numOfEdges;i++){
    int v1,v2;
    cout<<"Enter vertex v1 and v2"<<endl;
    cin>>v1>>v2;
    g.addEdge(v1,v2);
  }
  g.dfs();
}