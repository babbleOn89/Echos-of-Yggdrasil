#include "hero.hpp"
#include <string>
#include <iostream>

Hero::Hero()
{
    heroOne = LoadTexture("assets/hero/mhero2.png");
    heroTwo = LoadTexture("assets/hero/fhero2.png");
    
    currentImage = heroOne;
    type = Hero_One;
    
    scale = 0.25f;
    heroTwoScale = 0.25f;
    
    active = true;
    
    float groundY = 360;
    float heroFootOffset = 25;

    position.x = 150;
    position.y = groundY - currentImage.height * scale + heroFootOffset;

    currentAttack = ATTACK_NONE;
}

Hero::~Hero()
{
    UnloadTexture(heroOne);
    UnloadTexture(heroTwo);
}

void Hero::Update()
{
    Moveset();
}

void Hero::SetX(float newX)
{
    position.x = newX;
}

void Hero::Draw()
{
    if(active)
    {
        DrawTextureEx(currentImage, position, 0.0f, scale, WHITE);
    }
}

void Hero::SetHero(HeroType newType)
{
    type = newType;

    if(type == Hero_One)
    {
        currentImage = heroOne;
        scale = 0.25f;
    }
    else if(type == Hero_Two)
    {
        currentImage = heroTwo;
        scale = heroTwoScale;
    }

    float groundY = 360;
    float heroFootOffset = 25;

    position.y = groundY - currentImage.height * scale + heroFootOffset;
}

void Hero::Moveset()
{
    if(IsKeyPressed(KEY_LEFT))
    {
        currentAttack = ATTACK_FIREBALL;
        std::cout << "FIREBALL" << std::endl;
    }
    else if(IsKeyPressed(KEY_DOWN))
    {
        currentAttack = ATTACK_LIGHTNING;
        std::cout << "LIGHTNING" << std::endl;
    }
    else if(IsKeyPressed(KEY_RIGHT))
    {
        currentAttack = ATTACK_SHIELD;
        std::cout << "SHIELD" << std::endl;
    }
}
