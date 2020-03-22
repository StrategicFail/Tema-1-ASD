#include <bits/stdc++.h>
#include <chrono>
#include <ctime>


using namespace std;
using namespace std::chrono;

ifstream f("teste.in");
ofstream g("teste.out");


void bubble_sort (int v[], int n){
    int i, aux, ord;
    do{
    ord=1;
    for(i = 0; i < n-1; ++i)
        if(v[i] > v[i+1]){
            aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
            ord = 0;}
    }
    while(ord == 0);
}

void count_sort (int v[], int n){
int fr[10000],i, j = 0;
for (i = 0 ; i < n ; ++i)
        fr[i] = 0;
for (i = 0 ; i < n ; ++i)
    fr[v[i]]++;
for (i = 0; i < 1001 ; ++i)
    while (fr[i]--)
        v[j++] = i;
}

void interclasare(int a[], int s, int m, int d){
    int l[10000], r[10000], size_l, size_r, i, j, k;
    size_l = m - s + 1;
    size_r = d - m;
    for (int index = 0; index < size_l; ++index)
        l[index] = a[s + index];
    for (int index = 0; index < size_r; ++index)
        r[index] = a[m + 1 + index];
    k = s;
    i = j = 0;
    while (i < size_l && j < size_r)
        if (l[i] < r[j]){
            a[k] = l[i];
            i++;
            k++;
        }
        else{
            a[k] = r[j];
            j++;
            k++;
        }
    while (i < size_l){
        a[k] = l[i];
        i++;
        k++;
    }
    while (j < size_r){
        a[k] = r[j];
        k++;
        j++;
    }

    }



void merge_sort(int v[], int s, int d){
     if (s < d) {
        int m = s + (d-s) / 2;
        merge_sort(v, s, m);
        merge_sort(v, m+1, d);
        interclasare(v, s, m, d);
    }
}
void quick_sort(int v[], int s, int d) {
  int pivot, i, j, aux;
  i = s;
  j = d;
  pivot = v[(i + j) / 2];
  do {
    while ( (i < d) && (v[i] < pivot) ) i++;
    while ( (j > s) && (v[j] > pivot) ) j--;
    if ( i <= j ) {
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
      i++;
      j--;
    }
  } while ( i <= j );
  if ( s < j ) quick_sort(v, s, j);
  if ( i < d ) quick_sort(v, i, d);
}

void insertion_sort(int v[], int n){
    int aux, k;
    for (int i = 0 ; i < n ; ++i){
        aux = v[i];
        k = i;
        while (k > 0 && aux < v[k - 1]){
            v[k] = v[k - 1];
            k--;
        }
        v[k] = aux;
    }
}

void print (int v[], int n){
    for (int i=0 ; i<n ; ++i)
        cout<<v[i]<<' ';
    cout<<'\n';
}

bool isSorted(int v[], int n){
    int i;
    bool ok = true;
    for (i = 0 ; i < n-1 ; ++i)
        if (v[i+1] < v[i])
            ok = false;
    return ok;
}

int main(){
int nr_teste, nr_numere, nr_max, v[100000];
f >> nr_teste;
for ( int i = 1 ; i <= nr_teste; i++){
    f >> nr_numere;
    f >> nr_max;
    srand((int) time(0));
    for (int j = 1; j <= nr_numere ; j++)
        v[j] = rand() % nr_max;
if (nr_numere > 10000){
    auto start_bubble = high_resolution_clock :: now();
    bubble_sort(v, nr_numere);
    if (isSorted(v, nr_numere)){
        cout << "Functia de bubble sort a sortat cu succes " << nr_numere << "  numere, cu maximul " << nr_max << " in: ";
    }
    else
        cout << "Functia de bubble sort nu a efectuat sortarea numerelor.";
    auto stop_bubble = high_resolution_clock :: now();
    auto duration_bubble = duration_cast <microseconds> (stop_bubble - start_bubble);
    cout << duration_bubble.count() <<" microsecunde." << '\n';}
    else
        cout << "Dimensiunea datelor este prea mare pentru bubble sort." << '\n';

    auto start_insertion = high_resolution_clock :: now();
    insertion_sort(v, nr_numere);
    if (isSorted(v, nr_numere)){
        cout << "Functia de insertion sort a sortat cu succes " << nr_numere << "  numere, cu maximul " << nr_max << " in: ";
    }
    else
        cout << "Functia de insertion sort nu a efectuat sortarea numerelor.";
    auto stop_insertion = high_resolution_clock :: now();
    auto duration_insertion = duration_cast <microseconds> (stop_insertion - start_insertion);
    cout << duration_insertion.count() << " microsecunde" << '\n';

    auto start_quick = high_resolution_clock :: now();
    quick_sort(v, 0, nr_numere - 1);
    if (isSorted(v, nr_numere)){
        cout << "Functia de quick sort a sortat cu succes " << nr_numere << "  numere, cu maximul " << nr_max << " in: ";
    }
    else
        cout << "Functia de quick sort nu a efectuat sortarea numerelor.";
    auto stop_quick = high_resolution_clock :: now();
    auto duration_quick = duration_cast <microseconds> (stop_quick - start_quick);
    cout << duration_quick.count() << " microsecunde" << '\n';

    auto start_merge = high_resolution_clock :: now();
    merge_sort(v, 0, nr_numere - 1);
    if (isSorted(v, nr_numere)){
        cout << "Functia de merge sort a sortat cu succes " << nr_numere << "  numere, cu maximul " << nr_max << " in: ";
    }
    else
        cout << "Functia de merge sort nu a efectuat sortarea numerelor.";
    auto stop_merge = high_resolution_clock :: now();
    auto duration_merge = duration_cast <microseconds> (stop_merge - start_merge);
    cout << duration_merge.count() << " microsecunde" << '\n';

    if (nr_max < 1000){
      auto start_count = high_resolution_clock :: now();
    count_sort(v, nr_numere);
    if (isSorted(v, nr_numere)){
        cout << "Functia de count sort a sortat cu succes " << nr_numere << "  numere, cu maximul " << nr_max << " in: ";
    }
    else
        cout << "Functia de count sort nu a efectuat sortarea numerelor.";
    auto stop_count = high_resolution_clock :: now();
    auto duration_count = duration_cast <microseconds> (stop_count - start_count);
    cout << duration_count.count() << " microsecunde" << '\n';}
    else
        cout << "Dimensiunea datelor este prea mare pentru count sort." << '\n';




    cout<<'\n';
    }

}

