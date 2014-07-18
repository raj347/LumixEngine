#pragma once


#include "core/lumix.h"
#include "core/string.h"
#include "core/vec3.h"
#include "universe/universe.h"


namespace Lumix
{


class Engine;


struct RaycastHit
{
	Vec3 position;
	Vec3 normal;
	Entity entity;
};


class LUMIX_PHYSICS_API PhysicsScene
{
	friend class PhysicsSystem;
	public:
		static PhysicsScene* create(PhysicsSystem& system, Universe& universe, Engine& engine);
		static void destroy(PhysicsScene* scene);
		
		virtual ~PhysicsScene() {}
		virtual void update(float time_delta) = 0;
		virtual void render() = 0;
		virtual bool raycast(const Vec3& origin, const Vec3& dir, float distance, RaycastHit& result) = 0;
		virtual Component createBoxRigidActor(Entity entity) = 0;
		virtual Component createMeshRigidActor(Entity entity) = 0;
		virtual Component createController(Entity entity) = 0;
		virtual Component createHeightfield(Entity entity) = 0;
		virtual PhysicsSystem& getSystem() const = 0;
		
		virtual void getIsDynamic(Component cmp, bool& is) = 0;
		virtual void setIsDynamic(Component cmp, const bool& is) = 0;
		virtual void getHalfExtents(Component cmp, Vec3& size) = 0;
		virtual void setHalfExtents(Component cmp, const Vec3& size) = 0;
		virtual void getShapeSource(Component cmp, string& str) = 0;
		virtual void setShapeSource(Component cmp, const string& str) = 0;
		virtual void getHeightmap(Component cmp, string& str) = 0;
		virtual void setHeightmap(Component cmp, const string& str) = 0;
		virtual void getHeightmapXZScale(Component cmp, float& scale) = 0;
		virtual void setHeightmapXZScale(Component cmp, const float& scale) = 0;
		virtual void getHeightmapYScale(Component cmp, float& scale) = 0;
		virtual void setHeightmapYScale(Component cmp, const float& scale) = 0;

		virtual void moveController(Component cmp, const Vec3& v, float dt) = 0;
	
		virtual void serialize(ISerializer& serializer) = 0;
		virtual void deserialize(ISerializer& serializer) = 0;
};


} // !namespace Lumix
