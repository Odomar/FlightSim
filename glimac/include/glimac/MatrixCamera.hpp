#include <glm/glm.hpp>
#include <glimac/glm.hpp>
#include <cmath>
#include "Camera.hpp"

namespace glimac {
	class MatrixCamera : public Camera {
	public:
		MatrixCamera(float x, float y, float z);

		void moveFront(float t, int limit) override;
		void rotateYaw(float degrees) override;
		void rotatePitch(float degrees) override;
		void rotateRoll(float degrees) override;
		glm::mat4 getViewMatrix() override;

	private:
		glm::vec3 position;

		float roll = 0;
		float pitch = 0;
		float yaw = 0;

		void clampPosition(double limit);
		void updateViewMatrix();

		glm::mat4 viewMatrix;
	};
}
