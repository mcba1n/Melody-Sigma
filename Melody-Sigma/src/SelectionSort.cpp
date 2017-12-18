#include <iostream>
#include "SelectionSort.h"
using namespace std;

SelectionSort::SelectionSort(){

}
SelectionSort::~SelectionSort(){

}
void SelectionSort::sel_sort(int *a, int n){
    int temp, loc;
    for(int k=0; k<n-1; k++){
        min_(a, k, n, loc);
        //interchanging a[k] and a[loc]
        temp=a[k];
        a[k]=a[loc];
        a[loc]=temp;
    }
}
void SelectionSort::min_(int *a, int k, int n, int &loc){
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
