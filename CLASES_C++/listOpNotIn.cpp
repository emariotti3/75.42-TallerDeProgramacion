#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>

std::vector<int>::iterator listIt;

template<>
std::vector<int> std::vector<int>::operator-(std::vector<int> &list) const{
    std::vector<int> not_in_list();
    for (listIt it = this->begin(); it != this->end(); ++it){
        bool has_element = false;
        listIt it2 = list.begin();
        while ( (!has_element) || (it2 != list.end() ){
            has_element = ((*it) == (*it2));
            it2++;
        }
        if (!has_element){
            not_in_list.push_back(*it);
        }
    }
    return not_in_list;
}
