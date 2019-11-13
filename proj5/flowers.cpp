#define _CRT_SECURE_NO_DEPRECATE
#include "utilities.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int maxWords = 2;
const char WORDFILENAME[] = "/Users/akshay/Desktop/words.txt";

int countFlowers(char trialWord[], char word[])
{
    int flowers = 0;
    int length=(strlen(trialWord) < strlen(word)) ? strlen(trialWord) : strlen(word);
    for (int i = 0; i < length; i++)
    {
        if (trialWord[i] == word[i])
        {
            flowers++;
        }
    }
    return flowers;
}

int countBees(char trialWord[], char word[])
{
    int bees = 0;
    int length=(strlen(trialWord) < strlen(word)) ? strlen(trialWord) : strlen(word);
    for (int i = 0; i < length; i++)
    {
        //will only count bees if there isn't a flower at the index
        if (trialWord[i] != word[i])
        { 
            
        }
    }
    
    return bees;
}

bool allLower(char word[])
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (!islower(word[i]))
        {
            return false;
        }
    }
    return true;
}

int playOneRound(const char words[][7], int nWords, int wordnum)
{
//nWords = length of words list
//words = list of words
//wordnum = already randomly generated number for the index of word in words
    
    //error handling for edge cases, as directed by instructions
    if (nWords <= 0 || wordnum < 0 || wordnum >= nWords)
    {
        return -1;
    }
    
    //this code here will handle the part of game from right after the main tells the user the length of the word until the user specifies their guess word
    // return -1: error
    // return 0: not guessed the word
    // return 1: guessed the word
    
    //this function does not write the message about the player successfully determining the mystery wor
    char trialWord[100];
    int flowers = 0;
    int bees = 0;
    while (true)
    {
        cout << "Trial Word: ";
        cin.getline(trialWord, 100);
        if (allLower(trialWord) && strlen(trialWord) >= 4 && strlen(trialWord) <= 6)
        {
            // determine bees and flowers

            //int bees = countBees(trialWord, words[wordnum]);
            //int flowers = countFlowers(trialWord, words[wordnum]);
            cout << "Flowers: " << flowers << ", Bees: " << bees << endl;
            
        }
        
        else
        {
            cout << "Your trial word must be a word of 4 to 6 lower case letters." << endl;
        }
    }
        
        
    
    
    
    return 7;
}

void smallbergLoadingCode(int n)
{
    if (n == 2)
    {
        cout << "getWords successfully found the file and read its two words." << endl;
        cout << "You're ready to start working on Project 5." << endl;
    }
    else if (n == -1)
    {
        cout << "The path to your file of words is probably incorrect" << endl;
    }
    else
    {
        cout << "getWords found the file, but loaded " << n
                 << " words instead of 2" << endl;
    }
}

int main()
{
    
    
    char w[maxWords][7];
    int n = getWords(w, maxWords, WORDFILENAME);
    //smallbergLoadingCode(n);
    if (n < 1 || n > maxWords)
    {
        // should this also happen if n is greater than maxWords?
        cout << "No words were loaded, so I can't play the game.";
        return 1;
    }
    
    
    int numOfRounds;
    cout << "How many rounds do you want to play? ";
    cin >> numOfRounds;
    cin.ignore(10000, '\n');
    
    
    double scoreSum = 0;
    double average = 0;
    int minimum = 0;
    int maximum = 0;
    
    for (int round = 1; round <= numOfRounds; round++)
    {
        cout << endl;
        cout << "Round " << round << endl;
        
        int randIndex = randInt(0, maxWords-1);
        cout << "The mystery word is " << strlen(w[randIndex]) << " letters long." << endl;
        int roundScore = playOneRound(w, maxWords, randIndex);
        
        scoreSum += roundScore;
        average = scoreSum/round;
        if (round == 1 || roundScore < minimum)
        {
            minimum = roundScore;
        }
        if (round == 1 || roundScore > maximum)
        {
            maximum = roundScore;
        }
        
        cout.setf(ios::fixed);
        cout.precision(9);
        cout << "Average: " << setprecision(2) << average << ", minimum: " << minimum << ",  maximum: " << maximum << endl;
    }
    
    
    
    cout << endl;
}
