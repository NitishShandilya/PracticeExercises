//
// Created by Nitish Mohan Shandilya on 7/14/20.
//

#include <deque>
#include <queue>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct MyClass {
    int a =2;
   MyClass() {
       cout << "\nConstructor Called!\n";
   }
   MyClass(const int input) : a(input) {
       cout << "\nParametrized constructor called!\n";
   }
   ~MyClass() {
       cout << "\nDestructor Called!\n";
   }
   /*MyClass& operator = (const MyClass& other) {
       cout << "\nCopy assignment operator called!\n";
       this->a = other.a;
   }
   MyClass(const MyClass& other) {
       cout << "\nCopy constructor called!\n";
       this->a = other.a;
   }*/


   /*bool operator < (const MyClass& other) const {
       return this->a > other.a;
   }*/

    /*bool operator == (const MyClass& other) const {
        return this->a == other.a;
    }*/

   struct Comp {
     bool operator () (const MyClass& other1, const MyClass& other2) const {
         return other1.a > other2.a;
     }
   };

};

bool myClassFunc(const MyClass& myClass) {
    return myClass.a == 0;
}

void testVector() {

    deque<MyClass> vec;
    //int arr[5] = {1,2,3,4,5};
    //vec.insert(vec.end(),arr, arr+5);
    //vec.resize(3);
    //MyClass myClass;
    vec.emplace(vec.end());
    vec.emplace(vec.end());
    vec.emplace(vec.end());
    //vec.push_back();
    //vec.push_back(4);
    for (auto it = vec.rbegin(); it!= vec.rend(); ++it) {
        cout << it->a << endl;
    }
    /*for (int ele : vec) {
        cout << ele;
    }*/

    /*char d = 'a';
    //signed char c = static_cast<signed char>(i);
    //cout << "Size of char: " << sizeof(c) << " Value is: "<< +c << endl;
    cout << "Size of short: " << sizeof(d) << " Value is: "<< int(d) << endl;
    cout << endl;*/
    vec.at(1).a = 2;
    cout << "Size: " << vec.size() << endl ;
    //<< "Capacity: " << vec.capacity() << endl;
    vec.erase(remove_if(vec.begin(), vec.end(), myClassFunc), vec.end());
    //vec.shrink_to_fit();
    cout << "Max Size: " << vec.max_size() << endl ;
    //<< "Capacity: " << vec.capacity() << endl;
    vec.clear();
    cout << "Size: " << vec.size() << endl ;
    //<< "Capacity: " << vec.capacity() << endl;
}

void testList() {
    list<MyClass> mList;
    //mList.push_back(3);
    //mList.push_front(2);

    //mList.insert(mList.end(), 4);
    //vector<int> vec = {1,2,3,9};

    //auto iter = mList.before_begin();
    //mList.insert(iter, vec.begin(), vec.end());
    mList.emplace_front();
    //mList.emplace_after(iter);
    mList.emplace_front();
    mList.emplace(mList.begin());

    //cout << "List Size: " << mList.size() << endl;

    /*for (list<int>::const_iterator it = mList.cbegin(); it != mList.cend(); ++it) {
        cout << *it << endl;
    }*/

    list<int> mList2;
    auto iter2 = mList.begin();
    advance(iter2,2);

    //mList2.splice(mList2.begin(),mList, mList.begin(), iter2);

    cout << "Next List\n";
    for (auto it = mList2.cbegin(); it != mList2.cend(); ++it) {
        cout << *it << endl;
    }

    /*list<int> mList3(mList);
    for (list<int>::const_iterator it = mList3.cbegin(); it != mList3.cend(); ++it) {
        cout << *it << endl;
    }*/

    for (auto it = mList.cbegin(); it != mList.cend(); ++it) {
        cout << it->a << endl;
    }


    auto iter12 = mList.begin();
    advance(iter12,2);
    iter12->a = 2;
    //mList.erase_after(mList.begin());
    cout << "First List" << endl;
    //cout << "List Size: " << mList.size() << endl;
    for (auto it = mList.cbegin(); it != mList.cend(); ++it) {
        cout << it->a << endl;
    }


}

void testSet() {
    /*set<MyClass> s;

    vector<MyClass> vec;
    vector<int> intVec = {1,11,3,4,5,6};
    for (auto it = intVec.begin(); it != intVec.end(); ++it) {
        vec.emplace_back(*it);
    }
    //MyClass::Comp compObj;
    //sort(vec.begin(), vec.end(), compObj);

    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << it->a << endl;
    }

    s.insert(vec.begin(), vec.end());
    s.emplace();
    auto it = s.equal_range(11);
    //if (it != s.end())
    if (it.first == s.end() && it.second == s.end())
        cout << "Element found" << it.first->a << endl;
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << it->a << endl;
    }*/

    set<string> s;
    s.insert({"Hello", "Bello", "Hello"});

    auto it = s.find("Bello");
    if (it != s.end())
        cout << *it;
    auto inserted = s.insert("Hello");

    cout << inserted.second << endl;

    for (string ele : s) {
        cout << ele << "\n";
    }
    unsigned char erased = s.erase("Hello");
    cout << erased << "size of size_t: " << sizeof(erased);

};

void testMap() {
    multimap<int, bool> myMap;
    myMap.insert({3,false});
    myMap.emplace(4,false);
    myMap.insert({3, true });
    if (myMap.find(5) != myMap.end()); myMap.insert({5, true});
        cout << "Done";

    auto range = myMap.equal_range(3);
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << " <-> " << it->second << endl;
    }

    for (auto ele : myMap) {
        cout << ele.first << " -> " << ele.second << endl;
    }
    auto found = myMap.find(88);
    if (found != myMap.end())
        cout << "Found";

}

void testUnorderedSet() {
    unordered_set<int> s;
    s.insert(34);
    s.insert(4556);
    for (int ele : s) {
        cout << ele << endl;
    }
    unsigned int it = s.erase(34);
    cout << it;
}

void testPriorityQueue() {
    priority_queue<MyClass, vector<MyClass>, MyClass::Comp> queue;
    queue.emplace(3);
    queue.emplace(5);
    queue.emplace(4);
    queue.emplace(1);
    const MyClass myClass = queue.top();
    queue.pop();
    cout << myClass.a;


}

void testSTLs() {
    //testVector();
    //testList();
    //testDeque();
    //testForwardList();
    //testSet();
    //testMap();
    //testUnorderedSet();
    /*testUnorderedMap();
    testUnorderedMultiSet();
    testUnorderedMultiMap();
    testMultiSet();
    testMultiMap();
    testStack();
    testQueue();*/
    testPriorityQueue();

}