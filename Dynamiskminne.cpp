#include "Dynamiskminne.h"
#include <iostream> 

using namespace std; 

void fillInFibonacciNumers(int result[], int length)
{
    int t1=0, t2=1, t3, i=0; 
    result[0] = t1; 
    result[1] = t2;  
    for (i = 2; i<length; i++)
    {
        t3 = t1 + t2; 
        t1 = t2; 
        t2 = t3; 
        result[i] = t3; 
    }
}

void printArray(int arr[], int length)
{
    for (int i = 0; i<length; i++)
    {
        cout << arr[i] << " "; 
    }
}

void CreateFibonacci()
{   
    int length; 
    cout << "Hvor mange tall ønsker du å generere?" << endl; 
    cin >> length; 

    int *fibonacci = new int[length];

    fillInFibonacciNumers(fibonacci, length);
    printArray(fibonacci,length); 

    delete[] fibonacci; 
    fibonacci = nullptr; 

}




