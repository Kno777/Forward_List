#include <iostream>
#include "list.h"

int main()
{
    Forward_List<int> myList;
    myList.push_front(77);
    myList.push_front(55);
    myList.push_front(99);
    for(auto it = myList.begin(); it != myList.end(); ++it)
    {
        std::cout << *it << " ";
    }

    //Forward_List<int> myl__;
    //myl__ = myList;

    //std::cout << myl__.front();

    //Forward_List<int> ml1(myList);
    //std::cout << ml1.front();

    //Forward_List<int> init{12,34,56,67};
    //std::cout << init.front();
    
}