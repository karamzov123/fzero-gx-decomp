typedef unsigned short u16;
void AIStartDMA(void) {
    volatile unsigned short* r = (volatile unsigned short*)0xCC005036;
    *r |= 0x8000;
}
void AIStopDMA(void) {
    volatile unsigned short* r = (volatile unsigned short*)0xCC005036;
    *r &= ~0x8000;
}
