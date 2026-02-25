int maximum_deliciousness(vector<int> rabbits){
    int n = rabbits.size();
    if (n == 0) return 0;
    if (n == 1) return max(0LL, rabbits[0]);

    vector<int> answers(n, 0);
    answers[0] = max(0LL, rabbits[0]);
    answers[1] = max(answers[0], rabbits[1]);

    for (int i = 2; i < n; i++){
        answers[i] = max(answers[i - 1], rabbits[i] + answers[i - 2]);
    }

    return answers[n - 1];
}
