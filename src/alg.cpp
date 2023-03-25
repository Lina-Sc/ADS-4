// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int a = 0;
  for (int n = 0; n < len - 1; n++) {
    for (int m = n + 1; m < len; m++) {
      if (arr[n] + arr[m] == value)
        a += 1;
    }
  }
  if (a > 0)
    return a;
  else
    return 0;
}
int countPairs2(int *arr, int len, int value) {
  int a = 0;
  for (int n = 0; n < len - 1; n++) {
    for (int m = len - 1; m > n; m--) {
      if (arr[n] + arr[m] == value)
        a += 1;
    }
  }
  if (a > 0)
    return a;
  else
    return 0;
}
int countPairs3(int *arr, int len, int value) {
  int a = 0;
  for (int n = 0; n < len - 1; n++) {
    int left = n, right = len;
    while (left < right-1) {
      int mid = (left + right) / 2;
      if (arr[n] + arr[mid] == value) {
        a += 1;
        int m = mid + 1;
        while (arr[n] + arr[m] == value && m < right) {
          a += 1;
          m += 1;
        }
        m = mid - 1;
        while (arr[n] + arr[m] == value && m > left) {
          a += 1;
          m -= 1;
        }
        break;
      }
      if (arr[n] + arr[mid] > value)
        right = mid;
      else
        left = mid;
    }
  }
  if (a > 0)
    return a;
  else
    return 0;
}
