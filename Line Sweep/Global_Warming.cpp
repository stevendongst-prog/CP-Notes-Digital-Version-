int n;
cin >> n;
vector<int> heights(n);
for (int i = 0; i < n; i++) cin >> heights[i];
vector<pair<int,int>> events;
events.push_back(make_pair(LLONG_MIN, 1));
events.push_back(make_pair(heights[0], -1));

for (int i = 1; i < n; i++){
    if (heights[i] > heights[i - 1]){
        int left = heights[i - 1];
        int right = heights[i] - 1;
        events.push_back(make_pair(left, 1));
        events.push_back(make_pair(right + 1, -1));
    }
}

sort(events.begin(), events.end());

int current = 0, maximum = 0;
for (int i = 0; i < events.size(); i++){
    current += events[i].second;
    maximum = max(maximum, current);
}

cout << maximum;
