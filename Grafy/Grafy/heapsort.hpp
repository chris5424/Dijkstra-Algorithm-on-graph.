#pragma once


void maxheap(int tab[], int rozmiar, int parentInd);


//
//void heapsort(int tab[], int rozmiar)
//{
//	if (rozmiar == 0) {
//		return;
//	}
//	int do_posortowania = rozmiar;
//	for (int i = do_posortowania / 2 - 1; i >= 0; i--) {
//		maxheap(tab, rozmiar, i);
//	}
//
//	for (int i = do_posortowania - 1; i > 0; i--) {
//		int temp;
//		temp = tab[0];
//		tab[0] = tab[i];
//		tab[i] = temp;
//		do_posortowania--;
//		maxheap(tab, do_posortowania, 0);
//	}
//}





//template <typename T>
//void maxheap_intro(T tab[], int right, int parentInd)
//{
//	int maxIndex = parentInd;
//	int leftChild = parentInd * 2 + 1;
//	int rightChild = parentInd * 2 + 2;
//
//	if (leftChild < right && tab[leftChild] > tab[maxIndex]) {
//		maxIndex = leftChild;
//	}
//	if (rightChild < right && tab[rightChild] > tab[maxIndex]) {
//		maxIndex = rightChild;
//	}
//	if (maxIndex != parentInd) {
//		T temp;
//		temp = tab[maxIndex];
//		tab[maxIndex] = tab[parentInd];
//		tab[parentInd] = temp;
//		maxheap(tab, right, maxIndex);
//	}
//}
//template <typename T>
//void heapsort_intro(T tab[],int left, int right)
//{
//	if ((right-left) == 0) {
//		return;
//	}
//	int do_posortowania = right-left;
//	for (int i = do_posortowania / 2 - 1; i >= left; i--) {
//		maxheap(tab, right, i);
//	}
//
//	for (int i = do_posortowania - 1; i > left; i--) {
//		T temp;
//		temp = tab[left];
//		tab[left] = tab[i];
//		tab[i] = temp;
//		do_posortowania--;
//		maxheap(tab, do_posortowania, left);
//	}
//}
