#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include<algorithm>
#include"Random.h"

constexpr double lvlUP{35};
constexpr double dmgBoost{15};
constexpr double dfsBoost{10};

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class Monster{
    protected:
    std::string m_name;
    char m_type;
    double m_health;
    double m_attack;
    double m_defense;
    double m_current_Attack;
    double m_current_Defense;
    int expReward;
    double m_gold;

    public:
    Monster(const std::string_view name, const char type, double health, double attack, double defense, int exp, double gold)
    : m_name{name}, m_type{type}, m_health{health}, m_attack{attack}, m_defense{defense}, m_current_Attack{attack}, m_current_Defense{defense}, expReward{exp}, m_gold{gold}
    {}

    virtual ~Monster() = default;

    const std::string_view getName() const {return m_name;};
    char getSymbol() const {return m_type;};
    double getHealth() const {return m_health;};
    double getAttack() const {return m_current_Attack;};
    double getDefense() const {return m_current_Defense;}; 
    double getBaseAttack() const {return m_attack;};
    double getBaseDefence() const {return m_defense;};
    double getGold() const {return m_gold;};
    int getExpReward() const {return expReward;};

    void damageBoost(bool activate){
        if(activate == true){
            if(m_current_Attack == 150.00){
                std::cout<<"Attack can't go any higher for "<<m_name<<"\n";
            }
            m_current_Attack  = std::min(150.00, m_current_Attack + dmgBoost);
            std::cout<<"Attack increased temporarily by "<<m_current_Attack<<" for "<<m_name<<"\n";
        }
        else if(activate == false){
            if(m_current_Attack == 10.0){
                std::cout<<"Attack can't go any Lower for "<<m_name<<"\n";
            }
            m_current_Attack  = std::max(10.0, m_current_Attack - dmgBoost);
            std::cout<<"Attack Downed temporarily by "<<m_current_Attack<<" for "<<m_name<<"\n";
        }
    }

    void defenceBoost(bool activate){
        if(activate == true){
            if(m_current_Defense == 100.00){
                std::cout<<"Defence can't go any higher for "<<m_name<<"\n";
            }
            m_current_Defense = std::min(100.00, m_current_Defense + dfsBoost);
            std::cout<<"Defence increased temporarily by "<<m_current_Defense<<" for "<<m_name<<"\n";
        }
        else if(activate == false){
            if(m_current_Defense == 20.0){
                std::cout<<"Defence can't go any Lower for "<<m_name<<"\n";
            }
            m_current_Defense = std::max(20.0, m_current_Defense - dfsBoost);
            std::cout<<"Defence Downed temporarily by "<<m_current_Defense<<" for "<<m_name<<"\n";
        }
    }


    void clearBoost(){
       m_current_Attack = m_attack;
       m_current_Defense = m_defense;
    }

    void Attack(double attack){
        double damage = std::max(8.0,attack - m_current_Defense);
        m_health -= damage;
        std::cout<<"\n=====================================\n";
        std::cout<<damage<<" Amount of damage dealt!";
        std::cout<<"\n=====================================\n";
    }

    bool isDead(){
        return m_health <= 0;
    }

    virtual std::ostream& print(std::ostream& out) const  = 0;

    friend std::ostream& operator<<(std::ostream& out, const Monster& m1){
        m1.print(out);
        return out;
    }
};

class Player : public Monster{
    int m_level;
    int m_exp;
    public:
    Player(const std::string_view name, const char type = '@', double health = 150.00, double attack = 60.00, double defense = 60.00, int level = 1, int exp = 0, double gold = 0.0)
    : Monster{name, type, health, attack, defense, exp, gold}, m_level{level}, m_exp{exp}
    {}

    void gainXP(int amount){
        m_exp += amount;
        std::cout<<"You gained "<<amount<<" of EXP!\n";
        checkLevelUP();
    }

