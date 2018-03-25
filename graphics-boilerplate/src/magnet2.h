#include "main.h"

#ifndef Magnet2_H
#define Magnet2_H

class Magnet2{
public:
    Magnet2() {}
    Magnet2(float x, float y, color_t color, int type);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
private:
    VAO *object;

};

#endif // Magnet_H
