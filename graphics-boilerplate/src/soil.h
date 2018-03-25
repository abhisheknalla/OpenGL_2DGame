#include "main.h"

#ifndef SOIL_H
#define SOIL_H

class Soil {
public:
    Soil() {}
    Soil(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
  //  void set_position(float x, float y);
private:
    VAO *object;

};

#endif // BALL_H
