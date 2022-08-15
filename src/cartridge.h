#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include "debug.h"
#include "types.h"
#include <fstream>
#include <iostream>

class Cartridge {
	//Location title
	enum Location_Map {
		Begin_Code = 0x0100,
		End_Code = 0x0103,
		Begin_Graphic = 0x0104,
		End_Graphic = 0x0133, 
		Begin_Title = 0x0134,
		End_Title = 0x0142,
		Color_GB = 0x0143,
		Ascii_hex_digit_high = 0x0144,
		Ascii_hex_digit_low = 0x0145,
		GB_SGB_Indicator = 0x0146,
		Type_cartridge = 0x0147,
		ROM_size = 0x0148,
		RAM_size = 0x0149,
		Destination_code = 0x014A,
		Licensee_code = 0x014B,
		Mask_ROM = 0x014C,
		Complement_check = 0x014D,
		Begin_Checksum = 0x013E,
		End_Checksum = 0x014f
	};

	enum GBORSGB {
		GB = 0x00,
		SGB = 0x03
	};
	enum Rom_Size {
		Rom32KByte = 0x00, 
		Rom64KByte = 0x01,
		Rom128KByte = 0x02,
		Rom256KByte = 0x03,
		Rom512KByte = 0x04,
		Rom1MByte = 0x05,
		Rom2MByte = 0x06,
		Rom1_1MByte = 0x52,
		Rom1_2MByte = 0x053,
		Rom1_5MByte = 0x54,
	};

	enum Ram_Size {
		RamNone = 0x00,
		Ram2kB = 0x01,
		Ram8kB = 0x02,
		Ram32kB = 0x03,
		Ram128kB =0x04
	};

	enum Cartridge_type {
		ROM_ONLY = 0x00,
		ROM_MBC1 = 0x01,
		ROM_MBC1_RAM = 0x02,
		ROM_MBC1_RAM_BATT = 0x03,
		ROM_MBC2 = 0x05,
		ROM_MBC2_BATTERY = 0x06,
		ROM_RAM = 0x08,
		ROM_RAM_BATTERY = 0x09,
		ROM_MMM01 = 0x0B,
		ROM_MMM01_SRAM = 0x0C, 
		ROM_MMM01_SRAM_BATT_FE_Hudson_HuC_3 = 0x0D,
		ROM_MBC3_TIMER_BATT = 0x0F,
		ROM_MBC3_TIMER_RAM_BATT = 0x10,
		ROM_MBC3 = 0x11,
		ROM_MBC3_RAM = 0x12, 
		ROM_MBC3_RAM_BATT = 0x13,
		ROM_MBC5 = 0x19,
		ROM_MBC5_RAM = 0x1A,
		ROM_MBC5_RAM_BATT = 0x1B,
		ROM_MBC5_RUMBLE = 0x1C,
		ROM_MBC5_RUMBLE_SRAM = 0x1D,
		ROM_MBC5_RUMBLE_SRAM_BATT = 0x1E,
		Pocket_Camera = 0x1F,
		Bandai_TAMA5 = 0xFD,        
		Hudson_HuC_1 = 0xFF,
	};
	void PrintTitle();
	void PrintGBorSGBIndicator();
	void PrintCartridgeType();
	void PrintCartridgeLang();
	void PrintCartridgeSizeRom();
	void PrintCartridgeSizeRam();
	friend class Debug;

public:
	u8 *ROM;

	Cartridge();
	~Cartridge();
	void Load(std::string filename);
	void Unload(std::string filename);
	void ShowCartridgeHeader();
};

#endif
