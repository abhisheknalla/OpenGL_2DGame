#include "main.h"

#ifndef SLAB_H
#define SLAB_H


class Slab {
public:
    Slab() {}
    Slab(float x, float y, color_t color, float speed_x, float speed_y, float ball_size, int angle);
    float speed_x;
    float speed_y;
    int flag_air;
    float radius;
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(float speed, float new_pos);
    color_t col;
    double speed;
    bounding_box_t2 bounding_box();
private:
    VAO *object;
};

#endif // BALL_H
