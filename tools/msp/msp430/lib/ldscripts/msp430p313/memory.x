MEMORY {
  sfr              : ORIGIN = 0x0000, LENGTH = 0x0010 /* END=0x0010, size 16 */
  peripheral_8bit  : ORIGIN = 0x0010, LENGTH = 0x00f0 /* END=0x0100, size 240 */
  peripheral_16bit : ORIGIN = 0x0100, LENGTH = 0x0100 /* END=0x0200, size 256 */
  ram (wx)         : ORIGIN = 0x0200, LENGTH = 0x0100 /* END=0x0300, size 256 */
  rom (rx)         : ORIGIN = 0xe000, LENGTH = 0x1fe0 /* END=0xffe0, size 8160 */
  vectors          : ORIGIN = 0xffe0, LENGTH = 0x0020 /* END=0x10000, size 32 */
  /* Remaining banks are absent */
  bsl              : ORIGIN = 0x0000, LENGTH = 0x0000
  infomem          : ORIGIN = 0x0000, LENGTH = 0x0000
  infoa            : ORIGIN = 0x0000, LENGTH = 0x0000
  infob            : ORIGIN = 0x0000, LENGTH = 0x0000
  infoc            : ORIGIN = 0x0000, LENGTH = 0x0000
  infod            : ORIGIN = 0x0000, LENGTH = 0x0000
  far_rom          : ORIGIN = 0x00000000, LENGTH = 0x00000000
}
REGION_ALIAS("REGION_TEXT", rom);
REGION_ALIAS("REGION_DATA", ram);
REGION_ALIAS("REGION_FAR_ROM", far_rom);
