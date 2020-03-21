#include <iostream>
#include <algorithm>
#include <thread>

#include <GL/glew.h>

#include <glimac/glm.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <glimac/common.hpp>
#include <glimac/SkyBox.hpp>
#include <glimac/CubeProgram.hpp>
#include <glimac/SkyboxProgram.hpp>
#include <glimac/EulerCamera.hpp>
#include <glimac/MatrixCamera.hpp>
#include <glimac/QuaternionCamera.hpp>

#define VERTEX_ATTR_POSITION 0
#define VERTEX_ATTR_NORMAL 1
#define VERTEX_ATTR_TEXTURE 2

#define FRAMERATE 60

#define SIZE 512. // X

using namespace glimac;
using namespace std;

int main(int argc, char** argv) {
	// Initialize SDL and open a window
	const float windowWidth = 1920.f;
	const float windowHeight = 1080.f;
	SDLWindowManager windowManager(windowWidth, windowHeight, "MasterCraft");

	// Initialize glew for OpenGL3+ support
	GLenum glewInitError = glewInit();
	if(GLEW_OK != glewInitError) {
		std::cerr << glewGetErrorString(glewInitError) << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

	if(-1 == SDL_EnableKeyRepeat(10, 10)) {
		return EXIT_FAILURE;
	}
	// Night texture loading
	std::unique_ptr<Image> skybox = loadImage("../FlightSim/Main/assets/textures/night.PNG");
	if(skybox == nullptr) {
		std::cerr << "Can't load night skybox's textures map" << std::endl;
		return EXIT_FAILURE;
	}

	// Charge les shaders
	FilePath applicationPath(argv[0]);
	CubeProgram cubeProgram(applicationPath);
	SkyBoxProgram skyBoxProgram(applicationPath);

	/*********************************
	 * HERE SHOULD COME THE INITIALIZATION CODE
	 *********************************/

	glEnable(GL_DEPTH_TEST);

	//-----------------------Skybox initialization-----------------------//

	// Sky vbo
	SkyBox cube;
	GLint n = cube.getVertexCount();
	const ShapeVertex* vertices = cube.getDataPointer();
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, n * sizeof(ShapeVertex), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//Sky vao
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
	glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
	glEnableVertexAttribArray(VERTEX_ATTR_TEXTURE);
	glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), nullptr);
	glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex),(const GLvoid*)(offsetof(ShapeVertex, normal)));
	glVertexAttribPointer(VERTEX_ATTR_TEXTURE, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex),(const GLvoid*)(offsetof(ShapeVertex, texCoords)));
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//-----------------------Textures-----------------------//

	// skybox
	GLuint skyTextures;
	glGenTextures(1, &skyTextures);
	glBindTexture(GL_TEXTURE_2D, skyTextures);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, skybox->getWidth(), skybox->getHeight(), 0, GL_RGBA, GL_FLOAT, skybox->getPixels());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

	//---------------- Initializations --------------------//

	bool done = false;
	float speed = 0.25;
//	EulerCamera camera(SIZE / 2, SIZE / 2, SIZE - 1);
//	MatrixCamera camera(SIZE / 2, SIZE / 2, SIZE - 1);
	QuaternionCamera camera(SIZE / 2, SIZE / 2, SIZE - 1);
	glm::mat4 viewMatrix = camera.getViewMatrix();
	glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), windowWidth/windowHeight, 0.1f, 1000.f);
	glm::mat4 MVMatrix, NormalMatrix;

	int lastMousePosX, lastMousePosY;

	//---------------- Application loop --------------------//

	std::chrono::system_clock::time_point a;
	std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
	constexpr float duration_ms = (1. / FRAMERATE) * 1000.;

	while(!done) {
		// sleep if framerate is too high
		a = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> work_time = a - b;

		if (work_time.count() < duration_ms)
		{
			std::chrono::duration<double, std::milli> delta_ms(duration_ms - work_time.count());
			auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
			std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
		}

		b = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> sleep_time = b - a;

		SDL_GetRelativeMouseState(&lastMousePosX, &lastMousePosY);

		/*********************************
		 * HERE SHOULD COME THE RENDERING CODE
		 *********************************/

		// Event loop:
		SDL_Event e;
		while(windowManager.pollEvent(e)) {
			if(e.type == SDL_QUIT) {
				done = true; // Leave the loop after this iteration
			}
			// Keyboard
			if(e.type == SDL_KEYDOWN) {
				if(e.key.keysym.sym == SDLK_ESCAPE) {
					done = true; // Quit
				}
				if(e.key.keysym.sym == SDLK_q) {
					camera.rotateYaw(0.25);
				}
				if(e.key.keysym.sym == SDLK_d) {
					camera.rotateYaw(-0.25);
				}
				if(e.key.keysym.sym == SDLK_z) {
					camera.rotatePitch(0.25);
				}
				if(e.key.keysym.sym == SDLK_s) {
					camera.rotatePitch(-0.25);
				}
				if(e.key.keysym.sym == SDLK_a) {
					camera.rotateRoll(0.5);
				}
				if(e.key.keysym.sym == SDLK_e) {
					camera.rotateRoll(-0.5);
				}
				if(e.key.keysym.sym == SDLK_SPACE) {
					if(speed > 0) {
						speed = 0;
					}
				}
			}
			if(e.type == SDL_KEYUP) {
				if(speed == 0 && e.key.keysym.sym == SDLK_SPACE) {
					speed = 0.25;
				}
			}
		}

		camera.moveFront(speed, SIZE);

		viewMatrix = camera.getViewMatrix();

		glBindVertexArray(vao);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//---------------- skybox and lightning TO OPTIMIZE --------------------//

		skyBoxProgram.m_Program.use();
		glm::vec4 lightMMatrix =  glm::rotate(glm::mat4(1), windowManager.getTime() / 5, glm::vec3(0, 0, 1)) * glm::vec4(16 * 8 * 4, 128, 16 * 8 * 4, 0);
		glm::vec4 lightMVMatrix = viewMatrix * lightMMatrix;

		// draw the skybox and init light coeffs according the time
		MVMatrix = glm::scale(viewMatrix, glm::vec3(SIZE, SIZE, SIZE));
//		MVMatrix = glm::scale(viewMatrix, glm::vec3(1, 1, 1));
//		MVMatrix = glm::translate(MVMatrix, camera.getPosition() - glm::vec3(0.5, 0.5, 0.5));
		NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
		glUniformMatrix4fv(skyBoxProgram.uNormalMatrix, 1, GL_FALSE , glm::value_ptr(NormalMatrix));
		glUniformMatrix4fv(skyBoxProgram.uMVMatrix, 1, GL_FALSE , glm::value_ptr(MVMatrix));
		glUniformMatrix4fv(skyBoxProgram.uMVPMatrix, 1, GL_FALSE , glm::value_ptr(ProjMatrix * MVMatrix));
		glActiveTexture(GL_TEXTURE0);

		glBindTexture(GL_TEXTURE_2D, skyTextures);

		//Draw the skybox
		glUniform1i(skyBoxProgram.uTexture, 0);
		glDepthMask(GL_FALSE);
		glDrawArrays(GL_TRIANGLES, 0, n);
		glDepthMask(GL_TRUE);

		glBindVertexArray(0);
		windowManager.swapBuffers();
	}

	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
	glDeleteTextures(1, &skyTextures);

	return EXIT_SUCCESS;
}
