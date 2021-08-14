#include<bits/stdc++.h>

using namespace std;

int main(){

    int arr[] = {2,3,4,5,6,7,8,9,10};
    int i, item;
    int arr_size = sizeof(arr)/4;

    // array value printing
    cout<<"Array value"<<"\t";
    for(i=0;i<arr_size;i++)
        cout<<arr[i]<<" ";

    cout<<endl<<"Enter a number to search ";
    cin>>item;
    bool isFound = false;

    //searching array value
    for(i=0;i<arr_size;i++){
        if(arr[i]==item){
            cout<<"Item found in index " << i << " & value is = " << arr[i] <<endl;
            isFound = true;
            break;
        }
    }

    // if not found item in the array
    if(!isFound)
        cout<<"Value not found"<<endl;

    return 0;
}
