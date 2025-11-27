#include<algorithm>
#include<iostream>
#include<cassert>
#include<array>
#include "Random.h"


struct Card{
    enum Card_rank{
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_jack,
        rank_queen,
        rank_king,

        rank_count,
    };

    enum Card_suits{
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        suits_count,
    };

    Card_rank card{};
    Card_suits suit{};

    static constexpr std::array allSuits { suit_club, suit_diamond, suit_heart, suit_spade};
    static constexpr std::array allRanks { 
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_jack,
        rank_queen,
        rank_king,
    };

    friend std::ostream& operator<<(std::ostream& out, const Card& card){
        static constexpr std::array char_rank {'A', '2', '3','4','5','6','7','8','9','J','Q','K'};
        static constexpr std::array char_suit {'C','D','H','S'};
        out << char_rank[card.card] << char_suit [card.suit];
        return out;
    }

    int returnVal(){
        static constexpr std::array rank_value {11,2,3,4,5,6,7,8,9,10,10,10};
        return rank_value[card];
    }
};

class Deck{
    std::array <Card, 52> card_deck{};
    std::size_t index_cards{0};
    public:
    Deck(){
        std::size_t index{0};
        for(auto s : Card::allSuits){
            for(auto r : Card::allRanks){
                card_deck[index++] = Card{r,s};
            }
        }
    }

    void shuffle(){
        std::shuffle(card_deck.begin(), card_deck.end(), Random::mt);
    }

    Card dealCard(){
        assert(index_cards != 52 && "Deck::dealCard ran out of cards");
        return card_deck[index_cards++];
    }
};

struct Player{
    int score{0};
};

namespace Settings{
    static constexpr int dealer_bust{17};
    static constexpr int player_bust{21};
};

bool dealer_turn(Deck& deck, Player& dealer){
    while(dealer.score < Settings::dealer_bust){
        Card card{deck.dealCard()};
        dealer.score += card.returnVal();
        std::cout<<"The dealer flips a "<<card<<" They now have: "<<dealer.score<<"\n";
    }
    if(dealer.score > Settings::dealer_bust){
        std::cout<<"Dealer went bust!\n";
        return false;
    }
    return true;
}

bool player_turn(Deck& deck, Player& player){
    char c{'?'};
    while(player.score < Settings::player_bust){
       std::cout<<"=============================\n";
       std::cout<<"(h) to hit, or (s) to stand: ";
       std::cin>>c;
       std::cout<<"=============================\n";
       if(c == 'h'){
            Card card{deck.dealCard()};
            player.score += card.returnVal();
            std::cout<<"You flips a "<<card<<" You now have: "<<player.score<<"\n";
        }
        if(c == 's'){
            return false;
        }
    }
    if(player.score > Settings::player_bust){
        return true;
    }
    return false;
}

bool BlackJack(){
    Deck deck{};
    deck.shuffle();
    Player dealer{deck.dealCard().returnVal()};
    std::cout<<"The dealer is showing: "<<dealer.score<<"\n";
    Player player{deck.dealCard().returnVal() + deck.dealCard().returnVal()};
    std::cout<<"You are showing: "<<player.score<<"\n";

    if(player_turn(deck,player)){
        return false;
    }
    if(!dealer_turn(deck,dealer)){
        return true;
    }
    if(player.score > dealer.score){
        return true;
    }
    return false;
}

int main()
{
    char choice{'?'};
    while(true){
        if(BlackJack()){
            std::cout<<"You win!\n";
        }
        else{
            std::cout<<"You lost!\n";
        }
        std::cout<<"Enter letter 'q' to quit and any letter to continue: ";
        std::cin>>choice;
        if(choice == 'q'){
            break;
        }
    }
}



