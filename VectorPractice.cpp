#include <iostream>

using namespace std;

class RedoStructure
{
    int a;

public:
    RedoStructure():a(0){}
    void setValue(const int newValue)
    { a = newValue; }
    const int getValue() const
    { return a; }
};

class VectorPractice
{
    RedoStructure *redoStructure;
    int *structureNumbers;


public:
    int size;
    void allocate(const int size);
    void resize(const int newSize);
    void deallocate();
    void print() const;
};

void VectorPractice::allocate(const int sizeToAllocate) {
    redoStructure = (RedoStructure*)malloc(size*sizeof(class RedoStructure));
    structureNumbers = (int*)malloc(size*sizeof(int));
    size = sizeToAllocate;
}

void VectorPractice::resize(const int newSize) {
    redoStructure = (RedoStructure*)realloc(redoStructure, newSize*sizeof(class RedoStructure));
    structureNumbers = (int*)realloc(structureNumbers, newSize*sizeof(int));
    size = newSize;
}

void VectorPractice::deallocate() {
    if (redoStructure != NULL)
        free(redoStructure);

    if (structureNumbers != NULL)
        free(structureNumbers);
}

void VectorPractice::print() const {
    for (int i=0 ; i<size; ++i)
    {
      cout << "Address is: " << (redoStructure + i)  << "Value is: " << (redoStructure + i)->getValue() << endl;
    }
}