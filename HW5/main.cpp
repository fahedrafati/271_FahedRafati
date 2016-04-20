//
//  main.cpp
//  HW5
//
//  Created by Fahed on 4/19/16.
//  Copyright © 2016 Fahed. All rights reserved.
//

//Had a lot of help from abdul, worked with a few partners and a lot of googling

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Bubble_Sort(int A[], int n);
void Insertion_Sort(int A[], int n);
void swap(int &x, int &y);
int partition(int a[], int left, int right, int pivotIndex);
void Quick_Sort(int a[], int left, int right);
void Shell_Sort(int A[], int n);
void merge(int A[], int low, int high, int mid);
void Merge_Sort(int A[], int low, int high);

bool number_array(string red, int *& noms);

int comparisons = 0;
int exchanges = 0;

void Bubble_Sort(int A[], int n)    //Bubble Sort
{
    int i, j, temp;// defining int variables
    for(i = 1; i < n; i++)      //number of passes
    {
        for(j = 0; j < n - 1; j++)      //for statement initialized
        {
            comparisons++;         //comparison
            if(A[j] > A[j + 1])     //compare two numbers following eachother
            {
                temp = A[j];        //swap A[j] with A[j + 1]
                A[j] = A[j + 1];
                A[j + 1] = temp;
                exchanges++;        //making exchanges within the if statement
            }
        }
    }
    cout << "Bubble Sort Comparisons: " << comparisons << endl; //console output
    cout << "Bubble Sort Exchanges: " << exchanges << endl; //console output
    cout << endl; //space
}

void Insertion_Sort(int A[], int n)     //Insertion Sort
{
    int i, j, element; // defining int variables
    for(i = 1; i < n; i++) //initalizing for loop
    {
        element = A[i];     //placing elements into for loop array
        j = i;
        comparisons++;      //making comparison
        while ((j > 0) && (A[j - 1] > element))
        {
            
            A[j] = A[j - 1];        //shift elements
            j = j - 1;
            exchanges++;        //making exchanges
            comparisons++;      //making comparisons
        }
        A[j] = element;         //place element at jth position
    }
    cout << "Insertion Sort Comparisons: " << comparisons << endl;   //console output
    cout << "Insertion Sort Exchanges: " << exchanges << endl;       //console output
    cout << endl; //space
}

void swap(int &x, int &y)  //for Quick_Sort function in order to pass by reference not value
{
    int temp; // defining int variable
    temp = x;
    x = y;
    y = temp;
}

int partition(int a[], int left, int right, int pivotIndex)     //for Quick_Sort
{
    int pivot = a[pivotIndex];      //pivot made
    do // do loop initialized
    {
        while (a[left] < pivot) //while loop initialized
        {
            left++;     //increase left by one
            comparisons++;      //making comparisons for left
        }
        comparisons++;
        while (a[right] > pivot)
        {
            right--;        //decrease right by one
            comparisons++;      //making comparisons for right
        }
        comparisons++;
        if (left < right && a[left] != a[right])
        {
            swap(a[left], a[right]);        //making a swap with left and right
            exchanges++;        //making exchanges in the if statement for swap
        }
        else
        {
            return right;
        }
    }
    while (left < right);
    return right;
}

void Quick_Sort(int a[], int left, int right) //Quick sorting, will call swap and partition function above
{
    if (left < right)
    {
        int pivot = (left + right) / 2;         // middle
        int pivotNew = partition(a, left, right, pivot);
        Quick_Sort(a, left, pivotNew - 1);
        Quick_Sort(a, pivotNew + 1, right);
    }
}

void Shell_Sort(int A[], int n)//Shell sort
{
    int temp, gap, i;
    int swapped;
    gap = n/2;
    do
    {
        do
        {
            swapped = 0;        //swapped here is different that the swap function above
            for(i = 0; i < n - gap; i++)
            {
                comparisons++;      //comparison within the for loop but before the if statement, same as bubble sort function
                if(A[i] > A[i + gap])
                {
                    temp = A[i];
                    A[i] = A[i + gap];
                    A[i + gap] = temp;
                    swapped = 1;
                    exchanges++;    //making exchanges within the if statement, same as bubble sort function
                }
            }
        }
        while(swapped == 1);    //set swap equal to 1
    }
    while((gap = gap/2) >= 1);
    cout << "Shell Comparisons: " << comparisons << endl;   //console output
    cout << "Shell Exchanges: " << exchanges << endl;       //console output
    cout << endl; //space
}

