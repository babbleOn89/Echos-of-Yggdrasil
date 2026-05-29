#pragma once
#include <raylib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "hero.hpp"
#include "enemy.hpp"

enum BattleTurn
{
    TURN_START,
    PLAYER_TURN,
    RESOLVE_TURN,
    TURN_DELAY
};

enum GameState
{
    CHARACTER_SELECT,
    BATTLE
};

class Game
{
public:
    Game();
    ~Game();
    void Update();
    void Draw();

    float timeLeft;
    bool run;

private:
    int windowWidth;
    int windowHeight;
    int selectedHero;

    void DrawWorldUI();

    std::vector<std::string> battleQuotes;

    std::string heroDialogue;
    std::string enemyDialogue;

    float dialogueTimer;
    float nextDialogueTime;

    void TriggerRandomDialogue();
    void DrawDialogueBox(std::string text, int x, int y);

    GameState currentState;
    BattleTurn currentTurn;
    float turnTimer;
    std::string battleMessage;
    Hero hero;
    Hero heroPreview;
    Enemy enemy;
};
