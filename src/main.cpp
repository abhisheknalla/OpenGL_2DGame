#include "main.h"
#include "timer.h"
#include "ball.h"
#include "earth.h"
#include "soil.h"
#include "pond.h"
#include "flying.h"
#include "trampoline.h"
#include "tramplegs.h"
#include "trees.h"
#include "porcupine.h"
#include "porlegs.h"
#include "magnet.h"
#include "magnet2.h"
#include "mount.h"
#include "slab.h"
#include <stdlib.h>

int k=0;
//#include <conio.h>
#define GROUND_PLANE_WIDTH 600
using namespace std;

static void cursorPositionCallback(GLFWwindow *window, double xPos, double yPos);
void cursorEnterCallback(GLFWwindow *window, int entered);
void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

Magnet semi3;
Magnet2 semi4;
Trees tri1,tri2,tri3,tri4,tri5,tri8,tri9;
Mount tri7;
Pond semi1,semi5;
Ball ball1, ball2;
Earth rect1;
Soil rect2;
Flying balls[10];
Trampoline rect3;
Tramplegs rect4;
Porlegs tri6[3];
Slab rects[10];
int dir_flag = 0;
Porcupine semi2[3];
Timer bgm(20);
bool start = true;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float screen_zoom2 =1;


int a[10]={-1};



float top2    = screen_center_y + 4 / screen_zoom2;
float bottom2 = screen_center_y - 4 / screen_zoom2;
float left2   = screen_center_x - 4 / screen_zoom2;
float right2  = screen_center_x + 4 / screen_zoom2;



Timer t60(1.0 / 60);
Timer t20(1.0 / 30);
int magflag=0;
float side = 0;
/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
//  rectangle();

    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
  //important  // glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
  //important  // glm::vec3 target (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
  //important  // glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
  //important  // Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    Matrices.view = glm::lookAt(glm::vec3(side, 0, 3), glm::vec3(side, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane


    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;
    //glScalef(1.5,1.5,1.5);
    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model
    // Scene render

  //  ball2.draw(VP);
    tri7.draw(VP);
    rect1.draw(VP);
    rect4.draw(VP);
    rect3.draw(VP);
    tri1.draw(VP);
    tri2.draw(VP);
    tri3.draw(VP);
    tri4.draw(VP);
    tri5.draw(VP);tri8.draw(VP);tri9.draw(VP);
    rect2.draw(VP);
    semi1.draw(VP);semi5.draw(VP);
    if(magflag==1)
    {
      semi3.draw(VP);
      semi4.draw(VP);
      magflag=0;
    }
    for(int i=0;i<3;i++)
    {
    semi2[i].draw(VP);
//    tri6[i].draw(VP);
    }
    ball1.draw(VP);
    for(int i=0;i<9;i++)
    {
      balls[i].draw(VP);
    }
    for(int i=0;i<9;i++)
    {
      if(a[i]==i)
        rects[i].draw(VP);
    }
}


