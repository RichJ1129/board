/*********************************************************************
 ** Author: Richard Joseph
 ** Date: 3/13/19
 ** Description: Class Declaration for SBoard
 *********************************************************************/

#ifndef SBoard_hpp
#define SBoard_hpp

#include <iostream>

class SBoard
{    
private:
    int tokensPlaced;
    char coordArray[10][10];
    
public:
    SBoard();
    int getNumTokens();
    int placeToken(int, int);
    void readPlacementsFromFile(std::string);
    void displayBoard();
    int countSquares(int, int);
};


#endif /* SBoard_hpp */
