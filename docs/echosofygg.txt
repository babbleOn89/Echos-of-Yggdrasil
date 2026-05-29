==========================
STUPID WIZARDS ATTACKS
==========================

things to consider:

- damage
- mana cost
- animation
- cooldown
- sound effect
- elemental type
- projectile speed
- status effects
- random assignment
- AI weighting

Potential format:

class Attack
{
public:
    std::string name;

    int damage;
    int manaCost;

    float cooldown;

    Color attackColor;
};

Attack fireball;
fireball.name = "Fireball";
fireball.damage = 20;
fireball.manaCost = 5;

Attack currentAttack; || std::vector<Attack> moveset;

potentially:

randomized spells
unlockable spells
enemy-specific attacks
spellbooks
procedural combat
cooldown systems
Pokémon-style move lists
card-game mechanics

//random attacks set to key input
Q = Fireball this battle
Q = Shield next battle

attackSlots[0] = randomAttack();
attackSlots[1] = randomAttack();
attackSlots[2] = randomAttack();

if(IsKeyPressed(KEY_Q))
{
    currentAttack = attackSlots[0];
}
