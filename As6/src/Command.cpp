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


