// https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1
void StackQueue :: push(int x)
{
    s1.push(x);
}
/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
    // Already have items in reverse stack
    if(!s2.empty()){
        int data=s2.top();
        s2.pop();
        return data;
    }
    else{
        // Shift all elements to 2nd stack
        if(s1.empty()){
            return -1;
        }
        else{
            while(!s1.empty()){
                int top=s1.top();
                s2.push(top);
                s1.pop();
            }
            int topData=s2.top();
            s2.pop();
            return topData;
        }
    }
}
