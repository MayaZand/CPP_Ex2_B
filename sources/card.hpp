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
      /*constructor: */
      Card (Shape shape, Value value);
      
      /*getters & setters: */
      Shape getShape();
      //void setShape(Shape shape);
      Value getVal();
      //void setVal(Value value);

      /*methods: */
      string toString();
      int cardCompare(Card c2);
      string enumShapeToString (Shape shape);
      string enumValToString (Value val); 

    }; 
}
