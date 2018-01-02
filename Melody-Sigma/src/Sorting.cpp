#include <iostream>
#include "Sorting.h"

using namespace std;

Sort::Sort(){

}

Sort::~Sort(){

}
void Sort::SelectionSort(int *a, int n){
    int temp, loc;
    for(int k=0; k<n-1; k++){
        min_(a, k, n, loc);
        //interchanging a[k] and a[loc]
        temp=a[k];
        a[k]=a[loc];
        a[loc]=temp;
    }
}
void Sort::InsertionSort(int *arr, int n){
        int k=1, temp, ptr;
        //arr[index]: Here index can be 0 as well, but in that case array must start from 1 to N. Depends upon the user input implementation.
        arr[-1]=-32767; //values within int range is supported
        while(k<n){
        temp=arr[k];
        ptr=k-1;
        while(temp<arr[ptr]){
            //shifting the elements of the sorted part
            arr[ptr+1]=arr[ptr];
            ptr=ptr-1;
        }
        //insertion of the element at proper place
        arr[ptr+1]=temp;
        k++;
    }
}
void Sort::min_(int *a, int k, int n, int &loc){
    int min_ele;
    min_ele=a[k];
    loc=k;
    for(int j=k+1; j<n; j++){
        if(min_ele>a[j]){
            min_ele=a[j];
            loc=j;
        }
    }

}
void Sort::print(int *arr, int n){
        for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
