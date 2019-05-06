/**
 * Class name: Bullet
 * Made by: Alex Kastanek
 * Date: May 5, 2019
 * Description: This is the bullet object shot by the player
 * 	and enemy ai. It inherits from entity381, but is always
 * 	moving forward at speed and checking for collisions.
 */

#include "Entity381.h"

#ifndef _BULLET_H
#define _BULLET_H

class Bullet : public Entity381
{
public:
	Bullet(
		Ogre::SceneManager* manager,
		EntityMgr* entityMgr,
		int entityId,
		std::string entityName,
		std::string meshFileName = "cube.mesh",
		Ogre::Vector3 position = Ogre::Vector3::ZERO,
		Ogre::Quaternion orientation = Ogre::Quaternion::IDENTITY);
	~Bullet();

	void Initialize();
	void Tick(float dt);
};

#endif /* _BULLET_H */
