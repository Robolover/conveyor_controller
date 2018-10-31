#include "ros/ros.h"
#include "conveyor_controller/controll_mode.h"
#include "conveyor_controller/controller_msg_publisher.h"

int getch(void)
{
  int ch;
  struct termios buf;
  struct termios save;

   tcgetattr(0, &save);
   buf = save;
   buf.c_lflag &= ~(ICANON|ECHO);
   buf.c_cc[VMIN] = 1;
   buf.c_cc[VTIME] = 0;
   tcsetattr(0, TCSAFLUSH, &buf);
   ch = getchar();
   tcsetattr(0, TCSAFLUSH, &save);
   return ch;
}

// int kbhit(void)
// {
// #ifdef __linux__
//   struct termios oldt, newt;
//   int ch;
//   int oldf;
//
//   tcgetattr(STDIN_FILENO, &oldt);
//   newt = oldt;
//   newt.c_lflag &= ~(ICANON | ECHO);
//   tcsetattr(STDIN_FILENO, TCSANOW, &newt);
//   oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
//   fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
//
//   ch = getchar();
//
//   tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
//   fcntl(STDIN_FILENO, F_SETFL, oldf);
//
//   if (ch != EOF)
//   {
//     ungetc(ch, stdin);
//     return 1;
//   }
//
//   return 0;
// #elif defined(_WIN32) || defined(_WIN64)
//   return _kbhit();
// #endif
// }

int main(int argc, char **argv)
{
  ros::init(argc, argv, "controller_msg_publisher");
  ros::NodeHandle nh;
  ros::Publisher mode_msg_pub = nh.advertise<conveyor_controller::controll_mode>("mode_msg", 100);

  ros::Rate loop_rate(10);

  int mode = 0;

  while (ros::ok())
  {
    conveyor_controller::controll_mode msg;

  //  if(kbhit() == true)
  //  {
      //mode = getDirection(getch());
      mode = getch();
      msg.data = mode;

      ROS_INFO("send msg = %d", mode);
      mode_msg_pub.publish(msg);
  //  }
    loop_rate.sleep();
  }
  return 0;
}
