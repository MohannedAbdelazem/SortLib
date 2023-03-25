#include <bits/stdc++.h>
using namespace std;

//Swap function
// I made it so that I won't keep on repeating code
// Also I know that there's a swap function that already exists
template <typename T>
void Swap(T &element1, T &element2){
    T tmp = element1;
    element1 = element2;
    element2 = tmp;
}

//Insertion Sort
/*
*   Basic info:
*       Best case: O(n)
*       Average case: O(n^2)
*       Worst case: O(n^2)
*       Space complexity: O(1)
*/
/*
*  Description:
*    what happens in the algorithm is that it is mainly composed of two arrays 
*    one that is sorted and another that is none, in the function we made the unsorted
*    array is all elements in the array except for the first element which will be in the sorted part
*    the unsorted first element will be compared with the elements in the sorted array and they will replace it's
*    initial position until it finds it's suited optimal position and get placed in it by the command "arr[j+1 ] = key"
*/
template <typename T> 
void insertionSort(T *arr, int size){
    for(int i = 1;i<size;i++){
        T key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        
    }
}

//Selection Sort
/*
*   Basic info:
*       Best case: O(n^2)
*       Average case: O(n^2)
*       Worst case: O(n^2)
*       Space complexity: O(1)
*/
/*
*   Description:
*       This sorting array idea is built on the idea of getting the miniumum/maximum item and put it in it's suitable
*       position, for example if we have an array {33, 12, 11, 6, 0} to sort it the following steps will happen:
*       1- you have to get the minimum item from index 0 which will be 0
*       2- after getting the minimum item swap it with index 0 element so it will be {0, 12, 11, 6, 33}
*       3- index will move up to 1
*       4- you have to get the minimum item from index 1 which will be 6
*       5- after getting the minimum item swap it with index 1 element so it will be {0, 6, 11, 12, 33}
*       6- repeat the steps until eventually you get {0, 6, 11, 12, 33}
*/
template <typename T>
void selectionSort(T *arr, int size){
    for(int i = 0;i<size;i++){
        T min_index = i;
        for(int j = i+1;j<size;j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        Swap(arr[i], arr[min_index]);
    }
}


// Bubble Sort
/*
*   Basic info:
*       Best case: O(n)
*       Average case: O(n^2)
*       Worst case: O(n^2)
*       Space complexity: O(1)
*/
/*
*   Description:
*       It's one of the most basic sorting algorithms (and similar to selection sort) where in it you have two options
*       the first option which is to sort the array by sending the biggest elements in the end of the array
*       Or the second option where you sort the array by sending the smallest elements to the beginning of the array
*       In here I did the first option where at each iteration the biggest element will be at the end of the array
*       And this is by comparing each two items in the array for example this is what's going to happen to this array:
*       {33, 12, 11, 6, 0} -> {12, 33, 11, 6, 0} -> {12, 11, 33, 6, 0}
*       -> {12, 11, 6, 33, 0} -> {12, 11, 6, 0, 33} -> {11, 12, 6, 0, 33}
*       -> {11, 6, 12, 0, 33} -> {11, 6, 0, 12, 33} -> {6, 11, 0, 12, 33}
*       -> {6, 0, 11, 12, 33} -> {0, 6, 11, 12, 33}
*/
template <typename T>
void bubbleSort(T *arr, int size){
    bool flag = true;
    for(int i = 0;i< size;i++){
        for(int j = 0;j<size-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = false;
            }
        }
        if(flag){
            break;
        }
    }    
}

//Merge Sort
/*   Basic info:
*       Best case: O(nlogn)
*       Average case: O(nlogn)
*       Worst case: O(nlogn)
*       Space complexity: O(n)
*       (As for the merge function complexity is O(n))
*/
/*
*   Description:
*       This sorting algorithm works by divide and conquer concept,
*       To understand the idea behind this algorithm if you're an arabian you'd better watch this to get an idea
*       video: https://www.youtube.com/watch?v=-YKZBg5LiFQ
*       moving on, so the basic idea about this algorithm is that if you have an array of four elements for example
*       you will divide it into two arrays then those two arrays each will be divided into two sub arrays,
*       where the size of each array containing only one element, then the first subarray of the first half,
*       will be sorted the same thing goes for the other sub arrays then the first and the second subarrays
*       of the first have will merge together in a way that both will be sorted, then the same thing will happen
*       to the second part of the second half of the array, at last since both halves of the array are sorted
*       you can now merge them together using merge function again and now the array is sorted
*/
template<typename T>
void Merge(T *arr, int l, int m, int r){
    int i, j, k;
    const int n1 = m-l+1;
    const int n2 = r-m;
    T *L = new T[n1], *R = new T[n2];
    for(i = 0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(j = 0;j<n2;j++){
        R[j] = arr[m+j+1];
    }
    i = j = 0;
    k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = arr[j];
        j++;
        k++;
    }
}
template <typename T>
void mergeSort(T arr[], int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        
        Merge(arr, l, m, r);
    }
}

//Quick Sort
/*   Basic info:
*       Best case: O(nlogn)
*       Average case: O(nlogn)
*       Worst case: O(nlogn)
*       Space complexity: O(1)
*       (As for the merge function complexity is O(n))
*/
/*
*   Description:
*       Like the merge sort, it works by the concept of divide and conquer, this algorithms' idea is that it places
*       elements in its' suitable position. Since I didn't sleep at all I might leave the description at that but I'd
*       reccomend you watch youtube for it.
*/
template <typename T>
int partition(T arr[], int l, int h)
{
	T p = arr[l];
	int i = l;
	int j = h;
	while (i < j)
	{
		do
		{
			i++;
		} while (arr[i] <= p);
		do
		{
			j--;
		} while (arr[j] > p);

		if (i < j)
		    Swap(arr[i], arr[j]);
	}
	Swap(arr[l], arr[j]);
	return j;
}
template <typename T>
void quickSort(T arr[], int l, int h)
{

	if (l < h) {
		int piv = partition(arr, l, h);
		quickSort(arr, l, piv);
		quickSort(arr, piv + 1, h);
	}

}


int main(){

    int arr[] = {33, 12, 11, 6, 0};
    quickSort(arr, 0, 5);
    for(int i = 0;i< 5; i++){
        cout << arr[i] << endl;
    }
    return 0;
}
