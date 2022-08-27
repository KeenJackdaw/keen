package com.keenjackdaw.keen.type;

public enum AppType {
    CONSOLE("console"),
    WINDOW("window");

    private final String value;

    AppType(String value) {
        this.value = value;
    }

    public String getValue() {
        return value;
    }

    @Override
    public String toString() {
        return value;
    }
}