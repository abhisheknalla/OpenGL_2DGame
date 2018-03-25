#include "main.h"

#ifndef PORCUPINE_H
#define PORCUPINE_H

class Porcupine{
public:
    Porcupine() {}
    Porcupine(float x, float y, color_t color, float speed_x);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    float speed_x;
    void tick(int num);
    bounding_box_t bounding_box();
private:
    VAO *object;

};

#endif // Porcupine_H
