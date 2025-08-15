#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "KDP_Interface.h"
#include "KDP_Config.h"
#include <util/delay.h>

static u8 KPD_u8Keys[4][4] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

static u8 KPD_u8Rows[4] = {KPD_Row1PIN, KPD_Row2PIN, KPD_Row3PIN, KPD_Row4PIN};
static u8 KPD_u8Cols[4] = {KPD_Col1PIN, KPD_Col2PIN, KPD_Col3PIN, KPD_Col4PIN};

void KPD_voidInit(void)
{
    for (u8 i = 0; i < 4; i++) {
        DIO_voidSetPinDirection(KPD_RowsPort, KPD_u8Rows[i], DIO_u8_INPUT);
        DIO_voidSetPinValue(KPD_RowsPort, KPD_u8Rows[i], DIO_u8_HIGH);
    }

    for (u8 i = 0; i < 4; i++) {
        DIO_voidSetPinDirection(KPD_ColsPort, KPD_u8Cols[i], DIO_u8_OUTPUT);
        DIO_voidSetPinValue(KPD_ColsPort, KPD_u8Cols[i], DIO_u8_HIGH);
    }
}

u8 KPD_u8GetPressedKey(void)
{
    u8 row, col, value;

    for (col = 0; col < 4; col++) {
        for (u8 i = 0; i < 4; i++) {
            DIO_voidSetPinValue(KPD_ColsPort, KPD_u8Cols[i], DIO_u8_HIGH);
        }

        DIO_voidSetPinValue(KPD_ColsPort, KPD_u8Cols[col], DIO_u8_LOW);

        for (row = 0; row < 4; row++) {
        	value = DIO_u8GetPinValue(KPD_RowsPort, KPD_u8Rows[row]);            if (value == DIO_u8_LOW) {
                _delay_ms(20);
                while (1) {
                	value = DIO_u8GetPinValue(KPD_RowsPort, KPD_u8Rows[row]);                    if (value == DIO_u8_HIGH) break;
                }
                return KPD_u8Keys[row][col];
            }
        }
    }

    return 0xFF;
}
