#include "game.hpp"


Game::Game()
{
    windowWidth = 1400;
    windowHeight = 400;
    
    run = true;
    
    selectedHero = 1;
    currentState = CHARACTER_SELECT;

    heroPreview.SetHero(Hero_Two);
    heroPreview.SetX(1050);
    
    timeLeft = 180.0f;

    currentTurn = TURN_START;
    turnTimer = 0.0f;
    battleMessage = "Commence Battle!";

    battleQuotes =
    {
        "A worthy adversary",
        "You should have trained harder",
        "Surrender now!",
        "This is it for you!"
    };

    heroDialogue = "";
    enemyDialogue = "";

    dialogueTimer = 0.0f;
    nextDialogueTime =  2.0f;

}

Game::~Game()
{

}

void Game::Update()
{
    if(run && currentState == BATTLE)
    {
        timeLeft -= GetFrameTime();
        
        if(timeLeft <= 0)
        {
            timeLeft = 0;
            run = false; 

            return;
        }
    }
    if(currentState == CHARACTER_SELECT)
    {
        if(IsKeyPressed(KEY_LEFT))
        {
            selectedHero = 1;
        }

        if(IsKeyPressed(KEY_RIGHT))
        {
            selectedHero = 2;
        }

        if(IsKeyPressed(KEY_ENTER))
        {
            if(selectedHero == 1)
            {
                hero.SetHero(Hero_One);
            }
            else if(selectedHero == 2)
            {
                hero.SetHero(Hero_Two);
            }

            hero.SetX(150);
            currentState = BATTLE;
        }
    }
    else if(currentState == BATTLE)
    {

        nextDialogueTime -= GetFrameTime();

        if(nextDialogueTime <= 0)
        {
            TriggerRandomDialogue();
            nextDialogueTime = GetRandomValue(3, 6);
        }

        if(dialogueTimer > 0)
        {
            dialogueTimer -= GetFrameTime();

            if(dialogueTimer <= 0)
            {
                heroDialogue = "";
                enemyDialogue = "";
            }
        }


        if(currentTurn == TURN_START)
        {
            currentTurn = PLAYER_TURN;
            battleMessage = "Choose your attack!";
        }
        else if(currentTurn == PLAYER_TURN)
        {
            hero.currentAttack = ATTACK_NONE;
            hero.Moveset();

            if(hero.currentAttack != ATTACK_NONE)
            {
                enemy.ChooseAttack();
                currentTurn = RESOLVE_TURN;
            }
        }
        else if(currentTurn == RESOLVE_TURN)
        {
            if(hero.currentAttack == ATTACK_SHIELD && enemy.currentAttack != ATTACK_SHIELD)
            {
                battleMessage = "You blocked the enemy attack!";
            }
            else if(enemy.currentAttack == ATTACK_SHIELD && hero.currentAttack != ATTACK_SHIELD)
            {
                battleMessage = "Enemy blocked your attack!";
            }
            else if(hero.currentAttack == ATTACK_SHIELD && enemy.currentAttack == ATTACK_SHIELD)
            {
                battleMessage = "Both wizards shielded. Very dramatic. Nothing happened.";
            }
            else
            {
                battleMessage = "Both attacks hit!";
            }

            turnTimer = 1.5f;
            currentTurn = TURN_DELAY;
        }
        else if(currentTurn == TURN_DELAY)
        {
            turnTimer -= GetFrameTime();

            if(turnTimer <= 0)
            {
                hero.currentAttack = ATTACK_NONE;
                enemy.currentAttack = ATTACK_NONE;

                currentTurn = PLAYER_TURN;
                battleMessage = "Choose your attack!";
            }
        }
    }
}

void Game::Draw()
{
    if(currentState == CHARACTER_SELECT)
    {
        const char* message = "CHOOSE YOUR CHARACTER";
        int fontSize = 40;
        int textWidth = MeasureText(message, fontSize);
        int centerX = windowWidth/2;

        DrawText(message, centerX - textWidth/2 + 50, 60, fontSize, GOLD);

        if(selectedHero == 1)
        {
            DrawCircle(275, 300, 80, Fade(YELLOW, 0.35f));
        }
        if(selectedHero == 2)
        {
            DrawCircle(1165, 300, 80, Fade(YELLOW, 0.35f));
        }
        
        hero.Draw();
        heroPreview.Draw();
    }
    else if(currentState == BATTLE)
    {
        hero.Draw();
        enemy.Draw();
        
        DrawDialogueBox(heroDialogue, 90, 300);
        DrawDialogueBox(enemyDialogue, 950, 300);

        DrawText(battleMessage.c_str(), 450, 40, 30, GOLD);

        DrawText("LEFT: FIREBALL", 50, 40, 20, RED);
        DrawText("DOWN: Lightning", 50, 70, 20, SKYBLUE);
        DrawText("RIGHT: Shield", 50, 100, 20, GREEN);

    }

    DrawWorldUI();
}

void Game::DrawWorldUI()
{
    int totalSeconds = (int)timeLeft;

    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    const char* timerText = TextFormat("%d:%02d", minutes, seconds);

    int timerFontSize = 50;
    int timerTextWidth = MeasureText(timerText, timerFontSize);

    DrawText(timerText, GetScreenWidth()/2 - timerTextWidth/2, GetScreenHeight() - 70,
            timerFontSize, GOLD);
}

void Game::TriggerRandomDialogue()
{
    int randomLine = GetRandomValue(0, battleQuotes.size() - 1);
    int randomSpeaker = GetRandomValue(0, 1);

    std::string line = "\"" + battleQuotes[randomLine] + "\"";

    if(randomSpeaker == 0)
    {
        heroDialogue = line;
        enemyDialogue = "";
    }
    else
    {
        enemyDialogue = line;
        heroDialogue = "";
    }

    dialogueTimer = 2.0f;
}

void Game::DrawDialogueBox(std::string text, int x, int y)
{
    if(text == "")
    {
        return;
    }

    int fontSize = 20;
    int padding = 10;
    int textWidth = MeasureText(text.c_str(), fontSize);

    DrawRectangle(x - padding, y - padding, textWidth + padding * 2, 40, Fade(BLACK, 0.75f));
    DrawRectangleLines(x - padding, y - padding, textWidth + padding * 2, 40, WHITE);

    DrawText(text.c_str(), x, y, fontSize, WHITE);
}
