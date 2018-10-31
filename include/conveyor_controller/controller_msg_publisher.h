#include <stdio.h>
#include <term.h>
#include <termios.h>
#include <unistd.h>

class ConveyorMode
{
private:
  enum MODE
  {
    NONE = 0
    , FORWARD, BACKWARD, RLEFT, RRIGHT, PLEFT, PRIGHT
    , PLEFT_FORWARD, PRIGHT_FORWARD, PLEFT_BACKWARD, PRIGHT_BACKWARD, RLEFT_FORWARD, RRIGHT_FORWARD, RLEFT_BACKWARD, RRIGHT_BACKWARD, RLEFT_PLEFT, RLEFT_PRIGHT, RRIGHT_PLEFT, RRIGHT_PRIGHT
    , RLEFT_PLEFT_FORWARD, RLEFT_PLEFT_BACKWARD, RRIGHT_PLEFT_FORWARD, RRIGHT_PLEFT_BACKWARD, RLEFT_PRIGHT_FORWARD, RLEFT_PRIGHT_BACKWARD, RRIGHT_PRIGHT_FORWARD, RRIGHT_PRIGHT_BACKWARD
  } mobile_mode;

 public:
   MODE getDirection(int rcData)
   {
     switch (rcData)
     {
      case (97): mobile_mode = FORWARD; break;
      // case (RC100_BTN_U): mobile_mode = FORWARD; break;
      // case (RC100_BTN_D): mobile_mode = BACKWARD; break;
      // case (RC100_BTN_L): mobile_mode = RLEFT; break;
      // case (RC100_BTN_R): mobile_mode = RRIGHT; break;
      // case (RC100_BTN_6): mobile_mode = PLEFT; break;
      // case (RC100_BTN_5): mobile_mode = PRIGHT; break;
      //
      // case (RC100_BTN_U + RC100_BTN_6): mobile_mode = PLEFT_FORWARD; break;
      // case (RC100_BTN_U + RC100_BTN_5): mobile_mode = PRIGHT_FORWARD; break;
      // case (RC100_BTN_D + RC100_BTN_6): mobile_mode = PLEFT_BACKWARD; break;
      // case (RC100_BTN_D + RC100_BTN_5): mobile_mode = PRIGHT_BACKWARD; break;
      // case (RC100_BTN_U + RC100_BTN_L): mobile_mode = RLEFT_FORWARD; break;
      // case (RC100_BTN_U + RC100_BTN_R): mobile_mode = RRIGHT_FORWARD; break;
      // case (RC100_BTN_D + RC100_BTN_L): mobile_mode = RLEFT_BACKWARD; break;
      // case (RC100_BTN_D + RC100_BTN_R): mobile_mode = RRIGHT_BACKWARD; break;
      // case (RC100_BTN_L + RC100_BTN_6): mobile_mode = RLEFT_PLEFT; break;
      // case (RC100_BTN_L + RC100_BTN_5): mobile_mode = RLEFT_PRIGHT; break;
      // case (RC100_BTN_R + RC100_BTN_6): mobile_mode = RRIGHT_PLEFT; break;
      // case (RC100_BTN_R + RC100_BTN_5): mobile_mode = RRIGHT_PRIGHT; break;
      //
      // case (RC100_BTN_L + RC100_BTN_6 + RC100_BTN_U): mobile_mode = RLEFT_PLEFT_FORWARD; break;
      // case (RC100_BTN_L + RC100_BTN_6 + RC100_BTN_D): mobile_mode = RLEFT_PLEFT_BACKWARD; break;
      // case (RC100_BTN_R + RC100_BTN_6 + RC100_BTN_U): mobile_mode = RRIGHT_PLEFT_FORWARD; break;
      // case (RC100_BTN_R + RC100_BTN_6 + RC100_BTN_D): mobile_mode = RRIGHT_PLEFT_BACKWARD; break;
      // case (RC100_BTN_L + RC100_BTN_5 + RC100_BTN_U): mobile_mode = RLEFT_PRIGHT_FORWARD; break;
      // case (RC100_BTN_L + RC100_BTN_5 + RC100_BTN_D): mobile_mode = RLEFT_PRIGHT_BACKWARD; break;
      // case (RC100_BTN_R + RC100_BTN_5 + RC100_BTN_U): mobile_mode = RRIGHT_PRIGHT_FORWARD; break;
      // case (RC100_BTN_R + RC100_BTN_5 + RC100_BTN_D): mobile_mode = RRIGHT_PRIGHT_BACKWARD; break;

      default:  mobile_mode = NONE;
                break;
     }
     return mobile_mode;
   }
 };
