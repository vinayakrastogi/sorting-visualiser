#include <iostream>
#include "visualiser.h"
#include <cstdlib> 

class SORTING_ALGORITHMS {
    public:
        Visualiser vslr;
        
        void initialise(int array[], int size) {
            vslr.initialise(array,size);
            vslr.visualise(array,-1,-1);
        }

        //////////////////////////////////////
        // SELECTION SORT
        //////////////////////////////////////
        void selectionSort(int array[], int size) {
            int temp;
            for (int i = 0; i < size ; i++) {
                for (int j=i; j < size; j++) {
                    if (array[i] > array[j]) {
                        temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
                    }
                    vslr.visualise(array,i,j);
                }
            }
        }
        //////////////////////////////////////
        // BUBBLE SORT
        //////////////////////////////////////
        void bubbleSort(int arr[], int n) {
            int temp;
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++)  {
                    if (arr[j] > arr[j + 1]) {
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                    vslr.visualise(arr,j,j+1);
               }
            }
        }

        //////////////////////////////////////
        // INSERTION SORT
        //////////////////////////////////////
        void insertionSort(int arr[], int n) {
            int i, key, j;
            for (i = 1; i < n; i++) {
                key = arr[i];
                j = i - 1;
                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
                vslr.visualise(arr,key, j+1);
            }
        }

        //////////////////////////////////////
        // SHELL SORT
        //////////////////////////////////////
        int shellSort(int arr[], int n) {
            for (int gap = n/2; gap > 0; gap /= 2) {
                for (int i = gap; i < n; i += 1) {
                    int temp = arr[i];
                    int j;            
                    for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                        arr[j] = arr[j - gap];
                    }
                    arr[j] = temp;
                    vslr.visualise(arr,gap,i);
                }
            }
            return 0;
        }

        //////////////////////////////////////
        // MERGE SORT
        //////////////////////////////////////
        void merge(int arr[], int l, int m, int r) {
            int i, j, k;
            int n1 = m - l + 1;
            int n2 = r - m;
            int L[n1], R[n2];
            for (i = 0; i < n1; i++) {
                L[i] = arr[l + i];
            }
            for (j = 0; j < n2; j++) {
                R[j] = arr[m + 1 + j];
            }
            i = 0;
            j = 0;
            k = l;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    arr[k] = L[i];
                    i++;
                }
                else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }
            while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
            }
            while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
            }
        }
        void mergeSort(int arr[], int l, int r) {
            if (l < r) {
                int m = l + (r - l) / 2;
                vslr.visualise(arr,l,r);
                mergeSort(arr, l, m);
                vslr.visualise(arr,l,r);
                mergeSort(arr, m + 1, r);
                vslr.visualise(arr,l,r);
                merge(arr, l, m, r);
                vslr.visualise(arr,l,r);
            }
        }

        //////////////////////////////////////
        // QUICK SORT
        //////////////////////////////////////
        void swap(int* p1, int* p2) {
            int temp;
            temp = *p1;
            *p1 = *p2;
            *p2 = temp;
        }

        int partition(int arr[], int low, int high) {
            int pivot = arr[high];
            int i = (low - 1);
            for (int j = low; j <= high; j++) {
                if (arr[j] < pivot) {
                    i++;
                    swap(&arr[i], &arr[j]);
                }
            }
            swap(&arr[i + 1], &arr[high]);
            return (i + 1);
        }
        void quickSort(int arr[], int low, int high) {
            if (low < high) {
                int pi = partition(arr, low, high);
                vslr.visualise(arr,low,high);
                quickSort(arr, low, pi - 1);
                vslr.visualise(arr,low,high);
                quickSort(arr, pi + 1, high);
                vslr.visualise(arr,low,high);
            }
        }

        //////////////////////////////////////
        // GNOME SORT
        //////////////////////////////////////
        void gnomeSort(int arr[], int n) {
            int index = 0;
            int temp;
            while (index < n) {
                if (index == 0)
                    index++;
                if (arr[index] >= arr[index - 1]) 
                    index++; 
                else { 
                    temp = arr[index-1];
                    arr[index-1] = arr[index];
                    arr[index] = temp;
                    index--; 
                }
                vslr.visualise(arr,-1,index);
            } 
            return; 
        } 
};




int main() {
    SORTING_ALGORITHMS sort;
    int size;
    int choice;
    system("clear");



    std::cout << "\n\n\t\t CREATE A LIST" << std::endl;
    std::cout << "\t\t 1. CREATE A RANDOM ARRAY" << std::endl;
    std::cout << "\t\t 2. CREATE YOUR OWN ARRAY" << std::endl;
    std::cout << "\t\t ENTER YOUR CHOICE :: ";
    std::cin >> choice;

    std::cout << "\t\t ENTER LENGTH OF ARRAY :: ";
    std::cin >> size;
    int array[size];
    
    if (choice == 1) {
        std::cout << "\t\t ENTER RANGE OF EACH ELEMENT (0-40) :: ";
        std::cin >> choice;
        srand(time(0));
        for (int i = 0 ; i < size ; i++) {
            array[i] = rand() % choice;
        }

    } else {
        for (int i = 0 ; i < size ; i++) {
           std::cout << "\tENTER " << (i+1) << " ELEMENT --> ";
           std::cin >> array[i];
        }
    }
    std::cout << "GENERATED ARRAY :: " << std::endl << std::endl;
    sort.initialise(array,size);
    std::cout << std::endl;
    std::cout << "\t 1. SELECTION SORT" << std::endl;
    std::cout << "\t 2. BUBBLE SORT" << std::endl;
    std::cout << "\t 3. INSERTION SORT" << std::endl;
    std::cout << "\t 4. SHELL SORT" << std::endl;
    std::cout << "\t 5. MERGE SORT" << std::endl;
    std::cout << "\t 6. QUICK SORT" << std::endl;
    std::cout << "\t 7. GNOME SORT" << std::endl;
    std::cout << "\t CHOOSE SORTING ALGORITHM :: ";
    std::cin >> choice;

    switch (choice) {
        case (1):
            sort.selectionSort(array,size);
            break;
        case (2):
            sort.bubbleSort(array,size);
            break;
        case (3):
            sort.insertionSort(array,size);
            break;
        case (4):
            sort.shellSort(array,size);
            break;
        case (5):
            sort.mergeSort(array,0,size-1);
            break;
        case (6):
            sort.quickSort(array,0,size-1);
            break;
        case (7):
            sort.gnomeSort(array,size);
            break;
        default:
            std::cout << "WRONG CHOICE" << std::endl;
            break;
    }


    return 0;
}