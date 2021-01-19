#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Weapon.h"

using namespace std;

ostream& operator<<(ostream& flux, Weapon const& wpn) {
    wpn.showStats(flux);
    return flux;
}

Weapon::Weapon() {
    m_name = "Death row";
    m_health = 0;
    m_speed = 10000;
    m_attack = 10000;
}

Weapon::Weapon(string name, int health, int attack, int speed) {
    m_name = name;
    m_health = health;
    m_attack = attack;
    m_speed = speed;
}

int Weapon::getAttackPoints() const {
    return m_attack;
}

int Weapon::getHealth() const {
    return m_health;
}

string Weapon::getName() const {
    return m_name;
}

bool Weapon::isBroken() const {
    return m_health <= 0;
}

void Weapon::removeHealth(int points) {
    cout << m_name + " loses " << points << " health points." << endl;
    m_health -= points;
}

bool Weapon::dodges(int points) const {
    int score(rand() % m_speed);
    if (score > points) {
        return true;
    }
    else {
        return false;
    }
}

void Weapon::showStats(ostream& flux) const {
    flux << m_name << '\n';
    flux << "Health : " << m_health << '\n';
    flux << "Attack : " << m_attack << '\n';
    flux << "Speed : " << m_speed << '\n';
}