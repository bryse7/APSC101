void statusUpdate() {

  Serial.print ( "Sonar Response: " );
  Serial.print ( heightCM );
  Serial.print ( "cm | ");

  Serial.print ( "Countdown: " );
  Serial.print ( timer );
  Serial.print ( " s | " );

  LED_Status();

  openStatus();

  tweakStatus();

}

void LED_Status(){

  Serial.print( "LEDs on: " );

  switch( timer ){
    
        case 4:

            Serial.print ( "B" );
  
            break;
  
        case 3:
        
            Serial.print ( "BG" );
  
            break;
  
        case 2:
  
            Serial.print ( "BGY" );
  
            break;
  
        case 1:
  
            Serial.print ( "BGYR" );
  
            break;
  
        case 0:

            Serial.print ( "Blinked!" );
  
            break;
  
        default:

            Serial.print ( "None" );
  
            break;
  }

  Serial.print( " | " );
  
}

void openStatus(){
  
  
  if( timer == 0 && capture ) {
        
      Serial.print( "CLAW SWITCHED TO OPEN! | " );
          
  }
  else if( timer == 0 && !capture){

      Serial.print( "CLAW SWITCHED TO CLOSED! | " );
      
  }
  else if (capture){

      Serial.print( "CLAW IS OPEN | " );
  }
  else{

      Serial.print( "CLAW IS CLOSED | " );
  }
}

void tweakStatus(){

  Serial.print( " Temp position: " );
  Serial.print(tempPos);
  Serial.print( " | " );

  Serial.print( "Edit Mode: " );

  if( tweak ){
    Serial.print( "ON!" );
    Serial.print( " | " );

    Serial.print( "Change: " );
    Serial.println(change);
  }
  else{
    Serial.print( "OFF!" );
    Serial.print( "Change: " );
    Serial.println(change);
  }
  
  
}
