#define FSM_DEBOUNCE_STATE_0 100
#define FSM_DEBOUNCE_STATE_1 101

#define FSM_EDGE_STATE_0 200
#define FSM_EDGE_STATE_1 201

#define FSM_GESER_STATE_S1 301
#define FSM_GESER_STATE_S2 302
#define FSM_GESER_STATE_S3 303
#define FSM_GESER_STATE_S4 304

// https://forum.arduino.cc/t/adding-multiple-file-arduino-error/275739/2
#ifdef __cplusplus
extern "C" {
#endif

extern void FSM_debounce_init(int *state, int *counter, int *output);
extern void FSM_debounce(int input, int *state, int *counter,int *output, int delay);

extern void FSM_edge_detect_init(int *state, int *output);
extern void FSM_edge_detect(int input, int *state, int *output);

extern void FSM_geser_init(int *state, int *output);
extern void FSM_geser(int input_kiri, int input_kanan, int *state, int *output);


#ifdef __cplusplus
} // extern "C"
#endif

