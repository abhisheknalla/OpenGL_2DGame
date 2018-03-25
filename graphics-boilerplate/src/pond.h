#include "main.h"

#ifndef POND_H
#define POND_H

class Pond {
public:
    Pond() {}
    Pond(float x, float y, color_t color, int flag);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
   void set_position(float x, float y);
private:
    VAO *object;

};

#endif // BALL_H
