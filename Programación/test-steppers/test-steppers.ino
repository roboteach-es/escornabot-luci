/*
 *   Testing Luci's stepper motors
 */

const static uint8_t state_sequence[] = {B0011, B0110, B1100, B1001}; // full drive
const static uint8_t delta_state_sequence = sizeof(state_sequence)-1;

// step tracking
int currentStateIndex = 0;
int stepDelay = 2500;


/*
 *   S E T U P   &   L O O P   F U N C T I O N S
 */

void setup() {
    initCoilsPins();
    // alive!
    tone(2, 4699, 100); // default beep
}

void loop() {
    // move forward indefinitely
    setCoils(state_sequence[delta_state_sequence-currentStateIndex], state_sequence[currentStateIndex]);
    currentStateIndex++;
    if (currentStateIndex>3) currentStateIndex=0;
    delayMicroseconds(stepDelay);
}


/*
 *   S U P P O R T   F U N C T I O N S
 */

/*
Luci configuration to simplify PORTx usage

#define STEPPERS_MOTOR_LEFT_IN1 4    // blue
#define STEPPERS_MOTOR_LEFT_IN2 5    // pink
#define STEPPERS_MOTOR_LEFT_IN3 6    // yellow
#define STEPPERS_MOTOR_LEFT_IN4 7    // orange
#define STEPPERS_MOTOR_RIGHT_IN1 8   // blue
#define STEPPERS_MOTOR_RIGHT_IN2 9   // pink
#define STEPPERS_MOTOR_RIGHT_IN3 10  // yellow
#define STEPPERS_MOTOR_RIGHT_IN4 11  // orange
*/
void initCoilsPins()
{
    // PORTB maps to Arduino digital pins 8 to 13. The two high bits (6 & 7) map to the crystal pins and are not usable.
    DDRB = DDRB | B00001111;  // pins x,x,x,x,11,10,9,8 as OUTPUT - Right motor
    // PORTD maps to Arduino digital pins 0 to 7. Pins 0 and 1 are TX and RX, manipulate with care.
    DDRD = DDRD | B11110000;  // pins 7,6,5,4,x,x,x,x as OUTPUT - Left motor
}

void setCoils(uint8_t stateR, uint8_t stateL)
{
    // PORTD maps to Arduino digital pins 0 to 7
    // RightMotor - pins 4,5,6,7   -> PORTD bits[7-4] = stateR bits[3-0]
    // (a & ~mask) | (b & mask)
    // a -> PIND  b->(stateR << 4)  mask->B11110000
    PORTD = (PORTD & B00001111) | ((stateL << 4) & B11110000);

    // PORTB maps to Arduino digital pins 8 to 13 The two high bits (6 & 7) map to the crystal pins and are not usable
    // LeftMotor  - pins 8,9,10,11 -> PORTB bits[3-0] = stateL bits[3-0]
    // (a & ~mask) | (b & mask)
    // a -> PINB  b->stateL  mask->B00001111
    PORTB = (PORTB & B11110000) | (stateR & B00001111);
}
