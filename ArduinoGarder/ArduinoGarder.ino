//Define input pins for sensors

#define SENSOR1 3
#define SENSOR2 2
#define SENSOR3 1
#define SENSOR4 0

//Define output pins for relays
#define RELAY1 9
#define RELAY2 10
#define RELAY3 11
#define RELAY4 12

//Define Dry and wet sensor values
#define S1_WET 0
#define S1_DRY 252

#define S2_WET 0
#define S2_DRY 261

#define S3_WET 0
#define S3_DRY 199

#define S4_WET 0
#define S4_DRY 232

int S1_value = 0;
int S2_value = 0;
int S3_value = 0;
int S4_value = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
  digitalWrite(RELAY3, LOW);
  digitalWrite(RELAY4, LOW);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  S1_value = analogRead(SENSOR1);
  S2_value = analogRead(SENSOR2);
  S3_value = analogRead(SENSOR3);
  S4_value = analogRead(SENSOR4);

    // print the results to the Serial Monitor:
  Serial.print("sensor 1 = ");
  Serial.print(S1_value);
  Serial.print("\t sensor 2 =  ");
  Serial.print(S2_value);
  Serial.print("\t sensor 3 =  ");
  Serial.print(S3_value);
  Serial.print("\t sensor 4 =  ");
  Serial.println(S4_value);
  if(S1_value < 500){
    digitalWrite(RELAY1, HIGH);
  }else{
    digitalWrite(RELAY1, LOW);
  }
  if(S2_value < 500){
    digitalWrite(RELAY2, HIGH);
  }else{
    digitalWrite(RELAY2, LOW);
  }
  if(S3_value < 500){
    digitalWrite(RELAY3, HIGH);
  }else{
    digitalWrite(RELAY3, LOW);
  }
  if(S4_value < 500){
    digitalWrite(RELAY4, HIGH);
  }else{
    digitalWrite(RELAY4, LOW);
  }

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
