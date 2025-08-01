#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

// Let's give those bytes a name
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Make sure there's exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }

    // Try opening the memory card
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    FILE *img = NULL;
    int file_count = 0;
    char filename[8];
    int found_jpeg = 0;

    // Read 512 bytes at a time
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // Check for JPEG signature (first 4 bytes)
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If a JPEG was already being written, close it
            if (found_jpeg)
            {
                fclose(img);
            }
            else
            {
                found_jpeg = 1; // We just found our first JPEG
            }

            // Create new JPEG file
            sprintf(filename, "%03i.jpg", file_count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create image file.\n");
                fclose(raw_file);
                return 1;
            }
            file_count++;
        }

        // If we're writing a JPEG, write the current block
        if (found_jpeg)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
        }
    }

    // Clean up
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(raw_file);

    return 0;
}
