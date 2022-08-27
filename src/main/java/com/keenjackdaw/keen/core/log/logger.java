package com.keenjackdaw.keen.core.log;

public interface logger {

    /**
     * Log info message
     * @param message
     * @param objects
     */
    void info(Object message, Object... objects);

    /**
     * Log debug message
     * @param message
     * @param objects
     */
    void debug(Object message, Object... objects);

    /**
     * Log warn message
     * @param message
     * @param objects
     */
    void warn(Object message, Object... objects);

    /**
     * Log error message
     * @param message
     * @param objects
     */
    void error(Object message, Object... objects);

    /**
     * Log fatal message
     * @param message
     * @param objects
     */
    void fatal(Object message, Object... objects);

}
