MEMORY {
  sfr              : ORIGIN = 0x0000, LENGTH = 0x0010 /* END=0x0010, size 16 */
  peripheral_8bit  : ORIGIN = 0x0010, LENGTH = 0x00f0 /* END=0x0100, size 240 */
  peripheral_16bit : ORIGIN = 0x0100, LENGTH = 0x0100 /* END=0x0200, size 256 */
  ram (wx)         : ORIGIN = 0x0200, LENGTH = 0x0400 /* END=0x0600, size 1K */
  infomem          : ORIGIN = 0x1000, LENGTH = 0x0100 /* END=0x1100, size 256 */
  infod            : ORIGIN = 0x1000, LENGTH = 0x0040 /* END=0x1040, size 64 */
  infoc            : ORIGIN = 0x1040, LENGTH = 0x0040 /* END=0x1080, size 64 */
  infob            : ORIGIN = 0x1080, LENGTH = 0x0040 /* END=0x10c0, size 64 */
  infoa            : ORIGIN = 0x10c0, LENGTH = 0x0040 /* END=0x1100, size 64 */
  rom (rx)         : ORIGIN = 0x8000, LENGTH = 0x7fe0 /* END=0xffe0, size 32736 */
  vectors          : ORIGIN = 0xffe0, LENGTH = 0x0020 /* END=0x10000, size 32 */
  /* Remaining banks are absent */
  bsl              : ORIGIN = 0x0000, LENGTH = 0x0000
  far_rom          : ORIGIN = 0x00000000, LENGTH = 0x00000000
}
REGION_ALIAS("REGION_TEXT", rom);
REGION_ALIAS("REGION_DATA", ram);
REGION_ALIAS("REGION_FAR_ROM", far_rom);
