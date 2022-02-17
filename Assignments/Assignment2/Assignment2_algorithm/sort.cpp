#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include<string.h>
#include <iomanip>
#include <chrono>
#include<fstream>
using namespace std;

using namespace std::chrono;
void selectionSort(vector<long long>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i] > arr[j])
			{
				long long temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void insertionSort(vector<long long>& vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		long long key = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}
void merge(vector<long long>& vec, int l, int m, int r)
{
	int n1 = m - l + 1, n2 = r - m;
	long long* arr1 = new long long[n1], * arr2 = new long long[n2];
	for (int i = 0; i < n1; i++)
		arr1[i] = vec[i + l];
	for (int i = 0; i < n2; i++)
		arr2[i] = vec[m + i + 1];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2)
	{
		if (arr1[i] <= arr2[j])
		{
			vec[k] = arr1[i];
			i++;
		}
		else
		{
			vec[k] = arr2[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		vec[k] = arr1[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		vec[k] = arr2[j];
		k++;
		j++;
	}
}
void mergeSort(vector<long long>& vec, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(vec, l, m);
		mergeSort(vec, m + 1, r);
		merge(vec, l, m, r);
	}
}
int Partitioning(vector<long long>& arr, int low, int high)

{
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}
int partition_r(vector<long long>& arr, int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);
	swap(arr[random], arr[high]);
	return Partitioning(arr, low, high);
}
void QuickSort(vector<long long>& Arr, int low, int high)
{
	if (low < high)
	{
		int rightPosition = partition_r(Arr, low, high);
		QuickSort(Arr, low, rightPosition - 1);
		QuickSort(Arr, rightPosition + 1, high);
	}
}

void hybridSort(vector<long long>& vec, int l, int h)
{
	
	if (h - l <= 20)
	{
		insertionSort(vec);
		return;
	}
	else
	{
		int rightPosition = partition_r(vec, l, h);
		hybridSort(vec, l, rightPosition - 1);
		hybridSort(vec, rightPosition + 1, h);
	}
}
void print(vector<long long>& arr)
{

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
}

int main(int argc, char** argv)
{
	//ofstream outfile("output.txt");
	//ofstream outtime("time.txt");
	//ifstream re("../../data.txt");
	ifstream re;
	ofstream outfile, outtime;
	vector<long long> vec;
	long long y;
	re.open(argv[2]);
	if (!re)
		cout << "File is Empty" << endl;
	while (re >> y)
		vec.push_back(y);
	re.close();
	/*for (int i = 0; i < 10; i++) {
		cout << vec[i] << " ";
	}*/
	//auto f = []() -> long long
	//{ return rand() % 1000; };
	//generate(vec.begin(), vec.end(), f);
	// for (long long &x : vec)
	//     cin >> x; 
	//=====================================
	int x = (int)*argv[1] - 48;
	//cin >> x;
	auto start = high_resolution_clock::now();
	switch (x)
	{
	case 0:
		selectionSort(vec);
		break;
	case 1:
		insertionSort(vec);
		break;
	case 2:
		mergeSort(vec, 0, vec.size() - 1);
		break;
	case 3:
		QuickSort(vec, 0, vec.size() - 1);
		break;
	case 4:
		hybridSort(vec, 0, vec.size() - 1);
		break;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	//print(vec);
	outfile.open(argv[3]);
	for (int i = 0; i < vec.size(); i++)
		outfile << vec[i] << endl;
	outfile.close();
	outtime.open(argv[4]);
	switch (x)
	{
	case 0:
		outtime << "Time taken of size: " << vec.size() << " by Selection Sort : " << duration.count() << " microseconds" << endl;
		break;
	case 1:
		outtime << "Time taken of size: " << vec.size() << " by Insertion Sort: " << duration.count() << " microseconds" << endl;
		break;
	case 2:
		outtime << "Time taken of size: " << vec.size() << " by Merge Sort: " << duration.count() << " microseconds" << endl;
		break;
	case 3:
		outtime << "Time taken of size: " << vec.size() << " by Quick Sort: " << duration.count() << " microseconds" << endl;
		break;
	case 4:
		outtime << "Time taken of size: " << vec.size() << " by Hybrid Sort: " << duration.count() << " microseconds" << endl;
		break;
	}
	outtime.close();
}