#include<bits/stdc++.h>

using namespace std;

void bubleSort(int arr[],int arr_size)
{
    int i, j, temp;
    for(i=0;i<arr_size;i++)
    {
        bool flag = false;

        for(j=0;j<arr_size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true;
            }
        }
        if(!flag)
        {
            break;
        }

    }
}

int main(){

    int i;
    int arr[] = {2,7,4,2,5,3};//{1,2,3,4,6,5};
    int arr_size = sizeof(arr)/4;
    cout << "Before sorting the array look like \n"<<endl;
    for(i=0;i<arr_size;i++)
    {
        cout << "\t" << arr[i] << " ";
    }
    cout<<endl;
    bubleSort(arr,arr_size);

    cout << "\nAfter sorting the array look like \n"<<endl;
    for(i=0;i<arr_size;i++)
    {
        cout << "\t" << arr[i] << " ";
    }

    cout << endl;

    return 0;

}
