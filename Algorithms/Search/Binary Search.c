#include <stdio.h>

int binarySearch(int arr[], int searchFor, int startFrom, int endTo);

int main() {
    int nums[10] = {1, 5, 9, 12, 13, 25, 75, 100, 154, 210}, searchFor = 75, index;

    index = binarySearch(nums, searchFor, 0, 9);

    printf((index != -1) ? "%d is at %dth index." : "%d could not be found.", searchFor, index);

    return 0;
}

int binarySearch(int arr[], int searchFor, int startFrom, int endTo) {
    int start = startFrom, end = endTo, mid = (start + end) / 2;

    if (start > end) {
        return -1;
    }

    if (arr[mid] == searchFor) {
        return mid;
    } else if (arr[mid] > searchFor) {
        return binarySearch(arr, searchFor, startFrom, mid - 1);
    } else {
        return binarySearch(arr, searchFor, mid + 1, endTo);
    }
}
