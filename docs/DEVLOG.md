
# Name in Progress - DEVELOPMENT LOG

# Project Goal

A 2D fantasy wizard game built with C++ and raylib featuring playable wizards, enemy variants, turn-based combat systems, and cartoon fantasy visuals.

---

# DATE: 2026-05-28

# Session Length

~4 Hours

# Goals For Session

* Update character sprites
* Fit hero and enemy artwork into the battle window
* Improve battle screen presentation
* Flesh out story concepts

# Completed

* Replaced hero sprite artwork
* Added multiple enemy sprite variants
* Adjusted sprite scaling for battle scenes
* Improved visual consistency between hero and enemy characters
* Created outline for story direction
* Improved overall battle screen presentation

# Problems Encountered

* Enemy PNG files used different dimensions than hero sprites
* Characters appeared to stand at different heights despite similar scales
* Sprite positioning looked inconsistent between enemies

# Solutions / Discoveries

* Implemented enemy foot-offset positioning
* Learned that transparent padding affects sprite alignment
* Discovered that visual grounding is often solved with per-character offsets
* Kept the narrow battle-screen layout instead of redesigning the window

# Ideas For Later

* Rename spells
* Create Health system
* Create AP/Mana system
* Add combat animations
* Add damage calculations
* Expand story dialogue

# Commands / Build Notes

```bash
clear && g++ *.cpp -o StupidWizards -lraylib
```

# Files Modified

* enemy.cpp
* enemy.hpp
* Updated enemy sprite assets
* Updated hero sprite assets

# End Session Notes

Battle scenes now look significantly more cohesive. Character positioning and sprite presentation are beginning to resemble a real game rather than a prototype.

END SESSION

---

# DATE: 2026-05-23

# Session Length

Not Recorded

# Goals For Session

* Incorporate attack/battle system
* Add battle timer
* Create dialogue prototype

# Completed

* Added attack selection system
* Added battle timer
* Added dialogue prototype
* Established basic combat flow

# Problems Encountered

* No major issues encountered

# Solutions / Discoveries

* Confirmed combat loop structure is viable
* Established foundation for future combat systems

# Ideas For Later

* Better dialogue scripting
* Mana/AP system
* Health system

# Commands / Build Notes

```bash
clear && g++ *.cpp -o StupidWizards -lraylib
```

# Files Modified

* game.cpp
* game.hpp
* hero.cpp
* enemy.cpp

# End Session Notes

Combat framework is functional and ready for expansion.

END SESSION
