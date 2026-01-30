stack<int> s;
stack<int> minimum;

void push(int X){
    s.push(X);
    if (minimum.empty() || X <= minimum.top()){
        minimum.push(X);
    } else {
        minimum.push(minimum.top());
    }
}

void pop(){
    s.pop();
    minimum.pop();
}

int top(){return s.top();}

int getMin(){return minimum.top();}
