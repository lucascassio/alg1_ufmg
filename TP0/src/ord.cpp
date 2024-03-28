#include "../include/ord.hpp"

using namespace std;

void Ord::insertionSort(vector<int>& arr, int low, int n) {
  for(int i=low+1;i<n+1;i++) {
    int val = arr[i] ;
    int j = i ;
      while (j>low && arr[j-1]>val) {
        arr[j]= arr[j-1];
        j-= 1;
      }
    arr[j]= val;
  } 
}

int Ord::partition(vector<int>& arr, int l, int h) { 
  int x = arr[h]; 
  int i = (l - 1); 
  
  for (int j = l; j <= h - 1; j++) { 
    if (arr[j] <= x) { 
      i++; 
      swap(arr[i],arr[j]); 
    } 
  } 
  swap(arr[i+1],arr[h]);
  return (i + 1); 
} 

void Ord::quickSort(vector<int>& arr,int l,int h) {
  if(l<h) {
    int pi=partition(arr,l,h);
    quickSort(arr,l,pi-1);
    quickSort(arr,pi+1,h);
  }
}

void Ord::quickSortItr(vector<int>& arr, int l, int h) { 
    int stack[h - l + 1]; 
    int top = -1; 
    stack[++top] = l; 
    stack[++top] = h; 
  
    while (top >= 0) { 

        h = stack[top--]; 
        l = stack[top--]; 

        int p = partition(arr, l, h); 
  
        if (p - 1 > l) { 
            stack[++top] = l; 
            stack[++top] = p - 1; 
        } 

        if (p + 1 < h) { 
            stack[++top] = p + 1; 
            stack[++top] = h; 
        } 
    } 
}

void Ord::quickSortIns(vector<int>& arr, int low, int high) {
  while (low < high)  {
    if (high-low + 1 <= 30) {
      insertionSort(arr, low, high);
      break;
    } else {
      int pivot = partition(arr, low, high);
      if (pivot-low<high-pivot) {
        quickSortIns(arr, low, pivot - 1); 
        low = pivot + 1;
      } else {
        quickSortIns(arr, pivot + 1, high);
        high = pivot-1;
      }
    }
  }
}

void Ord::quickSortInsItr(vector<int>& arr, int low, int high) {
  stack<pair<int, int> > stk;
  stk.push(make_pair(low, high));

  while (!stk.empty()) {
      low = stk.top().first;
      high = stk.top().second;
      stk.pop();

      if (high - low + 1 <= 30) {
          insertionSort(arr, low, high);
          continue;
      }

      int pivot = partition(arr, low, high);

      if (pivot - 1 > low)
          stk.push(make_pair(low, pivot - 1));

      if (pivot + 1 < high)
          stk.push(make_pair(pivot + 1, high));
  }
}