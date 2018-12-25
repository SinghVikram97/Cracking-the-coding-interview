#include<bits/stdc++.h>
using namespace std;
template<typename T>
class StackNode{
    public:
        T data;
        StackNode *next;
        StackNode(T d){
            data=d;
            next=NULL;
        }
};
template<typename T>
class myStack{

    StackNode<T> *top;

    public:
        myStack(){
            top=NULL;
        }
        void push(T data);
        T pop();
        T peek();
        bool isEmpty();

};
template<typename T>
void myStack<T>::push(T data){
    StackNode<T> *newNode=new StackNode<T>(data);
    if(top==NULL){
        top=newNode;
    }
    else{
        newNode->next=top;
        top=newNode;
    }
}
template<typename T>
T myStack<T>::pop(){
    if(top==NULL){
      cout<<"Error!! The Stack is empty"<<endl;
    }
    else{
      int data=top->data;
      top=top->next;
      return data;
    }
}
template<typename T>
T myStack<T>::peek(){
   if(top==NULL){
     cout<<"Error!! The Stack is empty"<<endl;
   }
   else{
     int data=top->data;
     return data;
   }
}
template<typename T>
bool myStack<T>::isEmpty(){
  if(top==NULL){
    return true;
  }
  else{
    return false;
  }
}
int main(){

  myStack<int> s;
  char ch;
  do{

    cout<<"1.Add data\n2.Remove data\n3.See top data\n4.See if stack empty"<<endl;
    int choice;
    cin>>choice;

    switch (choice)
      {
        case 1:
          cout<<"Enter data to be added to Stack"<<endl;
          int data;
          cin>>data;
          s.push(data);
          break;

        case 2:
          cout<<"Popping item from Stack"<<endl;
          cout<<"Popped item from Stack is "<<s.pop()<<endl;
          break;

        case 3:
          cout<<"Data at the top of stack is"<<endl;
          cout<<s.peek()<<endl;
          break;

        case 4:
          if(s.isEmpty()){
            cout<<"Stack is empty"<<endl;
          }
          else{
            cout<<"Stack is not empty"<<endl;
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
