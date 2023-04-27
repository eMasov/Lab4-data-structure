#include <iostream>
#include "set.h"
#include <cassert>

void check_hash(int a);
void check_set_is_empty();
void check_set_insert_and_set_contains();
void check_set_example();
void check_set_remove();
void check_set_erase();

int main(){
    check_hash(1);
    check_set_is_empty();
    check_set_insert_and_set_contains();
    check_set_example();
    check_set_remove();
    check_set_erase();
    std::cout << "Done" << std::endl;
    return 0;
}

void check_hash(int a){
    assert(hash(a) == a % 101);
}

void check_set_is_empty(){
    Set a;
    assert(set_is_empty(a));
}

void check_set_insert_and_set_contains(){
    Set a;
    set_insert(a, 103);
    assert(set_contains(a, 103));
}

void check_set_example(){
    Set a;
    set_insert(a, 101);
    assert(set_example(a) == 101);   
}

void check_set_remove(){
    Set a;
    set_insert(a, 101);
    set_insert(a, 102);

    set_remove(a, 101);
    set_remove(a, 102);
    set_remove(a, 103);

    assert(!set_contains(a, 101) && !set_contains(a, 102));
}

void check_set_erase(){
    Set a;
    set_insert(a, 101);
    set_insert(a, 102);
    set_erase(a);
    /*bool check = true;
    for (size_t idx = 0; idx != 101; ++idx){
        if (a.list_ptr[idx] != nullptr){
            check = false;
        }
    }*/
    //assert(a.size == 0);
    assert(set_is_empty(a));
}