int n;
cin >> n;
vector<int> starts(n), ends(n);
int maximum = 0, current_lowest = 0;
for (int i = 0; i < n; i++) cin >> starts[i] >> ends[i];
vector<tuple<int,int,int>> lectures;
for (int i = 0; i < n; i++) lectures.push_back({starts[i], ends[i], i});
sort(lectures.begin(), lectures.end());
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<int> assignment(n);
int count = 0;
for (auto &[start, end, index] : lectures){
    if (!pq.empty() && pq.top().first < start){
        int hall = pq.top().second;
        pq.pop();
        assignment[index] = hall;
        pq.push(make_pair(end, hall));
    } else {
        count++;
        assignment[index] = count;
        pq.push(make_pair(end, count));
    }
}
cout << count << "\n";
for (int i = 0; i < n; i++) cout << assignment[i] << " ";
