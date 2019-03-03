#ifndef INC_ENTITY381_H_
#define INC_ENTITY381_H_

#include <vector>
#include <string>

#include "Aspect.h"
#include "RenderableAspect.h"
#include "PhysicsAspect.h"
#include "RotatorAspect.h"

#include <OgreVector3.h>
#include <OgreSceneManager.h>

class Entity381
{
public:
	Entity381 (Ogre::SceneManager* manager, RenderableAspect::Types type, std::string name, bool isSubClass);
	~Entity381 ();

	void Tick (float dt); // The update function
	void SetPosition (Ogre::Vector3* pos);
	void TranslatePosition (Ogre::Vector3* trans);
	void Initialize (Ogre::SceneManager* manager, RenderableAspect::Types type, std::string name);  // Call this after a subclass is constructed

	Ogre::Entity* mEntity = nullptr;
	Ogre::SceneNode* mSceneNode = nullptr;
	Ogre::Vector3* mPosition = nullptr;
	Ogre::Vector3* mVelocity = nullptr;
	Ogre::SceneManager* mSceneMgr = nullptr;

	// As3
	int entityID = -1;
	std::string entityName;

	float minSpeed = 0;
	float maxSpeed = 100;
	float speed = 0;  // The current speed, [minSpeed, maxSpeed]
	float desiredSpeed = 0; // The speed to accelerate to
	float acceleration = 5;

	float heading = 0;  // [0, 360)
	float desiredHeading = 0;  // The heading to rotate to
	float turnRate = 5;

	std::string meshFileName;


	void AddAspect (Aspect* aspect);

	Aspect* GetAspect (int index);

private:
	std::vector<Aspect*>* aspects;

};

class SphereEntity381 : public Entity381
{
public:
	SphereEntity381 (Ogre::SceneManager* manager, RenderableAspect::Types type, std::string name);
};



#endif /* INC_ENTITY381_H_ */
