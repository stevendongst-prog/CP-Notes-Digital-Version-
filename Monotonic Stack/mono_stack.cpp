int n;
cin >> n;
vector<int> array(n);
for (int i = 0; i < n; i++) cin >> array[i];
vector<int> result(n, -1);  // Store the nearest greater to the left.
stack<int> s1;  // Stack to keep indices of candidates.

// Find nearest greater element on the left.
for (int i = 0; i < n; i++){
    while (!s1.empty() && array[s1.top()] <= array[i]) s1.pop();
    if (!s1.empty()) result[i] = array[s1.top()];
    s1.push(i);  // Push current index onto the stack.
}

vector<int> result(n, -1);
stack<int> s2;

// Find nearest greater element on the right.
for (int i = n - 1; i >= 0; i--){
    while (!s2.empty() && array[s2.top()] <= array[i]) s2.pop();
    if (!s2.empty()) result[i] = array[s2.top()];
    s2.push(i);
}
