


#define PHOTO_GATE_INPUT_PIN      10
#define ALARM_OUTPUT_PIN          13  
#define TONE_OUTPUT_PIN           8
#define TIMEOUT_US                10000

void setup()
{
  pinMode(PHOTO_GATE_INPUT_PIN, INPUT);
  pinMode(ALARM_OUTPUT_PIN, OUTPUT);
  pinMode(TONE_OUTPUT_PIN, OUTPUT);
  digitalWrite(ALARM_OUTPUT_PIN, LOW);
} 

void loop()
{
  if (0 == pulseIn(PHOTO_GATE_INPUT_PIN, LOW, TIMEOUT_US)) 
  {
    digitalWrite(ALARM_OUTPUT_PIN, HIGH);

    int count = 4;
    while(count--)
    {
      tone(TONE_OUTPUT_PIN, 1000);
      delay(500);
      tone(TONE_OUTPUT_PIN, 800);
      delay(500);
    }
  }
  
  else
  {
    digitalWrite(ALARM_OUTPUT_PIN, LOW);
    noTone(TONE_OUTPUT_PIN);
  }
}

