#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int binary_search(int arr[],int len , int index){
    int left, right, mid;
    left = 0;
    right = len - 1;
    while (left <= right){
        mid = (left + right) / 2;
        if(arr[mid] == index)
            return mid;
        if(arr[mid] < index)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {

    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int index = binary_search(arr,len,0);
    cout << arr[index] << endl;

    return 0;
}