    void checkLevelUP(){
        bool level_up = false;
        int needed = 100 * m_level;

        while(m_exp >= needed){
            m_exp -= needed;
            m_level++;
            needed = 100 * m_level;
            level_up = true;
        }

        if(level_up){
            std::cout<<m_name<<" Leveled up!\n";
            onlevelUP();
            std::cout<< "\nName: "<< Player::getName() <<
            "\nHealth Points: "<<Player::getHealth()<<
            "\nAttack power: "<<Player::getAttack()<<
            "\nDefence Points: "<<Player::getDefense()<<
            "\nLevel: "<<Player::getLevel()<<"\n";
        }
    }

    void onlevelUP(){
        m_attack += lvlUP;
        m_defense += lvlUP;
        m_health += lvlUP;

        m_current_Attack = m_attack;
        m_current_Defense = m_defense;
    }

    void ChangeAttack(double boost){
        m_attack += boost;
        m_current_Attack = m_attack;
    }

    void ChangeDefense(double boost){
        m_defense += boost;
        m_current_Defense = m_defense;
        std::cout<<"Defence increased to "<<m_defense<<"\n";
    }

    int getLevel() const {return m_level;};

    bool hasWon(const char diff){
        switch(diff){
            case 'E' : return m_level == 15;
            break;
            case 'M' : return m_level == 25;
            break;
            case 'H' : return m_level == 35;
        }

        return false;
    }

    void gainGoldPlayer(double amount){
        m_gold += amount;
        std::cout<<m_name<<" gained "<<amount<<" of gold!\n";
    }

    void TakeGold(double amount){
        m_gold -= amount;
    }

    std::ostream& print(std::ostream& out) const override{
        out <<
        "\nName: "<< Player::getName() <<
        "\nHealth Points: "<<Player::getHealth()<<
        "\nAttack power: "<<Player::getAttack()<<
        "\nDefence Points: "<<Player::getDefense()<<
        "\nLevel: "<<Player::getLevel()<<
        "\nGold: "<<Player::getGold()<<"\n";
        return out;
    }
};

class Enemy : public Monster{
    public:
    Enemy(const std::string_view name, const char type, double health, double attack, double defense, int reward, double gold)
    : Monster{name, type, health, attack, defense, reward, gold}
    {}

    int getExp() const {return expReward;};

    enum Type{
        //Beta Enemies
        beta_Orc,
        beta_Goblin,
        beta_Spider,
        beta_Lizard,
        beta_Mantis,
        //Alpha Enemies
        alpha_Orc,
        alpha_Goblin,
        alpha_Spider,
        alpha_Lizard,
        alpha_Mantis,
        Max_Type,
    };

    private:
    static inline std::vector<std::unique_ptr<Monster>> MonsterData(){
        std::vector<std::unique_ptr<Monster>> data;
        //Beta Enemies
        data.push_back(std::make_unique<Enemy>("beta Orc", 'O', 100, 44, 55, 90, 20.0));
        data.push_back(std::make_unique<Enemy>("beta Goblin", 'G', 100, 50, 12, 85, 10.0));
        data.push_back(std::make_unique<Enemy>("beta Spider",'S', 98, 55, 10, 45, 15.0));
        data.push_back(std::make_unique<Enemy>("beta Lizard", 'L', 150, 30, 60, 70, 10.0));
        data.push_back(std::make_unique<Enemy>("beta Mantis", 'M', 70, 60, 20, 70, 15.0));

        data.push_back(std::make_unique<Enemy>("alpha Orc", 'O', 135, 79, 90, 125, 30.0));
        data.push_back(std::make_unique<Enemy>("alpha Goblin", 'G', 135, 85, 47, 120, 20.0));
        data.push_back(std::make_unique<Enemy>("alpha Spider",'S', 133, 95, 45, 80, 25.0));
        data.push_back(std::make_unique<Enemy>("alpha Lizard", 'L', 185, 65, 95, 105, 20.0));
        data.push_back(std::make_unique<Enemy>("alpha Mantis", 'M', 105, 133, 55, 105, 25.0));

        return data;
    };

