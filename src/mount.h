#include "main.h"

#ifndef Mount_H
#define Mount_H

class Mount{
public:
    Mount() {}
    Mount(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
private:
    VAO *object;

};

#endif // Mount_H
