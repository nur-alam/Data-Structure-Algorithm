#include<bits/stdc++.h>

using namespace std;


// for printing array
void printArray(int arr[],int arr_size);

void merging(int arr[],int startIndex,int mid,int lastIndex){
    int tempArr[100];
    int i,j,k;
    k = 0, i = startIndex, j = mid + 1;
    while(i<=mid && j<=lastIndex){
        if(arr[i]<arr[j]){
            tempArr[k++] = arr[i++]; //same as b[k] = a[i];k++;i++;
        }else{
            tempArr[k++] = arr[j++];
        }
    }
    while(i<=mid){
        tempArr[k++] = arr[i++];
    }
    while(j<=lastIndex){
        tempArr[k++] = arr[j++];
    }
    // copying temparray to original array
    for(i=lastIndex;i>=startIndex;i--){
        arr[i] = tempArr[--k];
    }
    //printArray(arr,6);
}

void mergeSort(int arr[],int startIndex,int lastIndex){
    int mid;
    if(startIndex<lastIndex){
        mid = floor( (startIndex+lastIndex) / 2 );
        mergeSort(arr,startIndex,mid);
        mergeSort(arr,mid+1,lastIndex);
        merging(arr,startIndex,mid,lastIndex);
    }
}


int main(){
    int i;
    int arr[] = {2,7,4,2,5,3};
    int arr_size = sizeof(arr)/4;
    cout << "Before sorting the array look like \n"<<endl;
    printArray(arr,arr_size);

    mergeSort(arr,0,arr_size-1);

    cout << "\nAfter sorting the array look like \n"<<endl;
    printArray(arr,arr_size);

    cout << endl;

    return 0;

}

// for printing array

void printArray(int arr[],int arr_size){
    int i;
    cout << endl;
    for(i=0;i<arr_size;i++)
    {
        cout << "\t" << arr[i] << " ";
    }
    cout << endl;
}
