#define BUTTON_AMOUNT 16

enum button_state {
    INACTIVE,
    PRESSED,
    HELD,
    RELEASED,
};

struct StickData {
    int16_t x_axis;
    int16_t y_axis;
    button_state button;
}

struct GyroscopeData {
    int16_t accelerometer_x;
    int16_t accelerometer_y;
    int16_t accelerometer_z;
    int16_t gyroscope_x;
    int16_t gyroscope_y;
    int16_t gyroscope_z;
}

struct InputData {
    button_state buttons[BUTTON_AMOUNT];
    StickData left_stick;
    StickData right_stick;
    GyroscopeData gyroscope_data;
};

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
