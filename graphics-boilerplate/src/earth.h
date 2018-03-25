#include "main.h"

#ifndef EARTH_H
#define EARTH_H

class Earth {
public:
    Earth() {}
    Earth(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
  //  void set_position(float x, float y);
private:
    VAO *object;

};

#endif // BALL_H
