#include "error_manager.h"

const SDL_MessageBoxButtonData Error::buttons[1] = { { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "OK" } };

void Error::New(Error::Type type, std::string message)
{
    if( type == Error::Type::SDL )
    {
        message += "\n  -" + (std::string)SDL_GetError();
    }

    else if( type == Error::Type::IMG )
    {
        message += "\n  -" + (std::string)IMG_GetError();
    }

    else if( type == Error::Type::TTF )
    {
        message += "\n  -" + (std::string)TTF_GetError();
    }

    const SDL_MessageBoxData message_box_data =
    {
        SDL_MESSAGEBOX_ERROR,
        NULL,
        "Error",
        message.c_str(),
        SDL_arraysize(buttons),
        buttons,
        NULL
    };

    SDL_ShowMessageBox(&message_box_data, NULL);
}
