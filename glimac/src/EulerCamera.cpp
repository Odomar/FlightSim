#include <iostream>

#include <cmath>

#include "glimac/EulerCamera.hpp"


namespace glimac {
	// Constructor with player's position
	EulerCamera::EulerCamera(float x, float y, float z) : position(glm::vec3(x, y, z)) {
	}

	void EulerCamera::clampPosition(int limit) {
		position = glm::vec3(
				fmax(fmin(position.x, limit), 0),
				fmax(fmin(position.y, limit), 0),
				fmax(fmin(position.z, limit), 0));
	}

	void EulerCamera::moveFront(float t, int limit) {
		position += t * frontVector;
		clampPosition(limit);
	}

	void EulerCamera::rotateRoll(float degrees) {
		float angle = (degrees * glm::pi<float>()) / 180.f;
		rightVector = glm::normalize(rightVector * glm::cos(angle) + upVector * glm::sin(angle));
		upVector = glm::cross(rightVector, frontVector);
	}

	void EulerCamera::rotatePitch(float degrees) {
		float angle = (degrees * glm::pi<float>()) / 180.f;
		frontVector = glm::normalize(frontVector * glm::cos(angle) + upVector * glm::sin(angle));
		upVector = glm::cross(rightVector, frontVector);
	}

	void EulerCamera::rotateYaw(float degrees) {
		float angle = (degrees * glm::pi<float>()) / 180.f;
		rightVector = glm::normalize(rightVector * glm::cos(angle) + frontVector * glm::sin(angle));
		frontVector = glm::cross(upVector, rightVector);
	}

	glm::mat4 EulerCamera::getViewMatrix() {
		return glm::lookAt(position, position + frontVector, upVector);
	}
}
