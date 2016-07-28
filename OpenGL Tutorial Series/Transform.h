#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>

class Transform 
{
public:
	Transform(const glm::vec3& translation = glm::vec3(), const glm::vec3& rotation = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0, 1.0, 1.0)) :
		mTranslation(translation),
		mRotation(rotation),
		mScale(scale) {}
	
	inline glm::mat4 GetModel() const {

		glm::mat4 translationMatrix = glm::translate(mTranslation);

		glm::vec3 radianRotation = glm::radians(mRotation);	// Convert degree rotation angles to radians.

		glm::quat quaternion	 = glm::quat(radianRotation); // Generate a quaternion from radian rotation.

		glm::mat4 rotationMatrix = glm::toMat4(quaternion); // Construct a matrix from the quaternion vector.

		glm::mat4 scaleMatrix = glm::scale(mScale);

		return translationMatrix * rotationMatrix * scaleMatrix;
	}

	inline void setTranslation(const glm::vec3& translation) { mTranslation = translation; }
	inline void setRotation(const glm::vec3& rotation) { mRotation = rotation; }
	inline void setScale(const glm::vec3& scale) { mScale = scale; }

	inline glm::vec3& GetTranslation() { return mTranslation; }
	inline glm::vec3& GetRotation() { return mRotation; }
	inline glm::vec3& GetScale() { return mScale; }


private:
	glm::vec3 mTranslation;
	glm::vec3 mRotation;
	glm::vec3 mScale;
};

#endif