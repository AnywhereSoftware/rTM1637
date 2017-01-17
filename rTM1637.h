#pragma once
#include "B4RDefines.h"
#include "TM1637Display.h"
//~version: 1.10
namespace B4R {
	//~shortname: TM1637Display
	class B4RTM1637Display {
		private:
			uint8_t beTM1637Display[sizeof(TM1637Display)];
			TM1637Display* display;
		public:
			//Initializes the object.
			//PinClk - Pin connected to the clock pin.
			//PinDIO - Pin connected to the DIO pin.
			void Initialize(Byte PinClk, Byte PinDIO);
			/**
			*Displays arbitrary data.
			*Each byte represents a single digit.
			*Each bit represents a segment.
			*Position - Position from which to start the modification (0 - leftmost, 3 - rightmost).
			*/
			void SetSegments(ArrayByte* Segments, Byte Position);
			//Displays the decimal number.
			void ShowNumberDec(Int Number);
			/**
			*Displays the decimal number.
			*Number - Number to be shown.
			*LeadingZero - Whether to add leading zeroes.
			*Length - Number of digits to set.
			*Position - Position of the least significant digit (0 - leftmost, 3 - rightmost).
			*/
			void ShowNumberDec2(Int Number, bool LeadingZero, Byte Length, Byte Position);
			/**
			*Similar to ShowNumberDec2. Controls the decimal dots or colon based on the DotsMask. Pass 0xFF to enable all dots / colons.
			*The argument is a bitmask, with each bit corresponding to a dot
			*between the digits (or colon mark, as implemented by each module). The MSB is the 
			*leftmost dot of the digit being update. For example, if Position is 1, the MSB of DotsMask
			*will correspond the dot near digit no. 2 from the left. Dots are updated only on
			*those digits actually being update (that is, no more than Length digits)
			*/
			void ShowNumberDec3(Int Number, bool LeadingZero, Byte Length, Byte Position, Byte DotsMask);
	};
}