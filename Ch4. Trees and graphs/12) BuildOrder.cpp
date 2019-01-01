// https://drive.google.com/file/d/1flcmfwHebp7zD0PF-A77PthY715pYNDx/view
#include<bits/stdc++.h>
using namespace std;
class Graph{
  int num_of_vertices;
  map<int,list<int> > adjList;
  public:
    Graph(int noOfVertices);
    void addEdge(int v1,int v2); // Directed graph
    void printAdjList();
    void topologicalSort();
};
Graph::Graph(int noOfVertices){
  num_of_vertices=noOfVertices;
}
void Graph::addEdge(int v1,int v2){
  adjList[v1].push_back(v2);
}
void Graph::printAdjList(){
  for(auto it=adjList.begin();it!=adjList.end();it++){
    cout<<(it->first)<<"-->";
    for(auto it1=adjList[it->first].begin();it1!=adjList[it->first].end();it1++){
      cout<<(*it1)<<" ";
    }
    cout<<endl;
  }
}
void Graph::topologicalSort(){

  map<int,int> inDegree;
  for(auto it=adjList.begin();it!=adjList.end();it++){
    inDegree[(it->first)]=0;
  }
  for(auto it=adjList.begin();it!=adjList.end();it++){
    for(auto it1=adjList[it->first].begin();it1!=adjList[it->first].end();it1++){
      inDegree[(*it1)]++;
    }
  }
  for(auto it=inDegree.begin();it!=inDegree.end();it++){
    cout<<(it->first)<<" "<<(it->second)<<endl;
  }
  queue<int> myQueue;

  // Push all vertices with indegree 0 into queue
  for(auto it=inDegree.begin();it!=inDegree.end();it++){
    if(inDegree[it->first]==0){
      myQueue.push(it->first);
    }
  }

  // While queue not empty perform action
  while(!myQueue.empty()){

    int frontVertex=myQueue.front();
    cout<<frontVertex<<" ";
    myQueue.pop();

    // Reduce indegree of it's neighbours by one
    for(auto it=adjList[frontVertex].begin();it!=adjList[frontVertex].end();it++){
      inDegree[(*it)]--;
      if(inDegree[(*it)]==0){
          myQueue.push((*it));
      }
    }
  }
  cout<<endl;
}
int main(){

  cout<<"Enter number of projects"<<endl;
  int num_of_vertices;
  cin>>num_of_vertices;
  Graph g(num_of_vertices);

  cout<<"Enter number of dependencies"<<endl;
  int dependencies;
  cin>>dependencies;

  for(int i=0;i<dependencies;i++){
    cout<<"Enter the pair "<<(i+1)<<endl;
    int p1,p2;
    cin>>p1>>p2;
    g.addEdge(p1,p2);
  }
  g.topologicalSort();
}
