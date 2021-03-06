#include "GameObject.h"
#include "Mesh.h"
#include "Material.h"
#include <glm/ext/matrix_transform.hpp>

GameObject::GameObject(Mesh* mesh, Material* material)
	: mesh(mesh), material(material), position(0.0f), rotation(0.0f), scale(1.0f)
{

}

void GameObject::setPosition(const glm::vec3& newPosition)
{
	position = newPosition;
}

void GameObject::setRotation(const glm::vec3& newRotation)
{
	rotation = newRotation;
}

void GameObject::setScale(const glm::vec3& newScale)
{
	scale = newScale;
}

Mesh* GameObject::getMesh() const
{
	return mesh;
}

Material* GameObject::getMaterial() const
{
	return material;
}

glm::mat4 GameObject::getModelMatrix() const
{
	return glm::translate(glm::mat4(1.0f), position) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)) *
		glm::scale(glm::mat4(1.0f), scale);
}

glm::vec3 GameObject::getPosition() const
{
	return position;
}

glm::vec3 GameObject::getRotation() const
{
	return rotation;
}

glm::vec3 GameObject::getScale() const
{
	return scale;
}