void merge(int A[], int low, int high, int mid)     //for Merge_Sort
{
    int i, j, k, C[10000];
    i = low;          //index for first part
    j = mid + 1;      //index for second part
    k = 0;            //merge arrays A and B in array C
    while ((i <= mid) && (j <= high))
    {
        comparisons++;      //making comparisons
        if (A[i] < A[j])
        {
            C[k] = A[i++];
            exchanges++;        //making exchanges
        }
        else
        {
            C[k] = A[j++];
            exchanges++;        //making exchanges
        }
        k++;
    }
    while (i <= mid)
    {
        C[k++] = A[i++];
        exchanges++;        //making exchanges
    }
    while (j <= high)
    {
        C[k++] = A[j++];
        exchanges++;        //making exchanges
    }
    for (i = low, j = 0; i < high; i++, j++)
        //copy array C contents back to array A
    {
        A[i] = C[j];
    }
}

void Merge_Sort(int A[], int low, int high)     //Merge sorting, call to the function above
{
    int mid;
    if (low < high)
    {
        mid=(low + high)/2;
        Merge_Sort(A, low, mid);
        Merge_Sort(A, mid + 1, high);
        merge(A, low, high, mid);       //call the function above
    }
    return;
}

bool number_array(string red, int *& noms)   //reading in the text files into arrays
{
    ifstream thisfile;      //input file stream
    thisfile.open(red.c_str());     //c-style string, open the input file
    
    if(!thisfile.is_open())     //if the file fails to open
    {
        cout << "File not found" << red << endl;
        cout << "Incorrect Location \n";
        cout << endl; //space
        return false;
    }
    string y;       //create a random string
    string x = " ";     //create a random string
    while(thisfile.peek()!= EOF)
        //peek reads and returns the next character without extracting
        //while this is not equal to end of the file
    {
        thisfile >> y;      //read in string y
        x += y + " ";
    }
    thisfile.clear();
    thisfile.close();       //close the input file
    
    vector<string> vertical;        //a vector of string
    y = "";
    for( int i = 0; i < x.length();i++)
    {
        if (x[i] == ' ')
        {
            vertical.push_back(y);
            y = "";
        }
        else
        {
            y += x[i];
        }
    }
    if(noms != NULL)        //freeing up memory just in case
    {
        delete noms;
    }
    noms = new int[vertical.size()];
    for(int i = 0; i < vertical.size(); i++)
    {
        noms[i]= atoi(vertical[i].c_str());
    }
    return true;
}

int main(int argc, const char * argv[])
{
    int * Every_nums;
    string just_names[4];
    just_names[0] = "FewUnique.txt";
    cout << "[1] FewUnique.txt" << endl;    //console output
    just_names[1] = "NearlySorted.txt";
    cout << "[2] NearlySorted.txt" << endl;     //console output
    just_names[2] = "Random.txt";
    cout << "[3] Random.txt" << endl;       //console output
    just_names[3] = "Reversed.txt";
    cout << "[4] Reversed.txt" << endl;     //console output
    cout << endl;  //space
    
    for(int i = 0; i < 4; i++) //reading each algorithm one by one
    {
        
        number_array(just_names[i], Every_nums);
        Bubble_Sort(Every_nums, 10000);
        
        number_array(just_names[i], Every_nums);
        Insertion_Sort(Every_nums, 10000);
        
        number_array(just_names[i], Every_nums);
        Quick_Sort(Every_nums, 0, 9999);
         cout << "Quick Comparisons: " << comparisons << endl;    //output put here as caused unending loop when placed in quick comparison function
         cout << "Quick Exchanges: " << exchanges << endl;      //output
         cout << endl;    //space
        
        number_array(just_names[i], Every_nums);
        Shell_Sort(Every_nums, 10000);
        
        number_array(just_names[i], Every_nums);
        Merge_Sort(Every_nums, 0, 9999);
        cout << "Merge Comparisons: " << comparisons << endl;     //output put here as just wouldnt work in merge sort function
        cout << "Merge Exchanges: " << exchanges << endl;      //output
        cout << endl;   //space
        
        
    }
    cout << "Above are the Comparisons & Exchanges" << endl; //ending statement
    return 0;
}