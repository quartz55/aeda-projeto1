#include <vector>

using std::vector;

//Algoritmos generalizados, baseados nos expostos na aula

// metodo de ordenação com complexidade temporal O(n^2);
template <class Comparable>
void insertionSort(vector<Comparable> &v)
{
	for (unsigned int p = 1; p < v.size(); p++)
	{
		Comparable tmp = v[p];
		int j;
		for (j = p; j > 0 && tmp < v[j - 1]; j--)
			v[j] = v[j - 1];
		v[j] = tmp;
	}
}

// metodo de ordenação com complexidade temporal O(n log n);
template <class Comparable>
void quickSort(vector<Comparable> &v, int left, int right)
{
	if (right - left <= 10) // se vetor pequeno
		insertionSort(v);
	else {
		Comparable x = median3(v, left, right); // x é o pivot
		int i = left; int j = right - 1; // passo de partição
		for (;;) {
			while (v[++i] < x);
			while (x < v[--j]);
			if (i < j)
				swap(v[i], v[j]);
			else break;
		}
		swap(v[i], v[right - 1]); //repoe pivot
		quickSort(v, left, i - 1);
		quickSort(v, i + 1, right);
	}
}


// metodo de pesquisa com complexidade temporal O(n);
template <class T>
int SequentialSearch(const vector<T> &v, T x)
{
	for (unsigned int i = 0; i < v.size(); i++)
	if (v[i] == x)
		return i; // encontrou
	return -1; // não encontrou
}

// metodo de pesquisa com complexidade temporal O(log n)

template <class T>
int BinarySearch(const vector<T> &v, T x)
{
	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (v[middle] < x)
			left = middle + 1;
		else if (x < v[middle)
			right = middle – 1;
		else
			return middle; // encontrou
	}
	return -1; // não encontrou
}
