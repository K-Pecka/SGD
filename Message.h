#ifndef SDL_GAME_MESSAGE_H
#define SDL_GAME_MESSAGE_H

#include <string>

struct ErrorMessage {
    std::string init = "Failed to initialize SDL!";
    std::string create = "Failed to create window!";
    std::string render = "Failed to create renderer!";
    std::string set = "No specific parameters!";
    std::string undefined = "Undefined error!";
};

enum class ErrorType {INIT,CREATE,RENDER,SET};
enum class ErrorMessageType {MERROR,MWARNING};
class Message {
    public:
         Message() = default;
        [[nodiscard]]  std::string getErrorMessage(ErrorType type) ;
        [[maybe_unused]]  void showMessageBox(ErrorType errorType, ErrorMessageType type);
        ErrorMessage errorMessage;
    private:


};

#endif //SDL_GAME_MESSAGE_H
