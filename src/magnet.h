#include "main.h"

#ifndef Magnet_H
#define Magnet_H

class Magnet{
public:
    Magnet() {}
    Magnet(float x, float y, color_t color, int type);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
private:
    VAO *object;

};

#endif // Magnet_H
