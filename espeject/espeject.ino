#include <Stepper.h>
#include <WiFi.h>
#include <PubSubClient.h>

const int stepsPerRevolution = 1600;
const char* ssid = "your-ssid";
const char* password =  "your-wifi-passcode";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

// Initialize the Stepper library on pins STEP, DIR
Stepper pebble(stepsPerRevolution, 5, 18);
Stepper longPebble(stepsPerRevolution, 12, 13);

void moveStepperRotations(Stepper stepper, int rotations);
void eject();

void setup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  pebble.setSpeed(200);
  longPebble.setSpeed(200);
  pinMode(19,OUTPUT);
  digitalWrite(19, HIGH); //MS1
  pinMode(18,OUTPUT);
  digitalWrite(18,LOW); //MS2
  pinMode(23,OUTPUT);
  digitalWrite(23,LOW); //ENABLE
}


void moveStepperRotations(Stepper stepper, int rotations) {
  long remainingSteps = (long) stepsPerRevolution * rotations; // Calculate steps from rotations
  int maxSteps = pow(2,15); // Max number of steps in one function call (based on u-int size limit)

  // While there are still steps remaining, step by integer limit intervals
  while (abs(remainingSteps) > maxSteps) {
      // Step by maxSteps intervals in the appropriate direction
      stepper.step(maxSteps * ((remainingSteps > 0) - (remainingSteps < 0)));

      // Update remaining amount of steps
      remainingSteps -= maxSteps * ((remainingSteps > 0) - (remainingSteps < 0));
  }

  // Step the remaining steps after we are safely below the integer limit
  stepper.step(remainingSteps);
}

void loop() {
  if (!client.connected()) {
    // Reconnect logic
    while (!client.connected()) {
      if (client.connect("hexkepler")) {
        client.subscribe("hexkepler/actions");
        client.subscribe("hexkepler/pebble");
        client.subscribe("hexkepler/longpebble");
        Serial.println("Subscribed. Emails coming your way soon. Just kidding, this doesn't email you.");
      }
      delay(5000); // Wait 5 seconds before retrying
    }
  }
  client.loop(); // Needed to maintain MQTT connection
}

void callback(char* topic, byte* message, unsigned int length) {
  String messageTemp;
  Serial.println("MQTT in. Topic: "+String(topic));
  for (int i = 0; i < length; i++) {
    messageTemp += (char)message[i];
  }

  if (String(topic) == "hexkepler/actions") {
    if(messageTemp == "ejecter") {
      eject();
    }
  }
  if (String(topic) == "hexkepler/pebble") {
    int rots = messageTemp.toInt();
    Serial.println("MQTT: pebble rotate "+messageTemp);
    moveStepperRotations(pebble,rots);
    Serial.println("Done rotating pebble "+messageTemp);
  }
  if (String(topic) == "hexkepler/longpebble") {
    int rots = messageTemp.toInt();
    Serial.println("MQTT: longPebble rotate "+messageTemp);
    moveStepperRotations(longPebble,rots);
    Serial.println("Done rotating longPebble "+messageTemp);
  }
}

void eject() {
  Serial.println("Ejecting");
  moveStepperRotations(longPebble,2);
  moveStepperRotations(pebble, 10);
  moveStepperRotations(longPebble, 10);
  moveStepperRotations(pebble, 77);
  moveStepperRotations(longPebble, 73);
  Serial.println("Retracting");
  moveStepperRotations(longPebble, -73);
  moveStepperRotations(pebble, -77);
  moveStepperRotations(longPebble, -10);
  moveStepperRotations(pebble,-10);
  moveStepperRotations(pebble,-1);
  moveStepperRotations(longPebble,-1);
  Serial.println("Done ejecting");
}
