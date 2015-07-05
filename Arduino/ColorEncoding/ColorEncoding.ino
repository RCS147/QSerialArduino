// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  
  char color[3];
  if(Serial.available() < 3)
  {
    return;  //Wait for 3 bytes of data.
  }
  
  Serial.readBytes(color, 3);
  
  //Output the colors
  analogWrite(11, color[0]); //Red
  analogWrite(9, color[1]);  //Green
  analogWrite(10, color[2]); //Blue  
}

