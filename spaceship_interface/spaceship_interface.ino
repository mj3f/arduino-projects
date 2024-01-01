int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);

}

// Check voltage on each ditigal input.

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2); // digital pin 2 connected to push button.

  if (switchState == LOW) {
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
  } else {
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    
    delay(250);

    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);    

    delay(250);
  }

}
