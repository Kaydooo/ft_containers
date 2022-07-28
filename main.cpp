#include "inc/vector.hpp"
#include "inc/stack.hpp"
#include "inc/map.hpp"
#include "inc/set.hpp"

// #include <map>
// #include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <cstdlib>


int main(int argc, char **argv)
{
   
    std::vector<int> vec_one;

    for(int i = 0; i< 20 ; ++i)
        vec_one.push_back(i);

    std::vector<int>::iterator it = vec_one.begin();
    std::cout << *it << std::endl;
    std::vector<int>::iterator it2 = 10000 + it ;
    std::cout << *it2 << std::endl;

    
    // const int SIZE = 20;
    // ft::map<int, int> testMap;
    // // std::map<int, int> testMap;

    // for(int i = 0; i < SIZE; ++i)
    // {
    //     testMap.insert(ft::make_pair(i, i + 1));
    // }

    // // std::cout << std::endl <<  testMap.max_size() << std::endl;

    // // testMap.testPrint();
    // ft::map<int, int> testMap2;
    // ft::map<int, int>::iterator it;
    // ft::map<int, int>::iterator ite;
    // // std::map<int, int> testMap2;
    // // std::map<int, int>::iterator it;
    // // std::map<int, int>::iterator ite;
    // it = testMap.begin();
    // ite = testMap.end();

    // for(it = testMap.begin(); it != testMap.end(); ++it)
    // {
    //     testMap2.insert(*it);
    // }
    // std::cout << testMap2.count(3) << std::endl;
    // for(it = testMap2.begin(); it != testMap2.end(); ++it)
    //     std::cout  << it->first << " | ";
    // std::cout << std::endl;

    // std::cout << " map1 size = " << testMap.size() << "  Map2 size = " << testMap2.size() << std::endl;
    // // for(int i = 0; i < 20 ; ++i)
    // //     testMap2.erase(i);
    // // for(int i = 0; i < 20 ; ++i)
    // //     testMap.erase(i);
    // testMap.insert(ft::make_pair(30, 3 + 1));
    // // testMap2 = testMap;
    // // testMap2.testPrint();
    // std::cout << std::endl;
    // // testMap2[44];
    // std::cout << "at 1 :" <<  testMap2[1] << std::endl ;
    // std::cout << "Before Swap : " << std::endl;
    // testMap2.testPrint();
    // std::cout << std::endl;
    // testMap.testPrint();
    // // testMap2.swap(testMap);
    // std::cout << std::endl << "After Swap : " << std::endl;
    // testMap2.testPrint();
    // std::cout << std::endl;
    // testMap.testPrint();
    // std::cout << std::endl;


    // // ft::map<int, std::string> mp;
    // // mp[42] = "fgzgxfn";
	// // mp[25] = "funny";
	// // mp[80] = "hey";
	// // mp[12] = "no";
	// // mp[27] = "bee";
	// // mp[90] = "8";

    // // std::cout << "size: " << mp.size() << std::endl;
    // // std::cout << "max_size: " << mp.max_size() << std::endl;

    // // if (print_content)
    // // {
    // // typename ft::map<int, std::string>::const_iterator it = mp.begin(), ite = mp.end();
    // // std::cout << std::endl << "Content is:" << std::endl;
    // // for (; it != ite; ++it)
    // //     std::cout << "- key = " << it->first << " value = " << it->second << std::endl;
    // // std::cout << std::endl;
    // // }
    // // testMap2.erase(testMap2.begin(), testMap2.end());
    // // testMap2.erase(testMap2.begin());

    // // for(it = testMap2.begin(); it != testMap2.end(); ++it)
    // //     std::cout  << it->first << " | ";


    // // for(it = testMap.begin(); it != testMap.end(); ++it)
    // // {
    // //     std::cout << it->first << " : " << it->second << std::endl;
    // //     std::cout << testMap.size() << std::endl;
    // // }

    // // std::pair<char, int> a[11];
    
    // // a[0].first = '9';
    // // a[0].second = 123222;
    // // a[1].first = '7';
    // // a[1].second = 10;
    // // a[2].first = '8';
    // // a[2].second = 22;
    // // a[3].first = '6';
    // // a[3].second = 33;
    // // a[4].first = '1';
    // // a[4].second = 44;
    // // a[5].first = '0';
    // // a[5].second = 123;
    // // a[6].first = '4';
    // // a[6].second = 1234;
    // // a[7].first = '3';
    // // a[7].second = 1234;
    // // a[8].first = '2';
    // // a[8].second = 1234;
    // // a[9].first = 'A';
    // // a[9].second = 1234;

    // // // std::pair<char, int> b[4];
    // // // b[2].first = 'x';
    // // // a[2].second = 22;

    // // // ft::bstNode< std::pair<char, int> > root;
    // // // ft::bstNode< std::pair<char, int> > node1(a[1]);
    // // // ft::bstNode< std::pair<char, int> > node2(a[2]);
    // // // ft::bstNode< std::pair<char, int> > node3(a[3]);
    // // // ft::bstNode< std::pair<char, int> > node4(a[4]);


    // // // // root.addRecursive(&root, &node4);
    // // // // root.addRecursive(&root, &node2);
    // // // // root.addRecursive(&root, &node1);
    // // // // root.addRecursive(&root, &node3);


    // // // // root.addRecursive(&root, a[2]);
    // // // // root.addRecursive(&root, a[3]);
    // // // // root.addRecursive(&root, a[4]);
    // // // // root.printTree(&root);

    // // // std::map<char, int> testMap;

    // // // std::cout << "New Map\n";
    // // // std::cout << "Empty = " << testMap.empty() << std::endl;
    // // // std::cout << "Size = " << testMap.size() << std::endl;
    // // // std::cout << "Max Size = " << testMap.max_size() << std::endl;
    // // // testMap.insert(a[1]);
    // // // testMap.insert(a[2]);
    // // // std::map<char, int>::iterator it;
    // // // std::map<char, int>::iterator ite;
    // // // for(it = testMap.begin(); it != testMap.end(); ++it)
    // // // {
    // // //     std::cout << it->first << std::endl;
    // // // }
    // // // it = testMap.end();
    // // // it++;
    // // // it++;
    // // // testMap.insert(a[4]);
    // // // it--;
    // // // std::cout << "haa " << it->first << std::endl;
    // // // std::map<char, int> myMap;
    // // // std::map<char, int>::iterator it;
    // // // std::pair<std::map<char, int>::iterator, bool> abc;


    // // std::map<char, int> myMap;
    // // std::map<char, int>::iterator it;
    // // std::pair<std::map<char, int>::iterator, bool> abc;

    // // std::cout << "New Map\n";
    // // std::cout << "Empty = " << myMap.empty() << std::endl;
    // // std::cout << "Size = " << myMap.size() << std::endl;
    // // std::cout << "Max Size = " << myMap.max_size() << std::endl;
    // // abc = myMap.insert(a[0]);
    // // std::cout << abc.second << std::endl;
    // // abc = myMap.insert(a[1]);
    // // std::cout << abc.second << std::endl;
    // // abc = myMap.insert(a[2]);
    // // std::cout << abc.second << std::endl;
    // // abc = myMap.insert(a[3]);
    // // std::cout << abc.second << std::endl;
    // // abc = myMap.insert(a[4]);
    // // std::cout << abc.second << std::endl;
    // // abc = myMap.insert(a[5]);
    // // std::cout << abc.second << std::endl;
    // // abc = myMap.insert(a[6]);
    // // std::cout << abc.second << std::endl;
    // // abc = myMap.insert(a[7]);
    // // std::cout << abc.second << std::endl;
    // // abc = myMap.insert(a[8]);
    // // std::cout << abc.second << std::endl;
    // // abc = myMap.insert(a[9]);
    // // std::cout << abc.second << std::endl;

    // // std::cout << "start here : )" << std:: endl;
    // // for(it = abc.first; it != myMap.end(); ++it)
    // // {
    // //     std::cout << "test" << it->first << std::endl;
    // // }
    // // std::cout << "Find z : \n";
    // // it = myMap.find(a[1].first);
    // // std::cout << "Key = " << it->first << " Value = " << it->second << std::endl;
    // // std::cout << "Find c : \n";
    // // it = myMap.find(a[0].first);
    // // std::cout << "Key = " << it->first << " Value = " << it->second << std::endl;
    // // // myMap.testPrint();
    // // std::cout << "removed " << it->first << std:: endl;
    // // myMap.erase(it);
    // // // ++it;
    // // // std::cout << "removed " << it->first << std:: endl;
    // // // myMap.erase(it);
    // // // myMap.testPrint();
    // // for(it = myMap.begin(); it != myMap.end(); ++it)
    // //     std::cout << it->first << std::endl;

    // // // std::map<char, int> coppyMAP(myMap);
    // // // coppyMAP.testPrint();

    // // // coppyMAP.erase(coppyMAP.begin(), coppyMAP.end());
    // // // coppyMAP.testPrint();

    // // // std::map<char, int>  cpyMap(myMap.begin(), myMap.end());
    // // // std::cout << "Copy myMap  " << std::endl;
    // // // cpyMap.testPrint();
    // // // for(it = cpyMap.begin(); it != cpyMap.end(); ++it)
    // // //     std::cout << it->first << std::endl;
    // // // std::cout << "Find O : \n";
    // // // it = myMap.find('O');
    // // // std::cout << "Key = " << it->first << " Value = " << it->second << std::endl;
    // // // std::map<char, int> secondMap;

    // // // secondMap.insert(myMap.begin(), myMap.end());
    // // // for(it = secondMap.begin(); it != secondMap.end(); ++it)
    // // // {
    // // //     std::cout << "test" << it->first << std::endl;
    // // // }
    // // //     std::cout << "test2" << it->first << std::endl;

    // // // myMap.testPrint();
    // // // std::cout << "start here : )" << std:: endl;
    // // // for(it = myMap.begin(); it != myMap.end(); ++it)
    // // // {
    // // //     std::cout << it->first << std::endl;
    // // // }
    // // // it = myMap.end();
    // // // std::cout << "xd" << it->first << std::endl;
    // // // it--;
    // // // std::cout << it->first << std::endl;
    // // // it--;
    // // // std::cout << it->first << std::endl;
    // // // it--;
    // // // std::cout << it->first << std::endl;
    // // // it--;
    // // // std::cout << it->first << std::endl;
    // // // it--;
    // // // std::cout << it->first << std::endl;
    // // // std::cout << "xd" << it->first << std::endl;
    // // // it++;
    // // // std::cout << it->first << std::endl;
    // // // it++;
    // // // std::cout << it->first << std::endl;
    // // // it++;
    // // // std::cout << it->first << std::endl;
    // // // std::cout << it->second << std::endl;
    // // // it++;
    // // // std::cout << it->first << std::endl;

    
    // // // myMap.testPrint();

}


/* SWAP TEST */
// int main()
// {
//     ft::map<int, char> alice;
//     ft::map<int, char> bob;
//     alice.insert(std::make_pair(1, 'a'));
//     alice.insert(std::make_pair(2, 'b'));
//     alice.insert(std::make_pair(3, 'C'));
//     bob.insert(std::make_pair(7, 'Z'));
//     bob.insert(std::make_pair(8, 'Y'));
//     bob.insert(std::make_pair(9, 'W'));

 
//     auto print = [](std::pair<const int, char>& n) { 
//         std::cout << " " << n.first << '(' << n.second << ')'; 
//     };
 
//     // Print state before swap
//     std::cout << "alice:";
//     std::for_each(alice.begin(), alice.end(), print);
//     std::cout << "\n" "bob  :";
//     std::for_each(bob.begin(), bob.end(), print);
//     std::cout << '\n';
 
//     std::cout << "-- SWAP\n";
//     ft::swap(alice, bob);
 
//     // Print state after swap
//     std::cout << "alice:";
//     std::for_each(alice.begin(), alice.end(), print);
//     std::cout << "\n" "bob  :";
//     std::for_each(bob.begin(), bob.end(), print);
//     std::cout << '\n';
// }