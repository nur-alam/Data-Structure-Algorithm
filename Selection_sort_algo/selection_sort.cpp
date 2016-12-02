#include<bits/stdc++.h>

using namespace std;

// for printing array

void printArray(int arr[],int arr_size);

void selectionSort(int arr[],int arr_size)
{
    int i,temp;
    for(int i = 0;i<arr_size-1;i++)
    {
        int min,j;
        min = i;
        for(j=i+1;j<arr_size;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        //swap(arr[i],arr[min]);
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


int main(){
    int i;
    int arr[] = {2,7,4,2,5,3};
    int arr_size = sizeof(arr)/4;
    cout << "Before sorting the array look like \n"<<endl;
    printArray(arr,arr_size);

    selectionSort(arr,arr_size);
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
