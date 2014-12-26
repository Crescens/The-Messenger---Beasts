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

	mX_ = 0;
	mY_ = 0;
	mW_ = 0;
	mH_ = 0;

	mVelocity_ = 0;
}


Actor::~Actor(void)
{
	for(int i = 0; i < sizeof(mSprites_); i++)
	{
		SDL_DestroyTexture(mSprites_.at(i));
	}
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

unsigned int Actor::getVelocity()
{
	return mVelocity_;
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

void Actor::setVelocity(unsigned int velocity)
{
	mVelocity_ = velocity;
}

// Velocity Addition and Subtraction

void Actor::addVelocity(int addition)
{
	mVelocity_ += addition;
}
void Actor::subVelocity(int subtraction)
{
	mVelocity_ -= subtraction;
}

// Allocate Textures to mSprites_ as well as creates a rect the size of the texture at index 0

void Actor::addTexture(SDL_Texture *tex)
{
	mSprites_.push_back(tex);

	if(mSprites_.at(0) == NULL)
	{
		SDL_QueryTexture(tex, NULL, NULL, &mW_, &mH_);
	}

	SDL_DestroyTexture(tex);
}

// Render the actor's sprite
//	void renderSprite(int x, int y, SDL_Renderer *renderer)
//	{

	