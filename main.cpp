//Programmer: Ryan Vasquez
//Date: october 17, 2013
//Class: CS53 section F Eric Barnes
//Purpose: This program uses the function.h file and functions
//in it to simulate a dart shooting game.
#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    float score_array[NUMBERSHOTS];
    int beers;
    char play_again;
    cout<<"Welcome to moes dart shooting game!"<<endl;
    do
    {
      beers = get_beers();
      if(beers < MINBEERS)
        present_score(beers);
      else if(beers <= MAXBEERS)
      {
        play(SOUNDS, score_array, beers);
        present_score(score_array, beers);
        present_score(score_array);
      }
      else
      {
        play(score_array);
        present_score(score_array);
      }
      cout<<"Do you want to play again? (enter y or n) ";
      cin>>play_again;
    }while(play_again == 'y');


    return 0;
}
