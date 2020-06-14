#include "HivePCH.h"
#include "PhysicsContactListener.h"
#include "HiveScene/GameObject.h"
#include "HiveHelpers/Structs.h"
#include "HiveComponents/ColliderComponent.h"

void Hive::PhysicsContactListener::BeginContact(b2Contact* contact)
{
	b2Fixture * AFixture = contact->GetFixtureA();
	b2Fixture * BFixture = contact->GetFixtureB();

	if (!BFixture || !AFixture) return;

	if (AFixture->IsSensor()) // If A is the trigger
	{
		Collision trigger{};
		trigger.objHit = static_cast<ColliderComponent*>(BFixture->GetUserData())->gameObject;
		trigger.contact = contact;

		trigger.objHit->OnTriggerEnter2D(trigger);
	}
	else if (BFixture->IsSensor()) // if B is the trigger
	{
		Collision trigger{};
		trigger.objHit = static_cast<ColliderComponent*>(AFixture->GetUserData())->gameObject;
		trigger.contact = contact;

		trigger.objHit->OnTriggerEnter2D(trigger);
	}
	else // A AND B aren't triggers but did collide
	{
		Collision collisionA{}; // collision for object A
		collisionA.objHit = static_cast<ColliderComponent*>(BFixture->GetUserData())->gameObject;
		collisionA.contact = contact;

		collisionA.objHit->OnCollisionEnter2D(collisionA);

		Collision collisionB{}; // collision for object B
		collisionB.objHit = static_cast<ColliderComponent*>(AFixture->GetUserData())->gameObject;
		collisionB.contact = contact;

		collisionB.objHit->OnCollisionEnter2D(collisionB);
	}
}

void Hive::PhysicsContactListener::EndContact(b2Contact* contact)
{
	b2Fixture* AFixture = contact->GetFixtureA();
	b2Fixture* BFixture = contact->GetFixtureB();

	if (!BFixture || !AFixture) return;


	if (AFixture->IsSensor()) // If A is the trigger
	{
		Collision trigger{};
		trigger.objHit = static_cast<ColliderComponent*>(BFixture->GetUserData())->gameObject;
		trigger.contact = contact;

		trigger.objHit->OnTriggerExit2D(trigger);
	}
	else if (BFixture->IsSensor()) // if B is the trigger
	{
		Collision trigger{};
		trigger.objHit = static_cast<ColliderComponent*>(AFixture->GetUserData())->gameObject;
		trigger.contact = contact;

		trigger.objHit->OnTriggerExit2D(trigger);
	}
	else // A AND B aren't triggers but did collide
	{
		Collision collisionA{}; // collision for object A
		collisionA.objHit = static_cast<ColliderComponent*>(BFixture->GetUserData())->gameObject;
		collisionA.contact = contact;

		collisionA.objHit->OnCollisionExit2D(collisionA);

		Collision collisionB{}; // collision for object B
		collisionB.objHit = static_cast<ColliderComponent*>(AFixture->GetUserData())->gameObject;
		collisionB.contact = contact;

		collisionB.objHit->OnCollisionExit2D(collisionB);
	}
}

void Hive::PhysicsContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	UNREFERENCED_PARAMETER(oldManifold);

	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture * fixtureB = contact->GetFixtureB();
	ColliderComponent* colliderA = static_cast<ColliderComponent*>(fixtureA->GetUserData());
	ColliderComponent* colliderB = static_cast<ColliderComponent*>(fixtureB->GetUserData());

	if (!colliderA->IsActive() || !colliderB->IsActive())
		contact->SetEnabled(false);

}

void Hive::PhysicsContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
	UNREFERENCED_PARAMETER(contact);
	UNREFERENCED_PARAMETER(impulse);

}