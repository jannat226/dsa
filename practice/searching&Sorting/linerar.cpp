
#include <iostream>

using namespace std;

// PROTOTYPE DECLARATION
int *createArray(int);
int linearSearch(int *, int, int);

int main()
{

    int dimension;
    int search_result;
    int *X;

    cout << "ENTER THE DIMENSION OF THE ARRAY -> ";
    cin >> dimension;

    X = createArray(dimension);

    // INSERTING ELEMENTS IN THE ARRAY
    for (int i = 0; i < dimension; i++)
    {
        cout << "X[" << i + 1 << "] ->";
        cin >> X[i];
    }

    search_result = linearSearch(X, dimension, 6);

    if (search_result != -1)
    {
        cout << "THE ELEMENT IS FOUND AT INDEX -> " << search_result << endl;
    }
    else
    {
        cout << "THE ELEMENT IS NOT FOUND IN THE ARRAY!" << endl;
    }

    return 0;
}

// FUNCTION DEFINITION
int *createArray(int dimension)
{
    int *X;
    X = (int *)malloc(dimension * sizeof(int));

    return X;
}

int linearSearch(int *X, int dimension, int element)
{
    for (int i = 0; i < dimension; i++)
    {
        if (X[i] == element)
        {
            return i;
        }
    }
    return -1;
}
