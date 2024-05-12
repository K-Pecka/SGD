#include "Message.h"
#include <Windows.h>

std::string Message::getErrorMessage(ErrorType type) {
    switch (type) {
        case ErrorType::INIT:
            return errorMessage.init;
        case ErrorType::CREATE:
            return errorMessage.create;
        case ErrorType::RENDER:
            return errorMessage.render;
        case ErrorType::SET:
            return errorMessage.set;
        default:
            return errorMessage.undefined;
    }
}

[[maybe_unused]] void Message::showMessageBox(const ErrorType errorType, ErrorMessageType type) {

    std::string color_message;
    switch(type) {
        case ErrorMessageType::MERROR:
            MessageBox(nullptr, getErrorMessage(errorType).c_str(), "ERROR", MB_OK | MB_ICONERROR);
            break;
        case ErrorMessageType::MWARNING:
            MessageBox(nullptr, getErrorMessage(errorType).c_str(), "WARNING", MB_OK | MB_ICONWARNING);
            break;
    }
}