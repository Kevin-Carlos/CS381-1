#ifndef INC_ENTITY381_H_
#define INC_ENTITY381_H_

#include <vector>
#include <string>

#include "Aspect.h"
#include "RenderableAspect.h"
#include "PhysicsAspect.h"
#include "RotatorAspect.h"
#include "UnitAI.h"

#include <OgreVector3.h>
#include <OgreSceneManager.h>

class Entity381
{
public:
	Entity381 (
		Ogre::SceneManager* manager,
		int entityId,
		std::string entityName,
		std::string meshFileName = "cube.mesh",
		Ogre::Vector3 position = Ogre::Vector3::ZERO,
		Ogre::Quaternion orientation = Ogre::Quaternion::IDENTITY);
	~Entity381 ();

	void Initialize ();
	void Tick (float dt); // The update function

	void ShowAABB (bool state);

	void AddAspect (Aspect* aspect);

	Aspect* GetAspect (int index);

	//void TranslatePosition (Ogre::Vector3* trans);
	//Ogre::Vector3 HeaderToDirection();

	Ogre::Entity* mEntity = nullptr;
	Ogre::SceneNode* mSceneNode = nullptr;
	Ogre::Vector3 mPosition;
	Ogre::Vector3 mVelocity;
	Ogre::Quaternion mOrientation;
	Ogre::SceneManager* mSceneMgr = nullptr;

	int mEntityID;
	std::string mEntityName;
	std::string mMeshFileName;

	float mSpeed = 0;
	float mTurnRate = 5;

private:
	std::vector<Aspect*>* mAspects;

};

#endif /* INC_ENTITY381_H_ */