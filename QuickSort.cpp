//
// Created by Nitish Mohan Shandilya on 7/2/20.
//
// [3, 4, 5, 7, 1, 0, 0, 2]
#include "stdlib.h"
#include "vector"

int partition(vector<int>& input, int begin, int end)
{
    int pivot = input[(end - begin)/2 + begin];
    //int pivot = input[end];
    while (begin <= end)
    {
        while (input[begin] > pivot) begin++;
        while (input[end] < pivot) end--;
        if (begin <= end)
        {
            int temp = input[begin];
            input[begin] = input[end];
            input[end] = temp;
            begin++;
            end--;
        }
    }
    return begin;
}

void quickSortInternal(vector<int>& input, int begin, int end)
{
    if (begin < end)
    {
        int partitionIndex = partition(input, begin, end);
        quickSortInternal(input, begin, partitionIndex-1);
        quickSortInternal(input, partitionIndex, end);
    }
}

void quickSort(vector<int>& input)
{
    quickSortInternal(input, 0, input.size()-1);
}

void testQuickSort()
{
    vector<int> input = {70, 60, 50, 40};
    quickSort(input);
    for (int ele : input)
        cout << ele << endl;
}