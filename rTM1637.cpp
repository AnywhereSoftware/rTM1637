
#include "B4RDefines.h"
namespace B4R {
	
	void B4RTM1637Display::Initialize(Byte PinClk, Byte PinDIO) {
		display = new (beTM1637Display) TM1637Display(PinClk, PinDIO);
		display->setBrightness(0x0f);
	}
	void B4RTM1637Display::SetSegments(ArrayByte* Segments, Byte Position) {
		display->setSegments((Byte*)Segments->data, Segments->length, Position);
	}
	void B4RTM1637Display::ShowNumberDec(Int Number) {
		ShowNumberDec2(Number, false, 4, 0);
	}
	void B4RTM1637Display::ShowNumberDec2(Int Number, bool LeadingZero, Byte Length, Byte Position) {
		display->showNumberDec(Number, LeadingZero, Length, Position);
	}
	void B4RTM1637Display::ShowNumberDec3(Int Number, bool LeadingZero, Byte Length, Byte Position, Byte DotsMask) {
		display->showNumberDecEx(Number, DotsMask, LeadingZero, Length, Position);
	}
}

