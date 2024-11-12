#include<stdio.h>
#include<stdlib.h>
int main()
{
    int[] array={29,18,43,10,36,25,46};
    tableSize=sizeof(array);
    int [tableSize] newTable;
    for (int i;i<tableSize,i++)
    {
        for (int j;j<tableSize,j++)
        {
            insert_position=array[i]%tableSize;
            if (i==newTable[insert_position])
                {
                    insert_position+=1;
                }
            newTable[insert_position]=i;
        }
    }
    for (int i;i<tableSize,i++)
    {
        printf("%d",newTable[insert_position]);
    }
}
