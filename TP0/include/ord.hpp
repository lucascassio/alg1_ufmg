#ifndef ORD_HPP
#define ORD_HPP

#include "bits/stdc++.h"

using namespace std;


class Ord {
  public:
  void insertionSort(vector<int>& v, int l, int n);
  void quickSort(vector<int>& v, int l, int h);
  void quickSortItr(vector<int>& v, int l, int h);
  void quickSortIns(vector<int>& v, int l, int h);
  void quickSortInsItr(vector<int>& v, int l, int h);
  private:
  int partition(vector<int>& v, int l, int h); 
};

#endif