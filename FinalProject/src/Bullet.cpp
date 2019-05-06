#include "Bullet.h"
#include "Engine.h"
#include "EntityMgr.h"
#include "InputMgr.h"

Bullet::Bullet (
	Ogre::SceneManager* manager,
	EntityMgr* entityMgr,
	int entityId,
	std::string entityName,
	std::string meshFileName,
	Ogre::Vector3 position,
	Ogre::Quaternion orientation)
: Entity381 (manager,entityMgr,entityId,entityName,meshFileName,position,
	orientation)
{
	mTag = "Bullet";

	targetPosition = Ogre::Vector3(0,0,999999);
	mSpeed = 200.0f;
}

Bullet::~Bullet()
{

}

void Bullet::Initialize()
{
	// create and attach entity and scene node
	mEntity = mSceneMgr->createEntity(mMeshFileName);
	mSceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mEntityName + "Node");
	mSceneNode->attachObject(mEntity);

	// create the aspects
	RenderableAspect* renderable = new RenderableAspect(this);
	PhysicsAspect* physics = new PhysicsAspect(this);
	CollisionAspect* collisions = new CollisionAspect(this);

	// add the aspects
	this->AddAspect(renderable);
	this->AddAspect(physics);
	this->AddAspect(collisions);
}

void Bullet::Tick(float dt)
{

}
