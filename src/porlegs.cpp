#include "porlegs.h"
#include "main.h"
#define PI 3.14159

Porlegs::Porlegs(float x, float y, color_t color, float speed_x) {
// this->position = glm::vec3(x, y, 0);
 this->speed_x = speed_x;
GLfloat vertex_buffer_data2[3258] = {};
    vertex_buffer_data2[0]=x - 0.1;
    vertex_buffer_data2[1]=y;
    vertex_buffer_data2[2]=0;

    vertex_buffer_data2[3]=x + 0.1;
    vertex_buffer_data2[4]=y;
    vertex_buffer_data2[5]=0;

    vertex_buffer_data2[6]=x + 0.05;
    vertex_buffer_data2[7]=y + 0.5;
    vertex_buffer_data2[8]=0;

this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, color, GL_FILL);
}

void Porlegs::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
  //  glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
//    rotate = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Porlegs::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Porlegs::tick(int num) {
  if(this->position.x >= 8)
    this->position.x -= this->speed_x*20;
  if(this->position.x <= -8)
    this->position.x += this->speed_x*20;
  if(num==0)
    this->position.x -= this->speed_x*20;
  else
    this->position.x += this->speed_x*20;
}/*
bounding_box_t Ball::bounding_box() {
    float x = this->position.x, y = this->position.y;
    bounding_box_t bbox = { x, y, 0.4, 0.4 };
    return bbox;
}
*/
