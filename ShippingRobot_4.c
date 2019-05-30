#include <16F877A.h>
#fuses NOWDT, PUT, HS, NOPROTECT, NOLVP
#use delay(clock=20M)
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7)
#define cambientrai PIN_D7
#define cambiengiua PIN_D6
#define cambienphai PIN_D5
#define IN1 PIN_B4
#define IN2 PIN_B5
#define IN3 PIN_B6
#define IN4 PIN_B7

void move_foward() {
   output_low(PIN_B7);
   output_high(PIN_B6);
   output_low(PIN_B4);
   output_high(PIN_B5);
}

void move_back() {
   
   output_high(PIN_B7);
   output_low(PIN_B6);
   output_high(PIN_B4);
   output_low(PIN_B5);
}
void stop(){
   output_low(PIN_B7);
   output_low(PIN_B6);
   output_low(PIN_B4);
   output_low(PIN_B5);
}
void move_left(){
   output_low(PIN_B7);
   output_high(PIN_B6);
   output_high(PIN_B4);
   output_low(PIN_B5);
}
void move_right(){
   output_high(PIN_B7);
   output_low(PIN_B6);
   output_low(PIN_B4);
   output_high(PIN_B5);
}
            


void main ()
   {
      char start, finish;
      char  data_foward ;
      char data , a;
      while (1) 
         { 
         //////////////////////////////////////////////////////////////////////
         if (kbhit() > 0) {
        while (kbhit()){
            data = getch();
            switch (data){
               case "11":
                  {start = '1';
                  finish = '1';
                  }
               case "12":
               {start = '1';
               finish = '2';
               }
            }
      delay_ms(500);      
         };
      }
      ////////////////////////////////////////////////////////////////////////////
            int trai = input(PIN_D7);
            int giua = input (PIN_D6);
            int phai = input (PIN_D5);
            
             setup_ccp1(CCP_PWM);
             setup_ccp2(CCP_PWM);
             setup_timer_2(T2_DIV_BY_16, 255, 1);
             
            int vitritruoc, destination,start,station;
            
            
         if ( (trai == 1 && giua == 0 && phai == 0) || (trai == 1 && giua == 1 && phai == 0) ) { // lech trai
             set_pwm1_duty(50); /// pwwm1 ben trai
             set_pwm2_duty(200); /// pwm2 ben phai
             move_left();
             delay_ms(1000);
             vitritruoc = 1;
             output_high(PIN_A0);
         } 
         if( (trai == 0 && giua == 0 && phai == 1) || (trai == 0 && giua == 1 && phai == 1)){ // lech phai
            set_pwm1_duty (200);
            set_pwm2_duty(50);
            move_right();
            delay_ms(1000);
            vitritruoc = 2;
            output_high(PIN_A1);
         }
         if( trai == 0 && giua == 1 && phai == 0) {
            set_pwm1_duty(100);
            set_pwm2_duty(100);
            move_foward();
            output_high(PIN_A0);
         }
         if( trai == 1 && giua == 1 && phai == 1) {
            set_pwm1_duty(200);
            set_pwm2_duty(200);
            move_foward();
            destination =+ 1;
            station =+ 1;
            output_low(PIN_A0);
          if(destination = finish) {
             set_pwm1_duty(0);
             set_pwm2_duty(100);
             move_right();
             delay_ms(4000);
             finish = data_fowarD;
             putc(data_foward);
             }
          if(station = start) {
            set_pwm1_duty(100);
            set_pwm2_duty(100);
            stop();
            delay_ms(10000);
            start = data_foward ;
            putc(data_foward);
          } 
         }
     //    if( destination = 3) {
    //        set_pwm1_duty(0);
    //        set_pwm2_duty(200);
    //        move_left();
    //        delay_ms(2000);
    //     }
    //     if( start = 1) {
    //        set_pwm1_duty(0);
    //        set_pwm2_duty(0);
    //        stop();
    //        delay_ms(3000);
    //     }
         if( trai == 0 && giua == 0 && phai ==0) {
            if(vitritruoc = 1) {
               set_pwm1_duty(150);
               set_pwm2_duty(100);
               move_left();
               delay_ms(1000);
               output_low(PIN_A0);
            }
            if(vitritruoc = 2){
               set_pwm1_duty(100);
               set_pwm2_duty(150);
               move_right();
               delay_ms(1000);
            }
         }
         }
         
   }
 
