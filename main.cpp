//
//  main.cpp
//  SBoard
//
//  Created by Richard Joseph on 3/6/19.
//  Copyright © 2019 Richard Joseph. All rights reserved.
//

#include <iostream>
#include "SBoard.hpp"
#include <string>

int main()
{
    SBoard sP ;
    sP.readPlacementsFromFile("File.txt");
    sP.displayBoard();
    std::cout << sP.getNumTokens() << std::endl;
    
    SBoard sb;
    std::cout << sb.placeToken(0,0) << std::endl;
    std::cout << sb.placeToken(0,2) << std::endl;
    std::cout << sb.placeToken(2,0) << std::endl;
    std::cout << sb.placeToken(2,2) << std::endl;
    std::cout << sb.placeToken(3,5) << std::endl;
    std::cout << sb.placeToken(5,5) << std::endl;
    std::cout << sb.placeToken(3,3) << std::endl;
    std::cout << sb.placeToken(5,3) << std::endl;
    std::cout << sb.placeToken(5,0) << std::endl;
    std::cout << sb.placeToken(0,5) << std::endl;

    sb.displayBoard();

    
    return 0;
}
