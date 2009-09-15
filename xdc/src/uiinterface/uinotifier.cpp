#include "uiinterface/uinotifier.h"

UiNotifier::UiNotifier() {}

UiNotifier* UiNotifier::getInstance() {
	static UiNotifier theInstance;
	return &theInstance;
}
