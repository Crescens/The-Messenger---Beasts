#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}


void GameObject::update(World &world)
{
	graphics_.update();

}