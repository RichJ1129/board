/*********************************************************************
 ** Author: Richard Joseph
 ** Date: 3/13/19
 ** Description: Class Implementation for SBoard
 *********************************************************************/

#include "SBoard.hpp"
#include <fstream>
#include <string>

/*********************************************************************
** Default Class constructor that initializes  all element of the
** array to being empty (denoted by '.') and initializes the number
** of tokens to zero
**********************************************************************/
SBoard::SBoard()
{
    tokensPlaced = 0;
    
    //For loop and nested for loop to intilize all the elements
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            coordArray[i][j] = '.';
        }
    }
}

int SBoard::getNumTokens()
{
    return tokensPlaced;
}

/*********************************************************************
 ** Method that takes the two ints row and column and places a token.
 ** If outside the range or if a token is already placed will return
 ** -1.
 **********************************************************************/
int SBoard::placeToken(int row, int column)
{
    /************************************************************************
    ** If statement that makes sure that row and column are the correct int
    ** values and that the array is placed in an empty space. Following
    ** statements to place token, increment tokensPlaced, and execute
    ** the conuntSquares fucntion and return the result
    *************************************************************************/
    if(row < 10 && row >= 0 && column < 10 && column >= 0 && coordArray[row][column] == '.')
    {
        coordArray[row][column] = 'O';
        ++tokensPlaced;
        int squares = countSquares(row, column);
        return squares;
    }
    
    else
    {
        return -1;
    }
}

//Method that takes the name of the file to read
void SBoard::readPlacementsFromFile(std::string placementFile)
{
    int row;
    int column;
    std::ifstream inputFile;
    inputFile.open(placementFile);
    
    //While loops that places first value read on the line to row and second value to column until the end of the file
    while(inputFile >> row >> column )
    {
        placeToken(row, column);
    }
    
    inputFile.close();
}

//Method that checks if a square has been made after placeToken has been executed
int SBoard::countSquares(int row, int column)
{
    int numSquares = 0; //Initializes numSquares to zero each time this method is called
    
    for(int i = 1; i < 10; i++)
        
    {
        // If token is placed in the top left
        if(coordArray[row + i][column] == 'O' && coordArray[row + i][column + i] == 'O' && coordArray[row][column + i] == 'O')
        {
            numSquares++;
        }
    
        // If token is placed in the top right
        if(coordArray[row][column - i] == 'O' && coordArray[row + i][column - i] == 'O' && coordArray[row + i][column] == 'O')
        {
            numSquares++;
        }
        
        //If token is placed in the bottom left
        if(coordArray[row - i][column] == 'O' && coordArray[row - i][column + i] == 'O' && coordArray[row][column + i] == 'O')
        {
            numSquares++;
        }
        
        //If token is placed in the bottom right
        if(coordArray[row - i][column] == 'O' && coordArray[row - i][column - i] == 'O' && coordArray[row][column - i] == 'O')
        {
            numSquares++;
        }
    }
    
    return numSquares; 
}


void SBoard::displayBoard()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            std::cout << coordArray[i][j] << " ";
        }
        std::cout << std::endl;

    }
}
