#include "main.h"

#ifndef TRAMPLEGS_H
#define TRAMPLEGS_H

class Tramplegs{
public:
    Tramplegs() {}
    Tramplegs(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
//    void set_position(float x, float y);
//bounding_box_t2 bounding_box();
private:
    VAO *object;

};

#endif // TRAMPOLINE_H
