#include<bits/stdc++.h>

using namespace std;

void insertionSort(int arr[] , int n)
{
    for(int i=1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {5,4,3,2,1};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,arrSize);
    for(int i=0; i<arrSize; i++)
        cout << arr[i] << " ";
    return 0;
}
