#include<bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin>>n;
    int arr[n-1];

    for (int i=0; i<n-1; i++){
        arr[i]=0;
    }

    int in_arr[n-1];
    for (int j=0; j<n-1;j++){
        cin>>in_arr[j];
        int ind = in_arr[j]-1;
        arr[ind]++; 
    }
    int out;
    for(int itr=0; arr[itr]==1; itr++){
        cout<<"here";
        out=itr+1;
    }
    int output = out +1;
    cout<<"algo1"<<output<<endl;
    for(int itr=0; itr<n-1; itr++){
        if (arr[itr]==0){
            cout<<"algo2"<<itr+1<<endl;
            break;
        }
    }
    
    



}
    

