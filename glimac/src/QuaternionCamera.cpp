#include "glimac/QuaternionCamera.hpp"

namespace glimac {
	QuaternionCamera::QuaternionCamera(float x, float y, float z) {
		position[c3ga::E1] = x;
		position[c3ga::E2] = y;
		position[c3ga::E3] = z;
		position[c3ga::Ei] = 0.5 * (x*x + y*y + z*z);
		position[c3ga::E0] = 1.0;
	}

	c3ga::Mvec<float> translator(float x, float y, float z) {
		c3ga::Mvec<float> t = x * c3ga::e1<float>() + y * c3ga::e2<float>() + z * c3ga::e3<float>();
		return 1 - 0.5 * t * c3ga::ei<float>();
	}

	c3ga::Mvec<float> rotor(const c3ga::Mvec<float> & B, float d) {
		float a = (d * glm::pi<float>()) / 180.f;
		return std::cos(0.5 * a) + std::sin(0.5 * a) * B;
	}

	void QuaternionCamera::rotateAxes(const c3ga::Mvec<float> & R) {
		frontVector = R * frontVector / R;
		rightVector = R * rightVector / R;
		upVector = R * upVector / R;
	}

	void QuaternionCamera::rotateYaw(float degrees) {
		c3ga::Mvec<float> yaw = rotor(upVector, degrees);
		rotateAxes(yaw);
	}

	void QuaternionCamera::rotatePitch(float degrees) {
		c3ga::Mvec<float> pitch = rotor(rightVector, degrees);
		rotateAxes(pitch);
	}

	void QuaternionCamera::rotateRoll(float degrees) {
		c3ga::Mvec<float> roll = rotor(frontVector, degrees);
		rotateAxes(roll);
	}

	void QuaternionCamera::moveFront(float t, int limit) {
		c3ga::Mvec<float> T = translator(-t * frontVector[c3ga::E13], -t * frontVector[c3ga::E12], -t * frontVector[c3ga::E23]);
		position = T * position / T;
		clampPosition(limit);
	}

	glm::mat4 QuaternionCamera::getViewMatrix() {
		// define glm vectors to use in lookat
		glm::vec3 glmPosition(position[c3ga::E1], position[c3ga::E2], position[c3ga::E3]);
		glm::vec3 glmFrontVector(-frontVector[c3ga::E13], -frontVector[c3ga::E12], -frontVector[c3ga::E23]);
		glm::vec3 glmUpVector(upVector[c3ga::E13], upVector[c3ga::E12], upVector[c3ga::E23]);
		return glm::lookAt(glmPosition, glmPosition + glmFrontVector, glmUpVector);
	}

	void QuaternionCamera::clampPosition(int limit) {
		position[c3ga::E1] = fmax(fmin(position[c3ga::E1], limit), 0),
		position[c3ga::E3] = fmax(fmin(position[c3ga::E3], limit), 0),
		position[c3ga::E2] = fmax(fmin(position[c3ga::E2], limit), 0);

		float x = position[c3ga::E1];
		float y = position[c3ga::E2];
		float z = position[c3ga::E3];
		position[c3ga::Ei] = 0.5 * (x*x + y*y + z*z);
		position[c3ga::E0] = 1.0;
	}
}