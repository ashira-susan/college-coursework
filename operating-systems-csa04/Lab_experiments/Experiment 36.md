## 36. Linked File Allocation

### Problem Statement

Write a C program to simulate **linked file allocation**. Each file block should contain data and a pointer to the next block. The program should allow the user to write blocks, read a particular block, and display the stored data.

### Program

```c id="m3q8vx"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Block
{
    char data[256];
    struct Block *next;
};

int main()
{
    struct Block *firstBlock = NULL;
    struct Block *lastBlock = NULL;
    struct Block *newBlock;
    struct Block *currentBlock;

    int blockCount = 0;
    int blockNumber;
    char data[256];
    char choice;

    printf("Linked Allocation Simulation\n");

    while (1)
    {
        printf("\nEnter W to write, R to read, or Q to quit: ");
        scanf(" %c", &choice);

        if (choice == 'Q' || choice == 'q')
        {
            break;
        }

        /* Write a block */
        if (choice == 'W' || choice == 'w')
        {
            printf("Enter data for the block: ");
            scanf(" %255[^\n]", data);

            newBlock = (struct Block *)malloc(sizeof(struct Block));

            if (newBlock == NULL)
            {
                printf("Memory allocation failed.\n");
                return 1;
            }

            strcpy(newBlock->data, data);
            newBlock->next = NULL;

            if (firstBlock == NULL)
            {
                firstBlock = newBlock;
                lastBlock = newBlock;
            }
            else
            {
                lastBlock->next = newBlock;
                lastBlock = newBlock;
            }

            blockCount++;

            printf("Block %d written successfully.\n", blockCount);
        }

        /* Read a block */
        else if (choice == 'R' || choice == 'r')
        {
            if (blockCount == 0)
            {
                printf("No blocks available.\n");
                continue;
            }

            printf("Enter block number to read (1-%d): ",
                   blockCount);
            scanf("%d", &blockNumber);

            if (blockNumber < 1 || blockNumber > blockCount)
            {
                printf("Invalid block number.\n");
            }
            else
            {
                currentBlock = firstBlock;

                for (int i = 1; i < blockNumber; i++)
                {
                    currentBlock = currentBlock->next;
                }

                printf("Block %d Data: %s\n",
                       blockNumber,
                       currentBlock->data);
            }
        }

        else
        {
            printf("Invalid choice.\n");
        }
    }

    /* Free allocated memory */
    currentBlock = firstBlock;

    while (currentBlock != NULL)
    {
        struct Block *nextBlock = currentBlock->next;
        free(currentBlock);
        currentBlock = nextBlock;
    }

    printf("\nProgram terminated.\n");

    return 0;
}
```

### Sample Output

```text id="z9c4mw"
Linked Allocation Simulation

Enter W to write, R to read, or Q to quit: W
Enter data for the block: First Block
Block 1 written successfully.

Enter W to write, R to read, or Q to quit: W
Enter data for the block: Second Block
Block 2 written successfully.

Enter W to write, R to read, or Q to quit: W
Enter data for the block: Third Block
Block 3 written successfully.

Enter W to write, R to read, or Q to quit: R
Enter block number to read (1-3): 2
Block 2 Data: Second Block

Enter W to write, R to read, or Q to quit: R
Enter block number to read (1-3): 3
Block 3 Data: Third Block

Enter W to write, R to read, or Q to quit: Q

Program terminated.
```

### Key Concepts

* **Linked Allocation** → File blocks are connected using pointers.
* `struct Block` → Represents one file block.
* `data[]` → Stores the contents of the block.
* `next` → Points to the next block.
* `malloc()` → Dynamically allocates memory for a new block.
* `free()` → Releases dynamically allocated memory.
* `firstBlock` → Points to the first block.
* `lastBlock` → Points to the last block.
* `currentBlock` → Used to traverse the linked blocks.

### How Linked Allocation Works

The blocks are connected like a linked list:

```text id="v2k6rq"
First Block
    ↓
┌───────────────┐
│ First Block   │
│ next ─────────┼──────┐
└───────────────┘      ↓
                 ┌───────────────┐
                 │ Second Block  │
                 │ next ─────────┼──────┐
                 └───────────────┘      ↓
                                  ┌───────────────┐
                                  │ Third Block   │
                                  │ next → NULL   │
                                  └───────────────┘
```

### Writing a Block

When the user chooses `W`:

```text id="c8m4ny"
Create new block
      ↓
Store data
      ↓
next = NULL
      ↓
Attach to last block
      ↓
Increase block count
```

### Reading a Block

If the user requests Block 3:

```text id="a5p7kd"
First Block
    ↓
Second Block
    ↓
Third Block
    ↓
Display data
```

The program follows the `next` pointer until it reaches the requested block.

### Linked vs Indexed Allocation

| Linked Allocation                | Indexed Allocation                |
| -------------------------------- | --------------------------------- |
| Uses pointers between blocks     | Uses an index table               |
| Blocks form a linked list        | Index stores block locations      |
| Sequential traversal is required | Index provides direct lookup      |
| No separate index table needed   | Requires additional index storage |

**Main concept:** In linked allocation, each file block contains a pointer to the **next block**, allowing the blocks to be stored at different locations.
