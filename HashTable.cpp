//
// Created by Nitish Mohan Shandilya on 6/29/20.
//

#include "LinkedList.cpp"

struct KeyNotFoundException : exception {
    const char* what() const noexcept {
        return "Key Not Found!!";
    }
};

struct DuplicateKeyException : exception {
    const char* what() const noexcept {
        return "Duplicate Key!!";
    }
};

template <typename keyType, typename valueType>
class HashNode {
public:
    keyType key;
    valueType value;

    HashNode(const keyType inputKey, const valueType inputValue) :
        key(inputKey), value(inputValue) {}
    bool operator == (const HashNode<keyType, valueType>& op) {
        return this->key == op.key;
    }

};

template <typename keyType, typename valueType>
class HashTable {
    vector<LinkedList<HashNode<keyType, valueType>>*> mData;
    int mNumberOfEntries;

    int hashFunction(keyType key) {
        return key % mNumberOfEntries;
    }

public:
    HashTable(const int numberOfEntries) : mNumberOfEntries(numberOfEntries) {
        mData.resize(numberOfEntries, nullptr);
        mData.push_back(nullptr);
    }
    void put(keyType key, valueType value);
    valueType get(keyType key);
    void print();
    void remove(keyType key);
};

template <typename keyType, typename valueType>
void HashTable<keyType, valueType>::put(keyType key, valueType value) {
    HashNode<keyType, valueType> newNode(key, value);

    int hashIndex = hashFunction(key);
    LinkedList<HashNode<keyType, valueType>>* entry = mData[hashIndex];

    if (entry == nullptr) {
        entry = new LinkedList<HashNode<keyType, valueType>>();
        mData[hashIndex] = entry;
    }


    Node<HashNode<keyType, valueType>>* temp = entry->head;
    while (temp!= NULL) {
        if (temp->data.key == key) {
            throw DuplicateKeyException();
        }
        temp = temp->next;
    }

    entry->addNode(newNode);
};

template <typename keyType, typename valueType>
valueType HashTable<keyType, valueType>::get(keyType key) {
    int hashIndex = hashFunction(key);
    LinkedList<HashNode<keyType, valueType>>* entry = mData[hashIndex];

    if (entry == nullptr) throw KeyNotFoundException();

    Node<HashNode<keyType, valueType>>* temp = entry->head;

    while (temp!= NULL) {
        if (temp->data.key == key) {
            return temp->data.value;
        }
        temp = temp->next;
    }
    throw KeyNotFoundException();
};

template<typename keyType, typename valueType>
void HashTable<keyType, valueType>::print() {
    for (auto it = mData.begin(); it != mData.end(); it++) {
        if (*it != nullptr) {
            cout << "Printing element: " << endl;
            Node<HashNode<keyType, valueType>>* temp = (*it)->head;
            while (temp != NULL) {
                cout << temp->data.key << " -> " << temp->data.value << endl;
                temp = temp->next;
            }
        }
    }
};

template <typename keyType, typename valueType>
void HashTable<keyType, valueType>::remove(keyType key) {
    const int index = hashFunction(key);
    LinkedList<HashNode<keyType, valueType>>* entry = mData[index];
    int keyFound = false;

    if (entry == nullptr) throw KeyNotFoundException();
    Node<HashNode<keyType, valueType>>* temp = entry->head;
    while (temp != NULL) {
        if (temp->data.key == key) {
            entry->deleteNodeByValue(temp->data);
            keyFound = true;
        }
        temp = temp->next;
    }
    if (!keyFound) throw KeyNotFoundException();
    if (entry->head == NULL) {
        delete mData[index];
    }
}

void testHashTable() {
    try {
        HashTable<int, int> hashTable(5);
        hashTable.put(3,4);
        cout << hashTable.get(3);
        hashTable.put(1,3);
        hashTable.put(6,7);
        hashTable.remove(6);
        hashTable.print();
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}