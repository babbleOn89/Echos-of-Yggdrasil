#pragma once
#include <raylib.h>
#include "attack.hpp"

enum HeroType
{
    Hero_One,
    Hero_Two
};

class Hero
{
public:
    AttackType currentAttack;
    Hero();
    ~Hero();
    void Update();
    void Moveset();
    void Draw();
    void SetHero(HeroType newType);
    void SetX(float newX);

private:
    Texture2D heroOne;
    Texture2D heroTwo;
    Texture2D currentImage;
    Vector2 position;

    HeroType type;
    
    float scale;
    float heroTwoScale;
    bool active;

};
