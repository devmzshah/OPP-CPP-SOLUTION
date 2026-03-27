#include <iostream>
using namespace std;

class Hero {
public:
    string heroName;
    string role;
    int hp;
    double strengthFactor;

    Hero(string n, string r, int h, double sf) {
        heroName = n;
        role = r;
        hp = h;
        strengthFactor = sf;
    }

    void gameIntro() {
        cout << "===== Battle Arena =====" << endl;
        cout << "Each hero must fight and defend wisely!" << endl;
        cout << "------------------------" << endl;
    }

    void showInfo() {
        cout << "Hero: " << heroName << " {" << role << "}" << endl;
        cout << "Health: " << hp << " | Strength: " << strengthFactor << endl;
    }

    virtual void attackMove() = 0;
    virtual void defenseMove() = 0;
};

class Warrior : public Hero {
public:
    string weaponType;
    int defenseArmor;

    Warrior(string n, int h, double sf, string wt, int da)
        : Hero(n, "Warrior", h, sf) {
        weaponType = wt;
        defenseArmor = da;
    }

    void attackMove() {
        double damage = strengthFactor + (strengthFactor * 0.25); // modified
        cout << heroName << " attacks using " << weaponType
             << " (Damage: " << damage << ")" << endl;
    }

    void defenseMove() {
        cout << heroName << " defends with armor rating "
             << defenseArmor << endl;
    }
};

class Mage : public Hero {
public:
    string spellName;
    int manaPoints;

    Mage(string n, int h, double sf, string sn, int mp)
        : Hero(n, "Mage", h, sf) {
        spellName = sn;
        manaPoints = mp;
    }

    void attackMove() {
        double damage = (strengthFactor * 1.5) + 10; // changed formula
        cout << heroName << " casts " << spellName
             << " (Damage: " << damage << ")" << endl;
    }

    void defenseMove() {
        cout << heroName << " creates shield using "
             << manaPoints << " mana." << endl;
    }
};

class Archer : public Hero {
public:
    string bowType;
    double hitAccuracy;

    Archer(string n, int h, double sf, string bt, double acc)
        : Hero(n, "Archer", h, sf) {
        bowType = bt;
        hitAccuracy = acc;
    }

    void attackMove() {
        double damage = (strengthFactor * hitAccuracy) + 2; // modified
        cout << heroName << " shoots with " << bowType
             << " (Damage: " << damage << ")" << endl;
    }

    void defenseMove() {
        cout << heroName << " evades the attack quickly!" << endl;
    }
};

int main() {
    Warrior w("Thorin", 150, 45.0, "Battle Axe", 85);
    Mage m("Gandalf", 95, 68.0, "Lightning Strike", 130);
    Archer a("Legolas", 115, 52.0, "Elven Bow", 0.92);

    w.gameIntro();

    w.showInfo();
    w.attackMove();
    w.defenseMove();
    cout << endl;

    m.showInfo();
    m.attackMove();
    m.defenseMove();
    cout << endl;

    a.showInfo();
    a.attackMove();
    a.defenseMove();

    return 0;
}