const int enPin=8;
const int stepXPin = 2; //X.STEP
const int dirXPin = 5; // X.DIR
const int stepYPin = 3; //Y.STEP
const int dirYPin = 6; // Y.DIR
const int stepZPin = 4; //Z.STEP
const int dirZPin = 7; // Z.DIR

int stepPin=stepYPin;
int dirPin=dirYPin;

struct stepperDefaults {
    int angleDegrees = 360;
    int stepsPerRevolution = 200;
    int delayMicroseconds = 50;
};

rotateStepper(int f_stepPin, float f_angleDegrees, int f_stepsPerRevolution, int f_delayMicroseconds) {
    for(int i;i<f_stepsPerRevolution*(f_angle/360);i++){
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(f_delayMicroseconds);
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(f_delayMicroseconds);
    }
}

void setup() {
    Serial.begin(9600);
    digitalWrite(enPin, LOW);
    pinMode(stepXPin, OUTPUT);
    pinMode(dirXPin, OUTPUT);
    pinMode(stepYPin, OUTPUT);
    pinMode(dirYPin, OUTPUT);
    pinMode(stepZPin, OUTPUT);
    pinMode(dirZPin, OUTPUT);
    struct stepperDefaults _defaults;
}

void loop() {
    rotateStepper(stepXPin,_defaults.angleDegrees,_defaults.stepsPerRevolution,_defaults.delayMicroseconds);
    delay(1000);
}