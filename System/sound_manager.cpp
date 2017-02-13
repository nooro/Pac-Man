#include "sound_manager.h"

Mix_Chunk *SoundManager::get_coin = NULL;

bool SoundManager::Init()
{
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) < 0)
    {
        Error::New(Error::Type::MIX, "Can not open the audio driver");
        return false;
    }

    SoundManager::get_coin = Mix_LoadWAV(SOUND_GET_COIN);
    if(SoundManager::get_coin == NULL)
    {
        Error::New(Error::Type::MIX, "Can not load the \"Get coin\" sound");
        return false;
    }

    Mix_VolumeChunk(SoundManager::get_coin, MIX_MAX_VOLUME / 50);

    return true;
}

void SoundManager::Play(SoundManager::Sounds sound)
{
    if( sound == SoundManager::Sounds::GetCoin )
    {
        if(!Mix_Playing(MIX_DEFAULT_CHANNELS))
        {
            Mix_PlayChannel(MIX_DEFAULT_CHANNELS, SoundManager::get_coin, NO_LOOP);
        }
    }
}

void SoundManager::Free()
{
    Mix_FreeChunk(SoundManager::get_coin);
    Mix_CloseAudio();
}

