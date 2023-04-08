#pragma once
#include <string>
using namespace std;


enum Shape {HEARTS, CLUBS, SPADES, DIAMONDS};
enum Value 
{ 
  ACE = 1, 
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT, 
  NINE, 
  TEN,
  JACK,
  QUEEN, 
  KING
  };

namespace ariel
{
    string shape; //CHECK IF NEEDED
    int num; //CHECK IF NEEDED

    class Card 
    {
      //fields - private by default
      Shape shapeOfCard; 
      Value valOfCard; 
      //int numOfCards = 13;
      //int numOfShapes = 4;
      
      public:
      //constructors & destructors
      Card (Shape shape, Value value);
      //~Card();

      //getters & setters
      Shape getShape() {return shapeOfCard;}
      void setShape(Shape shape);
      Value getVal() {return valOfCard;}
      void setVal(Value value);

      //methodes
      string toString();

    }; 
}