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
        Assert.assertTrue(mLoginActivity.isCPFValid("145.420.518-03"));
    }

    @Test
    public void testIsCPFValidShouldReturnTrue() {
        Assert.assertTrue(mLoginActivity.isCPFValid("593.382.592-18"));
        Assert.assertTrue(mLoginActivity.isCPFValid("661.358.517-30"));
        Assert.assertTrue(mLoginActivity.isCPFValid("172.549.539-28"));
        Assert.assertTrue(mLoginActivity.isCPFValid("210.752.815-20"));
        Assert.assertTrue(mLoginActivity.isCPFValid("092.586.376-90"));
    }

    @Test
    public void testIsCPFValidShouldReturnFalse() {
        Assert.assertFalse(mLoginActivity.isCPFValid("343.437.564-98"));
        Assert.assertFalse(mLoginActivity.isCPFValid("781.235.117-20"));
        Assert.assertFalse(mLoginActivity.isCPFValid("257.342.906-01"));
        Assert.assertFalse(mLoginActivity.isCPFValid("210.752.815-19"));
        Assert.assertFalse(mLoginActivity.isCPFValid("357.628.145-63"));
    }

    @Test
    public void testIsCPFValidWithLetters() {
        Assert.assertFalse(mLoginActivity.isCPFValid("123.3s21.123-4"));
    }

    @Test
    public void testIsCPFValidWithNumbersOnly() {
        Assert.assertTrue(mLoginActivity.isCPFValid("35972017334"));
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