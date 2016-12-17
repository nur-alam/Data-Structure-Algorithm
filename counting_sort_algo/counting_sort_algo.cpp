#include<bits/stdc++.h>

using namespace std;

// for printing array
void printArray(int arr[],int arr_size);

void countingSort(int arr[] , int sorted_array[] , int arr_size , int range)
{
    int i,j,array_repeat_count[range];

    // initialize with 0
    for(i=0;i<range;i++)
        array_repeat_count[i] = 0;

    // repeat counter array
    for(j=0;j<arr_size;j++)
        array_repeat_count[arr[j]] = array_repeat_count[arr[j]] + 1;

    // repeat counter array value rearranging like a[index] = a[index]+a[index-1]
    for(i=1;i<range;i++)
        array_repeat_count[i] = array_repeat_count[i] + array_repeat_count[i-1];

    for(j=arr_size-1;j>=0;j--){
        sorted_array[array_repeat_count[arr[j]]-1] = arr[j];
        array_repeat_count[arr[j]] = array_repeat_count[arr[j]]-1;
    }
    printArray(sorted_array,arr_size);
}


int main(){
    int i;
    int arr[] = {5,9,4,5,3,6,8,5,4,8,7,4,6,9,7};
    int arr_size = sizeof(arr)/4;
    int range = 10;
    int sorted_array[arr_size];
    countingSort(arr,sorted_array,arr_size,range);
    return 0;

}


// for printing array
void printArray(int arr[],int arr_size){
    int i;
    for(i=0;i<arr_size;i++)
    {
        cout << "\t" << arr[i] << " ";
    }
}
