#include <iostream>
#include <ctime>
#include <fstream>
#include "set.h"
#include <cassert>

void check_hash(Set& set, int a);
void check_set_is_empty();
void check_set_insert_and_set_contains();
void check_set_example();
void check_set_remove();
void check_set_erase();

int main(){
    Set q(101);
    check_hash(q, 1);
    check_set_is_empty();
    check_set_insert_and_set_contains();
    check_set_example();
    check_set_remove();
    check_set_erase();
    std::cout << "Done..." << std::endl;

    Set a(101);
    int step = 1300;
    std::fstream file1;
    file1.open("Hash_insert.csv", std::fstream::out);
    file1 << "N," << "Time s" << "\n";
    for (int N = 0; N <= 100 * step; N += step){
        //std::cout << "insert";
        time_t begin = clock();
        for (int i = 1; i <= N; ++i){
            a = set_insert(a, i);
        }
        double t = (double)(clock() - begin) / CLOCKS_PER_SEC;
        t /= N;
        file1 << N << "," << t  << "\n";
        std::cout << N << std::endl;
    }
    file1.close();
    
    
    Set b(101);
    std::fstream file2;
    file2.open("Hash_remove.csv", std::fstream::out);
    file2 << "N," << "Time s" << "\n";
    for (int N = 0; N <= 100 * step; N += step){
        for (int i = 1; i <= N; ++i){
            b = set_insert(b, i);
        }

        time_t begin = clock();
        for (int i = 1; i <= N; ++i){
            b = set_remove(b, i);
        }
        double t = (double)(clock() - begin) / CLOCKS_PER_SEC;
        t /= N;
        file2 << N << "," << t << "\n";
        std::cout << N << std::endl;
    }
    file2.close();
    
    std::fstream file3;
    file3.open("Hash_contains.csv", std::fstream::out);
    file3 << "N," << "Time s" << "\n";
    for (int N = 0; N <= 100 * step; N += step){
        time_t begin = clock();
        for (int i = 1; i <= N; ++i){
            set_contains(a, i);
        }
        double t = (double)(clock() - begin) / CLOCKS_PER_SEC;
        t /= N;
        file3 << N << "," << t << "\n";
        std::cout << N << std::endl;
    }
    file3.close();

    return 0;
}

void check_hash(Set& set, int a){
    assert(hash(set, a) == a % 101);
}

void check_set_is_empty(){
    Set a(101);
    assert(set_is_empty(a));
}

void check_set_insert_and_set_contains(){
    Set a(101);
    for (int idx = 0; idx != 104; ++idx){
        set_insert(a, idx);
    }
    assert(set_contains(a, 1) && a.capacity == 1010);
}

void check_set_example(){
    Set a(101);
    set_insert(a, 101);
    assert(set_example(a) == 101);   
}

void check_set_remove(){
    Set a(101);
    set_insert(a, 101);
    set_insert(a, 102);

    set_remove(a, 101);
    set_remove(a, 102);
    set_remove(a, 103);

    assert(!set_contains(a, 101) && !set_contains(a, 102));
}

void check_set_erase(){
    Set a(101);
    set_insert(a, 101);
    set_insert(a, 102);
    set_erase(a);
    assert(set_is_empty(a));
}