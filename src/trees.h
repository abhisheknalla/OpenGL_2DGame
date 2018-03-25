#include "main.h"

#ifndef TREES_H
#define TREES_H

class Trees{
public:
    Trees() {}
    Trees(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
private:
    VAO *object;

};

#endif // Trees_H
