#define FSM_DEBOUNCE_STATE_0 100
#define FSM_DEBOUNCE_STATE_1 101

#define FSM_EDGE_STATE_0 200
#define FSM_EDGE_STATE_1 201

#define FSM_GESER_STATE_S1 301
#define FSM_GESER_STATE_S2 302
#define FSM_GESER_STATE_S3 303
#define FSM_GESER_STATE_S4 304

void FSM_edge_detect_init(int *state, int *output);
void FSM_edge_detect(int input, int *state, int *output);

void FSM_geser_init(int *state, int *output);
void FSM_geser(int input_kiri, int input_kanan, int *state, int *output);


