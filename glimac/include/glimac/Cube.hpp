#pragma once

#include <vector>

#include "common.hpp"

namespace glimac {

    class Cube {
        // Alloue et construit les données (implantation dans le .cpp)
        void build(const std::pair<float, float> texCoords[6]);
        void build();

    public:
        // Constructeur: alloue le tableau de données et construit les attributs des vertex
        Cube(): m_nVertexCount(36) {
            build(); // Construction (voir le .cpp)
        }
        explicit Cube(const std::pair<float, float> texCoords[6]): m_nVertexCount(36) {
            build(texCoords); // Construction (voir le .cpp)
        }

        // Renvoit le pointeur vers les données
        const ShapeVertex* getDataPointer() const {
            return &m_Vertices[0];
        }

        // Renvoit le nombre de vertex
        GLsizei getVertexCount() const {
            return m_nVertexCount;
        }

    private:
        std::vector<ShapeVertex> m_Vertices; // Sommets
        GLsizei m_nVertexCount; // Nombre de sommets
    };

}
