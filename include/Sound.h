#ifndef SOUND_H
#define SOUND_H
#include "Component.h"
#define INCLUDE_SDL_MIXER
#include "Resources.h"
#include "SDL_include.h"

class Sound : public Component {
  public:
    explicit Sound(GameObject& associated)
        : Component(associated), chunk(nullptr), played(false) {}
    Sound(GameObject& associated, const std::string& file, bool play = false)
        : Component(associated), chunk(nullptr), played(false) {
        Open(file);
        if (play) Play();
    }

    ~Sound() { Stop(); }

    void Open(const std::string& file) { chunk = Resources::GetSound(file); }
    bool IsOpen() const { return (bool)chunk; }
    bool CanEnd() const { return played && !Mix_Playing(channel); }
    void Play(int times = 1);
    void Stop() const {
        if (chunk) Mix_HaltChannel(channel);
    }

    void Update(float dt) {}
    void Render() const {}
    bool Is(const std::string& type) const { return !type.compare("Sound"); }

  private:
    std::shared_ptr<Mix_Chunk> chunk;
    int channel = 0;
    mutable bool played;
};

#endif  // SOUND_H
