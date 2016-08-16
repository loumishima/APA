#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int encontraPivo(vector<int>, int, int);
int binarySearch(vector<int>, int, int, int);

int pBinarySearch(vector<int> arr, int n, int key)
{
   int pivot = encontraPivo(arr, 0, n-1);

   if (pivot == -1)
       return binarySearch(arr, 0, n-1, key);

   if (arr[pivot] == key)
       return pivot;
   if (arr[0] <= key)
       return binarySearch(arr, 0, pivot-1, key);
   return binarySearch(arr, pivot+1, n-1, key);
}
int encontraPivo(vector<int> arr, int low, int high)
{
   if (high < low)  return -1;
   if (high == low) return low;

   int mid = (low + high)/2;
   if (mid < high && arr[mid] > arr[mid + 1])
       return mid;
   if (mid > low && arr[mid] < arr[mid - 1])
       return (mid-1);
   if (arr[low] >= arr[mid])
       return encontraPivo(arr, low, mid-1);
   return encontraPivo(arr, mid + 1, high);
}

int binarySearch(vector<int>arr, int low, int high, int key)
{
   if (high < low)
       return -1;
   int mid = (low + high)/2;
   if (key == arr[mid])
       return mid;
   if (key > arr[mid])
       return binarySearch(arr, (mid + 1), high, key);
   return binarySearch(arr, low, (mid -1), key);
}
int main()
{
    vector<int> v;
    int var;
    while(true){
        cin >> var;
        if(cin.eof()) break;
        v.push_back(var);
    }
   int key = 3; // Valor que quero encontrar!
   printf("Posicao: %d\n", pBinarySearch(v, v.size(), key));
   return 0;
}
