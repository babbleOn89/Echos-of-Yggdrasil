#pragma once
#include <raylib.h>
#include "attack.hpp"

enum EnemyType
{
    ENEMY_PIERRE,
    ENEMY_GEORGE,
    ENEMY_GHOST
};

class Enemy
{
public:
    AttackType currentAttack;
    Enemy();
    ~Enemy();
    void Update();
    void ChooseAttack();
    void Draw();

public:
    Texture2D pierreTexture;
    Texture2D georgeTexture;
    Texture2D ghostTexture;
    Texture2D enemyTexture;
    Texture2D currentTexture;
    Vector2 position;

    EnemyType type;
    
    float pierreScale;
    float georgeScale;
    float ghostScale;
    float currentScale;

    bool active;
};
