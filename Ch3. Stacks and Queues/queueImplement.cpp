#include<bits/stdc++.h>
using namespace std; 
template<typename T>
class QueueNode{
  public:
    T data;
    QueueNode *next;
    QueueNode(T d){
      data=d;
      next=NULL;
    }
};
template<typename T>
class myQueue{
  QueueNode *first;
  QueueNode *last;
  public:

    myQueue(){
      first=NULL;
      last=NULL;
    }
    // Adds an item to end of the list
    void add(T item);
    // Remove first item from list
    T remove(); 
    // Remove top of the Queue
    T peek();
    // Returns true if Queue is empty
    bool isEmpty();
};
template<typename T>
// Adds an item to end of list
void myQueue<T>::add(T item){

  QueueNode<T> *newNode=new QueueNode(item);

  if(last==NULL){
    // 1st element to be inserted
    first=newNode;
    last=newNode;
  }
  else{
    // Insert at last
    last->next=newNode;
    last=newNode;
  }
}
// Removes an item from 1st position in the list
template<typename T>
T myQueue<T>::remove(){
   if(first==NULL){
     // No element in list
     cout<<"Error no items in the queue"<<endl;
   }
   else{
     int data=first->data;
     first=first->next;
     if(first==NULL){
       last=NULL;
     }
     return data;
   }
}
// Returns an item from top of the list
template<typename T>
T myQueue<T>::peek(){
  if(first==NULL){
    cout<<"Error no items in the queue"<<endl;
  }
  else{
    int data=first->data;
    return data;
  }
}
template<typename T>
bool myQueue<T>::isEmpty(){
  if(first==NULL){
    return true;
  }
  else{
    return false;
  }
}
int main(){
  myQueue<int> q;
  char ch;
  do{

    cout<<"1.Add data to end of list\n2.Remove first item in the list\n3.Return the top of the queue\n4.See if Queue empty"<<endl;
    int choice;
    cin>>choice;

    switch (choice)
      {
        case 1:
          cout<<"Enter data to be added to Queue"<<endl;
          int data;
          cin>>data;
          q.push(data);
          break;

        case 2:
          cout<<"Removing item from Queue"<<endl;
          cout<<"Popped item from Queue is "<<q.remove()<<endl;
          break;

        case 3:
          cout<<"Data at the top of Queue is"<<endl;
          cout<<q.peek()<<endl;
          break;

        case 4:
          if(q.isEmpty()){
            cout<<"Queue is empty"<<endl;
          }
          else{
            cout<<"Queue is not empty"<<endl;
          }

        default:
          cout<<"Wrong option selected"<<endl;
          break;
      }
      cout<<"Do you want to continue"<<endl;
      cin>>ch;
      cout<<ch<<endl;
    }while(ch=='Y' || ch=='y');
}