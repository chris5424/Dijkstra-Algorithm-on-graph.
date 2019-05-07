#include "heapsort.hpp"
void maxheap(int tab[], int rozmiar, int parentInd)
{
	int maxIndex = parentInd;
	int leftChild = parentInd * 2 + 1;
	int rightChild = parentInd * 2 + 2;

	if (leftChild < rozmiar && tab[leftChild] < tab[maxIndex]) {
		maxIndex = leftChild;
	}
	if (rightChild < rozmiar && tab[rightChild] < tab[maxIndex]) {
		maxIndex = rightChild;
	}
	if (maxIndex != parentInd) {
		int temp;
		temp = tab[maxIndex];
		tab[maxIndex] = tab[parentInd];
		tab[parentInd] = temp;
		maxheap(tab, rozmiar, maxIndex);
	}
}