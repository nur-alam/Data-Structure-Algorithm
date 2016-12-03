#include<bits/stdc++.h>

using namespace std;

// for printing array

void printArray(int arr[],int arr_size);


int partition(int arr[],int startIndex,int endIndex){
    int i,j,pivot;
    pivot = arr[endIndex];
    i = startIndex - 1;
    for(j=startIndex;j<endIndex;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[endIndex]);
    return i+1;
}


void quickSort(int arr[],int startIndex,int endIndex){
    if(startIndex<endIndex){
        int partitionIndex = partition(arr,startIndex,endIndex);
        printf("%d",partitionIndex);
        quickSort(arr,startIndex,partitionIndex-1);
        quickSort(arr,partitionIndex+1,endIndex);
    }
}


int main(){
    int i;
    int arr[] = {5,7,6,1,3,2,4};
    int arr_size = sizeof(arr)/4;
    cout << "Before sorting the array look like \n"<<endl;
    printArray(arr,arr_size);

    quickSort(arr,0,arr_size-1);

    cout << "\nAfter sorting the array look like \n"<<endl;
    printArray(arr,arr_size);

    cout << endl;

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
