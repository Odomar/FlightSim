#include <cmath>
#include "glimac/MatrixCamera.hpp"

namespace glimac {

	MatrixCamera::MatrixCamera(float x, float y, float z) : position(glm::vec3(x, y, z)){
		updateViewMatrix();
	}

	void MatrixCamera::updateViewMatrix() {
		glm::mat4 matRoll = glm::mat4(1.0f);
		glm::mat4 matPitch = glm::mat4(1.0f);
		glm::mat4 matYaw = glm::mat4(1.0f);

		matRoll = glm::rotate(matRoll, -roll, glm::vec3(0.0f, 0.0f, 1.0f));
		matPitch = glm::rotate(matPitch, -pitch, glm::vec3(1.0f, 0.0f, 0.0f));
		matYaw = glm::rotate(matYaw, -yaw, glm::vec3(0.0f, 1.0f, 0.0f));

		glm::mat4 rotate = matYaw * matPitch * matRoll;

		glm::mat4 translate = glm::mat4(1.0f);
		translate = glm::translate(translate, -position);

		viewMatrix = rotate * translate;
	}

	void MatrixCamera::rotateYaw(float degrees) {
		yaw += (degrees * glm::pi<float>()) / 180.f;
	}

	void MatrixCamera::rotatePitch(float degrees) {
		pitch += (degrees * glm::pi<float>()) / 180.f;
	}

	void MatrixCamera::rotateRoll(float degrees) {
		roll += (degrees * glm::pi<float>()) / 180.f;
	}

	glm::vec3 MatrixCamera::getPosition() {
		return position;
	}

	void MatrixCamera::moveFront(float t, int limit) {
		glm::vec3 frontVector = -glm::vec3(viewMatrix[0][2], viewMatrix[1][2], viewMatrix[2][2]);
		position += t * frontVector;
		clampPosition(limit);
	}

	void MatrixCamera::clampPosition(double limit) {
		position = glm::vec3(
				fmax(fmin(position.x, limit), 0),
				fmax(fmin(position.y, limit), 0),
				fmax(fmin(position.z, limit), 0));
	}

	glm::mat4 MatrixCamera::getViewMatrix() {
		updateViewMatrix();
		return viewMatrix;
	}
}
