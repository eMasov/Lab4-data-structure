#ifndef SET_h
#define SET_h

struct Node{   
    int key;
    Node* next;

    Node () {
        next = nullptr;
    }
};


struct Set{
    Node** list_ptr;
    size_t capacity;
    size_t size;

    Set(){
        size = 0;
        capacity = 101;
        list_ptr = new Node* [capacity];
        for (size_t i = 0; i < capacity; i++) {
            list_ptr[i] = nullptr;
        }
    }

    Set(size_t capacity){
        size = 0;
        this->capacity = capacity;
        list_ptr = new Node* [capacity];
        for (size_t i = 0; i < capacity; i++) {
            list_ptr[i] = nullptr;
        }
    }
};

int hash(Set& set, int n);
Set set_new();
bool set_is_empty(Set& set);
int set_example(Set& set);
bool set_contains(Set& set, int key);
Set& set_insert(Set& set, int key);
Set& set_remove(Set& set, int key);
Set& set_erase(Set& set);

#endif