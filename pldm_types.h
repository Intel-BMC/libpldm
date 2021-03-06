#ifndef PLDM_TYPES_H
#define PLDM_TYPES_H

#include <stdint.h>

/** @brief PLDM Types
 */
enum pldm_supported_types {
	PLDM_BASE = 0x00,
	PLDM_SMBIOS = 0x01,
	PLDM_PLATFORM = 0x02,
	PLDM_BIOS = 0x03,
	PLDM_FRU = 0x04,
	PLDM_FWUP = 0x05,
	PLDM_RDE = 0x06,
	PLDM_OEM = 0x3F,
};

typedef union {
	uint8_t byte;
	struct {
		uint8_t bit0 : 1;
		uint8_t bit1 : 1;
		uint8_t bit2 : 1;
		uint8_t bit3 : 1;
		uint8_t bit4 : 1;
		uint8_t bit5 : 1;
		uint8_t bit6 : 1;
		uint8_t bit7 : 1;
	} __attribute__((packed)) bits;
} bitfield8_t;

/** @struct pldm_version
 *
 *
 */
typedef struct pldm_version {
	uint8_t major;
	uint8_t minor;
	uint8_t update;
	uint8_t alpha;
} __attribute__((packed)) ver32_t;

typedef uint8_t bool8_t;

typedef union {
	uint16_t value;
	struct {
		uint8_t bit0 : 1;
		uint8_t bit1 : 1;
		uint8_t bit2 : 1;
		uint8_t bit3 : 1;
		uint8_t bit4 : 1;
		uint8_t bit5 : 1;
		uint8_t bit6 : 1;
		uint8_t bit7 : 1;
		uint8_t bit8 : 1;
		uint8_t bit9 : 1;
		uint8_t bit10 : 1;
		uint8_t bit11 : 1;
		uint8_t bit12 : 1;
		uint8_t bit13 : 1;
		uint8_t bit14 : 1;
		uint8_t bit15 : 1;
	} __attribute__((packed)) bits;
} bitfield16_t;

typedef union {
	uint32_t value;
	struct {
		uint8_t bit0 : 1;
		uint8_t bit1 : 1;
		uint8_t bit2 : 1;
		uint8_t bit3 : 1;
		uint8_t bit4 : 1;
		uint8_t bit5 : 1;
		uint8_t bit6 : 1;
		uint8_t bit7 : 1;
		uint8_t bit8 : 1;
		uint8_t bit9 : 1;
		uint8_t bit10 : 1;
		uint8_t bit11 : 1;
		uint8_t bit12 : 1;
		uint8_t bit13 : 1;
		uint8_t bit14 : 1;
		uint8_t bit15 : 1;
		uint8_t bit16 : 1;
		uint8_t bit17 : 1;
		uint8_t bit18 : 1;
		uint8_t bit19 : 1;
		uint8_t bit20 : 1;
		uint8_t bit21 : 1;
		uint8_t bit22 : 1;
		uint8_t bit23 : 1;
		uint8_t bit24 : 1;
		uint8_t bit25 : 1;
		uint8_t bit26 : 1;
		uint8_t bit27 : 1;
		uint8_t bit28 : 1;
		uint8_t bit29 : 1;
		uint8_t bit30 : 1;
		uint8_t bit31 : 1;
	} __attribute__((packed)) bits;
} bitfield32_t;

typedef union {
	uint64_t value;
	struct {
		uint8_t bit0 : 1;
		uint8_t bit1 : 1;
		uint8_t bit2 : 1;
		uint8_t bit3 : 1;
		uint8_t bit4 : 1;
		uint8_t bit5 : 1;
		uint8_t bit6 : 1;
		uint8_t bit7 : 1;
		uint8_t bit8 : 1;
		uint8_t bit9 : 1;
		uint8_t bit10 : 1;
		uint8_t bit11 : 1;
		uint8_t bit12 : 1;
		uint8_t bit13 : 1;
		uint8_t bit14 : 1;
		uint8_t bit15 : 1;
		uint8_t bit16 : 1;
		uint8_t bit17 : 1;
		uint8_t bit18 : 1;
		uint8_t bit19 : 1;
		uint8_t bit20 : 1;
		uint8_t bit21 : 1;
		uint8_t bit22 : 1;
		uint8_t bit23 : 1;
		uint8_t bit24 : 1;
		uint8_t bit25 : 1;
		uint8_t bit26 : 1;
		uint8_t bit27 : 1;
		uint8_t bit28 : 1;
		uint8_t bit29 : 1;
		uint8_t bit30 : 1;
		uint8_t bit31 : 1;
		uint8_t bit32 : 1;
		uint8_t bit33 : 1;
		uint8_t bit34 : 1;
		uint8_t bit35 : 1;
		uint8_t bit36 : 1;
		uint8_t bit37 : 1;
		uint8_t bit38 : 1;
		uint8_t bit39 : 1;
		uint8_t bit40 : 1;
		uint8_t bit41 : 1;
		uint8_t bit42 : 1;
		uint8_t bit43 : 1;
		uint8_t bit44 : 1;
		uint8_t bit45 : 1;
		uint8_t bit46 : 1;
		uint8_t bit47 : 1;
		uint8_t bit48 : 1;
		uint8_t bit49 : 1;
		uint8_t bit50 : 1;
		uint8_t bit51 : 1;
		uint8_t bit52 : 1;
		uint8_t bit53 : 1;
		uint8_t bit54 : 1;
		uint8_t bit55 : 1;
		uint8_t bit56 : 1;
		uint8_t bit57 : 1;
		uint8_t bit58 : 1;
		uint8_t bit59 : 1;
		uint8_t bit60 : 1;
		uint8_t bit61 : 1;
		uint8_t bit62 : 1;
		uint8_t bit63 : 1;
	} __attribute__((packed)) bits;
} bitfield64_t;

typedef float real32_t;

typedef struct {
#if defined(__LITTLE_ENDIAN_BITFIELD)
	uint8_t utc_resolution : 4;  /* bit 7:4 UTC & time resolution */
	uint8_t time_resolution : 4; /* bit 3:0 UTC & time resolution */
#else
	uint8_t time_resolution : 4; /* bit 3:0 UTC & time resolution */
	uint8_t utc_resolution : 4;  /* bit 7:4 UTC & time resolution */
#endif
	uint16_t year;		   /* year without any offset */
	uint8_t month;		   /* 1..12 */
	uint8_t day;		   /* 1..31 */
	uint8_t hour;		   /* 0..23 */
	uint8_t minute;		   /* 0..59 */
	uint8_t second;		   /* 0..59 */
	uint32_t microsecond : 24; /* 24 bit value starting from 0*/
	int16_t utc_offset;	   /* offset in minutes signed int16 */
} __attribute__((packed)) timestamp104_t;

#endif /* PLDM_TYPES_H */
