/*
 * Command.h
 *
 *  Created on: Mar 28, 2018
 *      Author: sushil
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <PhysicsAspect.h>
#include <OgreVector3.h>

/*
enum COMMAND_TYPE
{
	MOVE_TO_COMMAND,
	INTERCEPT_COMMAND
};
*/

class Entity381;

class Command {

public:
	Command(Entity381* ent);
	virtual ~Command();

	void init();
	virtual void tick(float dt);
	virtual bool done();

	Entity381* entity;
	PhysicsAspect* physics;

protected:
	bool isDone;
	bool runOnce;
	float startingDistance;

};

class MoveTo : public Command {

public:
	MoveTo(Entity381* ent, Ogre::Vector3 target);
	~MoveTo();

	void tick(float dt);

	Ogre::Vector3 targetLocation;
	float MOVE_DISTANCE_THRESHOLD;

	float acceptanceRadius;
};

class Intercept : public Command {

public:
	Intercept(Entity381* ent, Entity381* target);
	~Intercept();

	void tick(float dt);

	Entity381* targetEntity;
	float MOVE_DISTANCE_THRESHOLD;

	float acceptanceRadius;

private:
	Ogre::Vector3 lastTargetPosition;
};


#endif /* COMMAND_H_ */
