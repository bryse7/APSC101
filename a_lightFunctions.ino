void lights(){

  if ( heightCM <= BOUNDARY ){
    
    digitalWrite( LED_I, HIGH );
    
  }
  else{

    digitalWrite( LED_I, LOW );
    
  }
  
  switch (timer){
  
        case 1:
  
            digitalWrite( LED_B, HIGH );
            digitalWrite( LED_G, HIGH );

            break;
  
        case 0:
  
            digitalWrite( LED_Y, HIGH );
            digitalWrite( LED_R, HIGH );

            break;
  
        default:
  
            digitalWrite( LED_B, LOW );
            digitalWrite( LED_G, LOW );
            digitalWrite( LED_Y, LOW );
            digitalWrite( LED_R, LOW );
  
            break;
    }

  
}
