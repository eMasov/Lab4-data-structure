#include <vector>
#include <cstdio>
#include <iostream>
#include <cmath>

struct Node{   
    int key;
    Node* next;

    Node () {
        next = nullptr;
    }
};


struct Set{
    /*Set(){
        size = 0;
        capacity = 101;
        list_ptr = new Node* [capacity];
        for (size_t idx = 0; idx != capacity; ++idx) {
            list_ptr[idx] = nullptr;
        }
    }*/
    //public:
    Node** list_ptr;
    size_t capacity;
    size_t size;
    Set(size_t capacity){
        size = 0;
        this->capacity = capacity;
        list_ptr = new Node* [capacity];
        for (size_t i = 0; i < capacity; i++) {
            list_ptr[i] = nullptr;
        }
    }
};

Set& set_insert(Set& set, int key);

int hash(Set& set, int n){
    return abs(n % set.capacity);
}

Set set_new(int capacity = 101){
    return Set(capacity);
}

Set& rehash(Set& set){
    Set new_set(10 * set.size);

    for (size_t idx = 0; idx != set.size; ++idx){
        Node* ptr = set.list_ptr[idx];
        while(ptr){
            set_insert(new_set, ptr->key);
            ptr = ptr->next;
        }
    }
    new_set.size = set.size;
    Set& new_set_link = new_set;
    return new_set_link;    
}

bool set_is_empty(Set& set){
    for (size_t idx = 0; idx != set.capacity; ++idx){
        if (set.list_ptr[idx]){
            return false;
        }
    }
    return set.size == 0;
}

int set_example(Set& set){
    if (set_is_empty(set)){
        return 0;
    }
    for (unsigned idx = 0; idx != set.capacity; ++idx){
        if (set.list_ptr[idx]){
            return set.list_ptr[idx]->key;
        }
    }
    return 0;
}

bool set_contains(Set& set, int key){
    int idx = hash(set, key);
    Node* ptr = set.list_ptr[idx];
    while (ptr){
        if (ptr->key == key){
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

Set& set_insert(Set& set, int key){
    if (set_contains(set, key)){
        return set;
    }
    int idx = hash(set, key);
    Node* ptr = set.list_ptr[idx];
    Node* new_node = new Node();
    new_node->next = ptr;
    new_node->key = key;

    set.list_ptr[idx] = new_node;
    ++set.size;

    float size = set.size;
    float capacity = set.capacity;
    float load_factor = size / capacity;
    if (load_factor >= 1.0){
        set = rehash(set);
    }
    return set;
}

Set& set_remove(Set& set, int key){
    if (!set_contains(set, key)){
        return set;
    }

    int idx = hash(set, key);
    Node* current = set.list_ptr[idx];
    Node* next = current->next;

    if (current->key == key){
        set.list_ptr[idx] = next;
        delete current;
    }
    
    while(next && next->key != key){
        current = current->next;
        next = next->next;
    }
    
    
    current->next = current->next;
    delete next;
    --set.size;
    return set;
}

Set& set_erase(Set& set){
    set.size = 0;
    for (size_t idx = 0; idx != set.capacity; ++idx){
        Node* ptr = set.list_ptr[idx];
        while(ptr){
            Node* tmp = ptr;
            ptr = ptr->next;
            delete tmp;
        }
        set.list_ptr[idx] = ptr;
    }
    return set;
}