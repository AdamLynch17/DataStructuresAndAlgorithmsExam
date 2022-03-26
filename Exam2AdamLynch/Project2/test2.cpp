#include <iostream>
using namespace std;

int mainLinear() {
	int* pi;
	int piArray[] = { 12, 211, 48, 501, 91, 82, 110, 4 };
	pi = piArray;
	// run three search tests
	for (int test = 1; test <= 3; test++) {
		// take a search request from keyboard
		cout << "Specify the number to be searched for: ";
		int key;
		bool found = false;
		cin >> key;
		// L2. implement linear search through the array for the 1st occurrence 
		// of the key number; print the index if found or -1 otherwise

		for (int i = 0; i < sizeof(piArray); i++) {
			if (pi[i] == key) {
				found = true;
				cout << "The index of key " << key << " is " << i << endl;
			}
		}
		if (found == false)
			cout << "The index of key is -1" << endl;
		cout << "The complexity of the linear search is O(N)" << endl;
	}
	delete &pi;


	return 0;
}

int binarySearch(int* pi, int first, int last, int key)
{
	if (first > last) 
		return -1;

	if (last >= 1) {
		int mid = 1 + (last - 1) / 2;
		if (pi[mid] == key)
			return mid;

		if (pi[mid] > key)
			return binarySearch(pi, 0, mid - 1, key);
		else
			return binarySearch(pi, mid + 1, last, key);
	}
	
	return -1;
}

int mainBinary()
{
	int* pi;
	int piArray[] = { 12, 211, 48, 501, 91, 82, 110, 4 };
	pi = piArray;
	// run three search tests
	for (int test = 1; test <= 3; test++) {
		// take a search request from keyboard
		cout << "Specify the number to be searched for: ";
		int key;
		cin >> key;
		binarySearch(pi, 0, sizeof(pi), key);

		cout << "The complexity of the binary search is O(N log N)" << endl;
	}
	delete[] pi;
	return 0;
}

size_t Hash_(string key, size_t tableSize)
{
	size_t hash_index = 0;
	for (int i = 0; i < key.size(); i++) {
		char ch = key[i];
		hash_index = 37 * hash_index + ch;
	}
	return hash_index % tableSize;
}

int main()
{
	int tableSize = 223;
	int* pht = new int[tableSize];
	// H2. store the numbers in the hash table, e.g., 12 in a location specified by 
	// Hash("12", tableSize)
	pht[Hash_("12", tableSize)] = 12;
	pht[Hash_("211", tableSize)] = 211;
	pht[Hash_("48", tableSize)] = 48;
	pht[Hash_("501", tableSize)] = 501;
	pht[Hash_("91", tableSize)] = 91;
	pht[Hash_("82", tableSize)] = 82;
	pht[Hash_("110", tableSize)] = 110;
	pht[Hash_("4", tableSize)] = 4;

	// run three search tests
	for (int test = 1; test <= 3; test++) {
		cout << "Specify the number to be searched for: ";
		int key;
		cin >> key;
		int count = tableSize;
		int index = key % tableSize;
		while (pht[index] != NULL) {
			if (pht[index] == key) {
				cout << "The index of your key is " << index << endl;
				break;
			}
			index++;
			count--;
			index %= tableSize;
			if (count < 1) {
				cout << "The index of your key is -1" << endl;
				break;
			}
		}	
		cout << "The hashing-based search is potentially O(1)" << endl;
	}
	delete[] pht;
	return 0;
}
