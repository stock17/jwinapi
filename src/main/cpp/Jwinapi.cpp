#include "pch.h"
#include <stdio.h>      
#include "Jwinapi.h"
#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <PowrProf.h>

#pragma comment(lib, "PowrProf.lib")
#define DLLExport __declspec(dllexport)

extern "C"
{
	enum class VolumeUnit {
		Decibel,
		Scalar
	};

	//Get volume
	DLLExport float GetSystemVolume(VolumeUnit vUnit) {
		HRESULT hr;

		// -------------------------
		CoInitialize(NULL);
		IMMDeviceEnumerator *deviceEnumerator = NULL;
		hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
		IMMDevice *defaultDevice = NULL;

		hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
		deviceEnumerator->Release();
		deviceEnumerator = NULL;

		IAudioEndpointVolume *endpointVolume = NULL;
		hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
		defaultDevice->Release();
		defaultDevice = NULL;

		float currentVolume = 0;
		if (vUnit == VolumeUnit::Decibel) {
			//Current volume in dB
			hr = endpointVolume->GetMasterVolumeLevel(&currentVolume);
		}

		else if (vUnit == VolumeUnit::Scalar) {
			//Current volume as a scalar
			hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
		}
		endpointVolume->Release();
		CoUninitialize();

		return currentVolume;
	}

	//Sets volume
	DLLExport void SetSystemVolume(double newVolume, VolumeUnit vUnit) {
		HRESULT hr;

		// -------------------------
		CoInitialize(NULL);
		IMMDeviceEnumerator *deviceEnumerator = NULL;
		hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
		IMMDevice *defaultDevice = NULL;

		hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
		deviceEnumerator->Release();
		deviceEnumerator = NULL;

		IAudioEndpointVolume *endpointVolume = NULL;
		hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
		defaultDevice->Release();
		defaultDevice = NULL;

		if (vUnit == VolumeUnit::Decibel)
			hr = endpointVolume->SetMasterVolumeLevel((float)newVolume, NULL);

		else    if (vUnit == VolumeUnit::Scalar)
			hr = endpointVolume->SetMasterVolumeLevelScalar((float)newVolume, NULL);

		endpointVolume->Release();

		CoUninitialize();
	}

	DLLExport void SimulateKeyPressed(WORD key) {
		INPUT input;
		WORD vkey = key;
		input.type = INPUT_KEYBOARD;
		input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
		input.ki.time = 0;
		input.ki.dwExtraInfo = 0;
		input.ki.wVk = vkey;
		input.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
		SendInput(1, &input, sizeof(INPUT));
	}

	// Implementation of the native methods 
	/*
	* Class:     com_yurima_jwinapi_Jwinapi
	* Method:    setVolumeLevel
	* Signature: (D)V
	*/
	JNIEXPORT void JNICALL Java_com_yurima_jwinapi_Jwinapi_setVolumeLevel(JNIEnv * env, jclass clazz, jdouble level)
	{
		SetSystemVolume(level, VolumeUnit::Scalar);
	}

	/*
	* Class:     com_yurima_jwinapi_Jwinapi
	* Method:    getVolumeLevel
	* Signature: ()D
	*/
	JNIEXPORT jdouble JNICALL Java_com_yurima_jwinapi_Jwinapi_getVolumeLevel(JNIEnv * env, jclass clazz)
	{
		return GetSystemVolume(VolumeUnit::Scalar);
	}

	/*
	* Class:     com_yurima_jwinapi_Jwinapi
	* Method:    pressKey
	* Signature: (I)V
	*/
	JNIEXPORT void JNICALL Java_com_yurima_jwinapi_Jwinapi_pressKey(JNIEnv * env, jclass clazz, jint keycode)
	{
		if (keycode >= 0x01 && keycode <=0xFE) 
		{
			SimulateKeyPressed(keycode);	
		}		
	}

	/*
	* Class:     com_yurima_jwinapi_Jwinapi
	* Method:    sleepMode
	* Signature: ()V
	*/
	JNIEXPORT void JNICALL Java_com_yurima_jwinapi_Jwinapi_sleepMode(JNIEnv * env, jclass clazz)
	{
		SetSuspendState(false, false, false);
	}
}