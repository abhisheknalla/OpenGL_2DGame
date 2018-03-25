#include "soil.h"
#include "main.h"
#define PI 3.14159

Soil::Soil(float x, float y, color_t color) {
        static const GLfloat vertex_buffer_data2[] = {
        10.0, -2.4, 0, // vertex 1
        -10,  -2.4, 0, // vertex 2
        -10,  -2.9, 0, // vertex 3

        10,  -2.4, 0, // vertex 3
        -10, -2.9, 0, // vertex 4
        10, -2.9, 0 // vertex 1
    };
this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, color, GL_FILL);
}

void Soil::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}
/*
void Ball::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ball::tick() {
  //  this->position.x -= this->speed_x;
  if(this->position.y <=-2 && this->flag_air == -1){
    this->position.y = -2;
    this->speed_y = 0;
    this->flag_air = 0;
  }
    this->position.y += this->speed_y;
}

bounding_box_t Ball::bounding_box() {
    float x = this->position.x, y = this->position.y;
    bounding_box_t bbox = { x, y, 0.4, 0.4 };
    return bbox;
}
*/
