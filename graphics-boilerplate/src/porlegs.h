#include "main.h"

#ifndef Porlegs_H
#define Porlegs_H

class Porlegs{
public:
    Porlegs() {}
    Porlegs(float x, float y, color_t color,float speed_x);
    glm::vec3 position;
    float rotation;
    float speed_x;
    void draw(glm::mat4 VP);
    void tick(int num);
    void set_position(float x, float y);
private:
    VAO *object;

};

#endif // Porlegs_H
