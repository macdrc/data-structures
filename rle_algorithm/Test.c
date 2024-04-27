#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void compressRLE(char *input, FILE *outputFile) {
    int inputLength = strlen(input);
    fprintf(outputFile, "%c", input[0]); //printing the initial digit 
    for (int i = 0; i < inputLength; i++) {
       
        int count = 1;

        while (i < inputLength - 1 && input[i] == input[i + 1]) {
            count++; //increment count of either 1 or 0
            i++;
        }

        
        if (count >= 1) {
            fprintf(outputFile, "|%d",count); //print the |count
        } 
    }

    fprintf(outputFile, "\n"); //new line
}

void decompressRLE(char *input, FILE *outputFile) {
    int inputLen = strlen(input);
    int oneOrZero = input[0] - '0';  //make note of the initial character

    for (int i = 1; i < inputLen; i++) {
        char character = input[i];

       
        if (isdigit(input[i + 1])) {
            int count = 0;

           
            while (isdigit(input[i + 1])) {
                count = count * 10 + (input[i + 1] - '0');
                i++;
            }

            for (int j = 0; j < count; j++) {
                fprintf(outputFile, "%d", oneOrZero);
            }
        } else if (input[i + 1] == '|') {
            // used to handle cases like "0|10" or "1|151"
            i += 2; // skip past '|'
            int count = 0;

           //read the digit past |
            while (isdigit(input[i])) {
                count = count * 10 + (input[i] - '0');
                i++;
            }
            //print the thing
            for (int j = 0; j < count; j++) {
                fprintf(outputFile, "%d", oneOrZero);
            }

            // Move past '|'
            while (input[i] != '|') {
                i++;
            }
        } else {
           //write newline
            if (character == '\n') {
                fprintf(outputFile, "\n");
            }
          
             else {
                //write character
                fprintf(outputFile, "%c", character);
            }
        }

        //make sure to alternate between 1 and 0
        oneOrZero = 1 - oneOrZero;
    }
}



int main() {
    
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *compressedFile = fopen("compressed.txt", "w");
    if (compressedFile == NULL) {
        perror("Error opening compressed file");
        fclose(inputFile);
        return 1;
    }

    char *inputLine = NULL;
    size_t len = 0;

    // Read each line from the input file
    while (getline(&inputLine, &len, inputFile) != -1) {
        // Remove newline character at the end
        inputLine[strcspn(inputLine, "\n")] = '\0';

        // Compress the line and write to the compressed file
        compressRLE(inputLine, compressedFile);
    }

    // Free dynamically allocated memory
    free(inputLine);

    // Close the input file and compressed file
    fclose(inputFile);
    fclose(compressedFile);

    // Open compressed text file for reading
    FILE *compressedInputFile = fopen("compressed.txt", "r");
    if (compressedInputFile == NULL) {
        perror("Error opening compressed input file");
        return 1;
    }

    // Open decompressed text file for writing
    FILE *decompressedFile = fopen("decompressed.txt", "w");
    if (decompressedFile == NULL) {
        perror("Error opening decompressed file");
        fclose(compressedInputFile);
        return 1;
    }

    char *compressedLine = NULL;

    // Read each line from the compressed file
    while (getline(&compressedLine, &len, compressedInputFile) != -1) {
        // Remove newline character at the end
        compressedLine[strcspn(compressedLine, "\n")] = '\0';

        // Decompress the line and write to the decompressed file
        decompressRLE(compressedLine, decompressedFile);

        // Add newline character after each decompressed line
        fprintf(decompressedFile, "\n");
    }

    // Free dynamically allocated memory
    free(compressedLine);

    // Close the compressed input file and decompressed file
    fclose(compressedInputFile);
    fclose(decompressedFile);

    return 0;
}