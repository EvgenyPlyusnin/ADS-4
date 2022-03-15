// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
    int result = 0;
    int start = -1;
    int end = size;
    while (start < end - 1) {
        int index = (end + start) / 2;
        if (arr[index] < value) {
            start = index;
        } else {
            end = index;
        }
    }
    int rightIndex = end;
    int leftIndex = end - 1;
    while (rightIndex < size && arr[rightIndex] == value) {
        rightIndex++;
        result++;
    }
    while (leftIndex > 0 && arr[leftIndex] == value) {
        leftIndex--;
        result++;
    }
    return result;
}

int countPairs1(int *arr, int len, int value) {
    int result = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                result++;
            }
        }
    }
    return result;
}

int countPairs2(int *arr, int len, int value) {
    int result = 0;
    int end = len;
    for (int i = len; i > 0; i--) {
        if (arr[i] > value) {
            end--;
        }
    }
    for (int i = 0; i < end; i++) {
        for (int j = end; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                result++;
            } else if (arr[i] + arr[j] < value) {
                break;
            }
        }
        if (arr[i] != arr[i+1]) {
            end--;
        }
    }
    return result;
}

int countPairs3(int *arr, int len, int value) {
    int result = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] >= value / 2) {
            int countCenter = cbinsearch(arr, len, value - arr[i]);
            int countCenter2 = cbinsearch(arr, len, arr[i]);
            for (int j = countCenter - 1; j > 0; j--) {
                if (value % 2 != 0) {
                    result += countCenter * countCenter2;
                    break;
                }
                result += j;
            }
            break;
        }
        int count = cbinsearch(arr, len, value - arr[i]);
        result += count;
    }
    return result;
}
