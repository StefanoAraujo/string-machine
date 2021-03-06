#pragma once
#include "StringMachineShared.hpp"
#include "StringSynth.h"
#include "dsp/AmpFollower.h"
#include <array>

class StringMachinePlugin : public Plugin {
public:
    StringMachinePlugin();
    ~StringMachinePlugin();

    const char *getLabel() const override;
    const char *getMaker() const override;
    const char *getLicense() const override;
    const char *getDescription() const override;
    const char *getHomePage() const override;
    uint32_t getVersion() const override;
    int64_t getUniqueId() const override;

    void initParameter(uint32_t index, Parameter &parameter) override;
    float getParameterValue(uint32_t index) const override;
    void setParameterValue(uint32_t index, float value) override;

    void initProgramName(uint32_t index, String &programName) override;
    void loadProgram(uint32_t index) override;

    void activate() override;
    void deactivate() override;

    void run(const float **inputs, float **outputs, uint32_t frames,
             const MidiEvent *midiEvents, uint32_t midiEventCount) override;

private:
    StringSynth fSynth;
    AmpFollower fOutputLevelFollower[2];
    std::array<float, Parameter_Count> fParameterDefaults;
};
