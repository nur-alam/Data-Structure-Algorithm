#include<bits/stdc++.h>

using namespace std;

// insertionSort
void insertionSort(int arr[],int arr_size)
{
    int i,value,hole;
    for(i=1;i<arr_size;i++){
        value = arr[i];
        hole = i;
        while(hole>0 && arr[hole-1]>value){
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = value;
    }
}

// for printing array

void printArray(int arr[],int arr_size){
    int i;
    for(i=0;i<arr_size;i++)
    {
        cout << "\t" << arr[i] << " ";
    }
}

int main(){
    int i;
    int arr[] = {7,2,1,4,5,3};
    int arr_size = sizeof(arr)/4;
    cout << "Before sorting the array look like \n"<<endl;
    printArray(arr,arr_size);

    insertionSort(arr,arr_size);
    cout << "\nAfter sorting the array look like \n"<<endl;
    printArray(arr,arr_size);

    cout << endl;

    return 0;

}
