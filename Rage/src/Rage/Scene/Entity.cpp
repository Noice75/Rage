#include "rapch.h"
#include "Entity.h"

namespace Rage {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}