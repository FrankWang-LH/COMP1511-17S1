
// data page

#define N_TILES 4
#define MAX_TILE 8

int read_tiles(int tiles[N_TILES]);
void print_tiles(int tiles[N_TILES]);
int count_farnarkles(int sequence1[N_TILES], int sequence2[N_TILES]);
int count_arkles(int sequence1[N_TILES], int sequence2[N_TILES]);
void create_random_tiles(int tiles[N_TILES]);

// for challenge
#define MAX_TURNS 100

void farnarkle_player(int turn, int previous_guesses[MAX_TURNS][N_TILES], int farnarkles[MAX_TURNS], int arkles[MAX_TURNS], int guess[MAX_TILE]);