    static inline std::vector<std::unique_ptr<Monster>> EnemyData = MonsterData();

    public:

    static std::unique_ptr<Monster> createEnemy(Type t){
        std::size_t index = static_cast<std::size_t>(t);
        if(index < EnemyData.size()){
            return std::make_unique<Enemy>(
                *static_cast<Enemy*>(EnemyData[index].get())
            );
        }
        return nullptr;
    }

    static std::unique_ptr<Monster> getRandomEnemy(char Type){
        int ran{0};
        if(Type == 'E'){
            ran  = Random::get(0, 4);
        }else if(Type == 'M'){
            ran = Random::get(5, Max_Type - 1);
        }
        else if(Type == 'H'){
            ran = Random::get(0, Max_Type -1);
        }
        std::size_t index{static_cast<std::size_t>(ran)};
        return std::make_unique<Enemy>(
            *static_cast<Enemy*>(EnemyData[index].get())
        );
    }


    std::ostream& print(std::ostream& out) const override{
        out <<
        "\nName: "<< Enemy::getName() <<
        "\nHealth Points: "<<Enemy::getHealth()<<
        "\nAttack power: "<<Enemy::getAttack()<<
        "\nDefence Points: "<<Enemy::getDefense();
        return out;
    }

};

void DealDamageEnemy(Monster& p1, Monster& m1){
    std::cout<<"\n=====================================\n";
    std::cout<<"You attacked the monster";
    std::cout<<"\n=====================================\n";
    m1.Attack(p1.getAttack());
    if(!m1.isDead()){
        std::cout<<m1.getName()<<" Health: "<<m1.getHealth()<<"\n";
    }
};

void DealDamagePlayer(Monster& m1, Monster& p1){
    std::cout<<"\n=====================================\n";
    std::cout<<m1.getName()<<" Attacked "<<p1.getName();
    std::cout<<"\n=====================================\n";
    p1.Attack(m1.getAttack());
    if(!p1.isDead()){
        std::cout<<p1.getName()<<" Health: "<<p1.getHealth()<<"\n";
    }
}

void Bide(Monster& p1, Monster& p2){
    std::cout<<p1.getName()<<" Bide their attack!\n";
    std::cout<<p2.getName()<<" Gets a free attack!\n";
    DealDamagePlayer(p2,p1);
    p1.damageBoost(true);
    p1.damageBoost(true);
}

void Brace(Monster& m1){
    std::cout<<"\n=====================================\n";
    std::cout<<m1.getName()<<"Braced for Impact!\n";
    m1.defenceBoost(true);
    std::cout<<"\n=====================================\n";
}

bool runAway(Monster& p1){
    if(Random::get(1,100)> 50){
        std::cout<<p1.getName()<<" Escaped!\n";
        return true;
    }
    std::cout<<"Failed to flee!\n";
    return false;
}


void insultEnemy(Monster& m1, Monster& p1){
   static const std::vector<std::string> insults {
        "Stupid", "Poopyhead", "Ugly", "Lame", 
        "Loser", "Idiot", "Childish", "Lanky",
        "Fat", "Flat", "Boss baby"
    };
    std::string Insultnames{insults[Random::get<std::size_t>(0,insults.size() - 1)]};
    std::cout<<"\n=====================================\n";
    std::cout<<p1.getName()<<" insulted "<<m1.getName()<<" by calling them "<<Insultnames;
    std::cout<<"\n=====================================\n";
    m1.damageBoost(false);
    std::cout<<m1.getName()<<" Attack lowered by one stage!\n";
}

enum class ActorAction{
    Attack,
    Shop,
    Flee,
    Bide,
    Insult,
    Brace,
    Invalid,
};

enum class Shop{
    Attack_Drink,
    Defense_Drink,
    Sword,
    Shield,
    Chest_Armor,
    Axe,
    Invalid,
};

