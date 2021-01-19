#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Character.h"
#include "Weapon.h"

using namespace std;

ostream& operator<<(ostream& flux, Character const& charac) {
    charac.showStats(flux);
    return flux;
};

Character::Character() : m_weapon(0) {
    m_name = "Blurryface";
    m_dodge = true;
    m_deleteWeapon = true;
}

Character::Character(string name, Weapon& boat): m_weapon(0) {
    m_name = name;
    m_weapon = &boat;
    m_dodge = false;
    m_deleteWeapon = false;
}

Character::Character(Character const& otherCharac): 
m_name(otherCharac.m_name), m_dodge(otherCharac.m_dodge), m_deleteWeapon(otherCharac.m_deleteWeapon), m_weapon(0)
{
    m_weapon = new Weapon(*(otherCharac.m_weapon));
}

Character::~Character() {
    if (m_deleteWeapon) {
        delete m_weapon;
    }
}

Character& Character::operator=(Character const& otherCharac) {
    if (this != &otherCharac) {
        m_name = otherCharac.m_name;
        m_dodge = otherCharac.m_dodge;
        delete m_weapon;
        m_weapon = new Weapon(*(otherCharac.m_weapon));
        m_deleteWeapon = true;
    }
    return *this;
}

bool Character::boatFloats() const {
    return !(m_weapon->isBroken());
}

string Character::getName() const {
    return m_name;
}

void Character::attacks(Character& enemy) {
    // removes as many health points from the enemy's boat as the Character's boat has attack points
    m_dodge = false;
    cout << m_name + " attacks !" << endl;
    int attackPoints(m_weapon->getAttackPoints());
    enemy.takeBlow(attackPoints);
}

void Character::takeBlow(int points) {
    // if the character is in dodge mode, the weapon has a certain percentage of chances to dodge 
    // the attack based on their speed and the opponent's attack points
    if( m_dodge && m_weapon->dodges(points) ) {
        cout << m_name + "'s " + m_weapon->getName() + " has dodged the attack !" << endl;
    }
    else {
        m_weapon->removeHealth(points);
        showHealth();
    }
}

void Character::manoeuvres() {
    cout << m_name + " prudently manoeuvres." << endl;
    m_dodge = true;
}

void Character::automatedAction(Character& enemy) {
    int dice( rand() % 2) ;
    if(dice) {
        attacks(enemy);
    } else {
        manoeuvres();
    }
}

void Character::showHealth() const {
    cout << m_name + "'s " +  m_weapon->getName() + "'s health : \n";
    cout << m_weapon->getHealth() << endl;
}

void Character::showStats(ostream& flux) const {
    flux << m_name << '\n';
    flux << "Equipped with : ";
    m_weapon->showStats(flux);
}