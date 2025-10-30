//lowk im just practicing for a midterm and saving these on git to look at later
#include <stdio.h>
#include <iostream>

template <typename T>
void merge (T * a, T * aux, int low, int mid, int high){
    for(int k = low; k <= high; k++){
        aux[k] = a[k];
    }
    
    int i = low;
    int j = mid+1;

    for(int k = low; k <= high; ++k){
        if(i > mid){
            a[k] = aux[j++];
        }
        else if(j > high){
            a[k] = aux[i++];
        }
        else if(aux[i] > aux[j] ){
            a[k] = aux[j++];
        }
        else{
            a[k] = aux[i++];
        }
    }
}

template <typename T>
void split(T* a, T* aux, int low, int high){
    if(low >= high){
        return;
    }
    
    int mid = low + (high - low) / 2;
    split(a, aux, low, mid);
    split(a, aux, mid+1, high);
    merge(a, aux, low, mid, high);
}

template<typename T>
void MergeSort(T* a, int len){
    T* aux = new T[len];
    
    split(a, aux, 0, len-1);
    
    delete [] aux;
}

template<typename T>
void InsertionSort(T* a, int len){
    for(size_t k = 1; k < len; ++k){
        int i = k;
        int j = k-1;
        while(a[i] < a[j] && j >= 0){
            T temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i--;
            j--;
        }
    }
}

template<typename T>
void SelectionSort(T* a, int len){
    for(size_t k = 0; k < len; ++k){
        T min = k;
        for(size_t i = k; i < len; ++i){
            if(a[i] < a[min]){
                min = i;
            }
        }
        T temp = a[k];
        a[k] = a[min];
        a[min] = temp;
    }
}

template<typename T>
void QuickSort(T* a, int low, int high){
    if(low >= high){
        return;
    }

    int result;
    
    int i = low;
    int j = high + 1;
    T v = a[low];
    while(true){
        while(a[++i] < v){
            if(i == high) break;
        }
        while(v < a[--j]){
            if(j == low) break;
        }
        if(i >= j) break;
        
        T temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    T temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    
    QuickSort(a, low, j-1);
    QuickSort(a, j+1, high);
}

template<typename T>
void QuickSort(T* a, int len){
    QuickSort(a, 0, len-1);
}

int main()
{
    int a[] = {5,3,4,2,1};
    QuickSort(a, 5);
    for(auto i : a){
        std::cout << i << std::endl;
    }

    printf("Hello World");
    return 0;
}
