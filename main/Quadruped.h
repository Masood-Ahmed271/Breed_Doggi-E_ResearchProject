#ifndef Quadruped_h
#define Quadruped_h

#include <Servo.h>

typedef struct frame{
  float x;
  float y;
  float z;
}Frame;

typedef struct frames{
  Frame rf;
  Frame lf;
  Frame rb;
  Frame lb;
}Frames;

class Quadruped{
  private:
    float W;
    float L;

    float L1;
    float L2;
    float L3;

    float cog_x = 0.0;
    float cog_z = 0.0;
    float cog_y = 60.0;
  
    int servo_pins[12] = {28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39};
    int zero_positions[12] = {83, 110, 90, 85, 70, 90, 50, 110, 90, 130, 70, 90}; 

    Servo rfh1, rfh2, rfk, lfh1, lfh2, lfk, rbh1, rbh2, rbk, lbh1, lbh2, lbk;

    void init_local_frames();
    void attach_servos();
    
  public:
    Quadruped(float _w, float _l, float _l1, float _l2, float _l3);

    Frames local_frames;  
    Frames frames_wrt_cog;

    void init_initialise();
    void initialise();
    void IK();
    void IK_one_leg(String leg, float x, float y, float z);
    void update_frames_wrt_cog();
    void update_local_frames();
    void translate_cog(float x, float y);
    void translate_cog_on_support_polygon(String swing_leg);
};


#endif
