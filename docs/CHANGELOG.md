# STUPID WIZARDS - CHANGELOG

---

# v0.01 - The Wizard Awakens
2026-05-18

- Initial concept planning
- Decided on fantasy/cartoon wizard direction
- Planned playable wizard system
- Planned enemy wizard variants
- Chose C++ and raylib for development

Notes:
The project officially escaped containment and became real.

---

# v0.02 - Wizard Factory Expansion
2026-05-19

- Created "Pierre" enemy design
- Created "George" enemy design
- Added "Ghost" enemy (MORTAL KOMBAT!!)
- Created left-facing sprite variants
- Added transparent-background sprites
- Established visual style direction

Discoveries:
Separate left/right sprites seem cleaner than flipping textures.

---

# v0.03 - Systems & Summoning
2026-05-20

- Added enemy random spawning
- Began hero/enemy systems
- Created character select framework
- Improved positioning/scaling
- Fixed enemy sprite rendering bug

Bug Fix:
Enemy .png was not displaying due to filename typo because computers are evil sometimes.

Build Command:

```bash
g++ main.cpp hero.cpp enemy.cpp -o StupidWizards -lraylib
```

---

# v0.04 - Combat Arcana
2026-05-23

- Added attack/battle system
- Added battle timer
- Added dialogue prototype
- Combat flow beginning to function

Planned Features:
- Mana/AP system
- Health system
- Better dialogue scripting

Build Command:

```bash
clear && g++ *.cpp -o StupidWizards -lraylib
```

---

# v0.05 - Terminal Wizardry
2026-05-27

- Added attack selection controls
- Fireball, Shield, and Lightning attacks functional
- Attack events now print to terminal for debugging
- README added to GitHub
- Repository uploaded publicly as active WIP

Current Controls:
- RIGHT ARROW = Fireball
- LEFT ARROW = Shield
- DOWN ARROW = Lightning

Notes:
Animations are not implemented yet, but the combat skeleton is alive.
Which is mildly concerning for the enemy wizards.
