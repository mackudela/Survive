#include "Spell.h"

float Spell::getDamage()
{
    return damage;
}

sf::Vector2f Spell::getDirection()
{
    return direction;
}

bool Spell::isAlive()
{
    return false;
}

float Spell::getSpeed()
{
    return speed;
}
