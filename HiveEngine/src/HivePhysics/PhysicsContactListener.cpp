#include "HivePCH.h"
#include "PhysicsContactListener.h"
#include "HiveScene/GameObject.h"
#include "HiveHelpers/Structs.h"

void Hive::PhysicsContactListener::BeginContact(b2Contact* contact)
{
	b2Fixture * AFixture = contact->GetFixtureA();
	b2Fixture * BFixture = contact->GetFixtureB();

	if (AFixture->IsSensor()) // If A is the trigger
	{
		Collision trigger{};
		trigger.objHit = static_cast<GameObject*>(BFixture->GetUserData());
		trigger.contact = contact;

		trigger.objHit->OnTriggerEnter2D(trigger);
	}
	else if (BFixture->IsSensor()) // if B is the trigger
	{
		Collision trigger{};
		trigger.objHit = static_cast<GameObject*>(AFixture->GetUserData());
		trigger.contact = contact;

		trigger.objHit->OnTriggerEnter2D(trigger);
	}
	else // A AND B aren't triggers but did collide
	{
		Collision collisionA{}; // collision for object A
		collisionA.objHit = static_cast<GameObject*>(BFixture->GetUserData());
		collisionA.contact = contact;

		collisionA.objHit->OnCollisionEnter2D(collisionA);

		Collision collisionB{}; // collision for object B
		collisionB.objHit = static_cast<GameObject*>(AFixture->GetUserData());
		collisionB.contact = contact;

		collisionB.objHit->OnCollisionEnter2D(collisionB);
	}
}

void Hive::PhysicsContactListener::EndContact(b2Contact* contact)
{
	b2Fixture* AFixture = contact->GetFixtureA();
	b2Fixture* BFixture = contact->GetFixtureB();


	if (AFixture->IsSensor()) // If A is the trigger
	{
		Collision trigger{};
		trigger.objHit = static_cast<GameObject*>(BFixture->GetUserData());
		trigger.contact = contact;

		trigger.objHit->OnTriggerExit2D(trigger);
	}
	else if (BFixture->IsSensor()) // if B is the trigger
	{
		Collision trigger{};
		trigger.objHit = static_cast<GameObject*>(AFixture->GetUserData());
		trigger.contact = contact;

		trigger.objHit->OnTriggerExit2D(trigger);
	}
	else // A AND B aren't triggers but did collide
	{
		Collision collisionA{}; // collision for object A
		collisionA.objHit = static_cast<GameObject*>(BFixture->GetUserData());
		collisionA.contact = contact;

		collisionA.objHit->OnCollisionExit2D(collisionA);

		Collision collisionB{}; // collision for object B
		collisionB.objHit = static_cast<GameObject*>(AFixture->GetUserData());
		collisionB.contact = contact;

		collisionB.objHit->OnCollisionExit2D(collisionB);
	}
}

void Hive::PhysicsContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	UNREFERENCED_PARAMETER(contact);
	UNREFERENCED_PARAMETER(oldManifold);
	//throw std::logic_error("The method or operation is not implemented.");
}

void Hive::PhysicsContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
	UNREFERENCED_PARAMETER(contact);
	UNREFERENCED_PARAMETER(impulse);
//	throw std::logic_error("The method or operation is not implemented.");
}