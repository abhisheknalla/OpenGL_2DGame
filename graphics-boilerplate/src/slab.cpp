#include "slab.h"
#include "main.h"

#define PI 3.14159
Slab::Slab(float x, float y, color_t color, float speed_x, float speed_y, float ball_size, int angle) {
  this->position = glm::vec3(x, y - 0.05 - ball_size, 0);
  this->rotation = angle;
  this->radius = ball_size;
  this->speed_x = speed_x;
  this->speed_y = speed_y;
  this->flag_air = 0;

  GLfloat vertex_buffer_data2[] = {
    -0.5,-0.05 + 0.05 + ball_size ,0,
    0.5,-0.05 + 0.05 + ball_size,0,
    0.5,0.05 + 0.05 + ball_size,0,

    0.5,0.05 + 0.05 + ball_size,0,
    -0.5,0.05 + 0.05 + ball_size,0,
    -0.5,-0.05 + 0.05 + ball_size,0,
  };
  this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, color, GL_FILL);
  }

void Slab::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate  = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate     = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Slab::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Slab::tick(float speed, float new_pos) {
   this->position.x += this->speed_x;
  // printf("POSSlab: %lf\n ",this->position.x);
   if(this->position.x >= 8){
    this->position.x = -4;
    this->position.y = new_pos + 0.2;
//    this->position.y += tempo2;
  //  this->position.y  = 0.5 + (rand()%3);
    this->speed_x =speed;// 0.01 + (rand()%10)/100.0;
  }
}

bounding_box_t2 Slab::bounding_box() {
    float x = this->position.x, y = this->position.y;
    bounding_box_t2 bbox = { x, y+0.05 + this->radius,0.25,0.05};
  //  bounding_box_t bbox = { x, y, size };
    return bbox;
}
