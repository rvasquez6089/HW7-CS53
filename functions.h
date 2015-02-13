//Programmer: Ryan Vasquez
//Date: october 17, 2013
//Class: CS53 section F Eric Barnes
//Purpose: The functions.h file contains the fuction prototypes for the
//functions for the dart game. It also contains the global constants that the
//program uses.
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>


using namespace std;
const float PI = 3.14159;
const string SOUNDS[5] = {"ding ding ding!", "buuurrrrppp!", "Hey hey!",
  "Hmmmmmmm!", "DOH!"};
const int MINBEERS = 3;
const int MAXBEERS = 16;
const int NUMBERSHOTS = 14;//The number of shots the player gets to take
//with the dart gun.
const int WALLDISTANCE = 13;


void play(const string sounds[], float array_scores[], const int beers);
//Description:  The play function will allow the user to enter the number of
//beers they have drank and will let them attempt the shoot at the target
//Pre: A global const integer called NUMBERSHOTS and WALLDISTANCE must be
//present.
//The input score array can't be larger than NUMBERSHOTS cosntant and the sound
//array can't be more than 4 big.
//Post: This function will fill the score array with scores and will
//ouput the current score and x and y coordinates to the user.

void play(float array_scores[]);
//Description: The play() function will let a drunk user play
//by firing the gun for them and random choosing scores for the
//user.
//Pre: A global const integer called NUMBERSHOTS and WALLDISTANCE must be
//present.
//The score array has to be of size of NUMBERSHOTS const
//Post: THis function will fill the score array.
void present_score(const float array_scores[], const int beers);
//Description: The present_score() function will present a regular score to
//the sure based on the average of all of thier scores and the number of beers
//they drank
//Pre: A global const integer called NUMBERSHOTS must be
//present. The score array must be size of NUMBERSHOTS
//Post: The function will output the score to the screen and it will not
//change any of the input variables
void present_score(const float array_scores[]);
//Description: The present_score() function will present a handicapped score to
//the user using a secret formula based only on scores from their round.
//Pre:  A global constant integeger called NUMBERSHOTS and WALLDISTANCE must be
//present.
//The score array must be the size of NUMBERSHOTS const.
//Post: The function will output the handicapped score to the user.
void present_score(const int beers);
//Description: The present_score() function will display the integer part of the
//number of the beers the user drank times 1/2
//Pre: The beers input must be an int
//Post: A score is presented to the user based only on the number of beers the
//user drank.
int get_beers();
//Description: The get beers function will prompt the user for the number of
//beers the user has drank.
//Pre: None
//Post: The funciton will return an int from the user.
#endif // FUNCTIONS_H_INCLUDED
