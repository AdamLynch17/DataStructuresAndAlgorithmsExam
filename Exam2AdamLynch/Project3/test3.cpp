#include "List.h"
#include "ListNode.h"
#include <iostream>
using namespace std;

// quick sort
void quickSort(int* a, int first, int last)
{
	// partition
	int i = first, j = last;
	int pivot = a[(first + last) / 2];
	while (i <= j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++; j--;
		}
	}
	// recursion
	if (first < i - 1) quickSort(a, first, i - 1);
	if (i < last) quickSort(a, i, last);
}

void printTopX(int* rand_array, int N, int X) {
	quickSort(rand_array, 0, N);
	for (int r = (N - X); r < N; r++)
		cout << "The value at position " << r + 1 << " is equal to " << rand_array[r] << endl;
}

int mainQuick() {
	int N = 0;
	cout << "Specify value of N - ";
	cin >> N;
	int X = 0;
	cout << "Specify value of X - ";
	cin >> X;
	int* rArray = new int[N];
	for (int i = 0; i < N; i++)
		rArray[i] = 5 + (rand() % 95);

	printTopX(rArray, N, X);
	cout << "The complexity of printTopX is O(N log N)" << endl;
	return 0;
}

int mainComplexity()
{
	cout << "Suppose Quick Sort takes 5 ms to sort an array of size 512." << endl;
	// fill ... below and print out your answer
	cout << "Quick Sort (4096) should take 53 ms." << endl
		<< "Because: the complexity is N log N" << endl
		<< "Therefore: by dividing the time(5) by N(512) log N(2.7) and multiplying by the new N(4096) log N(3.6) we get 53s" << endl;
	return 0;
}

List<int>* insertionSort(List<int>* l)
{
	int i, j, item_i;
	i = 1;
	int k = l->size();
	for (i = 2; i < k; i++) {
		// item in position i
		item_i = l->get(i);
		j = i - 1;
		
		// for positions from j to 0 find the 1st position j with item <= item_i 
		while (j >= 0 && l->get(j) > item_i) {
			l->setp(j);
			int temp = l->get(j - 1);
			l->set_prev(l->get(j));
			l->set(j, temp);
			//l->get(j + 1) = l->get(j);
			j--;		
		}

		while (i <= j) {
			while (l->get(i) < item_i) i++;
			while (l->get(j) > item_i) j--;
		}
		// insert item_i into position j + 1
		cout << "Inserts" << endl;
		l->insert(j + 1, item_i);
		item_i += 1;
	}

	cout << "The complexity of this list-based insertion sort is O(N^2)" << endl;
	return l;
}

int main() {
	int N = 0;
	cout << "Specify value of N - ";
	cin >> N;
	List<int>* rlist = new List<int>;
	for (int i = 0; i < N; i++)
		rlist->insert_end(5 + (rand() % 95));
	rlist->print();
	insertionSort(rlist);
	rlist->print();

	return 0;
}