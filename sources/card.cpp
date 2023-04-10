#include "card.hpp"
using namespace ariel;

Card::Card (Shape shape, Value value)
{
    this->shapeOfCard = shape;
    this->valOfCard = value;
}

Shape Card::getShape()
{
    return shapeOfCard;
}

// void Card::setShape(Shape shape)
// {  
//     this->shapeOfCard = shape;
// }

Value Card::getVal()
{
    return this->valOfCard;
}

// void Card::setVal(Value value)
// {
//     this->valOfCard = value;
// }

string Card::toString()
{
    return enumValToString(getVal()) + " of " + enumShapeToString(getShape());
}

int Card::cardCompare(Card c2)
{
    if (this->getVal()==c2.getVal()) //both cards are equal
    {
        return 0;
    }
    else if ((this->getVal() ==1 && c2.getVal()!=2) || (this->getVal() > c2.getVal())) //Ace wins all but 2
    {
        return 1;
    }
    else
    { 
        return -1;
    }
}

string Card::enumShapeToString (Shape shape) 
{
    switch (shape)
    {
        case Shape::HEARTS:
            return "HEARTS";
        case Shape::CLUBS:
            return "CLUBS";
        case Shape::SPADES:
            return "SPADES";
        case Shape::DIAMONDS:
            return "DIAMONDS";
   
    }
}

string Card::enumValToString (Value val)  
{
    switch (val)
    {
        case Value::ACE:
            return "ACE";
        case Value::TWO:
            return "TWO";
        case Value::THREE:
            return "THREE";
        case Value::FOUR:
            return "FOUR";
         case Value::FIVE:
            return "FIVE";
         case Value::SIX:
            return "SIX";
         case Value::SEVEN:
            return "SEVEN";
         case Value::EIGHT:
            return "EIGHT";
         case Value::NINE:
            return "NINE";
         case Value::TEN:
            return "TEN";
         case Value::JACK:
            return "JACK";
         case Value::QUEEN:
            return "QUEEN";
         case Value::KING:
            return "KING";
    }
}