//glfwGetCursorPos(window, &xpos, &ypos);
int previous=-1;
void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_A);
    int right = glfwGetKey(window, GLFW_KEY_D);
    int up = glfwGetKey(window, GLFW_KEY_SPACE);
    int zoom_in = glfwGetKey(window, GLFW_KEY_KP_ADD);
    int zoom_out = glfwGetKey(window, GLFW_KEY_KP_SUBTRACT);
    int zoom_normal = glfwGetKey(window, GLFW_KEY_KP_MULTIPLY);
    int pan_up = glfwGetKey(window, GLFW_KEY_UP);
    int pan_down = glfwGetKey(window, GLFW_KEY_DOWN);
    int pan_right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int pan_left = glfwGetKey(window, GLFW_KEY_LEFT);
    if(pan_up)
    {
      top2+=0.01;
      pan();
    }
    //scree   n_zoom2 += 0.005;
    if(pan_down)
    {
      bottom2-=0.01;
      pan();
    }
    if(pan_left)
    {
      side-=0.01;
    }
    if(pan_right)
    {
      side+=0.01;
    }
    if(zoom_in)
    {
      screen_zoom2 += 0.005;
      zoom(1);
    }
    if(zoom_out)
    {
      screen_zoom2 -= 0.005;
      zoom(1);
    }
    if(zoom_normal)
    {
      screen_zoom2 = 1;
      zoom(1);
    }
    if(!left&&!right && ball1.speed_x>0.0005)
      ball1.speed_x -= 0.0005;
    else if(!left && !right && ball1.speed_x<0.0005)
      ball1.speed_x =0.0;
    else
      ball1.speed_x = 0.05;
  /*  if(left && ball1.pond_flag == 1)
    {
      if(ball1.position.x <= -0.8 && ball1.position.y >= -2)
        ball1.pond_flag = 0;
      else
      {
        ball1.position.x -= 0.05;
        ball1.position.y += 0.05;
      }
    }*/
    if (left||(!left && previous==1)) {
      previous=1;
      if(ball1.position.x<-3.6)
      {
        ball1.position.x += ball1.speed_x;
        previous=2;
      }
      if(dir_flag != 1){
      ball1.position.x -= ball1.speed_x;
    }
    }
    if(right ||(!right && previous==2)){
      previous=2;
        if(ball1.position.x>7.6)
        {
          ball1.position.x -= ball1.speed_x;
          previous=1;
        }
      if(dir_flag != 2){
        ball1.position.x += ball1.speed_x;
    }
  }
    if (up && ball1.flag_air == 0){
      if(!(ball1.position.x < 1 && ball1.position.x >-1 && ball1.position.y <= 2))
      {
      ball1.speed_y = 0.2;
      ball1.flag_air = 1;
    }
    else
    {
      ball1.position.y += 1.0;
      ball1.speed_y = 0.15;
      ball1.flag_air=1;
    }
    }
}

