#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[100];
    cout<<"\n\tWrite a string ";
    gets(s);
    int len = strlen(s);
    int decodeArr[len];
    int i,j,k=0,count,isCount;
    cout<<"\n\tencoded string ";

    for(i=0;s[i]!='\0';i++){
        count = 0;
        isCount = 0;
        if(i>0){
            if(s[i]==s[i-1]){
                isCount = 1;
            }
        }
        if(!isCount){
            for(j=i;s[i]==s[j];j++){
                if(s[i]==s[j]){
                    count++;
                    decodeArr[k++]=s[i];
                }
            }
            cout<<count<<s[i]<<" ";
        }
    }

    cout<<endl<<"\n\tDecoded string ";
    for(i=0; i<len; i++){
        printf("%c",decodeArr[i]);
    }
    cout<<endl<<"\n\t";

    return 0;
}
