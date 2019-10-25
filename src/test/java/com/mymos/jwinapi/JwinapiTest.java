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

    public void testPressSpaceKey(){
        for (int i = 0; i < 20; i++) {
            Jwinapi.pressSpaceKey();
        }
    }

    public void testPressRightKey(){
        for (int i = 0; i < 20; i++) {
            Jwinapi.pressRightKey();
        }
    }

    public void testPressLeftKey(){
        for (int i = 0; i < 15; i++) {
            Jwinapi.pressLeftKey();
        }
    }

    public void testSleepMode(){
//        Jwinapi.sleepMode();
    }

    public static void main(String[] args) {
        new JwinapiTest().testSetVolumeLevel();
        new JwinapiTest().testGetVolumeLevel();
        new JwinapiTest().testSleepMode();
        new JwinapiTest().testPressSpaceKey();
        new JwinapiTest().testPressRightKey();
        new JwinapiTest().testPressLeftKey();
    }
}