void printRoscoeShop(){
    std::cout<<"\n==== WELCOME TO ROSCOE'S SHOP! ====\n";
    std::cout << "Choose:\n";
    std::cout << "1. Defense drink <100g> <Permanently increase defense by 10pts>\n";
    std::cout << "2. Attack drink  <100g> <Permanently increases attack by 10pts>\n";
    std::cout << "3. Sword         <300g> <Permanently increases attack by 35pts>\n";
    std::cout << "4. Shield        <300g> <Permanently increases defense by 35pts>\n";
    std::cout << "5. Chest Armor   <500g> <Permanently increses defense by 55pts>\n";
    std::cout << "6. Axe           <500g> <Permanently increases attack by 55pts>\n";
    std::cout << "\n7. Exit Shop\n";
    std::cout << "Choice: ";
}

Shop getPlayerCart(Player& p1){
    int choice{};
    while(true){
        printRoscoeShop();
        std::cin>>choice;
        if(!std::cin){
            std::cin.clear();
            ignoreLine();
            std::cout<<"Invalid choice";
            continue;
        }
        if(choice == 1){
            if(p1.getGold() >= 100){
                p1.TakeGold(100.0);
                return Shop::Defense_Drink;
            }
            else{
                std::cout<<"Sorry you can't afford this!\n";
                continue;
            }
        }
        else if(choice == 2){
            if(p1.getGold() >= 100){
                p1.TakeGold(100.00);
                return Shop::Attack_Drink;
            }
            else{
                std::cout<<"Sorry you can't afford this!\n";
                continue;
            }
        }
        else if(choice == 3){
            if(p1.getGold() >= 300){
                p1.TakeGold(300.00);
                return Shop::Sword;
            }
            else{
                std::cout<<"Sorry you can't afford this!\n";
                continue;
            }
        }
        else if(choice == 4){
            if(p1.getGold() >= 300){
                p1.TakeGold(300.00);
                return Shop::Shield;
            }
            else{
                std::cout<<"Sorry you can't afford this!\n";
                continue;
            }
        }
        else if(choice == 5){
            if(p1.getGold() >= 500){
                p1.TakeGold(500.00);
                return Shop::Chest_Armor;
            }
            else{
                std::cout<<"Sorry you can't afford this!\n";
                continue;
            }
        }
        else if(choice == 6){
            if(p1.getGold() >= 500){
                p1.TakeGold(500.00);
                return Shop::Axe;
            }
            else{
                std::cout<<"Sorry you can't afford this!\n";
                continue;
            }
        }
        else if(choice == 7){
            break;
        }
        else{
            std::cout<<"Invalid Input!\n";
            continue;
        }
    }

    return Shop::Invalid;
}

bool ResolvePlayerCart(Player& p1, Shop playerCart){
    switch(playerCart){
        case Shop::Defense_Drink : 
            p1.ChangeDefense(10);
            return false;
        break;
        case Shop::Attack_Drink  : 
            p1.ChangeAttack(10);
            return false;
        break;
        case Shop::Sword : 
            p1.ChangeAttack(35);
            return false;
        break;
        case Shop::Shield : 
            p1.ChangeDefense(35);
            return false;
        break;
        case Shop::Chest_Armor : 
            p1.ChangeDefense(55);
            return false;
        break;
        case Shop::Axe : 
            p1.ChangeAttack(55);
            return false;
    }

    return false;
}


void printPlayerchoice(){
    std::cout<<"\n==== Your Turn! ====\n";
        std::cout << "Choose action:\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Go to Roscoe Shop\n";
        std::cout << "3. Flee\n";
        std::cout << "4. Bide   <skip a turn to get a major attack boost>\n";
        std::cout << "5. Insult <Lowers enemy attack stat>\n";
        std::cout << "6. Brace  <increases defense>\n";
        std::cout << "Choice: ";
}

