#include "main.h"

#ifndef Flying_H
#define Flying_H


class Flying {
public:
    Flying() {}
    Flying(float x, float y, color_t color, float speed_x, float speed_y, float ball_size);
    float radius;
    float speed_x;
    float speed_y;
    int flag_air;
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(float speed, float sized);
    color_t col;
    double speed;
    bounding_box_t bounding_box();
private:
    VAO *object;
};

#endif // BALL_H
