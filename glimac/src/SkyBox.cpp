#include <cmath>
#include <vector>
#include <iostream>
#include "glimac/common.hpp"
#include "glimac/SkyBox.hpp"
#include <glimac/glm.hpp>

namespace glimac {
	void SkyBox::build() {
        //Top
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(0., 1., 0.), glm::vec2(0.5, 1./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(0., 1., 0.), glm::vec2(0.25, 1./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(0., 1., 0.), glm::vec2(0.5, 0.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(0., 1., 0.), glm::vec2(0.25, 1./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(0., 1., 0.), glm::vec2(0.5, 0.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 1., 1.), glm::vec3(0., 1., 0.), glm::vec2(0.25, 0.)));
        //Bottom
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 0., 0.), glm::vec3(0., 1., 0.), glm::vec2(0.5, 1.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(0., 1., 0.), glm::vec2(0.5, 2./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(0., 1., 0.), glm::vec2(0.25, 1.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(0., 1., 0.), glm::vec2(0.5, 2./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(0., 1., 0.), glm::vec2(0.25, 1.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(0., 1., 0.), glm::vec2(0.25, 2./3.)));
        //Back
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(0., 0., 1.), glm::vec2(0.75, 2./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(0., 0., 1.), glm::vec2(0.75, 1./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(0., 0., 1.), glm::vec2(1., 2./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(0., 0., 1.), glm::vec2(0.75, 1./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(0., 0., 1.), glm::vec2(1., 2./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 1., 1.), glm::vec3(0., 0., 1.), glm::vec2(1., 1./3.)));
        //Front
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 0., 0.), glm::vec3(0., 0., 1.), glm::vec2(0.5, 2./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(0., 0., 1.), glm::vec2(0.25, 2./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(0., 0., 1.), glm::vec2(0.5, 1./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(0., 0., 1.), glm::vec2(0.25, 2./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(0., 0., 1.), glm::vec2(0.5, 1./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(0., 0., 1.), glm::vec2(0.25, 1./3.)));
        //Left
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 0., 0.), glm::vec3(1., 0., 0.), glm::vec2(0.25, 2./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(1., 0., 0.), glm::vec2(0.25, 1./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(1., 0., 0.), glm::vec2(0., 2./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 1., 0.), glm::vec3(1., 0., 0.), glm::vec2(0.25, 1./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 0., 1.), glm::vec3(1., 0., 0.), glm::vec2(0., 2./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(1., 1., 1.), glm::vec3(1., 0., 0.), glm::vec2(0., 1./3.)));
        //Right
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 0., 0.), glm::vec3(1., 0., 0.), glm::vec2(0.5, 2./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(1., 0., 0.), glm::vec2(0.75, 2./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(1., 0., 0.), glm::vec2(0.5, 1./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 0., 1.), glm::vec3(1., 0., 0.), glm::vec2(0.75, 2./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 1., 0.), glm::vec3(1., 0., 0.), glm::vec2(0.5, 1./3.)));
        m_Vertices.push_back(ShapeVertex(glm::vec3(0., 1., 1.), glm::vec3(1., 0., 0.), glm::vec2(0.75, 1./3.)));
	}
}
