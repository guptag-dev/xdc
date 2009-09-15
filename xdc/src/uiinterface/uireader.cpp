#include "uiinterface/uireader.h"

UiReader::UiReader() {}

UiReader* UiReader::getInstance() {
	static UiReader theInstance;
	return &theInstance;
}
