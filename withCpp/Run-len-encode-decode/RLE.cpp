#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[100];
    cout<<"\n\tWrite a string ";
    gets(s);
    int len = strlen(s);
    int encodearr[len];
    int i,j,k=0,count,isCount;
    cout<<"\n\tencoded string ";

    for(i=0;s[i]!='\0';i++){
       count = 0;
       isCount = 0;
       if(i>0){
          for(j=i;j>=0;j--){
             if(s[j]==s[i] && j!=i){
                isCount = 1;
             }
          }
       }

       if(!isCount){
           for(j=0;s[j]!='\0';j++){
              if(s[j]==s[i]){
                 count++;
                 encodearr[k++] = s[j];
              }
           }
           printf("%d%c",count,s[i]);
        }
    }

    cout<<endl<<"\n\tDecoded string ";
    for(i=0; i<len; i++){
        printf("%c",encodearr[i]);
    }
    cout<<endl<<"\n\t";

    return 0;
}
