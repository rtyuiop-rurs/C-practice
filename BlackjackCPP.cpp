#include <algorithm> // for std::shuffle
#include <array>
#include <cassert>
#include <iostream>
#include "Random.h"
#include <assert.h>
struct Card{

    enum Ranks{
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,

        max_count,
    };

    enum Suit{
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };

    static constexpr std::array allRanks {rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
    };

    static constexpr std::array allSuits {suit_club,suit_diamond,suit_heart,suit_spade,};

    Ranks rank{};
    Suit suit{};

    friend std::ostream& operator<<(std::ostream& out, const Card &card){
        static constexpr std::array rankChar{
         'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' 
        };

        static constexpr std::array suitChar {'C', 'D', 'H', 'S'};
        out << rankChar[card.rank] << suitChar [card.suit];
        return out;
    }

    int Rankval(){
        static constexpr std::array <int, Card::max_count> getRankvalue { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
        return getRankvalue[rank];
    }
};


class Deck{
    std::array <Card, 52> m_cards {};
    std::size_t m_cardNextIndex {0};
    public:
        Deck(){
            std::size_t index {0};
            for(auto s : Card::allSuits){
                for(auto r : Card::allRanks){
                    m_cards[index++] = Card{r,s};
                }
            }
        }

        void shuffle(){
            std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
            m_cardNextIndex = 0;
        }

        Card dealCard(){
            assert(m_cardNextIndex != 52 && "Deck::dealCard ran out of cards");
            return m_cards[m_cardNextIndex++];
        }
        
};

struct Player{
    int score{0};
};


namespace Setting{
    constexpr int p_bust{21};
    constexpr int stop_draw{17};
}

bool DealerBust(Deck & deck, Player& dealer){
    while(dealer.score < Setting::stop_draw){
        Card card{deck.dealCard()};
        dealer.score += card.Rankval();
        std::cout<<"The dealer flips a : "<<card<<" now he has :"<<dealer.score<<"\n";
    }

    if(dealer.score > Setting::stop_draw){
        std::cout<<"Dealer went bust!!";
        return true;
    }
    return false;
}

bool PlayerBust(Deck& deck, Player& player){
    char action{'?'};
    while(player.score < Setting::p_bust){
        std::cout<<"(h) to hit, or (s) to stand: h: ";
        std::cin>>action;
        if(action == 'h'){
            Card card{deck.dealCard()};
            player.score += card.Rankval();
            std::cout<<"You flips a :"<<card<<" now you have: "<<player.score<<"\n";
        }
        else if(action == 's'){
            return false;
        }

        if(player.score > Setting::p_bust){
            std::cout<<"You went bust!!";
            return true;
        }
        return false;
    };
}

bool BlackJack(){
    Deck deck{};
    deck.shuffle();
    Player dealer {deck.dealCard().Rankval()};
    std::cout<<"The dealer is showing : "<<dealer.score<<"\n";
    Player player {deck.dealCard().Rankval() + deck.dealCard().Rankval()};
    std::cout<<"You are showing: "<<player.score<<"\n";

    if(PlayerBust(deck,player)){
        return false;
    }
    else if(DealerBust(deck,dealer)){
        return true;
    }

    if(player.score > dealer.score) return true;
};

int main(){
    if(BlackJack()){
        std::cout<<"You win!";
    }
    else{
        std::cout<<"You lose!";
    }
}
