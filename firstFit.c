#include <stdio.h>

// Function to perform First Fit memory allocation
void FirstFit(int blocks[], int m, int files[], int n)
{
      int allocation[n];  // Array to store block allocation information for each file
      int transferred[n]; // Array to store the amount of file transferred to each block

      // Initialize allocation and transferred arrays to -1 (indicating not allocated yet)
      for (int i = 0; i < n; i++)
      {
            allocation[i] = -1;
            transferred[i] = -1;
      }

      // Iterate through each file
      for (int i = 0; i < n; i++)
      {
            // Try to find a block that can accommodate the file
            for (int j = 0; j < m; j++)
            {
                  if (blocks[j] >= files[i])
                  {
                        // Allocate the file to the block
                        allocation[i] = j;
                        transferred[i] = files[i];
                        blocks[j] -= files[i];
                        break;
                  }
            }
      }

      // Display the allocation results
      printf("\nFile Allocation using First-Fit:");
      printf("File Number\tFile Size\tBlock Number\tTransferred File Size\n");
      for (int i = 0; i < n; i++)
      {
            printf("%d\t\t%d\t\t", i + 1, files[i]);
            if (allocation[i] != -1)
            {
                  printf("%d\t\t%d\n", allocation[i] + 1, transferred[i]);
            }
            else
            {
                  printf("Not Allocated\t-\n");
            }
      }
}

int main()
{
      int m, n;

      // Prompt for the number of memory blocks and files
      printf("<First Fit Algorithm>\n\n");

      printf("- Memory Block No.\n");
      printf(" > Enter the number of memory blocks: ");
      scanf("%d", &m);

      printf("- File No.\n");
      printf(" > Enter the number of files: ");
      scanf("%d", &n);

      int blocks[m], files[n];

      // Prompt for the sizes of memory blocks
      printf("\n- Memory Block Size\n");
      printf(" > Enter the sizes of memory blocks:\n");
      for (int i = 0; i < m; i++)
      {
            printf("\t-> Block %d: ", i + 1);
            scanf("%d", &blocks[i]);
      }

      // Prompt for the sizes of files
      printf("\n- File Size\n");
      printf(" > Enter the sizes of files:\n");
      for (int i = 0; i < n; i++)
      {
            printf("\t-> File %d: ", i + 1);
            scanf("%d", &files[i]);
      }

      // Call the FirstFit function to perform memory allocation
      FirstFit(blocks, m, files, n);

      return 0;
}