package com.ts02.sigtrac.healthcare;

import com.google.api.client.util.Key;

/**
 * Created by natan on 11/3/2016.
 */
public class Place {

    @Key
    public String id;

    @Key
    public String name;

    @Key
    public String reference;

    @Override
    public String toString() {
        return name + " - " + id + " - " + reference;
    }

}