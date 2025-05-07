#define FSM_GESER_STATE_S1 1
#define FSM_GESER_STATE_S2 2
#define FSM_GESER_STATE_S3 3
#define FSM_GESER_STATE_S4 4

#define FSM_EDGE_STATE_0 100
#define FSM_EDGE_STATE_1 101


void FSM_geser_init(int *state, int *output);
void FSM_geser(int input_kiri, int input_kanan, int *state, int *output);
