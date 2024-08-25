// defining what corresponds to the digital pins on the Arduino
int white = 2; // white LED pin
int orange = 3; // orange LED pin
int button = 4; // pushbutton pin
int green = 5; // green LED pin
int yellow = 6; // yellow LED pin
int red = 7; // red LED pin

// defining the initial pushbutton status
int buttonState = 0; // LOW

void setup() {
	// initializing traffic lights for vehicles
	pinMode(green, OUTPUT);
	pinMode(yellow, OUTPUT);
    	pinMode(red, OUTPUT);
	// initializing traffic lights for pedestrians
   	pinMode(orange, OUTPUT);
  	pinMode(white, OUTPUT);
	// initializing the pedestrian push button
  	pinMode(button, INPUT);
}

void loop() {
	// turn on green for vehicles
    	green_light();
	// read the state of the button
	buttonState = digitalRead(button);
	// if the button was pressed
  	if (buttonState == HIGH){
		// wait for 5 seconds
      		delay(5000);
		// switch green to yellow
      		yellow_light();
		// wait for 2 seconds
      		delay(2000);
		// switch yellow to red
      		red_light();
		// wait for 2 seconds
      		delay(2000);
		// turn on the white light for pedestrians
      		white_light();
		// wait for 4 seconds
      		delay(4000);
		// switch white to blinking orange
      		orange_light();
		// wait for 3 seconds before turning green back on for vehicles
      		delay(3000);
		// reset the button to LOW (i.e. as if it was not pressed)
      		buttonState == LOW;
    	}

}

void green_light(){
  	// green goes on
  	digitalWrite(green, HIGH);
	//  turn off yellow, red, white, and orange
  	digitalWrite(yellow, LOW);
  	digitalWrite(red, LOW);
  	digitalWrite(white, LOW);
  	digitalWrite(orange, LOW);
}

void yellow_light(){
  	// yellow goes on
  	digitalWrite(yellow, HIGH);
	// turn off green, red, white, and orange
  	digitalWrite(green, LOW);
  	digitalWrite(red, LOW);
  	digitalWrite(white, LOW);
  	digitalWrite(orange, LOW);
}

void red_light(){
  	// red goes on
  	digitalWrite(red, HIGH);
	// turn off green and yellow
  	digitalWrite(green, LOW);
	digitalWrite(yellow, LOW);
}

void white_light(){
  // turn white on, turn off orange
  	digitalWrite(white, HIGH);
  	digitalWrite(orange, LOW);
}

void orange_light(){
 	//turn off white
  	digitalWrite(white, LOW);
	// blink orange LED for about 15 seconds
  	for (int i=0; i<10; i++){
		// turn orange on
    		digitalWrite(orange, HIGH);
		// wait for 3/4 of a second
    		delay(750);
		// turn orange on
    		digitalWrite(orange, LOW);
		// wait for 3/4 of a second
    		delay(750);
  	}  
}
