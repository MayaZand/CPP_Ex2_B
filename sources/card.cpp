#include "card.hpp"
using namespace ariel;

//constructor:
Card::Card (Shape shape, Value value)
{
    this->shapeOfCard = shape;
    this->valOfCard = value;
};

//getters & setters
// Shape Card::getShape()
// {
//     return shapeOfCard;
// }

void Card::setShape(Shape shape)
{  
    this->shapeOfCard = shape;
}

// Value Card::getVal()
// {
//     return valOfCard;
// }

void Card::setVal(Value value)
{
    this->valOfCard = value;
}

//methods:
string Card::toString()
{
    return getVal()+ "of" + getShape();
}



