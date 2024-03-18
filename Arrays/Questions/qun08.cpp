#include <iostream>
using namespace std;

int uniqueElement(int arr[], int size)
{
    int position = 1;
    
    for(int i = 1; i < size; i++) {
        
       
            if(arr[i] != arr[i-1])
            {
                arr[position] = arr[i];
                position++;
            }
    }
    return position;
}

void printArray(int arr[], int size)
{
    cout <<endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

int main()
{
    int size = 7;
    int arr[] = {1, 1, 2, 2, 2, 3, 3};
    cout <<endl;
    printArray(arr, size);
    int newSize = uniqueElement(arr, size);
    printArray(arr, newSize);
}