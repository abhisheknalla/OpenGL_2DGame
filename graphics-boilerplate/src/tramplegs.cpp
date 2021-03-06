#include "tramplegs.h"
#include "main.h"
#define PI 3.14159

Tramplegs::Tramplegs(float x, float y, color_t color) {
//this->position = glm::vec3(x, y, 0);
GLfloat vertex_buffer_data2[] = {
  1.6,-2,0,
  1.7,-2,0,
  1.6,-2.4,0,

  1.6,-2.4,0,
  1.7,-2,0,
  1.7,-2.4,0,

  2.3,-2,0,
  2.4,-2,0,
  2.3,-2.4,0,

  2.3,-2.4,0,
  2.4,-2,0,
  2.4,-2.4,0,
};
this->object = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data2, color, GL_FILL);
}

void Tramplegs::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
//    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
//    rotate = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
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
*/
/*bounding_box_t Tramplegs::bounding_box() {
    float x = 2, y = -2;
    bounding_box_t bbox = { x, y, 0.5, 0.5 };
    return bbox;
}*/
