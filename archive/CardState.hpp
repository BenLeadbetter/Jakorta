#ifndef GUARD__CARD_STATE_HPP
#define GUARD__CARD_STATE_HPP

#include "Card.hpp"


class CardState
{
    public:
        virtual ~CardState();
        virtual void whenClicked();
        virtual void enter(Card& card);
};

class InJakortaDeck : public CardState
{
    public:
        virtual void enter(Card& card);


    private:
        size_t m_DeckPosition;
};



#endif