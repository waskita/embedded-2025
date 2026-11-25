#define FSM_HOLD_OFF  200
#define FSM_HOLD_ON_0 201
#define FSM_HOLD_ON_1 202

// https://forum.arduino.cc/t/adding-multiple-file-arduino-error/275739/2
#ifdef __cplusplus
extern "C" {
#endif

extern void FSM_hold_init(int *state, int *counter, int *output);
extern void FSM_hold(int input, int *state, int *counter,int *output, int delay);


#ifdef __cplusplus
} // extern "C"
#endif

