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
    bool isPath(T v1,T v2);
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
bool Graph<T>::isPath(T v1,T v2){
  if(v1==v2){
    return true;
  }
  map<T,bool> visited;
  // Run bfs starting from v1 and see if we can visit v2
  queue<T> myQueue;
  myQueue.push(v1);
  visited[v1]=true;
  while(!myQueue.empty()){
    T frontElement=myQueue.front();
    myQueue.pop();
    if(frontElement==v2){
      return true;
    }
    for(auto it=adjList[frontElement].begin();it!=adjList[frontElement].end();it++){
      if(!visited[*it]){
        myQueue.push((*it));
        visited[(*it)]=true;
      }
    }
  }
  return visited[v2];
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
  g.printAdjList();
  cout<<"\n Enter 2 vertices to find whether path between them"<<endl;
  int v1,v2;
  cin>>v1>>v2;
  if(g.isPath(v1,v2)){
    cout<<"There is path between "<<v1<<" "<<v2<<endl;
  }
  else{
    cout<<"There is no path between "<<v1<<" "<<v2<<endl;
  }
}
