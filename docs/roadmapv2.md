STUPID WIZARDS v2 ROADMAP
│
├── 1. Battle Flow Upgrade
│   ├── TITLE
│   ├── CHARACTER_SELECT
│   ├── MOVE_SELECT        ← NEW
│   ├── ENEMY_INTRO
│   ├── BATTLE
│   ├── VICTORY
│   └── GAME_OVER
│
├── 2. Move Select Menu
│   ├── After choosing character
│   ├── Before enemy appears
│   ├── Pick 3–4 starting attacks
│   ├── Store selected moves
│   └── Confirm with ENTER
│
├── 3. Attack System
│   ├── Create Attack struct/class
│   │   ├── name
│   │   ├── damage
│   │   ├── manaCost
│   │   ├── apCost / apGain
│   │   ├── hitChance
│   │   └── description
│   │
│   ├── Player attacks
│   ├── Enemy attacks
│   └── Basic attack first, fancy attacks later
│
├── 4. Mana System
│   ├── mana starts at 0
│   ├── max mana = 100
│   ├── gain mana over time
│   │   └── maybe +1 or +5 per second first
│   ├── spells require mana
│   └── prevent casting if mana is too low
│
├── 5. AP System
│   ├── AP starts at 0
│   ├── max AP = 100
│   ├── successful hit = +10 AP
│   ├── missed hit = +0 AP
│   └── big special attacks use AP
│
├── 6. Chance To Miss
│   ├── Each move gets hitChance
│   │   ├── Basic wand bonk: 90%
│   │   ├── Fireball: 75%
│   │   ├── Chaos Blast: 55%
│   │   └── Ultimate: 85%
│   │
│   ├── Roll random number 1–100
│   ├── If roll <= hitChance → HIT
│   └── Else → MISS
│
├── 7. Stats System
│   ├── Player stats
│   │   ├── HP
│   │   ├── Mana
│   │   ├── AP
│   │   ├── Attack
│   │   └── Defense maybe later
│   │
│   ├── Enemy stats
│   │   ├── HP
│   │   ├── Attack
│   │   ├── Defense maybe later
│   │   └── Personality/dialogue type
│
├── 8. Dialogue Popups
│   ├── Random player lines
│   ├── Random enemy lines
│   ├── Trigger on:
│   │   ├── battle start
│   │   ├── hit
│   │   ├── miss
│   │   ├── low HP
│   │   └── victory/defeat
│   │
│   └── Display for 1–2 seconds
│
├── 9. Battle UI
│   ├── Player HP bar
│   ├── Enemy HP bar
│   ├── Mana bar
│   ├── AP bar
│   ├── Move menu
│   └── Dialogue box
│
└── 10. Polish Later
    ├── Different enemy personalities
    ├── Unique move sets per character
    ├── Better animations
    ├── Sound effects
    ├── Status effects
    └── Victory rewards

    Best Build Order
DO THIS FIRST
│
├── 1. Add MOVE_SELECT game state
├── 2. Make a simple move menu
├── 3. Create Attack struct
├── 4. Add mana + AP variables
├── 5. Add chance-to-miss logic
├── 6. Connect selected attack to battle
├── 7. Add random dialogue
└── 8. Polish UI bars

Suggested First Attack List
Basic Zap
├── Damage: 10
├── Mana Cost: 0
├── AP Gain: +10 on hit
└── Hit Chance: 90%

Fireball
├── Damage: 20
├── Mana Cost: 25
├── AP Gain: +10 on hit
└── Hit Chance: 75%

Shield Crack
├── Damage: 15
├── Mana Cost: 15
├── AP Gain: +10 on hit
└── Hit Chance: 85%

Big Dumb Spell
├── Damage: 45
├── Mana Cost: 50
├── AP Cost: 50
└── Hit Chance: 60%
Core Mental Model
Character Select
↓
Move Select
↓
Enemy Appears
↓
Battle Starts
↓
Player chooses attack
↓
Check mana/AP cost
↓
Roll hit chance
↓
Apply damage or miss
↓
Gain AP if hit
↓
Enemy turn
↓
Random dialogue sometimes
↓
Repeat until win/lose
