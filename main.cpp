/* 
 * File:   main.cpp
 * Author: javier
 *
 * Created on 2 de diciembre de 2012, 21:10
 */

#include <cstdlib>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int first[] = {5,10,15,20,25};
    sort(first,first+5);
    int second[] = {50,40,30,20,20,10};
    sort(second,second+5);
    
    set<int> myset;
    
    set_union(first, first+5, second, second+5, inserter(myset, myset.begin()));
    
    for (set<int>::iterator i=myset.begin(); i != myset.end(); i++) {
        cout << *i << ' ';
    }
    
    return 0;
}

