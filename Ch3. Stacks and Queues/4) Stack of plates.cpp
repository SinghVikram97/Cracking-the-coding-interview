#include<bits/stdc++.h>
using namespace std;
class SetOfStacks{
  vector<stack<int> > stacks;
  public:
    void push(int x);
    void pop();
    void print();
    stack<int> getLastStack();
}
void SetOfStacks::push(int x){
  stack<int> last=getLastStack();
  if(last!=NULL && !last.isFull()){
    last.push(x);
  }
  else{
    stack<int> newStack;
    newStack.push(x);
    stacks.push_back(newStack);
  }
}
int SetOfStacks::pop(){
  stack<int> last=getLastStack();
  if(last==NULL){
    cout<<"No stack exists"<<endl;
    return -1;
  }
  else{
    int v=last.pop();
    if(last.size()==0){
      auto it=stacks.end()-1;
      stacks.erase(it);
    }
    return v;
  }
}
stack<int> SetOfStacks::getLastStack(){
  if(stacks.size()==0){
    return NULL;
  }
  else{
    return stacks.back();
  }
};
int main(){
    SetOfStacks s;
    char ch;
    do{
      cout<<"1. Push to stack"<<" "<<"2. Pop from stack"<<endl;
      int choice;
      cin>>choice;
      
      switch (choice)
      {
        case 1:
          cout<<"Enter data to push to stack"<<endl;
          int data;
          cin>>data;
          s.push(data);
          break;
        
        case 2:
          cout<<"Popping from stack"<<endl;
          cout<<"Element popped from stack"<<s.pop()<<endl;
          break;

        case 3:
          cout<<"Stacks are"<<endl;
          s.print();
          break;
      
        default:
          cout<<"Wrong option entered";
          break;
      }
      cout<<"Do you want to continue"<<endl;
      cin>>ch;
    }while(ch=='Y' || ch=='y')
}