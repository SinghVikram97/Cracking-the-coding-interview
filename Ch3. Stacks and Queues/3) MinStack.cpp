// https://www.interviewbit.com/problems/min-stack/
vector<long long int> minimum;
stack<long long int> s;
MinStack::MinStack() {
    minimum.clear();
    while(!s.empty()){
        s.pop();
    }
}

void MinStack::push(int x) {
    s.push(x);
    if(minimum.size()!=0 && x<minimum.back()){
        minimum.push_back(x);
    }
    else if(minimum.size()==0){
        minimum.push_back(x);
    }
    else{
        // Do nothing
        // Return
    }
}

void MinStack::pop() {
    if(s.empty() || minimum.size()==0){
        return;
    }
    if(minimum.back()==s.top()){
        minimum.pop_back();
    }
    s.pop();
}

int MinStack::top() {
    if(!s.empty()){
        return s.top();
    }
    else{
        return -1;
    }
}

int MinStack::getMin() {
    if(minimum.size()!=0){
        return minimum.back();
    }
    else{
        return -1;
    }
}
