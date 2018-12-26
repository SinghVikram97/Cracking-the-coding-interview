// https://practice.geeksforgeeks.org/problems/sort-a-stack/1
void SortedStack :: sort()
{
   if(s.empty()){
       return;
   }
   stack<int> temp;
   while(!s.empty()){
       int data=s.top();
       s.pop();
       while(!temp.empty() && temp.top()>data){
           s.push(temp.top());
           temp.pop();
       }
       temp.push(data);
   }
   s=temp;
}
