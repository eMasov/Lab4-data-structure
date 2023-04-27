#include <vector>
#include <cstdio>
#include <iostream>

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
        for (size_t idx = 0; idx != capacity; ++idx) {
            list_ptr[idx] = nullptr;
        }
    }

    /*Set(size_t capacity){
        size = 0;
        this->capacity = capacity;
        list_ptr = new Node* [capacity];
        for (size_t i = 0; i < capacity; i++) {
            list_ptr[i] = nullptr;
        }
    }*/
};

int hash(int n){
    return n % 101;
}

Set set_new(){
    return Set{};
}

bool set_is_empty(const Set& set){
    for (size_t idx = 0; idx != 101; ++idx){
        if (set.list_ptr[idx]){
            return false;
        }
    }
    return set.size == 0;
}

int set_example(Set const &set){
    if (set_is_empty(set)){
        return 0;
    }
    for (unsigned idx = 0; idx != 101; ++idx){
        if (set.list_ptr[idx]){
            return set.list_ptr[idx]->key;
        }
    }
    return 0;
}

bool set_contains(Set const& set, int key){
    int idx = hash(key);
    Node* ptr = set.list_ptr[idx];
    while (ptr){
        if (ptr->key == key){
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

Set& set_insert(Set &set, int key){
    if (set_contains(set, key)){
        return set;
    }
    int idx = hash(key);
    Node* ptr = set.list_ptr[idx];
    Node* new_node = new Node();
    new_node->next = ptr;
    new_node->key = key;

    set.list_ptr[idx] = new_node;
    ++set.size;
    return set;
}

Set& set_remove(Set &set, int key){
    if (!set_contains(set, key)){
        return set;
    }

    int idx = hash(key);
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

Set& set_erase(Set &set){
    set.size = 0;
    for (size_t idx = 0; idx != 101; ++idx){
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