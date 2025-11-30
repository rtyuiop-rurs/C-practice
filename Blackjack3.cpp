#include<iostream>
#include "Random.h"
#include<array>
#include<algorithm>
#include<cassert>

struct Card{
    enum Rank{
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

    enum Suit{
        suit_hearts,
        suit_diamonds,
        suit_spades,
        suit_clubs,

        suit_count,
    };

    static constexpr std::array enum_rank{
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

    static constexpr std::array enum_suit {  suit_hearts,suit_diamonds,suit_spades,suit_clubs,};

    Rank rank{};
    Suit suit{};

    friend std::ostream& operator<<(std::ostream& out, const Card &card){
        static constexpr std::array rank_string {'A','2','3','4','5','6','7','8','9','J','Q','K'};
        static constexpr std::array suit_string {'H','D','S','C'};
        out << rank_string[card.rank] << suit_string[card.suit];
        return out;
    }

    int return_val(){
        static constexpr std::array card_value {11,2,3,4,5,6,7,8,9,10,10,10};
        return card_value[rank];
    }
};

class Deck{
    std::array <Card, 52> m_deck;
    std::size_t index_card{0};
    public:
    Deck(){
        std::size_t index{0};
        for(auto s : Card::enum_suit){
            for (auto r : Card::enum_rank){
                m_deck[index++] = Card{r,s};
            }
        }
    }

    void shuffle(){
        std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
    }

    Card dealCard(){
        assert(index_card != 52 && "Deck::dealCard ran out of cards");
        return m_deck[index_card++];
    }
};

struct Player{
    int score{0};
    int ace_counter{0};
};

namespace Settings{
    static constexpr int dealer_bust{17};
    static constexpr int player_bust{21};
};

bool dealerTurn(Player& dealer, Deck& deck){
    while(dealer.score < Settings::dealer_bust){
        Card card{deck.dealCard()};
        int card_val = card.return_val();
        dealer.score += card_val;
        std::cout<<"The dealer flips a "<<card<<" They now have: "<<dealer.score<<"\n";
        if(card_val == 11){
            dealer.ace_counter++;
        }
    }

    while(dealer.score > Settings::player_bust && dealer.ace_counter > 0){
        dealer.score -= 10;
        std::cout<<"Dealer current score is: "<<dealer.score<<"\n";
        dealer.ace_counter--;
    }

    if(dealer.score > Settings::dealer_bust){
        return false;
    }
    if(dealer.ace_counter > 0){
        dealer.score - 10;
    }
    return true;
}

bool playerTurn(Player& player, Deck& deck){
    char choice{'?'};
    while(player.score < Settings::player_bust){
        std::cout<<"(h) to hit, or (s) to stand: ";
        std::cin>>choice;
        if(choice == 'h'){
            Card card{deck.dealCard()};
            int card_val = card.return_val();
            player.score += card_val;
            std::cout<<"You were dealt "<<card<<" You now have: "<<player.score<<"\n";
            if(card_val == 11){
                player.ace_counter++;
            }
        }
        else if(choice == 's'){
            return false;
        }
    }

    while(player.score > Settings::player_bust && player.ace_counter > 0){
        player.score -= 10;
        std::cout<<"Your current score is: "<<player.score<<"\n";
        player.ace_counter--;
    }

    if(player.score > Settings::player_bust){
        return true;
    }
    if(player.ace_counter > 0 ){
        player.score - 10;
    }
    return false;
}

bool blackjack(int fair){
    Deck deck{};
    deck.shuffle();
    Player dealer{deck.dealCard().return_val()};
    std::cout<<"The dealer is showing: "<<dealer.score<<"\n";
    Player player{deck.dealCard().return_val() + deck.dealCard().return_val()};
    std::cout<<"You have score: "<<player.score<<"\n";

    if(playerTurn(player,deck)){
        std::cout<<"You went bust!\n";
        return false;
    }
    else if(!dealerTurn(dealer,deck)){
        std::cout<<"The dealer went bust!\n";
        return true;
    }
    else if(dealer.score > player.score){
        return false;
    }
    else if(dealer.score == player.score){
        fair++;
    }
    else{
        return true;
    }
    return false;
}

int main(){
    char choice{'f'};
    int fair{0};
    while(true){
        if(blackjack(fair)){
            std::cout<<"You win!\n";
        }
        else if(fair > 0){
            std::cout<<"Its a draw!\n";
        }
        else{
            std::cout<<"You lost!\n";
        }
        std::cout<<"Enter ('q') to quit and any letter to continue playing: ";
        std::cin>>choice;
        if(choice == 'q'){
            break;
        }
    }
    
}