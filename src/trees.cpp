#include "trees.h"
#include "main.h"
#define PI 3.14159

Trees::Trees(float x, float y, color_t color) {
 //this->position = glm::vec3(x, y, 0);
GLfloat vertex_buffer_data2[3258] = {};
    vertex_buffer_data2[0]=x;
    vertex_buffer_data2[1]=y;
    vertex_buffer_data2[2]=0;

    vertex_buffer_data2[3]=x+0.4;
    vertex_buffer_data2[4]=y;
    vertex_buffer_data2[5]=0;

    vertex_buffer_data2[6]=x+0.2;
    vertex_buffer_data2[7]=y+0.6;
    vertex_buffer_data2[8]=0;

this->object = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data2, color, GL_FILL);
}

void Trees::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Trees::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}
/*
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
