#pragma once
void createArray()
{

}

void displayArray()
{

}

void bubbleSort()
{

}

void selectionSort()
{

}

void insertionSort()
{

}

void quickSort()
{

}

void mergeSort()
{

}

void heapSort()
{

}

int sortOptionsMenuOption()
{
    cout << endl << "Sort simulations";
    cout << endl << "==========================================";
    cout << endl << "1> Create a dynamic array and fill with random elements";
    cout << endl << "2> Display the unsorted array";
    cout << endl << "3> Perform BubbleSort";
    cout << endl << "4> Perform SelectionSort";
    cout << endl << "5> Perform InsertionSort";
    cout << endl << "6> Perform QuickSort";
    cout << endl << "7> Perform MergeSort";
    cout << endl << "8> Perform HeapSort";
    cout << endl << "==========================================";
    cout << endl << "Exit 0";
    cout << endl << "==========================================" << endl;
    int options = inputInteger("Options: ", 0, 8);
    cout << endl << endl << endl;
    return options;
}

void sortOptions()
{
    do
    {
        switch (sortOptionsMenuOption())
        {
        case 0: return; break;
        case 1: createArray(); break;
        case 2: displayArray(); break;
        case 3: bubbleSort(); break;
        case 4: selectionSort(); break;
        case 5: insertionSort(); break;
        case 6: quickSort(); break;
        case 7: mergeSort(); break;
        case 8: heapSort(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}