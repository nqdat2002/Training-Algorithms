#include<bits/stdc++.h>
using namespace std;
void printArray(int a[], int n){
    for (int i = 0; i < n; i++){
    	cout << a[i] << " ";
	}
	cout << endl;
}
int cnt = 0;
void quickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p) i++;
		while (a[j] > p) j--;
		if (i <= j){
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < r){
		quickSort(a, i, r);
	}
	if (l < j){
		quickSort(a, l, j);
	}
}
int a[100001];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];		
	}
	quickSort(a, 0, n-1);
//	printArray(a, n);
    return 0;
}