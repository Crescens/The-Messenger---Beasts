#include "Actor.h"


Actor::Actor(void)
{
	mLevel_ = 1;
	mHealth_ = 50;
	mEnergy_ = 10;
	mAttack_ = 20;
	mDefense_ = 15;
	mMagic_Attack_ = 10;
	mMagic_Defense_ = 5;
	mEvasion_ = 10;
	mBlocking_ = 5;

	mX_ = 400;
	mY_ = 135;
	mW_ = 0;
	mH_ = 0;

}


Actor::~Actor(void)
{
	this->free();
}

// Getting stat parameters

unsigned int Actor::getLevel()
{
	return mLevel_;
}

unsigned int Actor::getHealth()
	{
	return mHealth_;
}

unsigned int Actor::getEnergy()
{
	return mEnergy_;
}

unsigned int Actor::getAttack()
{
	return mAttack_;
}

unsigned int Actor::getDefense()
{
	return mDefense_;
}

unsigned int Actor::getMagic_Attack()
{
	return mMagic_Attack_;
}

unsigned int Actor::getMagic_Defense()
{
	return mMagic_Defense_;
}

unsigned int Actor::getEvasion()
{
	return mEvasion_;
}

unsigned int Actor::getBlocking()
{
	return mBlocking_;
}

int Actor::getX()
{
	return mX_;
}

int Actor::getY()
{
	return mY_;
}

// Setting stat parameters

void Actor::setLevel(unsigned int level)
{
	mLevel_ = level;
}
	
void Actor::setHealth(unsigned int health)
{
	mHealth_ = health;
}

void Actor::setEnergy(unsigned int energy)
{
	mEnergy_ = energy;
}
	
void Actor::setAttack(unsigned int attack)
{
	mAttack_ = attack;
}
	
void Actor::setDefense(unsigned int defense)
{
	mDefense_ = defense;
}
	
void Actor::setMagic_Attack(unsigned int magic_attack)
{
	mMagic_Attack_ = magic_attack;
}
	
void Actor::setMagic_Defense(unsigned int magic_defense)
{
	mMagic_Defense_ = magic_defense;
}
	
void Actor::setEvasion(unsigned int evasion)
{
	mEvasion_ = evasion;
}
	
void Actor::setBlocking(unsigned int blocking)
{
	mBlocking_ = blocking;
}

// Velocity Addition and Subtraction

void Actor::addX(int x)
{
	mX_ += x;
}
void Actor::subX(int x)
{
	mX_ -= x;
}
void Actor::addY(int y)
{
	mY_ += y;
}
void Actor::subY(int y)
{
	mY_ -= y;
}


	