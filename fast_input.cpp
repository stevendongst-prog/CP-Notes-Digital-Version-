inline long long input(){
    int8_t sign = 1;
    long long number = 0;
    char c = getchar_unlocked();

    while (c < '0' || c > '9'){
        if (c == '-') sign = -1;
        c = getchar_unlocked();
    }

    while (c >= '0' && c <= '9'){
        number = number * 10 + (c - '0');
        c = getchar_unlocked();
    }

    return number * sign;
}
