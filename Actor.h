#pragma once

#include "Animation.h"

class Actor : public Animation
{

public:
	Actor(void);
	~Actor(void);

	// Get Functions
	unsigned int getLevel();
	unsigned int getHealth();
	unsigned int getEnergy();
	unsigned int getAttack();
	unsigned int getDefense();
	unsigned int getMagic_Attack();
	unsigned int getMagic_Defense();
	unsigned int getEvasion();
	unsigned int getBlocking();
	int getX();
	int getY();

	
	// Set Functions
	void setLevel(unsigned int level);
	void setHealth(unsigned int health);
	void setEnergy(unsigned int energy);
	void setAttack(unsigned int attack);
	void setDefense(unsigned int defense);
	void setMagic_Attack(unsigned int magic_attack);
	void setMagic_Defense(unsigned int magic_defense);
	void setEvasion(unsigned int evasion);
	void setBlocking(unsigned int blocking);
	
	// Direction Change
	void addX(int x);
	void subX(int x);
	void addY(int y);
	void subY(int y);

	// Walking states
	enum animationState
	{
		WALKING_UP,
		WALKING_LEFT,
		WALKING_DOWN,
		WALKING_RIGHT,
		KNOCKED_DOWN,
		ATTACKING_1,
		ATTACKING_2,
		ATTACKING_3
	};

	// Each of these objects holds a series of animations
	Animation moveUp;
	Animation moveRight;
	Animation moveDown;
	Animation moveLeft;



private:

	unsigned int mLevel_;
	unsigned int mHealth_;
	unsigned int mEnergy_;
	unsigned int mAttack_;
	unsigned int mDefense_;
	unsigned int mMagic_Attack_;
	unsigned int mMagic_Defense_;
	unsigned int mEvasion_;
	unsigned int mBlocking_;

	std::vector<std::string> mMove_List_;



	int mX_;
	int mLast_X_;
	int mY_;
	int mLast_Y_;
	int mW_; 
	int mH_;

	// Space reserved for Equipment slots and what is in each.
};

