#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end){
  if (start == end) //specific to early cases where there are two numbers sorted
		return;
  if(mid > end) //exit option 1
	 return;
  if(mid == end){ //exit option 2
  	if(arr[start] <= arr[mid]){
  	  return;
  	}
  }
  if((start + 1) == mid){
  	if(arr[start] > arr[mid]){
  	  int tmp = arr[start];
  	  arr[start] = arr[mid];
  	  arr[mid] = tmp;
  	  return merge(arr,start+1, mid+1, end);
  	}
  }
  if(arr[start] > arr[mid+1]){
  	int tmp = arr[mid+1];
  	copy(arr+start, arr+mid+1, arr+start+1); //shifting values
  	arr[start] = tmp;
  	return merge(arr,start+1, mid+1, end);
  }

  if(mid-start == 1){
  	return merge(arr,start+1, mid+1, end);
  }
  else{
	   return merge(arr,start+1, mid, end);
  }
}

void mergesort(int arr[], int start, int end) {
	if (start < end) {
		int mid = start + (end - start) / 2;
		mergesort(arr, start, mid);
		mergesort(arr, (mid + 1), end);
		merge(arr, start, mid, end);
	}
}

int main() {
	//int arr[]= {3,9,12, 88,2,10,17,51};
	int arr[]= {3,9,12,15,10,17,51};

	cout << "Before: ";
	for(int i = 0; i < sizeof(arr)/sizeof(int); i ++)
	  cout << arr[i] << ", ";
	cout << endl;

	//merge(arr, 0, 3, 7); //88
	merge(arr,0,3, 6); // no 88

	cout << "After: ";
	for(int i = 0; i < sizeof(arr)/sizeof(int); i ++)
	  cout << arr[i] << ", ";
	cout << endl;

	int arr2[] = { 5000,12, 99, 77,159,1, 8, 51, 13, 5,3, 9, 7, 3, 0, 21, 54, 4 };
	int arr_size = sizeof(arr2) / sizeof(arr2[0]);

	cout << "Before: ";
	for (int i = 0; i < arr_size; i++)
		cout << arr2[i] << " ";
	cout << endl;

	mergesort(arr2, 0, arr_size - 1);

	cout << "After: ";
	for (int i = 0; i < sizeof(arr2) / sizeof(int); i++)
		cout << arr2[i] << " ";
	cout << endl;

	return 0;
}
