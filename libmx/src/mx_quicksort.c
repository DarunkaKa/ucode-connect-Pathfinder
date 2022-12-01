#include "../inc/libmx.h"

int mx_quicksort(char** arr, int left, int right) {
    if (arr == NULL) {
        return -1;
    }
    if (right < left) {
        return 0;
    }
    int midd = (right + left) / 2;
    int left1;
    int right1;
    int count = 0;    
    for (left1 = left, right1 = right;  left1 < right1; left1++, right1--) {
        while (mx_strlen(arr[left1]) < mx_strlen(arr[midd])) {
            left1++;
        }
        while (mx_strlen(arr[right1]) > mx_strlen(arr[midd])) {
            right1--;
        }
        if (left1 < right1) {
            if (mx_strlen(arr[left1]) != mx_strlen(arr[right1])) {
                mx_swap(&arr[left1], &arr[right1]);
                count++;
            }
        }
    }
    if (left < right1) {
        count += mx_quicksort(arr, left, right1);
    }
    if (left1 < right) {
        count += mx_quicksort(arr, left1, right);
    }
    return count;
}