double xpos;
int pressed=0;
void mouse_input(GLFWwindow *window)
{
  pressed=0;
  int button,action;
  glfwSetCursorPosCallback(window, cursorPositionCallback);
  glfwSetMouseButtonCallback(window, mouseButtonCallback);
//  if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
//    pressed=1;
//  printf("xpos:%lf  ",xpos);
//  printf("ball:%lf  ",ball1.position.x);
//  printf("p: %d",pressed);
/*
  if(pressed==1){
  if (xpos/150 < ball1.position.x+2) {
    ball1.position.x -= 0.05;
    ball1.speed_x =0.05;
  }
  else{
      ball1.position.x += 0.05;
      ball1.speed_x = -0.05;
}
}*/
}
int no_of_ticks=0;
void tick_elements() {
    ball1.tick();
    ball2.tick();
    if(score>=50 && score<=80)
    {
      if(ball1.position.y<=2.5 && ball1.position.y>=1.5 && ball1.position.x<3 && ball1.position.x > 0)
      {
        ball1.position.x+=0.1;
      }
      if(ball1.position.y<=2.5 && ball1.position.y>=1.5 && ball1.position.x<0 && ball1.position.x > -3)
      {
        ball1.position.x+=0.05;
      }
    }

    if(score>=100 && score<=130)
    {
      if(ball1.position.y<=2.5 && ball1.position.y>=1.5 && ball1.position.x>-3 && ball1.position.x < 0)
      {
        ball1.position.x-=0.1;
      }

        if(ball1.position.y<=2.5 &&  ball1.position.y>=1.5 && ball1.position.x>0 && ball1.position.x < 3)
        {
          ball1.position.x-=0.05;
        }
    }
    if(no_of_ticks>50)
    {
      for(int i=0;i<3;i++)
      {
        int num = rand()%2;
        semi2[i].tick(num);
  //    tri6[i].tick(num);
      }
      no_of_ticks=0;
    }
    no_of_ticks++;
    for(int i=0;i<9;i++)
    {
      float random2 = 0.01 + (rand()%10)/100.0;
      float random3 = 0.2 + (rand()%4)/10.0;
      float tempo = balls[i].position.y;
      balls[i].tick(random2,random3);
      balls[i].radius = random3;
  //    float tempo2 = tempo - random3;
      //rects[i].position.y += tempo-random3;
      rects[i].tick(random2, tempo + random3);
    }
    for(int i=0;i<3;i++)
    {
      if(detect_collision(ball1.bounding_box(), semi2[i].bounding_box()))
      {
        score-=100;
        int roo = rand()%2;
        if(roo==0)
        {
          tri6[i] = Porlegs(8,-2.4,COLOR_POR,0.02);
          semi2[i] = Porcupine(8,-2.4,COLOR_POR, 0.02);
        }
        else

        {
          tri6[i] = Porlegs(-8,-2.4,COLOR_POR,0.02);
          semi2[i] = Porcupine(-8,-2.4,COLOR_POR, 0.02);
        }
      }
    }
    for(int i=0;i<9;i++)
    {
      if(a[i]!=i)
      {
      if (detect_collision(ball1.bounding_box(), balls[i].bounding_box())&&ball1.flag_air==-1)
      {
        score+=balls[i].speed_x*100;
      //  if(ball1.speed_x > 0)dir_flag =1; //from Right to left
      //  else if(ball1.speed_x < 0)dir_flag =2; //from Left to Right
      //  ball1.speed_x = 0;
      if(ball1.flag_air==-1)
        ball1.speed_y += 0.3;
      balls[i].position.x = 8;
      rects[i].position.x = 8;
      balls[i].speed_x = 0.01 + (rand()%10)/100.0;
      ball1.flag_air=1;
      //  ball1.flag_air = 0;
      }
      else
        dir_flag = 0;
      }
  }
    if(ball1.speed_y <= 0 && ball1.flag_air == 1){
      ball1.flag_air = -1;
      ball1.speed_y = 0;
    //  ball1.speed_y += 0.01;
    }
    if(ball1.flag_air == 1){
      ball1.speed_y -= 0.01;
    }
    if(ball1.flag_air == -1){
      ball1.speed_y -= 0.01;
    }
    for(int i=0;i<9;i++)
    {
      if(a[i]==i)
      {
        if(detect_collision2(ball1.bounding_box(), rects[i].bounding_box()))
        {
          double ang=rects[i].rotation*3.14/180;
          float temp = ball1.speed_y;
          ball1.speed_x = -temp*sin(ang);
          ball1.speed_y = -temp*cos(ang);
        }
      }
    }
    if(score>=50 && score<=80)
    {
        semi3 = Magnet(3,2,COLOR_MAG,1);
        semi4 = Magnet2(3,2,COLOR_MTN,1);
        magflag=1;
    }
    if(score>=100 && score <=130)
    {
        semi3 = Magnet(-3,2,COLOR_MAG,2);
        semi4 = Magnet2(-3,2,COLOR_MTN,2);
        magflag=1;
    }
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    semi1 = Pond(0, -2.4, COLOR_WATER,1);
    semi5 = Pond(5, -2.4, COLOR_WATER,2);
    rect2 = Soil(-10, -1.6, COLOR_SOIL);
    rect1 = Earth(-10, -1.6, COLOR_BROWN);
    ball1  = Ball(-2, -2, COLOR_YELLOW,0,0);
//    ball2       = Ball(-2, -2, COLOR_GREEN,0,0);
//    ball2.speed = -ball2.speed;
    rect4 = Tramplegs(2,-2, COLOR_RED2);
    rect3 = Trampoline(2,-2, COLOR_PURPLE);
    semi2[0] = Porcupine(-1,-2.4, COLOR_POR,0.02);
    semi2[1] = Porcupine(-6, -2.4, COLOR_POR,0.02);
    semi2[2] = Porcupine(6, -2.4, COLOR_POR,0.02);

    tri1 = Trees(-3,-2.43,COLOR_GREEN2);
    tri2 = Trees(-2.6,-2.4,COLOR_GREEN2);
    tri3 = Trees(-3.4,-2.46, COLOR_GREEN2);
    tri4 = Trees(3,-2.4, COLOR_GREEN2);
    tri5 = Trees(3.4,-2.42, COLOR_GREEN2);
    tri8 = Trees(6.4,-2.4, COLOR_GREEN2);
    tri9 = Trees(6.8,-2.44, COLOR_GREEN2);
    tri7 = Mount(-1.5,-2.6,COLOR_MTN);
    //tri6[0] = Porlegs(-1,-2.4,COLOR_POR, 0.02);
    //tri6[1] = Porlegs(-6,-2.4,COLOR_POR, 0.02);
    //tri6[2] = Porlegs(6,-2.4,COLOR_POR, 0.02);
    float initx = -5;
    float inity = 4.0;
    float carry=0;
    for(int i=0;i<9;i++)
    {
      carry -= 0.4 + (rand()%5)/10.0;
      std::cout << inity ;
      float speed = 0.01 + (rand()%10)/100.0;
      int size = 0.2 + (rand()%4)/10.0;
      int n = rand()%2;
      int in =rand()%3;
      balls[i]= Flying(initx , inity+ carry, COLOR_ORANGE,0.01 + speed,0,size);
      if(n==0)
      {
        if(in==1)
        {
          a[k]=i;
        }
        rects[k]=Slab(initx, inity + carry + 0.05, COLOR_BROWN, 0.01 + speed, 0, size, 45);
        k++;
      }
      if(n==1)
      {
        if(in==1)
        {
          a[k]=i;
        }
        rects[k]=Slab(initx, inity + carry + 0.05, COLOR_BROWN, 0.01 + speed, 0, size , 135);
        k++;
      }
      std::cout << speed << endl;
    }

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 600;
    int height = 600;

    window = initGLFW(width, height);


    initGL (window, width, height);
    glfwSetCursorPosCallback(window, cursorPositionCallback);
//   glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    glfwSetCursorEnterCallback(window,  cursorEnterCallback);
   glfwSetMouseButtonCallback(window, mouseButtonCallback);
    /* Draw in loop */
    GLfloat lineVertices[]=
    {
      2,2,0,
      4,4,0
    };
    int tickno=0;
    while (!glfwWindowShouldClose(window)) {
        // Process timerfloat
if(bgm.processTick()||start)
        {
            start=false;
            system("pactl -- set-sink-volume 0 50% ");
            system(" canberra-gtk-play -f  ../resources/harpsi-cs.wav --volume=\"10\" &");
}
        if (t60.processTick()) {
          tickno++;
//printf("PLAYER SCORE: %d\n ",score);
if(tickno==5000)
tickno=0;
if(tickno>3000)
{
  glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f);
}
else
{
  glClearColor (COLOR_BG2.r / 256.0, COLOR_BG2.g / 256.0, COLOR_BG2.b / 256.0, 0.0f);
}
            // OpenGL Draw commands
          draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
            //if(t60.processTick())
            mouse_input(window);

            string Result;
            stringstream convert;
            //cout << "nonedit score:" << score << endl;
            convert << score;
            Result = convert.str();

            const char *one = "Score: ";
            const char *two = Result.c_str();
        //    const char *three = "   Level ";
        //    string Result1;
        //    stringstream convert1;
        //    convert1 << level;
        //    Result1 = convert1.str();
        //    const char *four = Result1.c_str();
            string total( string(one) + two);
            glfwSetWindowTitle(window, total.c_str());
        }
//        if(t20.processTick())
  //

          //  ball1.position.y += speedo;
          //  int temp = 0.16 - (cx)*(cx);
    //      }
      //  }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision2(bounding_box_t a, bounding_box_t2 b) {
  return (abs(a.x - b.x)    < (a.r + b.w)) &&
         (abs(a.y - b.y)    < (a.r + b.h));
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x)*1.5 < (a.r + b.r)) &&
           (abs(a.y - b.y)*1.5  < (a.r + b.r)) && ((a.y - b.y)>0);
