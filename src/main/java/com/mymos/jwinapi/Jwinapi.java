package com.mymos.jwinapi;

public class Jwinapi {

    static {
        System.loadLibrary("jwinapi");
    }

    /**
     * The method sets the volume level of the default audio device
     *
     * @param level is the volume level from 0 to 1
     */
    public static native void setVolumeLevel (double level);

    /**
     * The method return the volume level of the default audio device
     *
     * @return the value from 0 to 1 (100%)
     */
    public static native double getVolumeLevel ();

    /**
     * The method simulates pressing of the key
     * by its <a href="https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes">virtual code</a>
     *
     * @param keycode is a virtual code of the key
     */
    public static native void pressKey(int keycode);

    /**
     * The method activates PC sleep mode
     */
    public static native void sleepMode();
}
