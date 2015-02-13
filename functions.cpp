//Programmer: Ryan Vasquez
//Date: october 17, 2013
//Class: CS53 section F Eric Barnes
//Purpose: The functions.cpp file contains the function definitions
// for the function prototypes in the function.h file. It lets
//the programmer simulate a dart shooting game when he/she includes
//the function.h file.
#include "functions.h"

using namespace std;

void play(const string sounds[], float array_scores[], const int beers)
{
  for(int i = 0; i < NUMBERSHOTS; i++)//The for loop will fill up every memory
  //location in the array.
  {
    srand(time(NULL));
    float angle_x;
    float angle_y;
    float x_coord;
    float y_coord;
    int sound_number;
    angle_x = rand()%(4*beers)-(2*beers);
    angle_x = angle_x*(PI/180.0);
    angle_y = rand()%(4*beers)-(2*beers);
    angle_y = angle_y*(PI/180.0);
    x_coord = (WALLDISTANCE*sin(angle_x))/cos(angle_x);
    y_coord = (WALLDISTANCE*sin(angle_y))/(cos(angle_y)*cos(angle_x));
    array_scores[i] = sqrt((x_coord*x_coord)+(y_coord*y_coord));
    x_coord = (static_cast<float>((static_cast<int>(x_coord*10))%100))/10;
    //This line of code will make the x_coord only have one decimal place
    //The static casts are needed because the mod operator only works with
    //integers
    y_coord = (static_cast<float>((static_cast<int>(y_coord*10))%100))/10;
    cout<<"x = "<<x_coord<<", y = "<<y_coord<<"       score = ";
    cout<<((static_cast<float> //This code limits the output of the score to
            //only 1 decimal without changing the value of the score in the
            //array.
                      ((static_cast<int>(array_scores[i]*10))%100))/10);

    if ((static_cast<int>(array_scores[i]))< 4)//This line of code ensures
    //that if the player shoots more than 4 feet from the bullseye that
    //he does not walk off of the sound array.
    {
      sound_number = (static_cast<int>(array_scores[i]));
    }
    else
    {
      sound_number = 4;
    }
    cout<<"  "<<sounds[sound_number];
    cout<<endl;
    sleep(1);//The sleep function will make the loop wait a second so that
    //when the random number is seeded again it will be seeded a different
    //number.
  }
}

void play(float array_scores[])
{
  for(int i = 0; i < NUMBERSHOTS; i++)
  {
    srand(time(NULL));
    float score;

    score = static_cast<float>(rand()%(56))/10;
    //The random number is modded by 56 so that the random number is between
    //0 and 55 and then static casted to a float and divided by 10 so that
    //the resulting random number is between 0 and 5.5 with precision to the
    //nearest 10th.
    array_scores[i] = score;
    cout<<"You score is :"<<score<<endl;
    sleep(1);
  }
}

void present_score(const float array_scores[])
{
  float average_dist = 0;
  float sum = 0;
  float score = 0;
  for(int i = 0; i < NUMBERSHOTS; i++)
  {
    average_dist += array_scores[i];
  }
  average_dist = average_dist/NUMBERSHOTS;
  for(int i = 0; i < NUMBERSHOTS; i++)
  {
    sum = sum+((average_dist-array_scores[i])*(average_dist-array_scores[i]));
  }
  score = (sum)/NUMBERSHOTS;
  cout<<"Here is your handicap score~! Score: "<<score<<endl;
}

void present_score(const float array_scores[], const int beers)
{
  float average_dist = 0;
  float score = 0;
  for(int i = 0; i < NUMBERSHOTS; i++)
  {
    average_dist += array_scores[i];
  }
  score = average_dist/NUMBERSHOTS;
  cout<<"Here is your regular score~! Score: "<<score<<endl;
}

void present_score(const int beers)
{
  int score;
  score = beers*.5;
  cout<<"Your score is "<<score<<endl;
}

int get_beers()
{
  int beers;
  cout<<"How many beers have you drank? ";
  cin>>beers;
  return beers;
}