//  return (abs(a.x - b.x) > 0 || abs(a) )
//  return ((abs((a.x + a.width)-(b.x - b.width)) > 0 )||(abs((a.x - a.width)-(b.x + b.width)) > 0 )
//  ||(abs((a.y + a.height)-(b.y- b.height)) > 0 )||(abs((a.y + a.height)-(b.y- b.height)) > 0 ));
}

void zoom(float scale)
{
      float top    = screen_center_y + 4 / screen_zoom2;
      float bottom = screen_center_y - 4 / screen_zoom2;
      float left   = screen_center_x - 4 / screen_zoom2;
      float right  = screen_center_x + 4 / screen_zoom2;
      Matrices.projection = glm::ortho(left*scale, right*scale, bottom*scale, top*scale, 0.1f, 500.0f);
}

void pan()
{
      Matrices.projection = glm::ortho(left2, right2, bottom2, top2, 0.1f, 500.0f);
}

void zoom_back()
{
float top    = screen_center_y + 4 / screen_zoom;
float bottom = screen_center_y - 4 / screen_zoom;
float left   = screen_center_x - 4 / screen_zoom;
float right  = screen_center_x + 4 / screen_zoom;
Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}

void reset_screen() {//for zoom crenn
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}

static void cursorPositionCallback(GLFWwindow *window, double xPos, double yPos)
{
  xpos = xPos;
//  std::cout << xPos << " : " << yPos << std::endl;
}

