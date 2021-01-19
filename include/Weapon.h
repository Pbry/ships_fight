#ifndef DEF_WEAPON
#define DEF_WEAPON

#include <string>


class Weapon {
    private:
    std::string m_name;
    int m_health;
    int m_attack;
    int m_speed;

    public:
    Weapon();
    Weapon(std::string name, int health, int attack, int speed) ;
    int getAttackPoints() const;
    int getHealth() const;
    std::string getName() const;
    bool isBroken() const;
    void removeHealth(int points);
    bool dodges(int points) const;
    void showStats(std::ostream& flux) const;
};

std::ostream& operator<<(std::ostream& flux, Weapon const& wpn);

#endif