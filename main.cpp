// ==========================================================================
//
// blink a led on PIOB pin 27 == arduino-due on-board LED
//
// This file is in the public domain.
//
// ==========================================================================

#include "hwlib.hpp"

int main( void ){	
   // hwlib will kill the watchdog
   
   // the on-board LED is connected to port B bit 27   
   auto led = hwlib::target::pin_in_out( hwlib::target::pins::d13 );
   led.direction_set_output();
   led.direction_flush();
   while(1){
      led.write( 1 );
      led.flush();
      hwlib::wait_ms( 200 );
      led.write( 0 );
      led.flush();
      hwlib::wait_ms( 200 );   
   }
}
