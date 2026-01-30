int findMin(int N, int A[]){
    int minimum = A[0];
    for (int i = 1; i < N; i++){
        minimum = min(minimum, A[i]);
    }
    return minimum;
}
