#include <glm/glm.hpp>
#include <glimac/glm.hpp>
#include <cmath>
#include "Camera.hpp"

namespace glimac {

	class EulerCamera : public Camera {
	public:
	    EulerCamera(float x, float y, float z);

		void moveFront(float t, int limit) override;
	    void rotateYaw(float degrees) override;
		void rotatePitch(float degrees) override;
		void rotateRoll(float degrees) override;
	    glm::vec3 getPosition() override;
	    glm::mat4 getViewMatrix() override;

	private:
		glm::vec3 position;

	    glm::vec3 frontVector = glm::vec3(0, 0, -1);
		glm::vec3 rightVector = glm::vec3(1, 0, 0);
		glm::vec3 upVector = glm::vec3(0, 1, 0);

		void clampPosition(int limit);
	};

}
