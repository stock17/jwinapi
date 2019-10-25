package com.mymos.jwinapi;

public class Jwinapi {

    static {
        System.loadLibrary("jwinapi");
    }

    public static native void setVolumeLevel (double level);
    public static native double getVolumeLevel ();
    public static native void sleepMode();

    public static native void onSpaceKeyPressed();
    public static native void onLeftKeyPressed();
    public static native void onRightKeyPressed();
}
