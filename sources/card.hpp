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
    class Card 
    {
      /*fields - private by default: */
      Shape shapeOfCard; 
      Value valOfCard; 
      
      public:
      /*
      constructor: 
      @param shape gets the shape of the card
      @param value gets the num value of the card
      */
      Card (Shape shape, Value value);
      
      /*methods: */

      /*
      @return the shape of the card
      */
      Shape getShape();

      /*
      @return the value of the card
      */
      Value getVal();

      /*
      @return a string that represents the card
      */
      string toString();

      /*
      this method get one card and compare it with another Card object.
      @param c2 is the card that the method compare with.
      @return 1 if c1 is stronger than c2, -1 if c2 is stronger than c1 and 0 otherwise
      */
      int cardCompare(Card c2);

      /*
      @return a string thay represents the enum word of the shape
      */
      string enumShapeToString (Shape shape);

      /*
      @return a string thay represents the enum word of the valye
      */
      string enumValToString (Value val); 
    }; 
}
