#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


// Define aliases
typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    // Check command line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover <file>.\n");
        return 1;
    }
    
    
    // Open input file
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    

    // Create buffer
    BYTE buffer[512];
    
    // Set flags
    int firstJPEGfound = 0;
    int counter = 0;
    
    // Init output file
    FILE *outfile;
    
    while (fread(buffer, 512, 1, infile))
    {
        // Check if start of JPEG
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && (buffer[3] >= 0xe0) && (buffer[3] <= 0xef))
        {
            
            // Set firstJPEGfound flag to 1 if haven't already
            if (firstJPEGfound == 0)
            {
                firstJPEGfound = 1;
            }
            else
            {
                // Close file if new JPEG
                fclose(outfile);
            }
            
            if (firstJPEGfound == 1)
            {
                // Generate filename
                char filename[8];
                sprintf(filename, "%03i.jpg", counter++);
                
                // Open new file
                outfile = fopen(filename, "w");
                if (outfile == NULL)
                {
                    printf("Could not open file.\n");
                    return 1;
                }
                
                // Write to file
                fwrite(buffer, 512, 1, outfile);
            }
        }
        else if (firstJPEGfound == 1)
        {
            // Continue writing to file
            fwrite(buffer, 512, 1, outfile);
        }
    }
    

}