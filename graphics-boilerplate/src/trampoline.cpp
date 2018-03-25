#include "trampoline.h"
#include "main.h"
#define PI 3.14159

Trampoline::Trampoline(float x, float y, color_t color) {
 this->position = glm::vec3(x, y, 0);
  double angle = -PI/180;
  int i;
GLfloat vertex_buffer_data2[3258] = {};
    /*vertex_buffer_data2[0]=2;
    vertex_buffer_data2[1]=-2;
    vertex_buffer_data2[2]=0;

    vertex_buffer_data2[3]=3;
    vertex_buffer_data2[4]=-2;
    vertex_buffer_data2[5]=0;

    vertex_buffer_data2[6]=2;
    vertex_buffer_data2[7]=-2.4;
    vertex_buffer_data2[8]=0;

    vertex_buffer_data2[9]=2;
    vertex_buffer_data2[10]=-2.4;
    vertex_buffer_data2[11]=0;

    vertex_buffer_data2[12]=3;
    vertex_buffer_data2[13]=-2;
    vertex_buffer_data2[14]=0;
    vertex_buffer_data2[15]=3;
    vertex_buffer_data2[16]=-2.4;
    vertex_buffer_data2[17]=0;*/
  for(i=0;i<1620;){
    if(i>100 && i<1520)
    {
      vertex_buffer_data2[i] = (0.3 * cos(angle) + 0.0 * sin(angle));
      vertex_buffer_data2[i + 1] = (0.3 * sin(angle) - 0.0 * cos(angle));
      vertex_buffer_data2[i + 2] = 0;

      vertex_buffer_data2[i + 3] = (0.3 * cos(angle + PI/180) + 0.0 * sin(angle + PI/180));
      vertex_buffer_data2[i + 4] = (0.3 * sin(angle + PI/ 180) - 0.0 * cos(angle + PI/ 180));
      vertex_buffer_data2[i + 5] = 0;

      vertex_buffer_data2[i + 6] = 0;
      vertex_buffer_data2[i + 7] = 0;
      vertex_buffer_data2[i + 8] = 0;
    }
    else
    {
    vertex_buffer_data2[i] = (0.4 * cos(angle) + 0.0 * sin(angle));
    vertex_buffer_data2[i + 1] = (0.4 * sin(angle) - 0.0 * cos(angle));
    vertex_buffer_data2[i + 2] = 0;

    vertex_buffer_data2[i + 3] = (0.4 * cos(angle + PI/180) + 0.0 * sin(angle + PI/180));
    vertex_buffer_data2[i + 4] = (0.4 * sin(angle + PI/ 180) - 0.0 * cos(angle + PI/ 180));
    vertex_buffer_data2[i + 5] = 0;

    vertex_buffer_data2[i + 6] = 0;
    vertex_buffer_data2[i + 7] = 0;
    vertex_buffer_data2[i + 8] = 0;
  }
    i+=9;
    angle = - PI/180 + angle;
}
this->object = create3DObject(GL_TRIANGLES, 546, vertex_buffer_data2, color, GL_FILL);
}

void Trampoline::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Trampoline::set_position(float x, float y) {
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
