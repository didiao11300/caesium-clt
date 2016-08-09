#ifndef CCLT_UTILS
#define CCLT_UTILS

#include <jpeglib.h>
#include <turbojpeg.h>
#include <sys/types.h>
#include <stdbool.h>

#define APP_VERSION "0.9.1"
#define BUILD 20160808

typedef struct cclt_jpeg_parameters {
	int quality;
	int width;
	int height;
	int color_space;
	int dct_method;
	bool exif_copy;
	bool lossless;
	enum TJSAMP subsample;
} cclt_jpeg_parameters;

typedef struct cclt_png_parameters {
	int iterations;
	int iterations_large;
	int block_split_strategy;
	bool lossy_8;
	bool transparent;
	int auto_filter_strategy;
} cclt_png_parameters;

typedef struct cclt_parameters {
	cclt_jpeg_parameters jpeg;
	cclt_png_parameters png;

	char* output_folder;
	char** input_files;
	int input_files_count;
	bool recursive;
	bool structure;
} cclt_parameters;

enum image_type {
	JPEG,
	PNG,
	UNKN,
};

int string_to_int(char* in_string);
void print_help();
int mkpath(const char *pathname, mode_t mode);
enum image_type detect_image_type(char* path);
int is_directory(const char *file_path);
void scan_folder(cclt_parameters* parameters, char* basedir, int recur);
char* get_human_size(long size);

#endif
