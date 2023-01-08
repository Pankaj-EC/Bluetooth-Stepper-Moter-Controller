int pin1 = 7;
int pin2 = 8;
int pin3 = 9;
int pin4 = 10;
int value;
int a = A0;
char P;
int counter = 0;
int currentState = 0;
int previousState = 0;

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop() {
  value = 5;
  while (Serial.available()) {
    P = Serial.read();

    if (P == 'R')
    {
      currentState = 1;
    }
    else
    {
      currentState = 0;
    }
    if (currentState != previousState) {
      if (currentState == 1) {
        counter = counter + 1;
      }
    }
    previousState = currentState;
    if (counter == 2)
    {
      counter = 0;
    }
    switch (counter)
    {
      case 1:
        f();
        break;

      case 0:
        r();
        break;
    }
  }

 Serial.println(counter);


}

void f()
{
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  delay(value);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  delay(value);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  delay(value);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(value);
  
}
void r()
{
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  delay(value);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  delay(value);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  delay(value);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  delay(value);
  

}