ActorAction getPlayerAction(){
    int choice{};
    printPlayerchoice();
    std::cin>>choice;
    ignoreLine();
    if(!std::cin){
        std::cin.clear(); 
        ignoreLine();  
        return ActorAction::Invalid;
    }
    switch(choice){
        case 1 : return ActorAction::Attack;
        case 2 : return ActorAction::Shop;
        case 3 : return ActorAction::Flee;
        case 4 : return ActorAction::Bide;
        case 5 : return ActorAction::Insult;
        case 6 : return ActorAction::Brace;
        default: return ActorAction::Invalid;
    }
}

ActorAction getEnemyAction(const Monster& m1, const Player& p1){
    std::cout<<"\nENEMY TURN\n";
    if((m1.getHealth() < 30.00 || p1.getAttack() > 70) && m1.getDefense() < 100){
        return ActorAction::Brace;
    }
    if(m1.getAttack() < 20.0 && m1.getHealth() > 50){
        return ActorAction::Bide;
    }
    if(Random::get(1,100) > 50){
        return ActorAction::Insult;
    }

    return ActorAction::Attack;
}

bool resolvePlayerAction(Player& p1, Monster& enemy, ActorAction PlayerAction){
    switch(PlayerAction){
        case ActorAction::Attack : 
            DealDamageEnemy(p1,enemy);
            if(enemy.isDead()){
                std::cout<<enemy.getName()<<" Is defeated!\n";
                p1.gainXP(enemy.getExpReward());
                p1.gainGoldPlayer(enemy.getGold());
                return true;
            }
        break;
        case ActorAction::Shop : ResolvePlayerCart(p1,getPlayerCart(p1));
        break;
        case ActorAction::Flee : runAway(p1);
        break;
        case ActorAction::Bide : Bide(p1,enemy);
        break;
        case ActorAction::Insult : insultEnemy(enemy,p1);
        break;
        case ActorAction::Brace : Brace(p1);
        break;
        case ActorAction::Invalid : 
            std::cout<<"Invalid choice! Looks like the Enemy is Attacking you!!\n";
            return false;
        break;
    }

    return false;
}

bool resolveEnemyAction(Monster& enemy, Player& p1, ActorAction EnemyAction){
    switch(EnemyAction){
        case ActorAction::Attack : 
            DealDamagePlayer(enemy,p1);
            if(p1.isDead()){
                return true;
            }
        break;
        case ActorAction::Bide :  Bide(enemy, p1);
        break;
        case ActorAction::Brace : Brace(enemy);
        break;
        case ActorAction::Insult : insultEnemy(p1,enemy);
        break;
    }

    return false;
}

void BattleLoop(Player& p1, Monster& m1){
    bool battleEnd = false;
    bool player_turn = true;
    bool shop = false;
    int rounds{0};
    std::cout << "\n===== NEW BATTLE =====\n";
    std::cout << "You encounter: " << m1.getName() << "\n";
    std::cout <<m1<<"\n";
    while(!battleEnd){
        std::cout<<"\nROUND "<<rounds<<"\n";
        if(player_turn){
            battleEnd = resolvePlayerAction(p1,m1,getPlayerAction());
        }
        else{
            battleEnd = resolveEnemyAction(m1,p1,getEnemyAction(m1,p1));
        }
        player_turn = !player_turn;

        if(rounds > 5){
            p1.clearBoost();
            m1.clearBoost();
            rounds = 0;
        }
    
        std::cout<<"Press Enter to continue: "<<"\n";
        ignoreLine();

        rounds++;
    }
    
}

void printStatus(Player& p1){
    std::cout<<"\n\n=====Status=====\n\n";
    std::cout<<p1<<"\n";
    std::cout<<"\n================\n";
}

int main(){
    std::string name{"none"};
    char diff{'?'};
    std::cout<<"Enter your name: ";
    std::cin>>name;
    Player p1{name};
    std::cout<<"Enter difficulty <E for easy, M for medium and H for hard> ";
    std::cin>>diff;
    while(!p1.hasWon(diff)){
        auto Enemy = Enemy::getRandomEnemy(diff);
        BattleLoop(p1,*Enemy);
        ResolvePlayerCart(p1,getPlayerCart(p1));
        printStatus(p1);
    }
}
