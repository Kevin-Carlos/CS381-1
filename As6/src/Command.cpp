/*
 * Command.cpp
 *
 *  Created on: Apr 7, 2019
 *      Author: alex
 */

Command::Command(Entity381* ent)
{
	entity = ent;
	isDone = true;
}

virtual Command::~Command()
{

}

virtual void Command::tick(float dt)
{

}

virtual bool Command::done()
{
	return isDone;
}

MoveTo::MoveTo(Entity381* ent, Ogre::Vector3 target) : Command(ent)
{
	targetLocation = target;
	MOVE_DISTANCE_THRESHOLD = 100;
}

MoveTo::~MoveTo()
{

}

void MoveTo::tick(float dt)
{

}

Intercept::Intercept(Entity381* ent, Ogre::Vector3 target) : Command(ent)
{
	targetLocation = target;
	MOVE_DISTANCE_THRESHOLD = 100;
	interceptRadius = 100;
}

Intercept::~Intercept()
{

}

void Intercept::tick(float dt)
{

}
