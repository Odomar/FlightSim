#include <cmath>
#include <vector>
#include <iostream>
#include "glimac/common.hpp"
#include "glimac/Cube.hpp"
#include <glimac/glm.hpp>

#define OFFSET 16

namespace glimac {
	void Cube::build() {
        //Top
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(0., 1., 0.), glm::vec2(1., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(0., 1., 0.), glm::vec2(0., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(0., 1., 0.), glm::vec2(1., 0.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(0., 1., 0.), glm::vec2(0., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(0., 1., 0.), glm::vec2(1., 0.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 1.), glm::vec3(0., 1., 0.), glm::vec2(0., 0.)));
        //Bottom
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 0.), glm::vec3(0., 1., 0.), glm::vec2(1., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(0., 1., 0.), glm::vec2(1., 0.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(0., 1., 0.), glm::vec2(0., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(0., 1., 0.), glm::vec2(1., 0.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(0., 1., 0.), glm::vec2(0., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(0., 1., 0.), glm::vec2(0., 0.)));
        //Back
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(0., 0., 1.), glm::vec2(0., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(0., 0., 1.), glm::vec2(0., 0.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(0., 0., 1.), glm::vec2(1., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(0., 0., 1.), glm::vec2(0., 0.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(0., 0., 1.), glm::vec2(1., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 1.), glm::vec3(0., 0., 1.), glm::vec2(1., 0.)));
        //Front
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 0.), glm::vec3(0., 0., 1.), glm::vec2(1., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(0., 0., 1.), glm::vec2(0., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(0., 0., 1.), glm::vec2(1., 0.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(0., 0., 1.), glm::vec2(0., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(0., 0., 1.), glm::vec2(1., 0.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(0., 0., 1.), glm::vec2(0., 0.)));
        //Left
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(1., 0., 0.), glm::vec2(1., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(1., 0., 0.), glm::vec2(1., 0.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(1., 0., 0.), glm::vec2(0., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(1., 0., 0.), glm::vec2(1., 0.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(1., 0., 0.), glm::vec2(0., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 1.), glm::vec3(1., 0., 0.), glm::vec2(0., 0.)));
        //Right
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 0.), glm::vec3(1., 0., 0.), glm::vec2(0., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(1., 0., 0.), glm::vec2(1., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(1., 0., 0.), glm::vec2(0., 0.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(1., 0., 0.), glm::vec2(1., 1.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(1., 0., 0.), glm::vec2(0., 0.)));
        m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(1., 0., 0.), glm::vec2(1., 0.)));
	}

	void Cube::build(const std::pair<float, float> * texCoords) {
		// Top
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(0., 1., 0.), glm::vec2(texCoords[0].first + OFFSET, texCoords[0].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(0., 1., 0.), glm::vec2(texCoords[0].first, texCoords[0].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(0., 1., 0.), glm::vec2(texCoords[0].first + OFFSET, texCoords[0].second)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(0., 1., 0.), glm::vec2(texCoords[0].first, texCoords[0].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(0., 1., 0.), glm::vec2(texCoords[0].first + OFFSET, texCoords[0].second)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 1.), glm::vec3(0., 1., 0.), glm::vec2(texCoords[0].first, texCoords[0].second)));
		//Front
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 0.), glm::vec3(0., 0., 1.), glm::vec2(texCoords[1].first + OFFSET, texCoords[1].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(0., 0., 1.), glm::vec2(texCoords[1].first + OFFSET, texCoords[1].second)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(0., 0., 1.), glm::vec2(texCoords[1].first, texCoords[1].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(0., 0., 1.), glm::vec2(texCoords[1].first + OFFSET, texCoords[1].second)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(0., 0., 1.), glm::vec2(texCoords[1].first, texCoords[1].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(0., 0., 1.), glm::vec2(texCoords[1].first, texCoords[1].second)));
		//Right
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 0.), glm::vec3(1., 0., 0.), glm::vec2(texCoords[2].first, texCoords[2].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(1., 0., 0.), glm::vec2(texCoords[2].first + OFFSET, texCoords[2].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(1., 0., 0.), glm::vec2(texCoords[2].first, texCoords[2].second)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(1., 0., 0.), glm::vec2(texCoords[2].first + OFFSET, texCoords[2].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(1., 0., 0.), glm::vec2(texCoords[2].first, texCoords[2].second)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(1., 0., 0.), glm::vec2(texCoords[2].first + OFFSET, texCoords[2].second)));
		//Left
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(1., 0., 0.), glm::vec2(texCoords[3].first + OFFSET, texCoords[3].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(1., 0., 0.), glm::vec2(texCoords[3].first + OFFSET, texCoords[3].second)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(1., 0., 0.), glm::vec2(texCoords[3].first, texCoords[3].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(1., 0., 0.), glm::vec2(texCoords[3].first + OFFSET, texCoords[3].second)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(1., 0., 0.), glm::vec2(texCoords[3].first, texCoords[3].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 1.), glm::vec3(1., 0., 0.), glm::vec2(texCoords[3].first, texCoords[3].second)));
		//Back
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(0., 0., 1.), glm::vec2(texCoords[4].first, texCoords[4].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(0., 0., 1.), glm::vec2(texCoords[4].first, texCoords[4].second)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(0., 0., 1.), glm::vec2(texCoords[4].first + OFFSET, texCoords[4].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(0., 0., 1.), glm::vec2(texCoords[4].first, texCoords[4].second)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(0., 0., 1.), glm::vec2(texCoords[4].first + OFFSET, texCoords[4].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 1., 1.), glm::vec3(0., 0., 1.), glm::vec2(texCoords[4].first + OFFSET, texCoords[4].second)));
		//Bottom
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 0.), glm::vec3(0., 1., 0.), glm::vec2(texCoords[5].first + OFFSET, texCoords[5].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(0., 1., 0.), glm::vec2(texCoords[5].first + OFFSET, texCoords[5].second)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(0., 1., 0.), glm::vec2(texCoords[5].first, texCoords[5].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(0., 1., 0.), glm::vec2(texCoords[5].first + OFFSET, texCoords[5].second)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(0., 1., 0.), glm::vec2(texCoords[5].first, texCoords[5].second + OFFSET)));
		m_Vertices.emplace_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(0., 1., 0.), glm::vec2(texCoords[5].first, texCoords[5].second)));
	}
}
