// Frank Wang
// Apr 2017
// Adapted from lab 7 header file

int read_pbm(char filename[], int height, int width, int pixels[height][width]);
int get_pbm_dimensions(char filename[], int *height, int *width);
void print_image(int height, int width, int pixels[height][width]);
void get_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width);
void copy_pixels(int height, int width, int pixels[height][width],
                 int start_row, int start_column, int copy_height, int copy_width,
                 int copy[copy_height][copy_width]);
double get_horizontal_balance(int height, int width, int pixels[height][width]);

double get_vertical_balance(int height, int width, int pixels[height][width]);

int condition(int height, int width, int config[height][width]);

int holes(int height, int width, int config[height][width]);

int threes(int height, int width, int config[height][width]);

int oneSev(int height, int width, int config[height][width], int noHole);

int noHoles(int height, int width, int config[height][width]);

int tfive(int height, int width, int config[height][width]);
