#include "map.hpp"
#include <map>
#include <iostream>


int main()
{
    std::pair<char, int> a[5];
    
    a[1].first = 'z';
    a[1].second = 10;
    a[2].first = 'x';
    a[2].second = 22;
    a[3].first = 'y';
    a[3].second = 33;
    a[4].first = 'c';
    a[4].second = 44;
    a[0].first = 'b';
    a[0].second = 123222;

    // std::pair<char, int> b[4];
    // b[2].first = 'x';
    // a[2].second = 22;

    // ft::bstNode< std::pair<char, int> > root;
    // ft::bstNode< std::pair<char, int> > node1(a[1]);
    // ft::bstNode< std::pair<char, int> > node2(a[2]);
    // ft::bstNode< std::pair<char, int> > node3(a[3]);
    // ft::bstNode< std::pair<char, int> > node4(a[4]);


    // // root.addRecursive(&root, &node4);
    // // root.addRecursive(&root, &node2);
    // // root.addRecursive(&root, &node1);
    // // root.addRecursive(&root, &node3);


    // // root.addRecursive(&root, a[2]);
    // // root.addRecursive(&root, a[3]);
    // // root.addRecursive(&root, a[4]);
    // // root.printTree(&root);

    // std::map<char, int> testMap;

    // std::cout << "New Map\n";
    // std::cout << "Empty = " << testMap.empty() << std::endl;
    // std::cout << "Size = " << testMap.size() << std::endl;
    // std::cout << "Max Size = " << testMap.max_size() << std::endl;
    // testMap.insert(a[1]);
    // testMap.insert(a[2]);
    // std::map<char, int>::iterator it;
    // std::map<char, int>::iterator ite;
    // for(it = testMap.begin(); it != testMap.end(); ++it)
    // {
    //     std::cout << it->first << std::endl;
    // }
    // it = testMap.end();
    // it++;
    // it++;
    // testMap.insert(a[4]);
    // it--;
    // std::cout << "haa " << it->first << std::endl;
    // std::map<char, int> myMap;
    // std::map<char, int>::iterator it;

    ft::map<char, int> myMap;
    ft::map<char, int>::iterator it;
    std::cout << "New Map\n";
    std::cout << "Empty = " << myMap.empty() << std::endl;
    std::cout << "Size = " << myMap.size() << std::endl;
    std::cout << "Max Size = " << myMap.max_size() << std::endl;
    std::pair<ft::map<char, int>::iterator, bool> abc;
    abc = myMap.insert(a[1]);
    std::cout << abc.second << std::endl;
    abc = myMap.insert(a[2]);
    std::cout << abc.second << std::endl;
    abc = myMap.insert(a[4]);
    std::cout << abc.second << std::endl;
    abc = myMap.insert(a[3]);
    std::cout << abc.second << std::endl;
    abc = myMap.insert(a[0]);
    std::cout << abc.second << std::endl;

    std::cout << "start here : )" << std:: endl;
    for(it = abc.first; it != myMap.end(); ++it)
    {
        std::cout << "test" << it->first << std::endl;
    }
    std::cout << "Find z : \n";
    it = myMap.find(a[1].first);
    std::cout << "Key = " << it->first << " Value = " << it->second << std::endl;
    std::cout << "Find a : \n";
    it = myMap.find(a[4].first);
    std::cout << "Key = " << it->first << " Value = " << it->second << std::endl;
    myMap.testPrint();
    myMap.erase(it);
    myMap.testPrint();

    // std::cout << "Find O : \n";
    // it = myMap.find('O');
    // std::cout << "Key = " << it->first << " Value = " << it->second << std::endl;
    // ft::map<char, int> secondMap;

    // secondMap.insert(myMap.begin(), myMap.end());
    // for(it = secondMap.begin(); it != secondMap.end(); ++it)
    // {
    //     std::cout << "test" << it->first << std::endl;
    // }
    //     std::cout << "test2" << it->first << std::endl;

    // myMap.testPrint();
    // std::cout << "start here : )" << std:: endl;
    // for(it = myMap.begin(); it != myMap.end(); ++it)
    // {
    //     std::cout << it->first << std::endl;
    // }
    // it = myMap.end();
    // std::cout << "xd" << it->first << std::endl;
    // it--;
    // std::cout << it->first << std::endl;
    // it--;
    // std::cout << it->first << std::endl;
    // it--;
    // std::cout << it->first << std::endl;
    // it--;
    // std::cout << it->first << std::endl;
    // it--;
    // std::cout << it->first << std::endl;
    // std::cout << "xd" << it->first << std::endl;
    // it++;
    // std::cout << it->first << std::endl;
    // it++;
    // std::cout << it->first << std::endl;
    // it++;
    // std::cout << it->first << std::endl;
    // std::cout << it->second << std::endl;
    // it++;
    // std::cout << it->first << std::endl;

    
    // myMap.testPrint();

}