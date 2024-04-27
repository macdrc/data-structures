#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "FreeImage.h"

// Function to perform RLE compression
void rle_compress(uint8_t* input_data, int width, int height, uint8_t* compressed_data) {
    int count = 1;
    uint8_t pixel = *input_data;

    for (int i = 1; i < width * height; i++) {
        if (input_data[i] == pixel && count < 255) {
            count++;
        } else {
            *compressed_data++ = count;
            *compressed_data++ = pixel;
            count = 1;
            pixel = input_data[i];
        }
    }

    *compressed_data++ = count;
    *compressed_data++ = pixel;
}

int main() {
    const char* input_filename = "heart.bmp";
    const char* output_filename = "compressed_heart.bmp";
    const int input_width = 84;
    const int input_height = 84;
    const int output_width = 32;
    const int output_height = 32;

    FreeImage_Initialise(0);

    // Load the input image
    FIBITMAP* input_image = FreeImage_Load(FIF_BMP, input_filename, BMP_DEFAULT);

    if (!input_image) {
        printf("Error: Unable to load input image.\n");
        FreeImage_DeInitialise();
        return 1;
    }

    // Verify the input image dimensions
    int img_width = FreeImage_GetWidth(input_image);
    int img_height = FreeImage_GetHeight(input_image);

    if (img_width != input_width || img_height != input_height) {
        printf("Error: Input image must be 84x84 pixels.\n");
        FreeImage_Unload(input_image);
        FreeImage_DeInitialise();
        return 1;
    }

    // Resize the image to 32x32 pixels (nearest-neighbor scaling)
    FIBITMAP* output_image = FreeImage_Rescale(input_image, output_width, output_height, FILTER_BOX);

    // Create a grayscale 8-bit image
    FIBITMAP* grayscale_image = FreeImage_ConvertToGreyscale(output_image);

    // Get the image data
    BYTE* input_data = FreeImage_GetBits(grayscale_image);

    // Allocate memory for compressed data
    size_t compressed_size = output_width * output_height * 2;  // Max size for worst case
    uint8_t* compressed_data = (uint8_t*)malloc(compressed_size);

    if (!compressed_data) {
        printf("Error: Memory allocation failed.\n");
        FreeImage_Unload(input_image);
        FreeImage_Unload(output_image);
        FreeImage_Unload(grayscale_image);
        FreeImage_DeInitialise();
        return 1;
    }

    // Perform RLE compression
    rle_compress(input_data, output_width, output_height, compressed_data);

    // Save the compressed image
    FIBITMAP* compressed_bmp = FreeImage_ConvertFromRawBits(compressed_data, output_width, output_height, output_width, 8, 0xFF, 0xFF, 0xFF, 1);
    FreeImage_Save(FIF_BMP, compressed_bmp, output_filename, BMP_DEFAULT);

    // Free resources
    free(compressed_data);
    FreeImage_Unload(input_image);
    FreeImage_Unload(output_image);
    FreeImage_Unload(grayscale_image);
    FreeImage_Unload(compressed_bmp);
    FreeImage_DeInitialise();

    printf("Compression complete. Compressed image saved as 'compressed_heart.bmp'.\n");

    return 0;
}
