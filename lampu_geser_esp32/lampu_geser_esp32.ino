#define WEMOS_LED_BUILTIN 22

#define LAMPU_1 12
#define LAMPU_2 14
#define LAMPU_3 27
#define LAMPU_4 26

#define SWITCH_1 25
#define SWITCH_2 33

int edge_state;
int edge_output;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  Serial.println(F(__FILE__));
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(WEMOS_LED_BUILTIN, OUTPUT);
  pinMode(LAMPU_1, OUTPUT);
  pinMode(LAMPU_2, OUTPUT);
  pinMode(LAMPU_3, OUTPUT);
  pinMode(LAMPU_4, OUTPUT);

  pinMode(SWITCH_1, INPUT_PULLDOWN);
  pinMode(SWITCH_2, INPUT_PULLDOWN);

  FSM_edge_detect_init(&edge_state, &edge_output);
}
int counter = 0;
// the loop function runs over and over again forever

void fsm_edge_detect(int input, int *output, int *state, int *counter) {
  // *state adalah input sebelumnya
  if (input == 0 && *state == 0) {
    *output = 1;
  } else {
    *output = 0;
  }
  *state = input;
}
void fsm_lampu_geser(int input_kiri, int input_kanan, int *state) {
  // state adalah nomor lampu yang aktif: 1,2,3,4
}

#define FSM_GESER_STATE_S1 1
#define FSM_GESER_STATE_S2 2
#define FSM_GESER_STATE_S3 3
#define FSM_GESER_STATE_S4 4

#define FSM_EDGE_STATE_0 100
#define FSM_EDGE_STATE_1 101

//#FSM_geser
//#FSM_debounce
//#FSM_edge_detect


void FSM_edge_detect_init(int *state, int *output) {
  *state = FSM_EDGE_STATE_0;
}
void FSM_edge_detect(int input, int *state, int *output) {
  int next_state = *state;
  if (*state == FSM_EDGE_STATE_0 && input == 0) {
    next_state = FSM_EDGE_STATE_0;
    *output = 0;
  }
  if (*state == FSM_EDGE_STATE_0 && input == 1) {
    next_state = FSM_EDGE_STATE_1;
    *output = 1;
  }
  if (*state == FSM_EDGE_STATE_1 && input == 0) {
    next_state = FSM_EDGE_STATE_0;
    *output = 0;
  }
  if (*state == FSM_EDGE_STATE_1 && input == 1) {
    next_state = FSM_EDGE_STATE_1;
    *output = 0;
  }
  *state = next_state;
}

void FSM_geser_init(int *state, int *output) {
  *state = FSM_GESER_STATE_S1;
  *output = 1;
}

void FSM_geser(int input_kiri, int input_kanan, int *state, int *output) {
  int next_state = *state;  // default not change state

  if (*state == FSM_GESER_STATE_S1 && input_kiri == 1) {
    next_state = FSM_GESER_STATE_S4;
    *output = 4;
  }
  if (*state == FSM_GESER_STATE_S1 && input_kanan == 1) {
    next_state = FSM_GESER_STATE_S2;
    *output = 2;
  }
  if (*state == FSM_GESER_STATE_S2 && input_kiri == 1) {
    next_state = FSM_GESER_STATE_S1;
    *output = 1;
  }
  if (*state == FSM_GESER_STATE_S2 && input_kanan == 1) {
    next_state = FSM_GESER_STATE_S3;
    *output = 3;
  }
  if (*state == FSM_GESER_STATE_S3 && input_kiri == 1) {
    next_state = FSM_GESER_STATE_S2;
    *output = 2;
  }
  if (*state == FSM_GESER_STATE_S3 && input_kanan == 1) {
    next_state = FSM_GESER_STATE_S4;
    *output = 4;
  }
  if (*state == FSM_GESER_STATE_S4 && input_kiri == 1) {
    next_state = FSM_GESER_STATE_S3;
    *output = 3;
  }
  if (*state == FSM_GESER_STATE_S4 && input_kanan == 1) {
    next_state = FSM_GESER_STATE_S1;
    *output = 1;
  }
  *state = next_state;
}

void output_led(int geser_output) {
  switch (geser_output) {
    case 1:
      {
        digitalWrite(LAMPU_1, HIGH);
        digitalWrite(LAMPU_2, LOW);
        digitalWrite(LAMPU_3, LOW);
        digitalWrite(LAMPU_4, LOW);
        break;
      }
    case 2:
      {
        digitalWrite(LAMPU_1, LOW);
        digitalWrite(LAMPU_2, HIGH);
        digitalWrite(LAMPU_3, LOW);
        digitalWrite(LAMPU_4, LOW);
        break;
      }
    case 3:
      {
        digitalWrite(LAMPU_1, LOW);
        digitalWrite(LAMPU_2, LOW);
        digitalWrite(LAMPU_3, HIGH);
        digitalWrite(LAMPU_4, LOW);
        break;
      }
    case 4:
      {
        digitalWrite(LAMPU_1, LOW);
        digitalWrite(LAMPU_2, LOW);
        digitalWrite(LAMPU_3, LOW);
        digitalWrite(LAMPU_4, HIGH);
        break;
      }
  }
}

void print_status(int state, int output) {
  Serial.print(state);
  Serial.print(" ");
  Serial.print(output);
  Serial.println();
}
int geser_state = 0;
int geser_output = 0;

void delay_500() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(250);                       // wait for a second
}
// cek fsm edge detect

void loop() {
  int input;
  input = digitalRead(SWITCH_1);
  FSM_edge_detect(input, &edge_state, &edge_output);
  if (edge_output == 1) {
    Serial.println("Output 1");
  }
  Serial.print(input);
  Serial.print(" ");
  Serial.print(edge_state);
  Serial.print(" ");
  Serial.print(edge_output);
  Serial.println();

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(250);                       // wait for a second
}

// cek fsm geser
void loop1() {
  FSM_geser_init(&geser_state, &geser_output);

  // geser kiri
  FSM_geser(1, 0, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();
  FSM_geser(1, 0, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();
  FSM_geser(1, 0, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();
  FSM_geser(1, 0, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();

  // no change
  FSM_geser(0, 0, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();
  FSM_geser(0, 0, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();
  FSM_geser(0, 0, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();
  FSM_geser(0, 0, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();


  // geser kanan
  FSM_geser(0, 1, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();
  FSM_geser(0, 1, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();
  FSM_geser(0, 1, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();
  FSM_geser(0, 1, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();

  // no change
  FSM_geser(0, 0, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();
  FSM_geser(0, 0, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();
  FSM_geser(0, 0, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();
  FSM_geser(0, 0, &geser_state, &geser_output);
  print_status(geser_state, geser_output);
  output_led(geser_output);
  delay_500();
}
