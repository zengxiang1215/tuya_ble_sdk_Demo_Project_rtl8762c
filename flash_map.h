/**
*****************************************************************************************
*     Copyright(c) 2017, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file    flash_map.h
  * @brief   Flash Layout Configuration, and flash layout must be changed with config file!
  * @note    flash_map.h must be generated by FlashMapGenerateTool!
   * *************************************************************************************
  */

#ifndef _FLASH_MAP_H_
#define _FLASH_MAP_H_

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Sample Flash Layout (Not support bank switch)
 *============================================================================*/
/* Flash total size                                256K
example:
   1) Reaerved:                                      4K (0x800000)
   2) OEM Header:                                    4K
   3) OTA Bank0:                                   140K (0x802000)
      a) OTA Header               4K (0x803000)
      b) Secure boot loader       4K (0x80D000)
         Notes: Secure boot loader image start address must configured at 0x80D000 and size can't less than 4KB!
      c) Patch code              40K (0x803000)
      d) APP code                92K (0x80E000)
      e) APP data1                0K (0x825000)
      f) APP data2                0K (0x825000)
   4) OTA Bank1:                                     0K (0x825000)
      a) OTA Header               0K
      b) Secure boot loader       0K
      c) Patch code               0K
      d) APP code                 0K
      e) APP data1                0K
      f) APP data2                0K
   5) FTL:                                          16K (0x825000)
   6) OTA Tmp:                                      92K (0x829000)
   7) APP Defined Section:                           0K
*/


/*============================================================================*
*                        Sample Flash Layout (Support bank switch)
*============================================================================*/
/*  Flash total size                                1MB
example:
   1) Reaerved:                                      4K (0x800000)
   2) OEM Header:                                    4K (0x801000)
   3) OTA Bank0:                                   252K (0x802000)
      a) OTA Header                 4K (0x802000)
      b) Secure boot loader         0K (0x803000)
      c) Patch code                40K (0x803000)
      d) APP code                 208K (0x80D000)
      e) APP data1                  0K (0x841000)
      f) APP data2                  0K (0x841000)
   4) OTA Bank1:                                   252K (0x841000)
      Notes: OTA Bank1 size must be same as OTA Bank0!
      a) OTA Header                 4K (0x841000)
      b) Secure boot loader         0K (0x842000)
      c) Patch code                40K (0x842000)
      d) APP code                 208K (0x84C000)
      e) APP data1                  0K (0x880000)
      f) APP data2                  0K (0x880000)
   5) FTL:                                          16K (0x880000)
   6) OTA Tmp:                                       0K (0x884000)
   7) APP Defined Section:                         200K (0x884000)
Notes: OTA Bank1 end address offset is aligned 512KB, so all code space is protected by flash BP.
*/

/*============================================================================*
 *            Flash Layout Configuration (Generated by FlashMapGenerateTool)
 *============================================================================*/

#define FLASH_ADDR                      0x00800000  //Fixed
#define FLASH_SIZE                      0x00040000  //256K Bytes

/* ========== High Level Flash Layout Configuration ========== */
#define RESERVED_ADDR                   0x00800000
#define RESERVED_SIZE                   0x00001000  //4K Bytes
#define OEM_CFG_ADDR                    0x00801000
#define OEM_CFG_SIZE                    0x00001000  //4K Bytes
#define OTA_BANK0_ADDR                  0x00802000
#define OTA_BANK0_SIZE                  0x00023000  //140K Bytes
#define OTA_BANK1_ADDR                  0x00825000
#define OTA_BANK1_SIZE                  0x00000000  //0K Bytes
#define FTL_ADDR                        0x00825000
#define FTL_SIZE                        0x00004000  //16K Bytes
#define OTA_TMP_ADDR                    0x00829000
#define OTA_TMP_SIZE                    0x00017000  //92K Bytes
#define BKP_DATA1_ADDR                  0x00000000
#define BKP_DATA1_SIZE                  0x00000000  //0K Bytes
#define BKP_DATA2_ADDR                  0x00000000
#define BKP_DATA2_SIZE                  0x00000000  //0K Bytes

/* ========== OTA Bank0 Flash Layout Configuration ========== */
#define BANK0_OTA_HEADER_ADDR           0x00802000
#define BANK0_OTA_HEADER_SIZE           0x00001000  //4K Bytes
#define BANK0_SECURE_BOOT_ADDR          0x0080D000
#define BANK0_SECURE_BOOT_SIZE          0x00001000  //4K Bytes
#define BANK0_ROM_PATCH_ADDR            0x00803000
#define BANK0_ROM_PATCH_SIZE            0x0000A000  //40K Bytes
#define BANK0_APP_ADDR                  0x0080E000
#define BANK0_APP_SIZE                  0x00017000  //92K Bytes
#define BANK0_APP_DATA1_ADDR            0x00825000
#define BANK0_APP_DATA1_SIZE            0x00000000  //0K Bytes
#define BANK0_APP_DATA2_ADDR            0x00825000
#define BANK0_APP_DATA2_SIZE            0x00000000  //0K Bytes

/* ========== OTA Bank1 Flash Layout Configuration ========== */
#define BANK1_OTA_HEADER_ADDR           0x00000000
#define BANK1_OTA_HEADER_SIZE           0x00000000  //0K Bytes
#define BANK1_SECURE_BOOT_ADDR          0x00000000
#define BANK1_SECURE_BOOT_SIZE          0x00000000  //0K Bytes
#define BANK1_ROM_PATCH_ADDR            0x00000000
#define BANK1_ROM_PATCH_SIZE            0x00000000  //0K Bytes
#define BANK1_APP_ADDR                  0x00000000
#define BANK1_APP_SIZE                  0x00000000  //0K Bytes
#define BANK1_APP_DATA1_ADDR            0x00000000
#define BANK1_APP_DATA1_SIZE            0x00000000  //0K Bytes
#define BANK1_APP_DATA2_ADDR            0x00000000
#define BANK1_APP_DATA2_SIZE            0x00000000  //0K Bytes



#ifdef __cplusplus
}
#endif


/** @} */ /* _FLASH_MAP_H_ */
#endif
