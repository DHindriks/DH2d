#ifndef ENTITY_H
#define ENTITY_H

#include <glm/glm.hpp>
#include <common\vectorx.h>
#include <common\sprite.h>

class Entity
{
public:
	Entity();
	Point3 position;
	Point3 rotation;
	Point3 scale;
	float collisionrange;

	

	virtual ~Entity();

};

#endif /* ENTITY_H */