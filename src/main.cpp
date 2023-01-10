#include<Arduino.h>
#include<vector>
#include<memory>
#include"all.hpp"

sensor::PhotoRefSens linesensor_r(6, 127);//しきい値を127に設定
sensor::PhotoRefSens linesensor_l(7, 127);//しきい値を127に設定
motorDriver::MD10C motor_r(9, 0);//PWMチャネルを0に設定
motorDriver::MD10C motor_l(11,1);//PWMチャネルを1に設定

/* モーター出力 */
const uint16_t powerscale = 127;

void set_motorpower(){
    if (linesensor_r.compareValue() && !linesensor_l.compareValue()) {// 左のセンサーのみ線上 -> 右に旋回
        motor_r.setPower(powerscale);
        motor_l.setPower(-powerscale);
    }
    else if (!linesensor_r.compareValue() && linesensor_l.compareValue()) {// 右のセンサーのみ線上 -> 左に旋回
        motor_r.setPower(-powerscale);
        motor_l.setPower(powerscale);
    }
    else if (!linesensor_r.compareValue() && !linesensor_l.compareValue()) {// 左右のセンサーともに線上にない -> 直進
        motor_r.setPower(powerscale);
        motor_l.setPower(powerscale);
    }
    else{// 左右のセンサーともに線上 -> 後進
        motor_r.setPower(-powerscale);
        motor_l.setPower(-powerscale);
    }
}

void run(uint delay_time){// 走らせるだけ
    motor_r.run();
    motor_l.run();
    delay(delay_time);
}

void setup(){
    linesensor_r.init();
    linesensor_l.init();
    motor_r.init();
    motor_l.init();
}

void loop(){
    set_motorpower();
    run(10);
}