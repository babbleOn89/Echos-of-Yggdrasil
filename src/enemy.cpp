#include "enemy.hpp"

Enemy::Enemy()
{
    pierreTexture = LoadTexture("assets/bosses/pierre2.png");
    georgeTexture = LoadTexture("assets/bosses/george2.png");
    ghostTexture = LoadTexture("assets/bosses/ghost2.png");

    pierreScale = 0.28f;
    georgeScale = 0.28f;
    ghostScale = 0.28f;

    active = true;
    
    float groundY = 340;
    float enemyFootOffset= 0;

    int choice = GetRandomValue(0, 2);

    if(choice == 0)
    {
        type = ENEMY_PIERRE;
        currentTexture = pierreTexture;
        currentScale = pierreScale;
        enemyFootOffset = 65;
    }
    else if(choice == 1)
    {
        type = ENEMY_GEORGE;
        currentTexture = georgeTexture;
        currentScale = georgeScale;
        enemyFootOffset = 65;
    }
    else if(choice == 2)
    {
        type = ENEMY_GHOST;
        currentTexture = ghostTexture;
        currentScale = ghostScale;
        enemyFootOffset = 65;
    }

    position.x = 950;
    position.y = groundY - currentTexture.height * currentScale + enemyFootOffset;

    currentAttack = ATTACK_NONE;

}

Enemy::~Enemy()
{
    UnloadTexture(pierreTexture);
    UnloadTexture(georgeTexture);
    UnloadTexture(ghostTexture);
}

void Enemy::Update()
{
    //empty for now
}

void Enemy::Draw()
{
    if(type == ENEMY_PIERRE)
    {
        currentTexture = pierreTexture;
        currentScale = pierreScale;
    }
    else if (type == ENEMY_GEORGE)
    {
        currentTexture = georgeTexture;
        currentScale = georgeScale;
    }
    else if(type == ENEMY_GHOST)
    {
        currentTexture = ghostTexture;
        currentScale = ghostScale;
    }

    DrawTextureEx(currentTexture, position, 0.0f, currentScale, WHITE);
}

void Enemy::ChooseAttack()
{
    int choice = GetRandomValue(0, 2);
    
    if(choice == 0)
    {
        currentAttack = ATTACK_FIREBALL;
    }
    else if(choice == 1)
    {
        currentAttack = ATTACK_LIGHTNING;
    }
    else
    {
        currentAttack = ATTACK_SHIELD;
    }

}
