#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include "image.h"

enum AnimationType { Loop, GoBack };

class Animation : public Image
{
    public:
        Animation();
        void Create(string path, int frames, double fps, AnimationType type);

        void PlayNextFrame();
        void Reset();
        bool IsFinished();

    private:
        double fps;
        int frames, current_frame, middle_frame;
        int time_for_frame, last_time_updated;
        int frame_width;
        bool is_finished;
        AnimationType type;

        void ClipCurrentFrame();
};

#endif // ANIMATION_H_INCLUDED
