//
//  main.cpp
//  HW5
//
//  Created by Fahed on 4/19/16.
//  Copyright © 2016 Fahed. All rights reserved.
//
#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

void read_file(char * file_name, int * A[]);

void bubble_sort(int A[], int n);

void insertion_sort(int A[], int n);

int partition(int A[], int low, int high);
void sswap(int * x, int * y);
void quick_sort(int A[], int low, int high);

void shell_sort(int A[], int n);

void merge(int A[], int low, int high, int mid);
void merge_sort(int A[], int low, int high);

int main()
{
    char choice;
    int random[10000];  // creates int array size 10000 for random.txt
    int reversed[10000];  // creates int array size 10000 for reversed.txt
    int nearlySorted[10000];  // creates int array size 10000 for nearlysorted.txt
    int fewUnique[10000];  // creates int array size 10000 for fewunique.txt
    int temp[10000];  // creates int array size 10000 for temp purposes
    ifstream in;  // ifstream for reading file
    string line;  // string line to read segments of the txt files
    clock_t t;  // clock for timing the sorts
    
    in.open("Random.txt");  // opens random.txt
    if(in.is_open())  // confirms file is open
    {
        for(int i = 0; i < 10000; i++)  // for loop to read random.txt
        {
            getline(in, line, ' ');  // iterates through text file and reads each number as a string
            random[i] = stoi(line);  // converts string to an int
            line = "";
        }
    }
    in.close();  // close file
    
    in.open("Reversed.txt");  // same as previous read file
    if(in.is_open())
    {
        for(int i = 0; i < 10000; i++)
        {
            getline(in, line, ' ');
            reversed[i] = stoi(line);
            line = "";
        }
    }
    in.close();
    
    in.open("NearlySorted.txt");  // same as previous read file
    if(in.is_open())
    {
        for(int i = 0; i < 10000; i++)
        {
            getline(in, line, ' ');
            nearlySorted[i] = stoi(line);
            line = "";
        }
    }
    in.close();
    
    in.open("FewUnique.txt");  // same as previous read file
    if(in.is_open())
    {
        for(int i = 0; i < 10000; i++)
        {
            getline(in, line, ' ');
            fewUnique[i] = stoi(line);
            line = "";
        }
    }
    in.close();
    
    do
    {
        cout << "Choose which sort to time \n";  // asks for user input
        cout << "1. Bubble sort \n";
        cout << "2. Insertion sort \n";
        cout << "3. Quick sort \n";
        cout << "4. Shell sort \n";
        cout << "5. Merge sort \n";
        cout << "0. To quit \n";
        
        cin >> choice;
        while(choice < '0' || choice > '5')  // checks input is 0-5
        {
            cout << "Please enter int 0 to 5: ";
            cin >> choice;
        }
        if(choice != '0')  // if choice is 0, breaks out, else preform switch statement
        {
            switch(choice)
            {
                case '1':  // case for bubble sort
                    cout << "Preforming Bubble sort \n";
                    cout << "	Time for Random.txt: ";  // sort for random
                {
                    for(int i = 0; i < 10000; i++)  // sets temp to random array
                    {
                        temp[i] = random[i];
                    }
                    t = clock();  // reads clock time
                    bubble_sort(temp, 10000);  // preforms bubble sort on temp array
                    t = clock() - t;  // reads clock time and subtracts previous clock time
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";  // prints clock time in seconds
                }
                    cout << "	Time for Reversed.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = reversed[i];
                    }
                    t = clock();
                    bubble_sort(temp, 10000);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    cout << "	Time for NearlySorted.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = nearlySorted[i];
                    }
                    t = clock();
                    bubble_sort(temp, 10000);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    cout << "	Time for FewUnique.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = fewUnique[i];
                    }
                    t = clock();
                    bubble_sort(temp, 10000);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    break;
                case '2':  // case for insertion sort
                    cout << "Preforming Insertion sort \n";
                    cout << "	Time for Random.txt: ";  // sort for random
                {
                    for(int i = 0; i < 10000; i++)  // sets temp to random array
                    {
                        temp[i] = random[i];
                    }
                    t = clock();  // reads clock time
                    insertion_sort(temp, 10000);  // preforms insertion sort on temp
                    t = clock() - t;  // calculates difference in clock time
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";  // prints clock time in seconds
                }
                    cout << "	Time for Reversed.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = reversed[i];
                    }
                    t = clock();
                    insertion_sort(temp, 10000);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    cout << "	Time for NearlySorted.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = nearlySorted[i];
                    }
                    t = clock();
                    insertion_sort(temp, 10000);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    cout << "	Time for FewUnique.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = fewUnique[i];
                    }
                    t = clock();
                    insertion_sort(temp, 10000);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    break;
                case '3':  // case for quick sort
                    cout << "Preforming Quick sort \n";
                    cout << "	Time for Random.txt: ";  // sort for random
                {
                    for(int i = 0; i < 10000; i++)  // sets temp array to random array
                    {
                        temp[i] = random[i];
                    }
                    t = clock();  // reads clock time
                    quick_sort(temp, 0, 9999);  // quick sorts temp
                    t = clock() - t;  // calculates difference in clock time
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";  // prints clock time in seconds
                }
                    cout << "	Time for Reversed.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = reversed[i];
                    }
                    t = clock();
                    quick_sort(temp, 0, 9999);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    cout << "	Time for NearlySorted.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = nearlySorted[i];
                    }
                    t = clock();
                    quick_sort(temp, 0, 9999);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    cout << "	Time for FewUnique.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = fewUnique[i];
                    }
                    t = clock();
                    quick_sort(temp, 0, 9999);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    break;
                case '4':  // case for shell sort
                    cout << "Preforming Shell sort \n";
                    cout << "	Time for Random.txt: ";  // shell sort for random
                {
                    for(int i = 0; i < 10000; i++)  // sets temp array to random array
                    {
                        temp[i] = random[i];
                    }
                    t = clock();  // reads clock time
                    shell_sort(temp, 10000);  // shell sorts temp array
                    t = clock() - t;  // calculates difference in clock time
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";  // prints clock time in seconds
                }
                    cout << "	Time for Reversed.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = reversed[i];
                    }
                    t = clock();
                    shell_sort(temp, 10000);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    cout << "	Time for NearlySorted.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = nearlySorted[i];
                    }
                    t = clock();
                    shell_sort(temp, 10000);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    cout << "	Time for FewUnique.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = fewUnique[i];
                    }
                    t = clock();
                    shell_sort(temp, 10000);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    break;
                case '5':  // case for merge sort
                    cout << "Preforming Merge sort \n";
                    cout << "	Time for Random.txt: ";  // merge sorts random
                {
                    for(int i = 0; i < 10000; i++)  // sets temp array to random array
                    {
                        temp[i] = random[i];
                    }
                    t = clock();  // reads clock time
                    merge_sort(temp, 0, 9999);  // merge sorts temp
                    t = clock() - t;  // calculates differece in clock time
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";  // prints clock time in seconds
                }
                    cout << "	Time for Reversed.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = reversed[i];
                    }
                    t = clock();
                    merge_sort(temp, 0, 9999);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    cout << "	Time for NearlySorted.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = nearlySorted[i];
                    }
                    t = clock();
                    merge_sort(temp, 0, 9999);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    cout << "	Time for FewUnique.txt: ";  // same as previous
                {
                    for(int i = 0; i < 10000; i++)
                    {
                        temp[i] = fewUnique[i];
                    }
                    t = clock();
                    merge_sort(temp, 0, 9999);
                    t = clock() - t;
                    cout << (((float)t)/CLOCKS_PER_SEC) << "seconds\n";
                }
                    break;
            }			
        }
    }while(choice != '0');
    return 0;
}
/*
 void read_file(char * file_name, int * A)
 {
	ifstream in;
	string line;
	in.open(file_name);
 
	if(in.is_open())
	{
 while(getline(in, line, ' '))
 {
 A[i] = line;
 }
 
	}
 }
 */

