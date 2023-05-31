//#include "iostream"
//using namespace std;
//
//int linearSearch(int arr[], int size, int target) // O(n)
//{
//	for (int i = 0; i < size; i++) {
//		if (arr[i] == target) return i;
//	}
//	return -1;
//}
//
//int linearSRecursion(int arr[], int size, int target) {
//	if (size == 0) return -1;
//	else if (arr[size - 1] == target) return size - 1;
//	else {
//		return linearSRecursion(arr, size - 1, target);
//	}
//}
//
//int binarySearchUtil(int arr[], int low, int high, int target) {
//	if (low >= high) return -1;
//	int middle = (low + high) / 2;
//	if (arr[middle] == target) return middle;
//	else if (arr[middle] >= target) {
//		return binarySearchUtil(arr, low, middle - 1, target);
//	}
//	else {
//		return binarySearchUtil(arr, middle + 1, high, target);
//	}
//}
//
//int binarySearch(int arr[], int size, int target) {
//	int low = 0;
//	int high = size - 1;
//	return binarySearchUtil(arr, low, high, target);
//}
//
//
//int main() {
//	int arr[] = { 2,4,6,8,10 };
//	cout << linearSearch(arr, 5, 8) << endl;
//	cout << linearSRecursion(arr, 5, 8) << endl;
//	cout << binarySearch(arr, 5, 8) << endl;
//	return 0;
//}