#include "porcupine.h"
#include "main.h"
#define PI 3.14159

Porcupine::Porcupine(float x, float y, color_t color, float speed_x) {
  this->position = glm::vec3(x, y, 0);
  this->speed_x = speed_x;
  double angle = -PI/180;
  int i=0;
GLfloat vertex_buffer_data2[3380] = {};
for(i=9;i<1629;){
    if(i>109 && i<1529)
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
    angle =  PI/180 + angle;
}

vertex_buffer_data2[i+0]=-0.1;
vertex_buffer_data2[i+1]=0;
vertex_buffer_data2[i+2]=0;

vertex_buffer_data2[i+3]=0.1;
vertex_buffer_data2[i+4]=0;
vertex_buffer_data2[i+5]=0;

vertex_buffer_data2[i+6]=0.0;
 vertex_buffer_data2[i+7]=0.6;
vertex_buffer_data2[i+8]=0;
i+=9;
vertex_buffer_data2[i+0]=0.2;
vertex_buffer_data2[i+1]=0;
vertex_buffer_data2[i+2]=0;

vertex_buffer_data2[i+3]=0.0;
vertex_buffer_data2[i+4]=0;
vertex_buffer_data2[i+5]=0;

vertex_buffer_data2[i+6]=0.1;
 vertex_buffer_data2[i+7]=0.4;
vertex_buffer_data2[i+8]=0;
i+=9;
vertex_buffer_data2[i+0]=-0.2;
vertex_buffer_data2[i+1]=0;
vertex_buffer_data2[i+2]=0;

vertex_buffer_data2[i+3]=0.0;
vertex_buffer_data2[i+4]=0;
vertex_buffer_data2[i+5]=0;

vertex_buffer_data2[i+6]=-0.1;
 vertex_buffer_data2[i+7]=0.4;
vertex_buffer_data2[i+8]=0;

this->object = create3DObject(GL_TRIANGLES, 590, vertex_buffer_data2, color, GL_FILL);
}

void Porcupine::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Porcupine::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Porcupine::tick(int num) {
  if(this->position.x >= 8)
    this->position.x -= this->speed_x*20;
  if(this->position.x <= -8)
    this->position.x += this->speed_x*20;
  if(num==0)
    this->position.x -= this->speed_x*20;
  else
    this->position.x += this->speed_x*20;
}

bounding_box_t Porcupine::bounding_box() {
    float x = this->position.x, y = this->position.y;
    bounding_box_t bbox = { x, y, 0.4 };
    return bbox;
}
