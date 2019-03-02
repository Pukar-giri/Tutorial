#include <iostream>
using namespace std;

template <typename Type, std::size_t M>
void sort(Type (&arr)[M], bool ascending = true)
{
    Type temp;
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = i + 1; j < M; j++)
        {
            if (ascending && arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            if (!ascending && arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template <typename Type, std::size_t M>
void print(Type (&arr)[M])
{
    int i;
    for (i = 0; i < M; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 12, 4, 13, 14, 5, 9, 6, 7, 8, 10, 11, 2, 3, 15};
    cout << "before sorting" << endl;
    print(arr);
    sort(arr);
    cout << "after sorting ascending" << endl;
    print(arr);
    int arr2[] = {1, 12, 4, 13, 14, 5, 9, 6, 7, 8};
    cout << "before sorting" << endl;
    print(arr2);
    sort(arr2, false);
    cout << "after sorting descending" << endl;
    print(arr2);
}