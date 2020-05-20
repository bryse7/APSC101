/*
 *          AUTHOR:   BRYSON WU
 *            DATE:   JANUARY 27, 2020
 *  STUDENT NUMBER:   10417798
 *  COURSE/SECTION:   APSC 101 / L2R
 * 
 *         PURPOSE:   
 */
#include <NewPing.h>
#include <Servo.h>

     // Connection [Pin]
     // -------------
#define SONAR_VCC 13                                 
#define SONAR_TRIG 12                                                     
#define SONAR_ECHO 11
#define SONAR_GND 10
     // -------------
#define SONAR_MAX 200     //Informs NewPing object of our sonar's maximum sensing range

NewPing sonar(SONAR_TRIG, SONAR_ECHO, SONAR_MAX); //Sets up our sonar object and names it sonar

     // Connection [Pin]
     // -------------
#define SERVO_CTRL 5
     // -------------
Servo servo;  //Sets up our servo object and names it servo

#define BOUNDARY 5        // Sets the height in cm below which our claw will operate in
#define COUNTDOWN 2        // Sets the amount of time in seconds before our claw activiates while within the boundary

#define OPEN_POS 0
#define CLOSE_POS 200
void setup() {

  Serial.begin ( 9600 );              //  Sets the data transmission rate to 9600 bits per second

  pinMode ( SONAR_VCC, OUTPUT );      //  This chunk of code provides the sonar power by sending 5V 
  pinMode ( SONAR_GND, OUTPUT );      //  through SONAR_VCC and a ground connection through SONAR_GND.
  digitalWrite ( SONAR_VCC, HIGH );   
  digitalWrite ( SONAR_GND, LOW );
  
  pinMode ( SONAR_TRIG, OUTPUT );     //  This chunk defines the I/O connections between arduino and sonar.
  pinMode ( SONAR_ECHO, INPUT );      //  Trigger pulses are sent through SONAR_TRIG and feedback is received 
                                      //  through SONAR_ECHO.
  
  pinMode ( SERVO_CTRL, OUTPUT );     //  This chunk tells the arduino to send position data through 
  servo.attach( SERVO_CTRL );         //  the SERVO_CTRL pin.

}

int heightCM;
int timer; 
boolean capture = true;

void loop() {

  heightCM = sonar.ping_cm();
  timer = COUNTDOWN;
  

  Serial.print ( heightCM );
  Serial.println (" cm");
  Serial.print ( "capture? ");
  Serial.println ( capture );

  while ( heightCM <= BOUNDARY ){

    heightCM = sonar.ping_cm();
    
    timer--;
    Serial.println ( timer );

    if ( timer == 0 ){
      
      switch (capture){

            case true:
              servo.write( CLOSE_POS );
              delay ( 1000 );
              
              capture = false;
              break;
            

            case false:
              servo.write ( OPEN_POS );
              delay ( 1000 );
              capture = true;
              break;

            default:

              break;
      } 
      
    }
    if ( timer < 0 ) timer = COUNTDOWN;

    delay( 1000 );
  }

  
  delay ( 1000 );
 
}