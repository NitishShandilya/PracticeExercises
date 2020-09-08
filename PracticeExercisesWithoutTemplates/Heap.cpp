//
// Created by Nitish Mohan Shandilya on 7/13/20.
//

// [3,4,1,0,-1,8,6]

namespace PracticeExercisesWithoutTemplates {

void heapify(vector<int>& input, const int size, int index) {
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if (left < size && input[left] > input[largest])
        largest = left;
    if (right < size && input[right] > input[largest])
        largest = right;

    if (largest != index) {
        int temp = input[index];
        input[index] = input[largest];
        input[largest] = temp;
        heapify(input, size, largest);
    }
}

void constructHeap(vector<int>& input) {
    for (int i=(input.size()/2)-1; i>=0; --i)
        heapify(input, input.size(), i);
}

int extractMin(vector<int>& input) {
    if (input.empty()) throw;
    int top = input.at(0);
    int bottom = *(input.end() - 1);
    input.at(0) = bottom;
    input.pop_back();
    heapify(input, input.size(), 0);
    return top;
}

void testHeap() {
    vector<int> input = {3,4,1,0,-1,8,6};
    constructHeap(input);
    for (int ele : input)
        cout << ele << endl;

    cout << extractMin(input);
    cout << extractMin(input);

    for (int ele : input)
        cout << ele << endl;
}

}