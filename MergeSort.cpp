//
// Created by Nitish Mohan Shandilya on 7/2/20.
//
// [3, 4, 4, 5, 1, 0, 7, 9, 10]

#include "stdlib.h"
#include "vector"
#include "string"

template <typename T>
void merge(vector<T>& input, int begin, int mid, int end, vector<T>& helper)
{
    for (int i = begin; i <= end; i++)
        helper[i] = input[i];

    int helperLeft = begin, helperRight = mid+1, inputIndex = begin;
    while (helperLeft <= mid && helperRight <= end)
    {
        if (helper[helperRight] <= helper[helperLeft])
            input[inputIndex++] = helper[helperRight++];
        else
            input[inputIndex++] = helper[helperLeft++];
    }

    for (int i = 0; i <= (mid - helperLeft); i++)
        input[inputIndex + i] = helper[helperLeft + i];
}

template <typename T>
void mergeSortInternal(vector<T>& input, int begin, int end, vector<T>& helper)
{
    if (begin < end)
    {
        int mid = (end - begin)/2 + begin;
        mergeSortInternal(input, begin, mid, helper);
        mergeSortInternal(input, mid+1, end, helper);
        merge(input, begin, mid, end, helper);
    }
}

template <typename T>
void mergeSort(vector<T>& input)
{
    vector<T> helper;
    helper.reserve(input.size());
    mergeSortInternal(input, 0, input.size()-1, helper);
}

void testMergeSort()
{
    // Int case
    vector<int> inputVectorInt = {3, 4, 4, 5, 1, 0, 7, 9, 10};
    mergeSort<int>(inputVectorInt);
    for (int ele : inputVectorInt)
        cout << ele << endl;

    // Double case
    vector<double> inputVectorDouble = {3.7878, 4.45444, 4.9999, 5.7878, 1.7, 0, 7, 9.2, 10};
    mergeSort<double>(inputVectorDouble);
    for (double ele : inputVectorDouble)
        cout << ele << endl;

    // String case
    vector<string> inputVectorString = {"yes", "yyess", "root", "no", "pop", "push"};
    mergeSort<string>(inputVectorString);
    for (string ele : inputVectorString)
        cout << ele << endl;
}