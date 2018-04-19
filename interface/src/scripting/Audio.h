//
//  Audio.h
//  interface/src/scripting
//
//  Created by Zach Pomerantz on 28/5/2017.
//  Copyright 2017 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#ifndef hifi_scripting_Audio_h
#define hifi_scripting_Audio_h

#include "AudioScriptingInterface.h"
#include "AudioDevices.h"
#include "AudioEffectOptions.h"
#include "SettingHandle.h"
#include "AudioFileWav.h"

namespace scripting {

class Audio : public AudioScriptingInterface {
    Q_OBJECT
    SINGLETON_DEPENDENCY

    /**jsdoc
    * The Audio API features tools to help control audio contexts and settings.
    *
    * @namespace Audio
    * @property {bool} muted - To Be Completed
    * @property {bool} noiseReduction - To Be Completed
    * @property {bool} inputVolume - To Be Completed
    * @property {bool} inputLevel - To Be Completed
    * @property {QString} context - To Be Completed
    * @property {} devices - To Be Completed
    */
 
    Q_PROPERTY(bool muted READ isMuted WRITE setMuted NOTIFY mutedChanged)
    Q_PROPERTY(bool noiseReduction READ noiseReductionEnabled WRITE enableNoiseReduction NOTIFY noiseReductionChanged)
    Q_PROPERTY(float inputVolume READ getInputVolume WRITE setInputVolume NOTIFY inputVolumeChanged)
    Q_PROPERTY(float inputLevel READ getInputLevel NOTIFY inputLevelChanged)
    Q_PROPERTY(QString context READ getContext NOTIFY contextChanged)
    Q_PROPERTY(AudioDevices* devices READ getDevices NOTIFY nop)

public:
    static QString AUDIO;
    static QString HMD;
    static QString DESKTOP;

    static float loudnessToLevel(float loudness);

    virtual ~Audio() {}

    bool isMuted() const { return _isMuted; }
    bool noiseReductionEnabled() const { return _enableNoiseReduction; }
    float getInputVolume() const { return _inputVolume; }
    float getInputLevel() const { return _inputLevel; }
    QString getContext() const;

    void setMuted(bool muted);
    void enableNoiseReduction(bool enable);
    void showMicMeter(bool show);
    void setInputVolume(float volume);

    /**jsdoc
    * The Audio API features tools to help control audio contexts and settings.
    *
    * @namespace Audio
    * @property {bool} muted - To Be Completed
    * @property {bool} noiseReduction - To Be Completed
    * @property {bool} inputVolume - To Be Completed
    * @property {bool} inputLevel - To Be Completed
    * @property {QString} context - To Be Completed
    * @property {} devices - To Be Completed
    */

    /**jsdoc
    * To Be Completed
    * @function Audio.setInputDevice
    * @param {} device
    * @param {bool} isHMD 
    */
    Q_INVOKABLE void setInputDevice(const QAudioDeviceInfo& device, bool isHMD);
    /**jsdoc
    * To Be Completed
    * @function Audio.setOutputDevice
    * @param {} device
    * @param {bool} isHMD
    */
    Q_INVOKABLE void setOutputDevice(const QAudioDeviceInfo& device, bool isHMD);
    /**jsdoc
    * To Be Completed
    * @function Audio.setReverb
    * @param {bool} enable
    */
    Q_INVOKABLE void setReverb(bool enable);
    /**jsdoc
    * To Be Completed
    * @function Audio.setReverbOptions
    * @param {} options
    */
    Q_INVOKABLE void setReverbOptions(const AudioEffectOptions* options);
    /**jsdoc
    * To Be Completed
    * @function Audio.setReverbOptions
    * @param {} options
    */
    Q_INVOKABLE bool startRecording(const QString& filename);
    Q_INVOKABLE void stopRecording();
    Q_INVOKABLE bool getRecording();

signals:
    void nop();
    void mutedChanged(bool isMuted);
    void noiseReductionChanged(bool isEnabled);
    void inputVolumeChanged(float volume);
    void inputLevelChanged(float level);
    void contextChanged(const QString& context);

public slots:
    void onContextChanged();

private slots:
    void onMutedChanged();
    void onNoiseReductionChanged();
    void onInputVolumeChanged(float volume);
    void onInputLoudnessChanged(float loudness);

protected:
    // Audio must live on a separate thread from AudioClient to avoid deadlocks
    Audio();

private:

    float _inputVolume { 1.0f };
    float _inputLevel { 0.0f };
    bool _isMuted { false };
    bool _enableNoiseReduction { true };  // Match default value of AudioClient::_isNoiseGateEnabled.
    bool _contextIsHMD { false };
    AudioDevices* getDevices() { return &_devices; }
    AudioDevices _devices;
};

};

#endif // hifi_scripting_Audio_h
