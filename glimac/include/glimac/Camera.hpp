#include <glm/glm.hpp>
#pragma once
namespace glimac {
	class Camera {
		virtual void moveFront(float t, int limit) = 0;
		virtual void rotateYaw(float degrees) = 0;
		virtual void rotatePitch(float degrees) = 0;
		virtual void rotateRoll(float degrees) = 0;
		virtual glm::mat4 getViewMatrix() = 0;
	};
}