#include <iostream>
#include "Algorithm/InsertionSort.h"
using namespace std;

InsertionSort::InsertionSort(){
    k=1;
}
InsertionSort::~InsertionSort(){

}
void InsertionSort::ins_sort(int *arr, int n){
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
void InsertionSort::print(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
