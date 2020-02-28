/***random0: generate the random integer***/

static unsigned long next = 1;
unsigned int random(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int) (next/65536) % 32768;
}

void setSeed(unsigned int seed)
{
    next = seed;
}