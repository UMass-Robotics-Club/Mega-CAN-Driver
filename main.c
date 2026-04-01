/**
 * @file main.c
 * @author omp
 * @date 2026-03-21
 * @brief Main function
 */

#include <xc.h>
#include <stdint.h>

void delay(volatile uint32_t count)
{
    while (count--)
    {
        __asm__ volatile ("nop");
    }
}

int main(){
    // Add your code here and press Ctrl + Shift + B to build
    
    //blimk scritp
    WDTCONCLR = _WDTCON_ON_MASK;
    
    // Set RB0 as output
    TRISBCLR = (1 << 0);

    // Initialize LOW
    LATBCLR = (1 << 0);

    while (1)
    {
        // Toggle RB0
        LATBINV = (1 << 0);

        // Delay
        delay(500000);
    }

    return 0;
}
