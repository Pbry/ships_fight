#ifndef DEF_CHARACTER
#define DEF_CHARACTER

#include <string>
#include "Weapon.h"


// TO DO : method : Weapon& changeWeapon(Weapon& newBoat)

class Character {
    private:
    std::string m_name;
    Weapon *m_weapon;
    bool m_dodge;
    bool m_deleteWeapon;
    void showStats(std::ostream& flux) const;

    public:
    Character();
    Character(std::string name, Weapon& boat);
    Character(Character const& otherCharac);
    ~Character();
    Character& operator=(Character const& otherCharac);
    bool boatFloats() const;
    std::string getName() const;
    void attacks(Character& enemy);
    void takeBlow(int points);
    void manoeuvres();
    void automatedAction(Character& enemy);
    void showHealth() const;

    friend std::ostream& operator<<(std::ostream &flux, Character const& charac);
};

#endif