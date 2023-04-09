#include "card.hpp"
using namespace ariel;

//constructor:
Card::Card (Shape shape, Value value)
{
    this->shapeOfCard = shape;
    this->valOfCard = value;
};

//getters & setters
Shape Card::getShape()
{
    return shapeOfCard;
}

void Card::setShape(Shape shape)
{  
    this->shapeOfCard = shape;
}

Value Card::getVal()
{
    return this->valOfCard;
}

void Card::setVal(Value value)
{
    this->valOfCard = value;
}

//methods:
string Card::toString()
{
    return getVal()+ "of" + getShape();
}

int Card::cardCompare(Card c2)
{
    if (this->getVal() ==1 && c2.getVal()!=2) //Ace wins all but 2
    {
        return 1;
    }
    if (this->valOfCard !=2 && c2.getVal()==1)
    { //Ace wins all but 2
        return -1;
    }
    if (this->getVal()==c2.getVal()) //both cards are equal
    {
        return 0;
    }
    if (this->getVal() > c2.getVal()) //c1 wins
    {
        return 1;
    }
    else return -1; //c2 wins
}


