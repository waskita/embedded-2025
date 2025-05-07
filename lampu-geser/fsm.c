#include "fsm.h"

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
