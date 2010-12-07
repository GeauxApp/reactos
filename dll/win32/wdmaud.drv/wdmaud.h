#ifndef WDMAUD_H__
#define WDMAUD_H__

#include <windows.h>
#include <ntddsnd.h>
#include <sndtypes.h>
#include <setupapi.h>
#include <mmddk.h>
#include <mmebuddy.h>

#include <ks.h>
#include <ksmedia.h>
#include "mmixer.h"
#include <debug.h>

BOOL
WdmAudInitUserModeMixer();

ULONG
WdmAudGetWaveOutCount();

ULONG
WdmAudGetWaveInCount();

ULONG
WdmAudGetMixerCount();

MMRESULT
WdmAudOpenSoundDeviceByLegacy();

MMRESULT
WdmAudGetNumWdmDevsByMMixer(
    IN  MMDEVICE_TYPE DeviceType,
    OUT DWORD* DeviceCount);

MMRESULT
WdmAudCommitWaveBufferByLegacy(
    IN  PSOUND_DEVICE_INSTANCE SoundDeviceInstance,
    IN  PVOID OffsetPtr,
    IN  DWORD Length,
    IN  PSOUND_OVERLAPPED Overlap,
    IN  LPOVERLAPPED_COMPLETION_ROUTINE CompletionRoutine);

MMRESULT
WriteFileEx_Remixer(
    IN  PSOUND_DEVICE_INSTANCE SoundDeviceInstance,
    IN  PVOID OffsetPtr,
    IN  DWORD Length,
    IN  PSOUND_OVERLAPPED Overlap,
    IN  LPOVERLAPPED_COMPLETION_ROUTINE CompletionRoutine);

MMRESULT
WdmAudGetCapabilitiesByMMixer(
    IN  PSOUND_DEVICE SoundDevice,
    IN  DWORD DeviceId,
    OUT PVOID Capabilities,
    IN  DWORD CapabilitiesSize);

MMRESULT
WdmAudOpenSoundDeviceByMMixer();

MMRESULT
WdmAudCloseSoundDeviceByMMixer(
    IN  struct _SOUND_DEVICE_INSTANCE* SoundDeviceInstance,
    IN  PVOID Handle);

MMRESULT
WdmAudGetLineInfo(
    IN HANDLE hMixer,
    IN DWORD MixerId,
    IN LPMIXERLINEW MixLine,
    IN ULONG Flags);

MMRESULT
WdmAudGetLineControls(
    IN HANDLE hMixer,
    IN DWORD MixerId,
    IN LPMIXERLINECONTROLSW MixControls,
    IN ULONG Flags);

MMRESULT
WdmAudSetControlDetails(
    IN HANDLE hMixer,
    IN DWORD MixerId,
    IN LPMIXERCONTROLDETAILS MixDetails,
    IN ULONG Flags);

MMRESULT
WdmAudGetControlDetails(
    IN HANDLE hMixer,
    IN DWORD MixerId,
    IN LPMIXERCONTROLDETAILS MixDetails,
    IN ULONG Flags);

MMRESULT
WdmAudSetWaveDeviceFormatByMMixer(
    IN  PSOUND_DEVICE_INSTANCE Instance,
    IN  DWORD DeviceId,
    IN  PWAVEFORMATEX WaveFormat,
    IN  DWORD WaveFormatSize);

MMRESULT
WdmAudGetDeviceInterfaceStringByMMixer(
    IN  MMDEVICE_TYPE DeviceType,
    IN  DWORD DeviceId,
    IN  LPWSTR Interface,
    IN  DWORD  InterfaceLength,
    OUT  DWORD * InterfaceSize);

MMRESULT
WdmAudSetMixerDeviceFormatByMMixer(
    IN  PSOUND_DEVICE_INSTANCE Instance,
    IN  DWORD DeviceId,
    IN  PWAVEFORMATEX WaveFormat,
    IN  DWORD WaveFormatSize);

MMRESULT
WdmAudQueryMixerInfoByMMixer(
    IN  struct _SOUND_DEVICE_INSTANCE* SoundDeviceInstance,
    IN DWORD MixerId,
    IN UINT uMsg,
    IN LPVOID Parameter,
    IN DWORD Flags);

MMRESULT
WdmAudSetWaveStateByMMixer(
    IN  struct _SOUND_DEVICE_INSTANCE* SoundDeviceInstance,
    IN BOOL bStart);

MMRESULT
WdmAudResetStreamByMMixer(
    IN  struct _SOUND_DEVICE_INSTANCE* SoundDeviceInstance,
    IN  MMDEVICE_TYPE DeviceType,
    IN  BOOLEAN bStartReset);

MMRESULT
WdmAudGetWavePositionByMMixer(
    IN  struct _SOUND_DEVICE_INSTANCE* SoundDeviceInstance,
    IN  MMTIME* Time);

MMRESULT
WdmAudCommitWaveBufferByMMixer(
    IN  PSOUND_DEVICE_INSTANCE SoundDeviceInstance,
    IN  PVOID OffsetPtr,
    IN  DWORD Length,
    IN  PSOUND_OVERLAPPED Overlap,
    IN  LPOVERLAPPED_COMPLETION_ROUTINE CompletionRoutine);

MMRESULT
WdmAudCleanupByMMixer();

#endif