void cursorEnterCallback(GLFWwindow *window, int entered)
{
  if(entered)
  {
    std::cout << "Entered Window" << std::endl;
  }
  else
    {
      std::cout << "Left Window" << std::endl;
    }
}

int prevclick=-1;
void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
//  if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
//  {
    if(!(button==GLFW_MOUSE_BUTTON_LEFT)&&ball1.speed_x>0.0005){
      ball1.speed_x -= 0.0005;printf("1");}
    else if(!(button==GLFW_MOUSE_BUTTON_LEFT)&&ball1.speed_x<0.0005)
      ball1.speed_x =0.0;
    else
      ball1.speed_x = 0.05;
    if (((button==GLFW_MOUSE_BUTTON_LEFT)&&(xpos/75 < ball1.position.x+4))||(!((button==GLFW_MOUSE_BUTTON_LEFT)&&(xpos/75 < ball1.position.x+4)) && prevclick==1)) {
      prevclick=1;printf("2");
      if(ball1.position.x<-3.6)
      {
        ball1.position.x += ball1.speed_x;
        prevclick=2;
      }
      if(dir_flag != 1){
      ball1.position.x -= ball1.speed_x;
    }
    }
    if(((button==GLFW_MOUSE_BUTTON_LEFT)&&(xpos/75 > ball1.position.x+4)) ||(!((button==GLFW_MOUSE_BUTTON_LEFT)&&(xpos/75 < ball1.position.x+4)) && prevclick==2)){
      prevclick=2;printf("3");
        if(ball1.position.x>3.6)
        {
          ball1.position.x -= ball1.speed_x;
          prevclick=1;
        }
      if(dir_flag != 2){
        ball1.position.x += ball1.speed_x;
    }
  }
}


//    ball1.position.x += 0.05;
  /*  if(!left&&!right && ball1.speed_x>0.0005)
      ball1.speed_x -= 0.0005;
    else if(!left && !right && ball1.speed_x<0.0005)
      ball1.speed_x =0.0;
    else
      ball1.speed_x = 0.05;*/

  /*  if (xpos/75 < ball1.position.x+4) {
      prevclick=1;
      ball1.position.x -= 0.05;
  //   ball1.speed_x = 0.05;
    }
    else{
      prevclick=2;
        ball1.position.x += 0.05;
  //      ball1.speed_x = 0.05;
  }
}*/

  //  pressed=1;
/*    std::cout << "Left Button pressed " <<std::endl;
  }
else{
  if(prevclick==1)
    ball1.position.x -=0.05;
  else
    ball1.position.x +=0.05;
      std::cout << "Left Button released" <<std::endl;
    }*/
