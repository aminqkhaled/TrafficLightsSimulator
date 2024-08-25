// variables
int white = 2; // the number of the white LED pin
int orange = 3; // the number of the orange LED pin
int button = 4; // the number of the pushbutton pin
int green = 5; // the number of the green LED pin
int yellow = 6; // the number of the yellow LED pin
int red = 7; // the number of the red LED pin


// delays for every LED
int GREEN_DELAY = 5000;
int YELLOW_DELAY = 2000;
int RED_DELAY = 5000;

int buttonState = 0; // variable for reading the pushbutton status

void setup() {
    pinMode(green, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(red, OUTPUT);
  	pinMode(orange, OUTPUT);
  	pinMode(white, OUTPUT);
  	pinMode(button, INPUT);
}

void loop() {
    green_light();
	buttonState = digitalRead(button);
  	if (buttonState == HIGH)
    {
      delay(5000);
      yellow_light();
      delay(YELLOW_DELAY);
      red_light();
      delay(2000);
      white_light();
      delay(4000);
      orange_light();
      delay(3000);
      buttonState == LOW;
    }

}

void green_light()
{
  // turn green on, turn off red, yellow, white, and orange
  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(white, LOW);
  digitalWrite(orange, LOW);
}

void yellow_light()
{
  // turn yellow on, turn off red, green, white, and orange
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(white, LOW);
  digitalWrite(orange, LOW);
}

void red_light()
{
  // turn red on, turn off yellow and green
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
}

void white_light()
{
	// turn white on, turn off orange
  	digitalWrite(white, HIGH);
  	digitalWrite(orange, LOW);
}

void orange_light()
{
	// blink orange, turn off white
  digitalWrite(white, LOW);
  for (int i=0; i<10; i++){
    digitalWrite(orange, HIGH);
    delay(750);
    digitalWrite(orange, LOW);
    delay(750);
  }  
}
