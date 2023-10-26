int analogPin5 = 5;
int analogPin4 = 4;
int analogPin3 = 3;
int analogPin2 = 2;
int analogPin1 = 1;
int analogPin0 = 0;

int left2;
int left1;
int middle;
int right1;
int right2;
int light;

int enA = 11;
int in1 = 13;
int in2 = 12;
int enB = 10;
int in3 = 9;
int in4 = 8;

bool firstTime = true;

int direc = 0;
int tiw = 0;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
    digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void loop() {
  left2 = analogRead(analogPin5);
  left1 = analogRead(analogPin4);
  middle = analogRead(analogPin3);
  right1 = analogRead(analogPin2);
  right2 = analogRead(analogPin1);
  light = analogRead(analogPin0);
  //delay(1000);

  Serial.print("left2 = ");
  Serial.println(left2);
  Serial.print("left1 = ");
  Serial.println(left1);
  Serial.print("middle = ");
  Serial.println(middle);
  Serial.print("right1 = ");
  Serial.println(right1);
  Serial.print("right2 = ");
  Serial.println(right2);
  Serial.print("light = ");
  Serial.println(light);
  Serial.print("direc = ");
  Serial.println(direc);

  if(left1 < 820)
  {
    digitalWrite(2, HIGH);
  }
  else
    digitalWrite(2, LOW);
  if(left2 < 820)
  {
    digitalWrite(3, HIGH);
  }
  else
    digitalWrite(3, LOW);
  if(middle < 820)
  {
    digitalWrite(4, HIGH);
  }
  else
    digitalWrite(4, LOW);
  if(right1 < 820)
  {
   digitalWrite(5, HIGH); 
  }
  else
   digitalWrite(5, LOW); 
  if(right2 < 820)
  {
    digitalWrite(6, HIGH);
  }
  else
    digitalWrite(6, LOW);
  
  if(left1 < 850 && right1 < 850 && middle < 850 && right2 < 850 && left2 < 850 && direc == 0){
    while(true)
    {
     digitalWrite(in1, LOW);
     digitalWrite(in2, LOW);
     digitalWrite(in3, LOW);
     digitalWrite(in4, LOW);
     analogWrite(enA, 0);
     analogWrite(enB, 0);
     if(analogRead(analogPin0) <= 550 && direc == 0)
     {
      direc++;
      digitalWrite(7, HIGH);
      delay(1200);
      tiw = millis();
     }
     else if(direc == 1)
     {
      if(analogRead(analogPin0) <= 550)
      {
        direc++;
        break;
      }
      if(millis() - tiw > 5000)
      {
        break;
      }
     }
    }
  }
  else if(direc == 1){
    digitalWrite(7, LOW);
    digitalWrite(in2, LOW);  
    digitalWrite(in1, LOW);
    analogWrite(enA, 0);
    digitalWrite(in4, HIGH);  
    digitalWrite(in3, LOW);
    analogWrite(enB, 100);
    delay(600);
    direc = 0;
  }
  else if(direc >= 2){
    digitalWrite(7, LOW);
    digitalWrite(in4, LOW); 
    digitalWrite(in3, LOW);
    analogWrite(enB, 0);
    digitalWrite(in2, HIGH);  
    digitalWrite(in1, LOW);
    analogWrite(enA, 100);
    delay(600);
    direc = 0;
  }
   else if(left2 < 800){ // ============================== lefft2
    while(middle >= 800 && right1 >= 800 && right2 >= 800)
    {
      digitalWrite(in4, LOW); 
      digitalWrite(in3, HIGH);
      analogWrite(enB, 0);
      digitalWrite(in2, HIGH);  
      digitalWrite(in1, LOW);
      analogWrite(enA, 80);  
      middle = analogRead(analogPin3);
      right1 = analogRead(analogPin2);
      right2 = analogRead(analogPin1);
    }
    if(middle < 800)
    {
      // digitalWrite(in2, LOW);  
      // digitalWrite(in1, HIGH);
      // analogWrite(enA, 0);
      // digitalWrite(in4, HIGH);  
      // digitalWrite(in3, LOW);
      // analogWrite(enB, 90);
      digitalWrite(in2, HIGH);  
      digitalWrite(in1, LOW);
      analogWrite(enA, 50);
      digitalWrite(in4, HIGH);  
      digitalWrite(in3, LOW);
      analogWrite(enB, 80);  
  }
   }
  else if(right2 < 800){ // ============================== right2
    while(middle >= 800 && left1 >= 800 && left2 >= 800)
    {
      digitalWrite(in2, LOW);  
      digitalWrite(in1, HIGH);
      analogWrite(enA, 0);
      digitalWrite(in4, HIGH);  
      digitalWrite(in3, LOW);
      analogWrite(enB, 80); 
      left2 = analogRead(analogPin5);
      left1 = analogRead(analogPin4);
      middle = analogRead(analogPin3);
  }
  if(middle < 800)
    {
      // digitalWrite(in4, LOW);  
      // digitalWrite(in3, HIGH);
      // analogWrite(enB, 0);
      // digitalWrite(in2, HIGH);  
      // digitalWrite(in1, LOW);
      // analogWrite(enA, 90);
      digitalWrite(in4, HIGH);  
      digitalWrite(in3, LOW);
      analogWrite(enB, 50);
      digitalWrite(in2, HIGH);  
      digitalWrite(in1, LOW);
      analogWrite(enA, 80);         
    }
  }
  else if(left2 < 800 && left1 < 800){ // ============================== left1 and lefft2
    while(middle >= 800 && right1 >= 800 && right2 >= 800)
    {
      digitalWrite(in4, LOW);  
      digitalWrite(in3, HIGH);
      analogWrite(enB, 0);
      digitalWrite(in2, HIGH);  
      digitalWrite(in1, LOW);
      analogWrite(enA, 73);
      middle = analogRead(analogPin3);
      right1 = analogRead(analogPin2);
      right2 = analogRead(analogPin1);
    }
    if(middle < 800)
    {
      // digitalWrite(in2, LOW);  
      // digitalWrite(in1, HIGH);
      // analogWrite(enA, 0);
      // digitalWrite(in4, HIGH);  
      // digitalWrite(in3, LOW);
      // analogWrite(enB, 85); 
      digitalWrite(in2, HIGH);  
      digitalWrite(in1, LOW);
      analogWrite(enA, 57);
      digitalWrite(in4, HIGH);  
      digitalWrite(in3, LOW);
      analogWrite(enB, 73); 
    }
  }
  else if(right2 < 800 && right1 < 800){ // ============================== right1 and right2
    while(middle >= 800 && left1 >= 800 && left2 >= 800)
    {
      digitalWrite(in2, LOW);  
      digitalWrite(in1, HIGH);
      analogWrite(enA, 0);
      digitalWrite(in4, HIGH);  
      digitalWrite(in3, LOW);
      analogWrite(enB, 75);
      left2 = analogRead(analogPin5);
      left1 = analogRead(analogPin4);
      middle = analogRead(analogPin3);
  }
  if(middle < 800)
    {
      // digitalWrite(in2, LOW);  
      // digitalWrite(in1, HIGH);
      // analogWrite(enA, 0);
      // digitalWrite(in4, HIGH);  
      // digitalWrite(in3, LOW);
      // analogWrite(enB, 85); 
      digitalWrite(in2, HIGH);  
      digitalWrite(in1, LOW);
      analogWrite(enA, 60);
      digitalWrite(in4, HIGH);  
      digitalWrite(in3, LOW);
      analogWrite(enB, 75);    
    }
  }
  else if(left1 < 800){ // ============================== left1
    while(middle >= 800 && right1 >= 800 && right2 >= 800)
    {
      digitalWrite(in4, LOW); 
      digitalWrite(in3, HIGH);
      analogWrite(enB, 0);
      digitalWrite(in2, HIGH);  
      digitalWrite(in1, LOW);
      analogWrite(enA, 70);
      middle = analogRead(analogPin3);
      right1 = analogRead(analogPin2);
      right2 = analogRead(analogPin1);
    }
    if(middle < 800)
    {
      // digitalWrite(in2, LOW);  
      // digitalWrite(in1, HIGH);
      // analogWrite(enA, 0);
      // digitalWrite(in4, HIGH);  
      // digitalWrite(in3, LOW);
      // analogWrite(enB, 80);
      digitalWrite(in2, HIGH);  
      digitalWrite(in1, LOW);
      analogWrite(enA, 55);
      digitalWrite(in4, HIGH);  
      digitalWrite(in3, LOW);
      analogWrite(enB, 70);
    }
  }
  else if(right1 < 800 ){ // ============================== right1
    while(middle >= 800 && left1 >= 800 && left2 >= 800)
    {
    digitalWrite(in2, LOW);  
    digitalWrite(in1, HIGH);
    analogWrite(enA, 0);
    digitalWrite(in4, HIGH);  
    digitalWrite(in3, LOW);
    analogWrite(enB, 70);
    left2 = analogRead(analogPin5);
    left1 = analogRead(analogPin4);
    middle = analogRead(analogPin3);
  }
  if(middle < 800)
    {
      // digitalWrite(in4, LOW);  
      // digitalWrite(in3, HIGH);
      // analogWrite(enB, 0);
      // digitalWrite(in2, HIGH);  
      // digitalWrite(in1, LOW);
      // analogWrite(enA, 80);
      digitalWrite(in4, HIGH);
      digitalWrite(in3, LOW);
      analogWrite(enB, 55);
      digitalWrite(in2, HIGH); 
      digitalWrite(in1, LOW);
      analogWrite(enA, 70);
    }
  }   
  else if(middle < 800) // ============================== forward movement
  {
    digitalWrite(in2, HIGH);
    digitalWrite(in1, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in3, LOW);
    analogWrite(enA, 70);
    analogWrite(enB, 70
    );
    firstTime = true;
    
  }
  else {
    if(firstTime) // ============================== speed movement
    {
      digitalWrite(in2, HIGH);
      digitalWrite(in1, LOW);
      digitalWrite(in4, HIGH);
      digitalWrite(in3, LOW);
      analogWrite(enA, 100);
      analogWrite(enB, 100);
      delay(50);
      firstTime = false;
    }
    do // ============================== backward movement
    {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enA, 120);
      analogWrite(enB, 120);
      left2 = analogRead(analogPin5);
      left1 = analogRead(analogPin4);
      middle = analogRead(analogPin3);
      right1 = analogRead(analogPin2);
      right2 = analogRead(analogPin1);
    }
     while(right1 >= 800 && right2 >= 800 && left1 >= 800 && left2 >= 800 && middle >= 800);
    }
}
