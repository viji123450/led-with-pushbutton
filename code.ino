const int led1 = 2;  
const int led2 = 3; 
const int led3 = 4;  
const int buttonPin = 7; 

int buttonState = 0;   
int lastButtonState = 0; 
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50; 

unsigned long lastPressTime = 0; 
int pressCount = 0; 
bool ledState = false;  

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  
}

void loop() {
  int reading = digitalRead(buttonPin);  
 
  if (reading != lastButtonState) {
    lastDebounceTime = millis();  
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW) {  
      if (millis() - lastPressTime > 300) {  
        pressCount++;  
        lastPressTime = millis();  
        if (pressCount > 3) pressCount = 1;  
      }
    }
  }

  
  switch (pressCount) {
    case 1:
      digitalWrite(led1, HIGH);  
      digitalWrite(led2, LOW);   
      digitalWrite(led3, LOW);   
      break;
    case 2:
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH); 
      digitalWrite(led3, LOW);   
      break;
    case 3:
      digitalWrite(led1, LOW);  
      digitalWrite(led2, LOW);  
      digitalWrite(led3, HIGH);  
      break;
    default:
      pressCount = 0;  
      digitalWrite(led1, LOW); 
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      break;
  }

  lastButtonState = reading; 
}
