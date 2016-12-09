#include<bits/stdc++.h>

using namespace std;
int *arr;
int arr_size;
int top = -1;

int push(int value){
    if(top<arr_size-1){
        top++;
        arr[top] = value;
    }else{
        cout<<"stack is full"<<endl;
        return 0;
    }

}

int pop(){
    if(top>=0){
        top--;
    }else{
        cout<<"stack is emply"<<endl;
        return 0;
    }
}

void print(){
    cout<<"current stack"<<" ";
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cout << "Enter array size " << " ";
    cin>>arr_size;
    arr = new int[arr_size];
    push(7);
    push(6);
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    print();
    pop();
    print();

    return 0;

}