// start bubble sort
void bubble_sort(int A[], int n)  // bubble sort, parameters array A and int n
{
    int temp;
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            if(A[j] > A[j+1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
// end bubble sort

// start insertion sort
void insertion_sort(int A[], int n)  // insertion sort, parameters array A and int n
{
    int j, temp;
    for(int i = 1; i < n; i++)
    {
        temp = A[i];
        j = i;
        
        while((j > 0) && (A[j - 1] > temp))
        {
            A[j] = A[j - 1];
            j = j - 1;
        }
        A[j] = temp;
    }
}
// end insertion sort

// start quick sort
int partition(int A[], int low, int high)  // for quick sort, parameters array A, int low, int high
{
    int pivot = A[low];
    
    do
    {
        while(A[low] < pivot)
            low++;
        
        while(A[high] > pivot)
            high--;
        
        if(low < high && A[low] != A[high])
            sswap(&A[low], &A[high]);
        else
            return high;
    }while(low < high);
    
    return high;
}

void sswap(int * x, int * y)  // for quick sort, parameters pointer for x and pointer for y
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void quick_sort(int A[], int low, int high)  // quick sort, parameters array A, int low, int high
{
    int j;
    if(low < high)
    {
        j = partition(A, low, high);
        quick_sort(A, low, j - 1);
        quick_sort(A, j + 1, high);
    }
}
// end quick sort


// start shell sort
void shell_sort(int A[], int n) //sorts by insertion
{
    int temp, gap, swapped;
    gap = n / 2;
    
    do
    {
        do
        {
            swapped = 0;
            
            for(int i = 0; i < n - gap; i++)
            {
                if(A[i] > A[i + gap])
                {
                    temp = A[i];
                    A[i] = A[i + gap];
                    A[i + gap] = temp;
                    swapped = 1;
                }
            }
        }while(swapped == 1);
        
    }while((gap = gap / 2) >= 1); 
}
// end shell sort


// start merge sort
void merge(int A[], int low, int high, int mid)
{
    int i, j, k, C[10000];
    i = low;
    j = mid + 1;
    k = 0;
    
    while((i <= mid) && (j <= high))
    {
        if(A[i] < A[j])
            C[k] = A[i++];
        else
            C[k] = A[j++];
        
        k++;
    }
    
    while(i <= mid)
        C[k++] = A[i++];
    
    while(j <= high)
        C[k++] = A[j++];
    
    for(i = low, j = 0; i <= high; i++, j++)
        A[i] = C[j];
}

void merge_sort(int A[], int low, int high) //sorts data items into ascending order
{
    int mid;
    
    if(low < high)
    {
        mid = (low + high) / 2;
        merge_sort(A, low, mid);
        merge_sort(A, mid + 1, high);
        merge(A, low, high, mid);
    }
    
}
// end merge sort