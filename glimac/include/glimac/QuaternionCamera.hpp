#include <glm/glm.hpp>
#include <glimac/glm.hpp>
#include <cmath>
#include "Camera.hpp"
#include <c3ga/Mvec.hpp>

namespace glimac {

	class QuaternionCamera : public Camera{
	public:
		QuaternionCamera(float x, float y, float z);

		void moveFront(float t, int limit) override;
		void rotateYaw(float degrees) override;
		void rotatePitch(float degrees) override;
		void rotateRoll(float degrees) override;
		glm::mat4 getViewMatrix() override;

	private:
		c3ga::Mvec<float> position;

		c3ga::Mvec<float> frontVector = c3ga::e23<float>();
		c3ga::Mvec<float> rightVector = c3ga::e13<float>();
		c3ga::Mvec<float> upVector = c3ga::e12<float>();

		void clampPosition(int limit);
		void rotateAxes(const c3ga::Mvec<float> & R);
	};

}
