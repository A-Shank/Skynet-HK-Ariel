/*
Name: Anthony Shank
Course: CSC215 - C/C++ Programming I
Instructor: Doug Perez
Description: Skynet HK-Ariel is a software program that uses a binary search tree to detect the enemy at a random location.
*/

//Our includes for this project.
#include <iostream>
#include <ctime>
//declaring to use namespace std to avoid writing it out.
using namespace std;
//created a function called searchLoop with all the logic
void searchLoop() { 
    //seding the random number
    srand(static_cast<unsigned int>(time(0)));
    //Initializing the variable enemyLocation to a random number between 1-64.
    int enemyLocation =(rand() % 64) + 1;
    //Initialzing the searchGridHighNumber to 64.
    int searchGridHighNumber = 64;
    //Initializing the searchGridLowNumber to 1.
    int searchGridLowNumber = 1;
    //Initializing the searchCount to 0
    int searchCount = 0;
    //Initializing the binary search tree.
    int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
    
    cout << "Generate Random enemy location on a 8x8 grid..." << endl;
    cout << "The enemy is located at location #" << enemyLocation << " on a 8x8 grid with 1-64 sectors." << endl;
    cout << "Skynet HK-Ariel initializing software..." << endl; 
    cout << "===============================================" << endl;
    //Created a do while loop here.
    do{
        //Initializing the targetLocationPrediction inside the do statement.
        targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
        searchCount++; //adding 1 everytime the loop runs to searchCount.

        //if statement checks if the enemyLocation is greater than the targetLocationPrediction.
        if (enemyLocation > targetLocationPrediction ) {
            cout << "Skynet HK-Ariel did not find the enemy at location #" << targetLocationPrediction << endl;
            searchGridLowNumber = targetLocationPrediction; // Updating the searchGridLowNumber to the targetLocationPrediction.
            cout << "The new searchGridLowNumber is #" << searchGridLowNumber << endl;
            cout << "===============================================" << endl;
           
        }
        //else if statement checks if the enemyLocation is less than targetLocationPrediction
        else if (enemyLocation < targetLocationPrediction ) {
            cout << "Skynet HK-Ariel did not find the enemy at location #" << targetLocationPrediction << endl;
            searchGridHighNumber = targetLocationPrediction; //Updating the searchGridHighNumber with targetLocationPrediction.
            cout << "The new searchGridHighNumber is #" << searchGridHighNumber << endl;
            cout << "===============================================" << endl;
        }
        //Comes true if the enemy was found and displays it.
        else {
            cout << "Skynet HK-Ariel Software found the Enemy!" << endl;
            cout << "The enemy was found at location #" << targetLocationPrediction << endl; 
            cout << "The enemy was hiding at location #" << enemyLocation << endl;
            /* Here i decremented the searchCount by 1 since we want the accurate search Count. Due to else statement coming true it runs the loop an additional time and outputs the actual searchCount + 1.
            This means if we only did 5 searches and the loop runs again to go into the else statment the math would be this 5 + 1 = 6 which we do not want, we only want to count the actual searches. */
            cout << "Skynet HK-Ariel software took #" << (searchCount -1)<< " attempts" << endl; 
            cout << "===============================================";
        }
    } while (targetLocationPrediction != enemyLocation); //Runs the loop as long the condition: targetLocationPrediction is not equal to enemyLocation.
}


int main()
{   
    //Calling for the searchLoop function inside main function.
    searchLoop();
}

