package com.mymos.jwinapi;

import junit.framework.TestCase;

public class JwinapiTest extends TestCase {

    public void testSetVolumeLevel() {
        Jwinapi.setVolumeLevel(0.5);
        double d = Jwinapi.getVolumeLevel();
        assert d == 0.5;

        Jwinapi.setVolumeLevel(0.7);
        d = Jwinapi.getVolumeLevel();
        assert d != 0.5;
    }

    public void testGetVolumeLevel() {
        Jwinapi.setVolumeLevel(0.5);
        double d = Jwinapi.getVolumeLevel();
        assert d == 0.5;

        Jwinapi.setVolumeLevel(0.7);
        d = Jwinapi.getVolumeLevel();
        assert d != 0.5;
    }

    public void testOnSpaceKeyPressed(){
        for (int i = 0; i < 20; i++) {
            Jwinapi.onSpaceKeyPressed();
        }
    }

    public void testOnRightKeyPressed(){
        for (int i = 0; i < 20; i++) {
            Jwinapi.onRightKeyPressed();
        }
    }

    public void testOnLeftKeyPressed(){
        for (int i = 0; i < 15; i++) {
            Jwinapi.onLeftKeyPressed();
        }
    }

    public void testSleepMode(){
//        Jwinapi.sleepMode();
    }

    public static void main(String[] args) {
        new JwinapiTest().testSetVolumeLevel();
        new JwinapiTest().testGetVolumeLevel();
         new JwinapiTest().testSleepMode();
        new JwinapiTest().testOnSpaceKeyPressed();
        new JwinapiTest().testOnRightKeyPressed();
        new JwinapiTest().testOnLeftKeyPressed();
    }
}