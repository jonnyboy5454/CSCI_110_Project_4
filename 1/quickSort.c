#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right, int pivot);
void swap(int arr[], int a, int b);

int main() {
	int
		x[50], i;

	srand(time(NULL));

	printf("50 random integers in range 0-99:\n");
	for (i = 0; i < 50; i++) {
		x[i] = rand() % 100;
		printf("%d ", x[i]);
	}
	printf("\n");

	printf("Quicksorted random integers:\n");
	quickSort(x, 0, 49);
	for (i = 0; i < 50; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");

	return 0;
}

void quickSort(int arr[], int left, int right) {
	int 
		pivot, newPivot;

	if (left < right) {
		pivot = 0;
		newPivot = partition(arr, left, right, pivot);
		quickSort(arr, left, newPivot - 1);
		quickSort(arr, newPivot + 1, right);
	}
}

int partition(int arr[], int left, int right, int pivot) {
	int
		pivotValue, storeIndex, i;
	
	pivotValue = arr[pivot];
	swap(arr, arr[pivot], arr[right]);
	storeIndex = left;

	for (i = left; i < right; ) {
		if (arr[i] < pivotValue) {
			swap(arr, arr[i], arr[storeIndex]);
			storeIndex++;
		}
	}
	swap(arr, arr[storeIndex], arr[right]);

	return storeIndex;
}

void swap(int arr[], int a, int b) {
	int 
		temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}