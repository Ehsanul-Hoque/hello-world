#include <stdio.h>

void sort(int arr[], int n, int startFrom);

int main() {
    int i, arr[6] = {5, 9, 3, 4, 8, 5};

    sort(arr, 6, 0);

    for (i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void sort(int arr[], int n, int startFrom)
{
    int i, min = arr[startFrom], t, minIndex = startFrom;

    for (i = (startFrom + 1); i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }

    if (startFrom != minIndex) {
        t = arr[startFrom];
        arr[startFrom] = arr[minIndex];
        arr[minIndex] = t;
    }

    if (++startFrom != (n - 1)) {
        sort(arr, n, startFrom);
    }
}
