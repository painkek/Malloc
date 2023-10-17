#include <stdio.h>

void BestFit(int blocks[], int memoryBlock, int files[], int fileNum)
{
      int allocation[fileNum];
      int transferred[fileNum];

      for (int i = 0; i < fileNum; i++)
      {
            allocation[i] = -1;
            transferred[i] = -1;
      }

      printf("\nFile Allocation using Best-Fit:");
      printf("\nFile No.\tFile Size\tBlock No.\tBlock Size\tTransferred File\tRemaining\n");

      for (int i = 0; i < fileNum; i++)
      {
            int bestBlock = -1;
            for (int j = 0; j < memoryBlock; j++)
            {
                  if (blocks[j] >= files[i])
                  {
                        if (bestBlock == -1)
                        {
                              bestBlock = j;
                        }
                        else if (blocks[bestBlock] > blocks[j])
                        {
                              bestBlock = j;
                        }
                  }
            }

            if (bestBlock != -1)
            {
                  allocation[i] = bestBlock;
                  transferred[i] = files[i];
                  blocks[bestBlock] -= files[i]; // update the block size or it substract the memory block size from the given file size
                  printf("%d \t\t %d \t\t ", i + 1, files[i]);

                  if (allocation[i] != -1)
                  {
                        printf("%d \t\t %d \t\t %d \t\t\t %d", allocation[i] + 1, files[i] + blocks[bestBlock], transferred[i], blocks[allocation[i]]);
                  }
            }
            else
            {
                  printf("%d \t\t %d \t\t ", i + 1, files[i]);
                  printf("Not Allocated \t -- \t\t -- \t\t\t --");
            }
            printf("\n");
      }
}

int main()
{
      printf("\n<Best Fit Algorithm>\n\n");

      // Memory Blocks and Files number input
      int memoryBlock, fileNum;

      printf("- Memory Block No.\n");
      printf(" > Enter the number of Memory Blocks: ");
      scanf("%d", &memoryBlock);

      printf("\n- File No.\n");
      printf(" > Enter the number of File Size: ");
      scanf("%d", &fileNum);

      // declare array for mBlocks and files sizes
      int blocks[memoryBlock], files[fileNum];

      // input memory block sizes
      printf("\n- Memory Block Size\n");
      printf(" > Enter the sizes of Memory Blocks:\n");
      for (int i = 0; i < memoryBlock; i++)
      {
            printf("\t> Block %d: ", i + 1);
            scanf("%d", &blocks[i]);
      }

      // input file sizes
      printf("\n- File Size\n");
      printf(" > Enter the sizes of Files:\n");
      for (int i = 0; i < fileNum; i++)
      {
            printf("\t> File %d: ", i + 1);
            scanf("%d", &files[i]);
      }

      BestFit(blocks, memoryBlock, files, fileNum);

      return 0;
}
