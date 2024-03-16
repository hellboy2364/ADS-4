// Copyright 2021 NNTU-CS
int bin_search(int*, int, int, int);
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[i] + arr[j] > value) {
                continue;
            }
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int x = bin_search(arr, i + 1, len - 1, value - arr[i]);
        int y = x;
        while (arr[y] == value - arr[i] && y > i) {
            count++;
            y--;
        }
        while (arr[x + 1] == value - arr[i]) {
            count++;
            x++;
        }
    }
    return count;
}
int bin_search(int *A, int left, int right, int x) {
    int mid = (left + right) / 2;
    if (left == mid)
        return A[left] == x ? left : A[right] == x ? right : -left;
    if (A[mid] < x)
        left = mid;
    else
        right = mid;
    return bin_search(A, left, right, x);
}
