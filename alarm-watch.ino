#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ===== OLED SETTINGS =====
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//  WiFi
const char* ssid = "myPC";
const char* password = "54ML17O7";

//  MQTT Broker
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

// Hardware pins
#define LED_PIN 4
#define MOTOR_PIN 23

//  SAFE SCREEN
void showSafeScreen() {
  display.clearDisplay();
  display.setTextColor(WHITE);

  display.setTextSize(2);
  display.setCursor(20, 10);
  display.println("SAFE");

  display.setTextSize(1);
  display.setCursor(30, 40);
  display.println("State: Normal");

  display.display();
}

//  ALERT SCREEN
void showAlertScreen() {
  display.clearDisplay();
  display.setTextColor(WHITE);

  display.setTextSize(2);
  display.setCursor(10, 5);
  display.println("ALERT !");

  display.setTextSize(2);
  display.setCursor(10, 30);
  display.println("Gas Leak");

  display.display();
}

//  When MQTT message arrives
void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";

  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Message: ");
  Serial.println(message);

  if (message == "ON") {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(MOTOR_PIN, HIGH);
    showAlertScreen();
  }
  else if (message == "OFF") {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(MOTOR_PIN, LOW);
    showSafeScreen();
  }
}

// Connect WiFi
void setup_wifi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
}

//  MQTT reconnect
void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting MQTT...");

    if (client.connect("ESP32_WATCH")) {
      Serial.println("connected");
      client.subscribe("watch/vibrate");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" retrying...");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);

  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (true);
  }

  showSafeScreen();  // Start with SAFE

  setup_wifi();

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
