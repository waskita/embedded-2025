// integrasi menggunakan delay() sebagai sumber waktu
#define WEMOS_LED_BUILTIN 22

#define LAMPU_1 12
#define LAMPU_2 14
#define LAMPU_3 27
#define LAMPU_4 26

#define SWITCH_1 25
#define SWITCH_2 33

#include "fsm.h"
int edge_state;
int edge_output;

int debounce_ki_state;  // kiri
int debounce_ki_counter;
int debounce_ki_output;
int debounce_ka_state;  // kanan
int debounce_ka_counter;
int debounce_ka_output;
//
int edge_ki_state, edge_ka_state;
int edge_ki_output, edge_ka_output;
int geser_state;
int geser_output;
int input_ki;
int input_ka;


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

  FSM_debounce_init(&debounce_ki_state, &debounce_ki_counter, &debounce_ki_output);
  FSM_debounce_init(&debounce_ka_state, &debounce_ka_counter, &debounce_ka_output);
  FSM_edge_detect_init(&edge_ki_state, &edge_ki_output);
  FSM_edge_detect_init(&edge_ka_state, &edge_ka_output);
  FSM_geser_init(&geser_state, &geser_output);
}
int counter = 0;
// the loop function runs over and over again forever

// mapping nilai output ke LED yang dinyalakan

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

void delay_500() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(250);                       // wait for a second
}
// cek fsm edge detect

void loop() {
  int bounce_delay = 100; // dalam unit time
  int input_ki, input_ka;
  input_ki = digitalRead(SWITCH_1);
  input_ka = digitalRead(SWITCH_2);

  FSM_debounce(input_ki, &debounce_ki_state, &debounce_ki_counter, &debounce_ki_output, bounce_delay);
  FSM_debounce(input_ka, &debounce_ka_state, &debounce_ka_counter, &debounce_ka_output, bounce_delay);
  FSM_edge_detect(debounce_ki_output, &edge_ki_state, &edge_ki_output);
  FSM_edge_detect(debounce_ka_output, &edge_ka_state, &edge_ka_output);
  FSM_geser(edge_ki_output, edge_ka_output, &geser_state, &geser_output);
  output_led(geser_output);
  delay(1);  // delay 1 ms saja
}
