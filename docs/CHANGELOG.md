# (TITLE IN PROGRESS) - CHANGELOG

---

# v0.05

2026-05-28

### Added

* Added attack selection controls
* Added Fireball, Shield, and Lightning attacks
* Added random enemy sprite selection
* Added new hero and enemy artwork
* Added additional enemy variants
* Added configurable enemy foot offsets

### Changed

* Improved battle screen presentation
* Improved sprite scaling and positioning
* Improved hero and enemy visual consistency
* Reorganized project documentation

### Fixed

* Fixed enemy sprite ground alignment issues

### Current Controls

* LEFT ARROW = Fireball
* DOWN ARROW = Lightning
* RIGHT ARROW = Shield

---

# v0.04

2026-05-23

### Added

* Added attack/battle system
* Added battle timer
* Added dialogue prototype

### Changed

* Combat flow now functions from attack selection to resolution

### Planned

* Mana/AP system
* Health system
* Improved dialogue scripting

Build Command:

```bash
clear && g++ *.cpp -o StupidWizards -lraylib
```

---

# v0.03

2026-05-20

### Added

* Added enemy random spawning
* Began hero/enemy systems
* Created character select framework

### Changed

* Improved positioning and scaling

### Fixed

* Fixed enemy sprite rendering issue caused by incorrect filename

Build Command:

```bash
g++ main.cpp hero.cpp enemy.cpp -o StupidWizards -lraylib
```

---

# v0.02

2026-05-19

### Added

* Created Pierre enemy design
* Created George enemy design
* Created Ghost enemy design
* Created left-facing sprite variants
* Added transparent-background sprites

### Changed

* Established overall visual style direction

### Notes

* Separate left/right sprites appear cleaner than texture flipping

---

# v0.01

2026-05-18

### Added

* Initial project planning
* Fantasy/cartoon wizard concept
* Playable wizard system design
* Enemy wizard variant planning
* Selected C++ and raylib as project technologies

### Notes

* Initial project creation

