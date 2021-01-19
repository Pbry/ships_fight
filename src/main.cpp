#include <iostream>
#include "Character.h"
#include "Weapon.h"

using namespace std;

char getPlayersAction() {
    char action;
    cout << "What will you do ? A- Attack, M- Manoeuvre" << endl;
    cin >> action;
    return action;
}

int main() {
    Weapon pirateShip("Basic pirate ship", 300, 40, 120); // name, health, attack, speed
    Weapon tradeShip("Wide tradeship", 400, 40, 40);

    // Idea : invisibly boost player's boat (.boost method)
    Character pirateCaptain("Pirate Capt'ain", pirateShip);
    Character merchant("Merchant", tradeShip);
    char action;
    bool gameOn(pirateCaptain.boatFloats() && merchant.boatFloats());

    cout << "You're a " + pirateCaptain.getName() + " boarding a " + merchant.getName() + "\n" << endl ;
    cout << pirateCaptain << endl;
    cout << merchant << endl;

    while(gameOn) {
        action = getPlayersAction();
        switch(action) {
            case 'A': pirateCaptain.attacks(merchant); break;
            case 'M': pirateCaptain.manoeuvres(); break;
            default : cout << "You did nothing." << endl;
        }
        gameOn = pirateCaptain.boatFloats() && merchant.boatFloats();
        if(gameOn) {
            merchant.automatedAction(pirateCaptain);
            gameOn = pirateCaptain.boatFloats() && merchant.boatFloats();
        }
    }
    char quit;
    if (pirateCaptain.boatFloats()) {
        cout << "Congratulations, you scuttled the enemy's boat ! (q to quit)";
        cin >> quit;
    } else {
        cout << "Looks like you've been scuttled... (q to quit)";
        cin >> quit;
    }

}