#include<bits/stdc++.h>

using namespace std;

int main(){

    int arr[] = {2,3,4,5,6,7,8,10};
    int i , startPoint, endPoint, midPoint, location;
    int item ; //the value we want search from array
    int arr_size = sizeof(arr)/4;
    // array value printing
    cout<<"Array value"<<"\t";
    for(i=0;i<arr_size;i++)
        cout<<arr[i]<<" ";

    // start binary search
    startPoint = 0; //first index of the array
    endPoint = (arr_size-1); //last index of the array
    location = -1; // just initialize a location

    cout<<endl<< "Enter a number to search ";
    cin>>item;

    while(startPoint <= endPoint)
    {
        midPoint = (startPoint+endPoint)/2;
        if(arr[midPoint]==item)
            {
               location = midPoint;
               break;
            }
        else if(arr[midPoint]<item)
            {
                startPoint = midPoint + 1;
            }
        else
            {
                endPoint = midPoint - 1;
            }
    }

    if(location==-1)
    {
        cout<<item<<" not found in the array."<<endl;
    }else
    {
        cout<<item<<" found in the array location : "<<midPoint<<endl;
    }

    return 0;

}
