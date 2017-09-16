#include "Border.h"

Border::Border(Country s, Country e) {
	start = s;
	end = e;
}

Country Border::getStart() {
	return start;
}

Country Border::getEnd() {
	return end;
}
