
//#include "bit_math.h" // Include the bit_math header file

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(R,B) 			(R=R|(1<<B))
#define CLR_BIT(R,B) 			(R&=~(1<<B))
#define TGL_BIT(R,B) 			(R^=(1<<B))
#define GET_BIT(R,B) 			((R>>B)&0x01)

#define SET_HIGH_NIB(R)			(R|=0xF0)
#define CLR_HIGH_NIB(R)			(R&=0x0F))
#define GET_HIGH_NIB(R)			((R >> 4) & 0x0F)
#define TGL_HIGH_NIB(R)			(R ^= 0xF0)

#define SET_LOW_NIB(R)     		(R|=0x0F)
#define CLR_LOW_NIB(R)  		(R&=0xF0)
#define GET_LOW_NIB(R)  		(R & 0x0F)
#define TGL_LOW_NIB(R) 			(R ^= 0x0F)

#define ASSIGN_REG(R, VAL)      ((R&0x00)| VAR)
#define ASSIGN_HIGH_NIB(R, VAR) ((R&=0x0F)|(VAR<<4))
#define ASSIGN_LOW_NIB(R, VAR)  ((R&=0xF0)|VAR)

#define RSHFT_REG(R, VAR)  		(R>>=VAR)
#define LSHFT_REG(R, VAR)  		(R<<=VAR)
#define CRSHFT_REG(R, VAR) 		(R >> VAR%8) | (R << (8 - VAR%8))
#define CLSHFT_REG(R, VAR) 		(R << VAR%8) | (R >> (8 - VAR%8))



#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)  CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0



#endif /* BitMath_H_*/

/*
int main() {
    // Test Bit Manipulation Macros
    unsigned char reg = 0x00; // Initial value of the register

    // Test SET_BIT
    SET_BIT(reg, 3);
    printf("After SET_BIT: 0x%02X  // Expected reg = 0x08\n", reg);

    // Test CLR_BIT
    CLR_BIT(reg, 3);
    printf("After CLR_BIT: 0x%02X  // Expected reg = 0x00\n", reg);

    // Test TGL_BIT
    TGL_BIT(reg, 2);
    printf("After TGL_BIT: 0x%02X  // Expected reg = 0x04\n", reg);

    // Test GET_BIT
    unsigned char bitValue = GET_BIT(reg, 4);
    printf("GET_BIT at position 4: %u  // Expected 0\n", bitValue);

    // Test Nibble Manipulation Macros
    reg = 0xAB; // Initial value of the register

    // Test SET_HIGH_NIB
    SET_HIGH_NIB(reg);
    printf("After SET_HIGH_NIB: 0x%02X  // Expected reg = 0xFB\n", reg);

    // Test CLR_HIGH_NIB
    CLR_HIGH_NIB(reg);
    printf("After CLR_HIGH_NIB: 0x%02X  // Expected reg = 0x0B\n", reg);

    // Test GET_HIGH_NIB
    unsigned char highNibbleValue = GET_HIGH_NIB(reg);
    printf("GET_HIGH_NIB: 0x%02X  // Expected 0x00\n", highNibbleValue);

    // Test TGL_HIGH_NIB
    TGL_HIGH_NIB(reg);
    printf("After TGL_HIGH_NIB: 0x%02X  // Expected reg = 0xFB\n", reg);

    // Test SET_LOW_NIB
    SET_LOW_NIB(reg);
    printf("After SET_LOW_NIB: 0x%02X  // Expected reg = 0xFF\n", reg);

    // Test CLR_LOW_NIB
    CLR_LOW_NIB(reg);
    printf("After CLR_LOW_NIB: 0x%02X  // Expected reg = 0xF0\n", reg);

    // Test GET_LOW_NIB
    unsigned char lowNibbleValue = GET_LOW_NIB(reg);
    printf("GET_LOW_NIB: 0x%02X  // Expected 0x00\n", lowNibbleValue);

    printf("Current REG: 0x%02X\n", reg);
    // Test TGL_LOW_NIB
    TGL_LOW_NIB(reg);
    printf("After TGL_LOW_NIB: 0x%02X  // Expected reg = 0xFF\n", reg);

    // Test General Register Manipulation Macros
    reg = 0x00; // Reset the register

    // Test ASSIGN_REG
    ASSIGN_REG(reg, 0x0F);
    printf("After ASSIGN_REG: 0x%02X  // Expected reg = 0x0F\n", reg);

    // Test ASSIGN_HIGH_NIB
    ASSIGN_HIGH_NIB(reg, 0x5);
    printf("After ASSIGN_HIGH_NIB: 0x%02X  // Expected reg = 0x5F\n", reg);

    // Test ASSIGN_LOW_NIB
    ASSIGN_LOW_NIB(reg, 0x3);
    printf("After ASSIGN_LOW_NIB: 0x%02X  // Expected reg = 0x53\n", reg);

    // Test RSHFT_REG
    RSHFT_REG(reg, 2);
    printf("After RSHFT_REG: 0x%02X  // Expected reg = 0x14\n", reg);

    // Test LSHFT_REG
    LSHFT_REG(reg, 3);
    printf("After LSHFT_REG: 0x%02X  // Expected reg = 0xA0\n", reg);

    // Test CRSHFT_REG
    CRSHFT_REG(reg, 2);
    printf("After CRSHFT_REG: 0x%02X  // Expected reg = 0x28\n", reg);

    // Test CLSHFT_REG
    CLSHFT_REG(reg, 3);
    printf("After CLSHFT_REG: 0x%02X  // Expected reg = 0x41\n", reg);

    return 0;
}
*/