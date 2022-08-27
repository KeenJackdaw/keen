package com.keenjackdaw.keen.core.app;

import com.keenjackdaw.keen.core.launcher.Launcher;

import java.io.OutputStream;

/**
 * What an application look like
 */
public interface Application {
    /**
     * Initialize app config, necessary parts etc.
     */
    void init();

    /**
     * Make application start
     */
    void start();

    /**
     * Render ui
     */
    void render();

    /**
     * Make application stop
     */
    void stop();

    /**
     * Output help message
     * @param outputStream output stream
     */
    void help(OutputStream outputStream);

    /**
     * Set launcher
     * @param launcher Launcher
     */
    void setLauncher(Launcher launcher);

    /**
     * Get launcher
     * @return Launcher
     */
    Launcher getLauncher();
}
