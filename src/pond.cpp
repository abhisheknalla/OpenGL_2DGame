#include "pond.h"
#include "main.h"
#define PI 3.14159

Pond::Pond(float x, float y, color_t color, int flag) {
    this->position = glm::vec3(x, y, 0);
    if(flag==1)
    {
  GLfloat g_vertex_buffer_data[3280] = {};
      double angle = -PI/180;
      int i;
  for(i=0;i<1620;){
      g_vertex_buffer_data[i] = (1 * cos(angle) + 0.0 * sin(angle));
      g_vertex_buffer_data[i + 1] = (1 * sin(angle) - 0.0 * cos(angle));
      g_vertex_buffer_data[i + 2] = 0;

      g_vertex_buffer_data[i + 3] = (1 * cos(angle + PI/180) + 0.0 * sin(angle + PI/180));
      g_vertex_buffer_data[i + 4] = (1 * sin(angle + PI/ 180) - 0.0 * cos(angle + PI/ 180));
      g_vertex_buffer_data[i + 5] = 0;

      g_vertex_buffer_data[i + 6] = 0;
      g_vertex_buffer_data[i + 7] = 0;
      g_vertex_buffer_data[i + 8] = 0;
      i+=9;
      angle = - PI/180 + angle;
  }
  g_vertex_buffer_data[i] = -1.3;
  g_vertex_buffer_data[i + 1] = 0;
  g_vertex_buffer_data[i + 2] = 0;

  g_vertex_buffer_data[i + 3] = 1.3;
  g_vertex_buffer_data[i + 4] = 0;
  g_vertex_buffer_data[i + 5] =0;

  g_vertex_buffer_data[i + 6] = 0;
  g_vertex_buffer_data[i + 7] = -1;
  g_vertex_buffer_data[i + 8] = 0;
this->object = create3DObject(GL_TRIANGLES, 550, g_vertex_buffer_data, color, GL_FILL);
}
else
{
  GLfloat g_vertex_buffer_data[3280] = {};
      double angle = -PI/180;
      int i;
  for(i=0;i<1620;){
      g_vertex_buffer_data[i] = (0.7 * cos(angle) + 0.0 * sin(angle));
      g_vertex_buffer_data[i + 1] = (0.7 * sin(angle) - 0.0 * cos(angle));
      g_vertex_buffer_data[i + 2] = 0;

      g_vertex_buffer_data[i + 3] = (0.7 * cos(angle + PI/180) + 0.0 * sin(angle + PI/180));
      g_vertex_buffer_data[i + 4] = (0.7 * sin(angle + PI/ 180) - 0.0 * cos(angle + PI/ 180));
      g_vertex_buffer_data[i + 5] = 0;

      g_vertex_buffer_data[i + 6] = 0;
      g_vertex_buffer_data[i + 7] = 0;
      g_vertex_buffer_data[i + 8] = 0;
      i+=9;
      angle = - PI/180 + angle;
  }
  g_vertex_buffer_data[i] = -1;
  g_vertex_buffer_data[i + 1] = 0;
  g_vertex_buffer_data[i + 2] = 0;

  g_vertex_buffer_data[i + 3] = 1;
  g_vertex_buffer_data[i + 4] = 0;
  g_vertex_buffer_data[i + 5] =0;

  g_vertex_buffer_data[i + 6] = 0;
  g_vertex_buffer_data[i + 7] = -0.7;
  g_vertex_buffer_data[i + 8] = 0;
this->object = create3DObject(GL_TRIANGLES, 550, g_vertex_buffer_data, color, GL_FILL);

}
}
void Pond::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}


void Pond::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
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
