//
//  main.cpp
//  BinaryTree
//
//  Created by Wolfgang Kraske on 2/6/15.
//  Copyright (c) 2015 Wolfgang Kraske. All rights reserved.
//

#include <iostream>
#include "BTree/BTree/BTree.cpp"

int main(int argc, const char * argv[]) {
    
    typedef Node<int> ND;
    

    std::cout << "Print this!" << std::endl;
    
    Node<int> na(4);
    std::list<Node<int>> ll{};

    ll.push_back(Node<int>(4));
    ll.push_back(Node<int>(1));
    ll.sort([](Node<int> a, Node<int> b) { return a < b; });
    std::array<int,8> li{ 19, 4, 3, 7, 11, 5, 17, 13 };
    std::sort(li.begin(), li.end(), [](const int& a, const int& b) { return a < b; });
    std::array<Node<int>, 4> ln{  Node<int>(4), Node<int>(1), Node<int>(7), Node<int>(11) };
    std::sort(ln.begin(), ln.end(), [](Node<int> a, Node<int> b) { return a < b; });
    //    ll.sort<compare<int>>();

    Node<int> n1(7);
    Node<int> n2(6);
    
    std::cout << ((n1 < n2) ? "n1 < n2" : "n2 <= n1") << std::endl;
    std::cout << ((n1 > n2) ? "n1 > n2" : "n2 >= n1") << std::endl;
    std::cout << ((n1 == n2) ? "n1 == n2" : "n2 != n1") << std::endl;

    std::cout << "N1: " << n1 << " N2: " << n2 << std::endl;
    n1 = n2;
    std::cout << "N1: " << n1 << " N2: " << n2 << std::endl;

    std::function<int(int)> f;
    
    f = [&f](int x) {
        if(x < 2) return 1;
        return x * f(x-1);
    };
    
    std::cout << f(5) << std::endl;
    
    std::list<int> testVals{7,6,11,8,13,17,19,23,29,2};
    for(int val : testVals) {
        na + Node<int>(val);
        std::cout << " : " << na.totalLevels << " : " << na.totalCardinality << " : " << na.totalWeight << " : " << na.weightDiff() << " TN: " << na << std::endl;
    }
    
    na.print();

    na.~Node();
    
    return 0;
}
