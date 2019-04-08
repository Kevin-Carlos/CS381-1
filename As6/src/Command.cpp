/*
 * Command.cpp
 *
 *  Created on: Apr 7, 2019
 *      Author: alex
 */

#include "Command.h"
#include "Entity381.h"
#include "Utils.h"

Command::Command(Entity381* ent)
{
	entity = ent;
	isDone = false;
	physics = nullptr;
}

Command::~Command()
{

}

void Command::init()
{
	physics = (PhysicsAspect*) entity->GetAspect(1);
}

void Command::tick(float dt)
{

}

bool Command::done()
{
	return isDone;
}

MoveTo::MoveTo(Entity381* ent, Ogre::Vector3 target) : Command(ent)
{
	targetLocation = target;
	MOVE_DISTANCE_THRESHOLD = 100;
	acceptanceRadius = 5;
}

MoveTo::~MoveTo()
{

}

void MoveTo::tick(float dt)
{
	float distance = entity->mPosition->distance(targetLocation);

	//Ogre::Vector3 direction = entity->HeaderToDirection();
	//float turnAmt = direction.dotProduct(*entity->mPosition - targetLocation);
	//entity->desiredHeading += turnAmt;

	Ogre::Vector3 direction = targetLocation - *entity->mPosition;

	if (distance > acceptanceRadius)
	{
		//physics->Accelerate(acc);
		entity->desiredSpeed = entity->maxSpeed;
		entity->desiredHeading = FixAngle(Ogre::Math::ATan2(direction.x, direction.z).valueDegrees());
	}
	else
	{
		isDone = true;
	}
}

Intercept::Intercept(Entity381* ent, Ogre::Vector3 target) : Command(ent)
{
	targetLocation = target;
	MOVE_DISTANCE_THRESHOLD = 100;
	acceptanceRadius = 100;
}

Intercept::~Intercept()
{

}

void Intercept::tick(float dt)
{

}
