package com.takeiji.takamura.sigtrac;


import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class LoginActivityTest {

    private LoginActivity mLoginActivity;

    @Before
    public void setUp() {
        mLoginActivity = new LoginActivity();
    }

    @Test
    public void testIsCPFValidWithPoints() {
        Assert.assertTrue(mLoginActivity.isCPFValid("123.321.123-4"));
    }

    @Test
    public void testIsCPFValidWithLetters() {
        Assert.assertFalse(mLoginActivity.isCPFValid("123.3s21.123-4"));
    }

    @Test
    public void testIsCPFValidWithNumbersOnly() {
        Assert.assertTrue(mLoginActivity.isCPFValid("1233211234"));
    }

    @Test
    public void testIsCPFValidWithTooShort() {
        Assert.assertFalse(mLoginActivity.isCPFValid("123"));
    }

    @Test
    public void testIsCPFValidWithTooLong() {
        Assert.assertFalse(mLoginActivity.isCPFValid("12323434324234324324324223423"));
    }

    @Test
    public void testIsPasswordValid() {
        assert(mLoginActivity.isPasswordValid("123456"));
    }
}