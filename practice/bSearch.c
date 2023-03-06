#include <stdio.h>

int BSearch(int arr[], int left, int right, int target);

int BSearch(int arr[], int left, int right, int target) {

    int middle = left + ((right - left) / 2);
    
    if (target == arr[middle]) {
        return middle;
    } else if (right == left) {
        return -1;
    } else if (target > arr[middle]) {
        BSearch(arr, middle + 1, right, target);
    } else {
        BSearch(arr, left, middle, target);
    }
}


int main() {

    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    
    int length = sizeof(arr) / sizeof(arr[0]);
    
    
    
    int result = BSearch(arr, 0, length - 1, 72);
    
    printf("The target is at index: Exp: 5, Result: %d\n", result);
    
    return 0;
}
