MEMORY {
  sfr              : ORIGIN = 0x0000, LENGTH = 0x0010 /* END=0x0010, size 16 */
  peripheral_8bit  : ORIGIN = 0x0010, LENGTH = 0x00f0 /* END=0x0100, size 240 */
  peripheral_16bit : ORIGIN = 0x0100, LENGTH = 0x0100 /* END=0x0200, size 256 */
  bsl              : ORIGIN = 0x1000, LENGTH = 0x0200 /* END=0x1200, size 512 */
  infomem          : ORIGIN = 0x1800, LENGTH = 0x0100 /* END=0x1900, size 256 */
  infob            : ORIGIN = 0x1800, LENGTH = 0x0080 /* END=0x1880, size 128 */
  infoa            : ORIGIN = 0x1880, LENGTH = 0x0080 /* END=0x1900, size 128 */
  ram (wx)         : ORIGIN = 0x1c00, LENGTH = 0x0400 /* END=0x2000, size 1K */
  rom (rx)         : ORIGIN = 0xc200, LENGTH = 0x3d80 /* END=0xff80, size 15744 */
  vectors          : ORIGIN = 0xff80, LENGTH = 0x0080 /* END=0x10000, size 128 */
  /* Remaining banks are absent */
  infoc            : ORIGIN = 0x0000, LENGTH = 0x0000
  infod            : ORIGIN = 0x0000, LENGTH = 0x0000
  far_rom          : ORIGIN = 0x00000000, LENGTH = 0x00000000
}
REGION_ALIAS("REGION_TEXT", rom);
REGION_ALIAS("REGION_DATA", ram);
REGION_ALIAS("REGION_FAR_ROM", far_rom);
