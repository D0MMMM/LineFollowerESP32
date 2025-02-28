// CMD - innovator tech company

// Domenick B. Mahusay 
// Albert Mark B. Alferez
// Carlos A. Sode Jr.



// Define motor driver pins
#define ENA 13
#define IN1 12
#define IN2 14
#define ENB 27
#define IN3 26
#define IN4 25

// Define IR sensor pins
#define IR_LEFT 32
#define IR_RIGHT 33

// Define motor speed
#define SPEED_FORWARD 140
#define SPEED_TURN 80
#define SPEED_STOP 0

void setup() {
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(IR_LEFT, INPUT);
    pinMode(IR_RIGHT, INPUT);
}

void loop() {
    int leftSensor = digitalRead(IR_LEFT);
    int rightSensor = digitalRead(IR_RIGHT);

    if (leftSensor == 1 && rightSensor == 0) {
        turnRight();
    } else if (leftSensor == 0 && rightSensor == 1) {
        turnLeft();
    } else if (leftSensor == 0 && rightSensor == 0) {
        moveForward();
    } else {
        stopMotors();
    }
}

void moveForward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, SPEED_FORWARD);
    analogWrite(ENB, SPEED_FORWARD);
}

void turnRight() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, SPEED_TURN);
    analogWrite(ENB, 140);
}

void turnLeft() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 140);
    analogWrite(ENB, SPEED_TURN);
}

void stopMotors() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, SPEED_STOP);
    analogWrite(ENB, SPEED_STOP);
}
