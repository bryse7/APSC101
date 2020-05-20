/*
  Page 3 of 3 additional pages in the original clawMain.ino file. 
  This page creates a mode, activated by the button inside the joystick, 
  that adjusts the target open and close positions for the servo motor in 
  real-time as needed. Used to make adjustments during testing.
*/
void clawTweaks(){

  tweak = true;

  if(capture){

    tempPos = OPEN_POS;
      
  }
  else{

    tempPos = CLOSE_POS;
    
  }

  btnConfirm = digitalRead( JOY_BTN );

  while( btnConfirm == 0 ){
    
    btnConfirm = digitalRead( JOY_BTN );

    Serial.println("Release button to move on!");
    
    indicator(0);
    statusUpdate();
  }

  while( tweak ){

    indicator(1);
    
    VRy = analogRead( JOY_VRy );
    change = map( VRy, 0, 1000, -1, 1 );

    tempPos = tempPos + change;

    servo.write(tempPos);

    btnConfirm = digitalRead( JOY_BTN );

    statusUpdate();

    if ( btnConfirm == 0 ) {

      if ( capture ){

        OPEN_POS = tempPos;
        btn = 0;

        Serial.print("New OPEN_POS: ");
        Serial.println(OPEN_POS);
      }
      else{

        CLOSE_POS = tempPos;
        btn = 0;

        Serial.print("New CLOSE_POS: ");
        Serial.println(CLOSE_POS);
      }

      tweak = false;
      
      indicator(2);
      statusUpdate();
    }

  }
   
}

int indicator (int i){

  switch(i){

    case 0:

      digitalWrite( LED_I, HIGH );
      delay ( 500 );

      digitalWrite( LED_I, LOW );
      delay ( 500 );

      digitalWrite( LED_I, HIGH );
      delay ( 1000 );

      digitalWrite( LED_I, LOW );
      delay ( 500 );
    
      break;
      
    case 1:

      digitalWrite( LED_I, HIGH );
      delay ( 100 );

      digitalWrite( LED_I, LOW );
      delay ( 100 );
      
      break;
      
    case 2:

      digitalWrite( LED_I, HIGH );
      delay ( 500 );

      digitalWrite( LED_I, LOW );
      delay ( 500 );

      digitalWrite( LED_I, HIGH );
      delay ( 500 );

      digitalWrite( LED_I, LOW );
      delay ( 500 );
      
      break;
      
    default:
      Serial.println("ERROR: indicator case corrupted!");
      break;
  }
}
