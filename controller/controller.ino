void setup() {
    Serial1.begin(9600);
    Serial1.println("Start");
}

void loop() {
    Serial1.println("Hello Pi");

    if (Serial1.available()) {
        String msg = Serial1.readStringUntil('\n');
        Serial.println("Got: " + msg);
    }

    if (Serial.available()) {
        String msg = Serial.readStringUntil('\n');
        Serial1.println("Got: " + msg);
    }
    delay(1000);
}
